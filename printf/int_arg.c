/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_arg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiulian <agiulian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 18:45:46 by agiulian          #+#    #+#             */
/*   Updated: 2017/01/25 19:29:08 by agiulian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
	if (!flags->edited)
		return;
	if (flags->left_adjusting)
		ft_edit_raw_left(flags);
	else
		ft_edit_raw(flags);
}
