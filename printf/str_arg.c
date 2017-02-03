/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_arg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiulian <agiulian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 18:45:46 by agiulian          #+#    #+#             */
/*   Updated: 2017/02/03 15:31:31 by agiulian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_wchar_string(t_flags *flags, wchar_t *save)
{
	int		len;
	char	*str;
	int		i;

	len = 0;
	i = 0;
//	if ((int)save[0] == 0)
	if (!save[len])
	{
		flags->raw = ft_strnew(1);
		flags->raw_len = 0;
		return ;
	}
	while (save && save[i])
	{
		if (!flags->raw)
			flags->raw = ft_strnew(4);
		ft_handle_unicode(flags, (int)save[i]);
		str = ft_memnjoin(str, flags->raw, len, flags->raw_len);
		len += flags->raw_len;
		i++;
	}
	str[len + 1] = '\0';
	flags->raw = str;
	flags->raw_len = len;
}

void	ft_str_conversion(t_flags *flags)
{
	wchar_t	*save;

	if (flags->l != 1)
		flags->raw = ft_strdup(va_arg(*(flags->ap), char*));
	else
	{
		save = (va_arg(*(flags->ap), wchar_t*));
		if (save)
			ft_wchar_string(flags, save);
	}
}

void	ft_str_arg(t_flags *flags)
{
	ft_length_priority(flags);
	ft_str_conversion(flags);
	if (!(flags->raw))
	{
		flags->raw_len = 6;
		flags->raw = ft_strdup("(null)");
	}
	ft_set_priority(flags);
	flags->malloc_len = ft_malloc_len(flags);
	flags->edited = (char*)ft_strnew(flags->malloc_len);
	if (!flags->edited || flags->ret == -1)
		return;
	if (flags->left_adjusting)
		ft_edit_raw_left(flags);
	else
		ft_edit_raw(flags);
}
