/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiulian <agiulian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 13:35:04 by agiulian          #+#    #+#             */
/*   Updated: 2017/01/24 18:29:25 by agiulian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strparse(char *s, va_list *ap)
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
			ft_arg_tab_initialize(flags);
	//		ft_set_priority(flags); dans variadic.c
		//	ft_print_flags(flags);
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
	char	*s;
	int		count;
	char	*buf;

	s = (char*)format;
	count = 0;
	va_start(ap, format);
	list = &ap;
	buf = ft_strparse(s, list);
	count = ft_strlen(buf);
	ft_putstr(buf);
	//ft_putendl("");
	va_end(ap);
	return (count);
}

/*int	main(void)
{
	char i;
	
	i = 3050;
//	ft_putstr("to parse : ");
//	ft_putendl(("%-++05.2aqwrqwrqwr"));
	ft_printf("%lld", -30000);
//	ft_putstr(ft_strparse("asdas%d%l%agds%%ll%lptest", list));
//	ft_putendl("");
	printf("%lld", -30000);
	return (0);
}*/
