/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiulian <agiulian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 16:46:48 by agiulian          #+#    #+#             */
/*   Updated: 2017/01/30 22:31:23 by agiulian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf/ft_printf.h"
#include <limits.h>

int	main(void)
{
//	char i;
	int i;

	i = 3050;
//	printf("{%-15Z}\n", 123);
//	ft_printf("{%-15Z}", 123);
	ft_printf("% Zoooo");
//	ft_printf("'{%03c}'\n", 0);
	//ft_putendl("");
	//printf("'{%3c}'\n", 0);
	//ft_printf("'{%3c}'\n", 0);
	//printf("ft : %i\n", ft_printf("{%3c}", 0));
	//printf("pr : %i", printf("{%3c}", 0));
	return (0);
}
