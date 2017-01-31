/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiulian <agiulian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 16:46:48 by agiulian          #+#    #+#             */
/*   Updated: 2017/01/31 18:23:39 by agiulian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf/ft_printf.h"
#include <limits.h>
#include <locale.h>

int	main(void)
{
	setlocale(LC_ALL, "");
	printf("%S\n", L"Á±≥");
	ft_printf("%S\n", L"Á±≥");
	ft_putendl("");
	ft_putendl("");
	ft_putendl("");
	printf("%c\n", L'±');
	ft_printf("%c\n", L'±');
	return (0);
}
