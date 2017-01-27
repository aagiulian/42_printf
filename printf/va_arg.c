/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   va_arg.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiulian <agiulian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/21 15:17:11 by agiulian          #+#    #+#             */
/*   Updated: 2017/01/27 18:08:59 by agiulian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_conv_error(t_flags *flags)
{
	flags->edited = NULL;
//	ft_putendl("conversion format is bad");
}

int		*ft_init_ascii_tab(int *ascii_tab)
{
	int	i;

	i = 0;
	while (i < 128)
	{
		ascii_tab[i] = i;
		i++;
	}
	return (ascii_tab);
}

void	ft_init_fctptr_table(void (**ptr_tab)(t_flags*))
{
	int	i;

	i = 0;
	while (i < 128)
	{
		ptr_tab[i] = &ft_conv_error;
		i++;
	}
	ptr_tab[37] = &ft_pct_arg;//&pct_arg; // %
//	ptr_tab[67] = &c_arg; // C
	ptr_tab[68] = &ft_int_arg; // D
	ptr_tab[79] = &ft_oint_arg; // O
//	ptr_tab[83] = &S_arg; // S
	ptr_tab[85] = &ft_uint_arg; // U
	ptr_tab[88] = &ft_xcapint_arg; // X
	ptr_tab[99] = &ft_char_arg; // c
	ptr_tab[100] = &ft_int_arg; // d
	ptr_tab[105] = &ft_int_arg; // i
	ptr_tab[111] = &ft_oint_arg; // o
	ptr_tab[112] = &ft_xint_arg; // p
	ptr_tab[115] = &ft_str_arg; // s
	ptr_tab[117] = &ft_uint_arg; // u
	ptr_tab[120] = &ft_xint_arg; // x
}

/*void	ft_arg_tab_initialize(t_flags *flags)
{
	int		ascii_tab[128];
	void	(*ptr_tab[128])(t_flags*);

	ft_init_ascii_tab(ascii_tab);
	ft_init_fctptr_table(ptr_tab);
	ptr_tab[(int)flags->conversion](flags);
}*/
