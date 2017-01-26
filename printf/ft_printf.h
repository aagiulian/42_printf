/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiulian <agiulian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 13:31:06 by agiulian          #+#    #+#             */
/*   Updated: 2017/01/26 18:42:23 by agiulian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/includes/libft.h"
# include <stdarg.h>
# include <stdio.h>
# include <inttypes.h>

# define DEBUG printf("Line: %i, File : %s.\n",__LINE__, __FILE__);

typedef struct	s_flags
{
	va_list		*ap;
	int			left_adjusting;
	int			sign;
	int			sign_put;
	int			space;
	int			alternate_form;
	int			width;
	int			zero_padding;
	int			precision; // rajoute des 0 pour tous les int, tronque chaine mais pas int
	int			precise;
	int			h;
	int			l;
	int			j;
	int			z;
	char		conversion;
	char		*raw; // attention faudra penser a le free
	int			raw_len;
	int			malloc_len;
	char		*edited; // pareil
	int			index;
}				t_flags;

int				ft_printf(const char *restrict format, ...);
//char	*ft_store(char **s);
char			*ft_grep_all(char *s, t_flags *flags, va_list *ap);
char			*ft_grep_flags(char *s, t_flags *flags);
char			*ft_grep_width(char *s, t_flags *flags);
char			*ft_grep_precision(char *s, t_flags *flags);
char			*ft_grep_length(char *s, t_flags *flags);
char			*ft_grep_conversion(char *s, t_flags *flags);
void			ft_reset_struct(t_flags *flags, va_list *ap);
void			ft_set_priority(t_flags *flags);
void			ft_zero_priority(t_flags *flags);
void			ft_left_over_zero(t_flags *flags);
void			ft_length_priority(t_flags *flags);
void			ft_signed_priority(t_flags *flags);
void			ft_size_priority(t_flags *flags);
void			ft_arg_tab_initialize(t_flags *flags); // plus utilisee
void			ft_init_fctptr_table(void (**ptr_tab)(t_flags*));
void			ft_access_ptrtab(t_flags *flags, void (**ptr_tab)(t_flags*));
void			ft_int_arg(t_flags *flags);
void			ft_uint_arg(t_flags *flags);
void			ft_oint_arg(t_flags *flags);
void			ft_xint_arg(t_flags *flags);
void			ft_xcapint_arg(t_flags *flags);
void			ft_pct_arg(t_flags *flags);
int				ft_malloc_len(t_flags *flags);
void			ft_edit_raw(t_flags *flags);
void			ft_edit_raw_left(t_flags *flags);
void			ft_print_flags(t_flags *flags); // pour test

#endif
