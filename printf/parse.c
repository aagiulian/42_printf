/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiulian <agiulian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 20:50:37 by agiulian          #+#    #+#             */
/*   Updated: 2017/02/10 01:01:52 by agiulian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_grep_all(char *s, t_flags *flags, va_list *ap)
{
	ft_reset_struct(flags, ap);
	s = ft_grep_flags(s, flags);
	s = ft_grep_width(s, flags);
	s = ft_grep_precision(s, flags);
	s = ft_grep_length(s, flags);
	s = ft_grep_conversion(s, flags);
	return (s);
}

void		ft_set_priority(t_flags *flags)
{
	ft_patch(flags);
	ft_signed_priority(flags);
	ft_zero_priority(flags);
	ft_size_priority(flags);
}

static char	*ft_split(char *buf, t_flags *flags)
{
	buf = ft_memnjoin(buf, flags->edited, flags->ret, \
			flags->malloc_len);
	ft_strdel(&flags->edited);
	flags->ret += flags->malloc_len;
	return (buf);
}

char		**color_tab_init(char **color_tab)
{
	color_tab[0] = "{red}";
	color_tab[1] = "{grn}";
	color_tab[2] = "{yel}";
	color_tab[3] = "{blu}";
	color_tab[4] = "{mag}";
	color_tab[5] = "{cyn}";
	color_tab[6] = "{wht}";
	color_tab[7] = "{ec}";
	return (color_tab);
}

char		*ft_putcolor(char *temp_c, int i)
{
	if (i == 0)
		ft_strncpy(temp_c, RED, 5);
	else if (i == 1)
		ft_strncpy(temp_c, GRN, 5);
	else if (i == 2)
		ft_strncpy(temp_c, YEL, 5);
	else if (i == 3)
		ft_strncpy(temp_c, BLU, 5);
	else if (i == 4)
		ft_strncpy(temp_c, MAG, 5);
	else if (i == 5)
		ft_strncpy(temp_c, CYN, 5);
	else if (i == 6)
		ft_strncpy(temp_c, WHT, 5);
	else if (i == 7)
		ft_strncpy(temp_c, EC, 4);
	if (temp_c + 5 && i != 7)
		return (temp_c + 5);
	else if (temp_c + 4 && i == 7)
		return (temp_c + 4);
	return (NULL);


}
void		ft_search_color(char *s, t_flags *flags)
{
	int		i;
	char	*color_tab[7];

	color_tab_init(color_tab);
	i = 0;
	while (i < 8)
	{
		if (ft_strstr(s, color_tab[i]))
		{
			if (!flags->raw || ft_strstr(s, color_tab[i]) < flags->raw)
			{
				flags->l = i;
				flags->raw = ft_strstr(s, color_tab[i]);
			}
			if (i == 7)
			{
				if ((flags->raw = ft_putcolor(flags->raw, flags->l)))
					s = flags->raw;
				else
					return ;
				flags->raw = NULL;
				i = 0;
				flags->l = 0;
			}
		}
		i++;
	}
}

static char	*ft_split_second(char **s, char *buf, t_flags *flags)
{
	buf = ft_memnjoin(buf, *s, flags->ret, ft_strchr(*s, '%') - *s);
	flags->ret += ft_strchr(*s, '%') - *s;
	*s = ft_strchr(*s, '%');
	return (buf);
}

char		*ft_strparse(char *str, va_list *ap, void (**ptr_tab)(t_flags*), \
		t_flags *flags)
{
	char	*buf;
	char	*s;
	char	*save;

	buf = NULL;
	s = ft_strdup(str);
	save = s;
	flags->raw = NULL;
	ft_search_color(s, flags);
	while (*s)
	{
		if (*s && *s != '%' && ft_strchr(s, '%'))
			buf = ft_split_second(&s, buf, flags);
		else if (*s && *s != '%')
		{
			buf = ft_memjoin(buf, s, flags->ret);
			flags->ret += ft_strlen(s);
		ft_strdel(&save);
			return (buf);
		}
		s++;
		s = ft_grep_all(s, flags, ap);
		ptr_tab[(int)flags->conversion](flags);
		if (flags->ret == -1)
		{
			ft_strdel(&buf);
			ft_strdel(&save);
			return (NULL);
		}
		if (flags->edited)
			buf = ft_split(buf, flags);
		if (flags->raw_len && flags->raw)
			ft_strdel(&flags->raw);
	}
		ft_strdel(&save);
	return (buf);
}
