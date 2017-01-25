/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variadic.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiulian <agiulian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 14:43:18 by agiulian          #+#    #+#             */
/*   Updated: 2017/01/25 18:15:19 by agiulian         ###   ########.fr       */
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

	max = ft_maxtwo(flags->width, flags->precision);
	if (max >= flags->raw_len)
	{
		if (max == flags->precision)
			return (max + flags->sign + flags->space); // si flags->sign == 2 alors on a un malloc + 1
		else
			return (max);
	}
	else
		return (flags->raw_len + flags->sign + flags->space);
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
	flags->width--;
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

void	ft_set_width(t_flags *flags)
{
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
	if (flags->sign > 0)
		ft_put_sign(flags);
	while (flags->precision > flags->raw_len)
	{
		(flags->edited)[flags->index] = '0';
		flags->precision--;
		flags->index++;
	}
	ft_strcpy(flags->edited + flags->index, flags->raw - flags->sign);
	(flags->edited)[flags->malloc_len] = '\0';
}

void	ft_edit_raw_left(t_flags *flags)
{
	if (flags->sign > 0)
		ft_put_sign(flags);
	if (flags->space)
		ft_put_space(flags);
	while (flags->precision > flags->raw_len)
	{
		(flags->edited)[flags->index] = '0';
		flags->precision--;
		flags->index++;
	}
	ft_strcpy(flags->edited + flags->index, flags->raw - flags->sign);
	flags->index += flags->raw_len;
	if (flags->width > 0)
		ft_set_width(flags);
	(flags->edited)[flags->malloc_len] = '\0';
}

void	ft_int_conversion(t_flags *flags)
{
	if (!flags->h && !flags->l && !flags->j && !flags->j && !flags->z)
		flags->raw = ft_itoa(va_arg(*(flags->ap), int));
	else if (flags->h == 2)
		flags->raw = ft_itoa((signed char)va_arg(*(flags->ap), int));
	else if (flags->h == 1)
		flags->raw = ft_itoa((short)va_arg(*(flags->ap), int));
	else if (flags->l == 1)
		flags->raw = ft_itoa((long)va_arg(*(flags->ap), int));
	else if (flags->l == 2)
		flags->raw = ft_itoa((long long)va_arg(*(flags->ap), int));
	else if (flags->j == 1)
		flags->raw = ft_itoa((intmax_t)va_arg(*(flags->ap), int));
	else if (flags->z == 1)
		flags->raw = ft_itoa((size_t)va_arg(*(flags->ap), int));
}

void	ft_int_arg(t_flags *flags)
{
	ft_int_conversion(flags);
	ft_set_priority(flags);
	flags->malloc_len = ft_malloc_len(flags);
	flags->edited = (char*)malloc(sizeof(flags->malloc_len + 1));
	//	if !(flags->edited) protection MALLOC NEEDED
	if (flags->left_adjusting)
		ft_edit_raw_left(flags);
	else
		ft_edit_raw(flags);
}

