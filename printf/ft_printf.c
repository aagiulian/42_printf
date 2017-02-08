/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiulian <agiulian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 13:35:04 by agiulian          #+#    #+#             */
/*   Updated: 2017/02/08 16:01:07 by agiulian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *restrict format, ...)
{
	va_list ap;
	char	*buf;
	void	(*ptr_tab[128])(t_flags*);
	t_flags	*flags;
	int		ret;

	if ((ft_strlen(format) == 0) || (ft_strlen(format) == 1 && \
				format[0] == '%'))
		return (0);
	if (!(flags = (t_flags*)malloc(sizeof(t_flags))))
		return (-1);
	ft_init_fctptr_table(ptr_tab);
	flags->ret = 0;
	va_start(ap, format);
	if ((!(buf = ft_strparse((char*)format, &ap, ptr_tab, flags))))
		return (-1);
	ft_reset_struct(flags, &ap);
	ret = flags->ret;
	free(flags);
	write(1, buf, ret);
	ft_strdel(&buf);
	va_end(ap);
	return (ret);
}
