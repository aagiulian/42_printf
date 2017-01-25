/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_handling.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiulian <agiulian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 18:57:44 by agiulian          #+#    #+#             */
/*   Updated: 2017/01/25 15:58:12 by agiulian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_reset_struct(t_flags *flags, va_list *ap)
{
	flags->ap = ap;
	flags->left_adjusting = 0; // right is default
	flags->sign = 0; // could be 1000+ equivalent to 1+
	flags->sign_put = 0; // a t'on mis le signe ?
	flags->space = 0;
	flags->alternate_form = 0;
	flags->width = 0;
	flags->zero_padding = 0;
	flags->precise = 0;
	flags->precision = 0; // Beware here -1 stands for default, 0 is default for d,i,o,u,x but means no decimal . for e,E,f
	flags->h = 0;
	flags->l = 0;
	flags->j = 0;
	flags->z = 0;
	flags->conversion = '\0';
	flags->raw = NULL;
	flags->raw_len = 0;
	flags->malloc_len = 0;
	flags->edited = NULL;
	flags->index = 0;
}

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
	ft_putendl("");
	ft_putendl("");
}
