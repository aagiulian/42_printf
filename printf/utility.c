/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variadic.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiulian <agiulian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 14:43:18 by agiulian          #+#    #+#             */
/*   Updated: 2017/02/08 16:58:46 by agiulian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_maxtwo(int a, int b)
{
	if (b > a)
		return (b);
	else
		return (a);
}

int		ft_malloc_len(t_flags *flags)
{
	int max;
	int	sign;

	sign = flags->sign;
	if (sign == 2)
		sign = 1;
	max = ft_maxtwo(flags->width, flags->precision);
	if (max >= flags->raw_len)
	{
		if (max == flags->precision)
		{
			if (flags->conversion == 'p' || (flags->conversion == 'x' \
						&& flags->alternate_form == 1))
			{
				flags->raw_len -= 2;
				return (max + 2);
			}
			return (max + sign + flags->space);
		}
		else
			return (max);
	}
	else
		return ((flags->raw_len) + sign + flags->space);
}

void	ft_edit_raw(t_flags *flags)
{
	if (flags->sign > 0 && flags->zero_padding)
		ft_put_sign(flags);
	if (flags->space)
		ft_put_space(flags);
	if (flags->width > 0)
		ft_set_width(flags);
	if (flags->alternate_form)
		ft_set_hashtag(flags);
	if (flags->sign > 0)
		ft_put_sign(flags);
	while (flags->precision > flags->raw_len)
	{
		(flags->edited)[flags->index] = '0';
		flags->precision--;
		flags->index++;
	}
	ft_memcpy(flags->edited + flags->index, flags->raw - flags->sign, \
			flags->raw_len);
	(flags->edited)[flags->malloc_len] = '\0';
}

void	ft_edit_raw_left(t_flags *flags)
{
	if (flags->sign > 0)
		ft_put_sign(flags);
	if (flags->space)
		ft_put_space(flags);
	if (flags->alternate_form)
		ft_set_hashtag(flags);
	while (flags->precision > flags->raw_len)
	{
		(flags->edited)[flags->index] = '0';
		flags->precision--;
		flags->index++;
	}
	ft_memcpy(flags->edited + flags->index, flags->raw - flags->sign, \
			flags->raw_len);
	flags->index += flags->raw_len;
	if ((flags->conversion == 'x' || flags->conversion == 'X' || \
				flags->conversion == 'p') && \
			flags->alternate_form)
		flags->index -= 2;
	if (flags->width > 0)
		ft_set_width(flags);
	(flags->edited)[flags->malloc_len] = '\0';
}
