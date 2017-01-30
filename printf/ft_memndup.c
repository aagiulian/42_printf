/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiulian <arthur.giuliano@student.42.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/17 19:45:56 by agiulian          #+#    #+#             */
/*   Updated: 2017/01/30 20:39:51 by agiulian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_memndup(const char *s1, unsigned int n)
{
	unsigned int	i;
	char			*s_n;

	i = 0;
	if (!s1)
		return (NULL);
	s_n = ft_strnew(n);
	if (s_n == NULL)
		return (NULL);
	while (i < n)
	{
		s_n[i] = s1[i];
		i++;
	}
	s_n[i] = '\0';
	return (s_n);
}
