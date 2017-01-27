/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_arg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiulian <agiulian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 18:45:46 by agiulian          #+#    #+#             */
/*   Updated: 2017/01/27 16:14:12 by agiulian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_str_conversion(t_flags *flags)
{
	if (flags->l != 1)
		flags->raw = ft_strdup(va_arg(*(flags->ap), char*));
	else
		flags->raw = ft_strdup(va_arg(*(flags->ap), char*));
}

void	ft_str_arg(t_flags *flags)
{
	ft_length_priority(flags);
	ft_str_conversion(flags);
	if (!(flags->raw))
	{
		flags->edited = ft_strdup("(null)");
		return ;
	}
	ft_set_priority(flags);
	if (flags->raw_len == 0)
		flags->precision = 0;
	if (flags->precision && flags->raw_len)
	{
		ft_bzero(flags->raw + flags->precision, flags->raw_len - flags->precision);
		flags->raw_len = ft_strlen(flags->raw);
	}
	flags->malloc_len = ft_malloc_len(flags);
	flags->edited = (char*)ft_strnew(flags->malloc_len);
	if (!flags->edited)
		return;
	if (flags->left_adjusting)
		ft_edit_raw_left(flags);
	else
		ft_edit_raw(flags);
}
