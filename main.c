/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiulian <agiulian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 16:46:48 by agiulian          #+#    #+#             */
/*   Updated: 2017/02/02 19:48:19 by agiulian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf/ft_printf.h"
#include <limits.h>
#include <locale.h>

int	main(void)
{
	setlocale(LC_ALL, "");
//	printf("%2hhS, %hhS\n", 0, L"米米");
//	printf("printf : %i\n", printf("%hhS, %hhS\n", 0, L"米米"));
//	ft_printf("%2hhS, %hhS\n", 0, L"米米");
//	printf("printf : %i\n", ft_printf("%hhS, %hhS\n", 0, L"米米"));
//	ft_printf("{%.2s}\n", 0);
//	printf("ptf %i\n", printf("{% S}", L""));
//	ft_printf("{% S}\n", L"");
//	printf("ftptf %i\n", printf("{% S}", L""));
	printf("%i\n" ,printf("%.4S\n", L"ÊM-M-^QÊM-^XØ‰∏M-ÂM-^O™ÁM-^L´„M-M-^B"));
	printf("%i" ,ft_printf("%.4S\n", L"ÊM-M-^QÊM-^XØ‰∏M-ÂM-^O™ÁM-^L´„M-M-^B"));
//	ft_printf("%4.s\n", "42");
//	ft_putendl("");
//	ft_putendl("");
//	printf("%.1iC\n", L'±');
//	ft_printf("%.1C\n", L'±');
	return (0);
}
