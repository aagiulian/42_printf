/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variadic.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiulian <agiulian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 14:43:18 by agiulian          #+#    #+#             */
/*   Updated: 2017/02/06 16:32:55 by agiulian         ###   ########.fr       */
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
			if (flags->conversion == 'p' || (flags->conversion == 'x' && flags->alternate_form == 1))
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

void	ft_put_sign(t_flags *flags)
{
	if (flags->sign == 2)
	{
		(flags->edited)[flags->index] = '-';
		flags->sign = -1;
	}
	else if (flags->sign == 1)
	{
		(flags->edited)[flags->index] = '+';
		flags->sign = 0;
	}
	flags->index++;
	flags->sign_put = 1;
	flags->width--;
}

void	ft_put_space(t_flags *flags)
{
	flags->edited[flags->index] = ' ';
	flags->index++;
	if (flags->width)
		flags->width--;
	else
		flags->precision--;
	flags->space = -1;
}

void	ft_fill_width(t_flags *flags)
{
		if (flags->zero_padding)
			(flags->edited)[flags->index] = '0';
		else
			(flags->edited)[flags->index] = ' ';
		flags->index++;
		flags->width--;
}

void	ft_set_hashtag(t_flags *flags)
{
	if (flags->conversion == 'x' || flags->conversion == 'X' || flags->conversion == 'p')
	{
		flags->edited[flags->index] = '0';
		flags->edited[flags->index + 1] = (flags->conversion == 'X') ? 'X' : 'x';
		flags->index += 2;
	}
}
void	ft_set_width(t_flags *flags)
{
	if (flags->conversion == 'p' && flags->zero_padding)
	{
		ft_set_hashtag(flags);
		flags->alternate_form = 0;
	}
	if (flags->sign == 0)
	{
		while (flags->width > flags->raw_len && flags->width > flags->precision)
			ft_fill_width(flags);
	}
	if (flags->sign)
	{
		while (flags->width - 1 + flags->sign_put > flags->raw_len && \
				flags->width - 1 + flags->sign_put  > flags->precision)
			ft_fill_width(flags);
	}
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
	ft_memcpy(flags->edited + flags->index, flags->raw - flags->sign, flags->raw_len);
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
	ft_strncpy(flags->edited + flags->index, flags->raw - flags->sign, flags->raw_len);
	flags->index += flags->raw_len;
	if ((flags->conversion == 'x' || flags->conversion == 'X' || flags->conversion == 'p') && \
			flags->alternate_form)
		flags->index -= 2;
	if (flags->width > 0)
		ft_set_width(flags);
	(flags->edited)[flags->malloc_len] = '\0';
//	if (flags->raw)
//		ft_strdel(&flags->raw);
}
