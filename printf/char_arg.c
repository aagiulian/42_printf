/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_arg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiulian <agiulian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 18:45:46 by agiulian          #+#    #+#             */
/*   Updated: 2017/01/30 16:11:13 by agiulian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_char_conversion(t_flags *flags)
{
	char c;

	flags->raw = ft_strnew(1);
	if (flags->l != 1)
		c = (va_arg(*(flags->ap), int));
	else
		c = (va_arg(*(flags->ap), int));
	if (!c)
	{
		flags->precision = 0;
	//	flags->width--;
		flags->raw[0] = '\0';
	}
	else
		flags->raw[0] = c;
}

void	ft_char_arg(t_flags *flags)
{
	ft_length_priority(flags);
	ft_char_conversion(flags);
	ft_set_priority(flags);
	flags->raw_len = 1;
	flags->malloc_len = ft_malloc_len(flags);
	flags->edited = ft_strnew(flags->malloc_len);
	if (!flags->edited)
		return;
	if (flags->left_adjusting)
		ft_edit_raw_left(flags);
	else
		ft_edit_raw(flags);
}
