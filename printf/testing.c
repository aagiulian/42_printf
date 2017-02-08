/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiulian <agiulian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 20:52:52 by agiulian          #+#    #+#             */
/*   Updated: 2017/02/06 20:53:08 by agiulian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_flags(t_flags *flags)
{
	ft_putstr("\nleft_adjusting : ");
	ft_putnbr(flags->left_adjusting);
	ft_putstr("\nsign : ");
	ft_putnbr(flags->sign);
	ft_putstr("\nsign_put : ");
	ft_putnbr(flags->sign_put);
	ft_putstr("\nspace : ");
	ft_putnbr(flags->space);
	ft_putstr("\nalternate_form : ");
	ft_putnbr(flags->alternate_form);
	ft_putstr("\nwidth : ");
	ft_putnbr(flags->width);
	ft_putstr("\nzero_padding : ");
	ft_putnbr(flags->zero_padding);
	ft_putstr("\nprecise : ");
	ft_putnbr(flags->precise);
	ft_putstr("\nprecision : ");
	ft_putnbr(flags->precision);
	ft_putstr("\nh : ");
	ft_putnbr(flags->h);
	ft_putstr("\nl : ");
	ft_putnbr(flags->l);
	ft_putstr("\nj : ");
	ft_putnbr(flags->j);
	ft_putstr("\nz : ");
	ft_putnbr(flags->z);
	ft_putstr("\nconversion : ");
	ft_putchar(flags->conversion);
	ft_putstr("\nraw : ");
	ft_putstr(flags->raw);
	ft_putstr("\nraw_len : ");
	ft_putnbr(flags->raw_len);
	ft_putstr("\nmalloc_len : ");
	ft_putnbr(flags->malloc_len);
	ft_putstr("\nedited : ");
	ft_putstr(flags->edited);
	ft_putstr("\nret : ");
	ft_putnbr(flags->ret);
	ft_putendl("");
	ft_putendl("");
}
