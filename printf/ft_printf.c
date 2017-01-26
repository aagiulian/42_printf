/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiulian <agiulian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 13:35:04 by agiulian          #+#    #+#             */
/*   Updated: 2017/01/26 16:03:38 by agiulian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strparse(char *s, va_list *ap, void (**ptr_tab)(t_flags*))
{
	t_flags	*flags;
	char	*buf;

	buf = NULL;
	flags = (t_flags*)malloc(sizeof(t_flags));
	while (*s)
	{
		if (*s && *s != '%')
		{
			if (ft_strchr(s, '%'))
			{
				buf = ft_strnjoin(buf, s, ft_strchr(s, '%') - s);
				s = ft_strchr(s, '%');
			}
			else
				return (ft_strjoin(buf, s));
		}
		if (*s && *s == '%')
		{
			s++;
			s = ft_grep_all(s, flags, ap);
		//	ft_arg_tab_initialize(flags);
			ptr_tab[(int)flags->conversion](flags);
			buf = ft_strjoin(buf, flags->edited);
		}
	}
	return (buf);
}

/*char	*ft_store(char **s)
{
	char	*buffer;
	int		i;


	buffer = (char*)malloc(sizeof(4096 + 1));
	while (**s && **s != '%' && i < 4096)
	{
		buffer[i] = **s;
		ft_putchar(buffer[i]);
		(*s)++;
		i++;
	}
	buffer[i] = '\0';
	return (buffer);
}*/
	
int		ft_printf(const char * restrict format, ...)
{
	va_list ap;
	va_list *list;
	int		count;
	char	*buf;
	void	(*ptr_tab[128])(t_flags*);

	ft_init_fctptr_table(ptr_tab);
	count = 0;
	va_start(ap, format);
	list = &ap;
	buf = ft_strparse((char*)format, list, ptr_tab);
	count = ft_strlen(buf);
	ft_putstr(buf);
	va_end(ap);
	return (count);
}
