/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiulian <agiulian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 20:50:37 by agiulian          #+#    #+#             */
/*   Updated: 2017/02/08 14:46:01 by agiulian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_grep_all(char *s, t_flags *flags, va_list *ap)
{
	ft_reset_struct(flags, ap);
	s = ft_grep_flags(s, flags);
	s = ft_grep_width(s, flags);
	s = ft_grep_precision(s, flags);
	s = ft_grep_length(s, flags);
	s = ft_grep_conversion(s, flags);
	return (s);
}

void	ft_set_priority(t_flags *flags)
{
	ft_patch(flags);
	ft_signed_priority(flags);
	ft_zero_priority(flags);
	ft_size_priority(flags);
}

char	*ft_strparse(char *s, va_list *ap, void (**ptr_tab)(t_flags*), \
		t_flags *flags)
{
	char	*buf;
	int		count;

	count = 0;
	buf = NULL;
	while (*s)
	{
		if (*s && *s != '%')
		{
			if (ft_strchr(s, '%'))
			{
				buf = ft_memnjoin(buf, s, flags->ret, ft_strchr(s, '%') - s);
				flags->ret += ft_strchr(s, '%') - s;
				s = ft_strchr(s, '%');
			}
			else
			{
				buf = ft_memjoin(buf, s, flags->ret);
				flags->ret += ft_strlen(s);
				return (buf);
			}
		}
		if (*s && *s == '%')
		{
			s++;
			s = ft_grep_all(s, flags, ap);
			ptr_tab[(int)flags->conversion](flags);
			if (flags->ret == -1)
				return (NULL);
			if (flags->edited)
			{
				buf = ft_memnjoin(buf, flags->edited, flags->ret, \
						flags->malloc_len);
				ft_strdel(&flags->edited);
			}
			if (flags->raw_len && flags->raw)
				ft_strdel(&flags->raw);
			flags->ret += flags->malloc_len;
		}
	}
	return (buf);
}
