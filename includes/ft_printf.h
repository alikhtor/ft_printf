/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alikhtor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 16:22:46 by alikhtor          #+#    #+#             */
/*   Updated: 2018/05/24 19:13:12 by alikhtor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <locale.h>
# include <wchar.h>
# include "../lib/libft/libft.h"

typedef struct		s_flags_width_precision
{
	int				width;
	int				precision;
	int				counter;
	unsigned short	upper_case;
	unsigned short	flag_empty;
	unsigned short	flag_pointer;
	unsigned short	flag_precision;
	unsigned short	flag_minus;
	unsigned short	flag_null;
	unsigned short	flag_plus;
	unsigned short	flag_space;
	unsigned short	flag_hashtag;
	unsigned short	flag_mod_hh;
	unsigned short	flag_mod_h;
	unsigned short	flag_mod_ll;
	unsigned short	flag_mod_l;
	unsigned short	flag_mod_j;
	unsigned short	flag_mod_z;
}					t_fwp;

int					ft_printf(char *fmt, ...);
char				*ft_search_fwp_for_d_or_i_spec\
						(char *temp_num_as_str, t_fwp *fwp);
void				ft_find_flags_width_precision(char **fmt, t_fwp *fwp);
void				ft_set_all_flags_to_null(t_fwp *fwp);
void				ft_copy_to_the_right_side_of_the_str\
						(char **ret, char *str, int size);
char				*ft_make_utf(wint_t utf_val);
void				ft_add_ch_to_the_ft_printf_str\
						(char ch, char **str, t_fwp *fwp);
char				*ft_width_for_no_spec(char temp, t_fwp *fwp);
char				*ft_itoa_singed(intmax_t n);
char				*ft_itoa_base_unsigned(size_t n, int base, int up);
char				*ft_convert_u_o_x(va_list *ap, int base, t_fwp *fwp);
char				*ft_replace_empty_chars(char *str, t_fwp *fwp);
void				ft_o_specificator\
						(char **printf_str, va_list *ap, t_fwp *fwp);
void				ft_u_specificator\
						(char **printf_str, va_list *ap, t_fwp *fwp);
void				ft_x_specificator\
						(char **printf_str, va_list *ap, t_fwp *fwp);
void				ft_d_or_i_specificator\
						(char **printf_str, va_list *ap, t_fwp *fwp);
void				ft_s_specificator\
						(char **printf_str, va_list *ap, t_fwp *fwp);
void				ft_ls_specificator\
						(char **printf_str, va_list *ap, t_fwp *fwp);
void				ft_c_specificator\
						(char **printf_str, va_list *ap, t_fwp *fwp);
void				ft_lc_specificator\
						(char **printf_str, va_list *ap, t_fwp *fwp);

#endif
