/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grep.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiulian <agiulian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 14:51:28 by agiulian          #+#    #+#             */
/*   Updated: 2017/02/08 18:41:38 by agiulian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_grep_flags(char *s, t_flags *flags)
{
	while (*s == '-' || *s == '+' || *s == ' ' || *s == '#' || *s == '0')
	{
		if (*s == '-')
			flags->left_adjusting++;
		else if (*s == '+')
			flags->sign = 1;
		else if (*s == ' ')
			flags->space++;
		else if (*s == '#')
			flags->alternate_form++;
		else if (*s == '0')
			flags->zero_padding++;
		s++;
	}
	return (s);
}

char	*ft_grep_width(char *s, t_flags *flags)
{
	while (*s >= '0' && *s <= '9')
	{
		flags->width *= 10;
		flags->width += *s - '0';
		s++;
	}
	s = ft_grep_flags(s, flags);
	if (*s == '*')
	{
		flags->width = va_arg((*flags->ap), int);
		if (flags->width < 0)
		{
			flags->width = -flags->width;
			flags->left_adjusting++;
		}
		s++;
		s = ft_grep_flags(s, flags);
		if (*s >= '0' && *s <= '9')
		{
			flags->width = 0;
			while (*s >= '0' && *s <= '9')
			{
				flags->width *= 10;
				flags->width += *s - '0';
				s++;
			}
		}
	}
	return (s);
}

char	*ft_grep_precision(char *s, t_flags *flags)
{
	if (*s == '.')
	{
		s++;
		flags->precise = 1;
		if (*s == '*')
		{
			flags->precision = va_arg((*flags->ap), int);
			if (flags->precision < 0)
			{
				flags->precise = 0;
				flags->precision = 0;
			}
			s++;
			return (s);
		}
		while (*s >= '0' && *s <= '9')
		{
			flags->precision *= 10;
			flags->precision += *s - '0';
			s++;
		}
	}
	return (s);
}

char	*ft_grep_length(char *s, t_flags *flags)
{
	if (*s == 'h')
	{
		flags->h++;
		if (*(s + 1) == 'h')
		{
			s++;
			flags->h++;
		}
	}
	else if (*s == 'l')
	{
		flags->l++;
		if (*(s + 1) == 'l')
		{
			flags->l++;
			s++;
		}
	}
	else if (*s == 'j')
		flags->j++;
	else if (*s == 'z')
		flags->z++;
	else
	{
		s = ft_grep_flags(s, flags);
		return (s);
	}
	s = ft_grep_flags(s + 1, flags);
	return (s);
}

char	*ft_grep_conversion(char *s, t_flags *flags)
{
	if (*s == 's' || *s == 'S' || *s == 'p' || *s == 'd' || *s == 'D' || \
			*s == 'i' || *s == 'o' || *s == 'O' || *s == 'u' || *s == 'U' \
			|| *s == 'x' || *s == 'X' || *s == 'c' || *s == 'C' || *s == 'b' \
			|| *s == 'B' || *s == '%')
		flags->conversion = *s;
	else
		flags->conversion = *s;
	s++;
	return (s);
}
