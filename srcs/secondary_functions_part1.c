/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   secondary_functions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alikhtor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 16:29:39 by alikhtor          #+#    #+#             */
/*   Updated: 2018/05/23 17:40:38 by alikhtor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void			ft_set_all_flags_to_null(t_fwp *fwp)
{
	fwp->width = 0;
	fwp->precision = 0;
	fwp->flag_pointer = 0;
	fwp->flag_empty = 0;
	fwp->upper_case = 0;
	fwp->flag_precision = 0;
	fwp->flag_minus = 0;
	fwp->flag_null = 0;
	fwp->flag_plus = 0;
	fwp->flag_space = 0;
	fwp->flag_hashtag = 0;
	fwp->flag_mod_hh = 0;
	fwp->flag_mod_h = 0;
	fwp->flag_mod_ll = 0;
	fwp->flag_mod_l = 0;
	fwp->flag_mod_j = 0;
	fwp->flag_mod_z = 0;
}

char			*ft_make_utf(wint_t utf_val)
{
	char		*res;

	res = ft_strnew(4);
	if (utf_val <= 0x7F)
		res[0] = utf_val;
	else if (utf_val <= 0x7FF)
	{
		res[0] = utf_val >> 6 | 0xC0;
		res[1] = (utf_val & 0x3F) | 0x80;
	}
	else if (utf_val <= 0xFFFF)
	{
		res[0] = utf_val >> 12 | 0xE0;
		res[1] = ((utf_val >> 6) & 0x3F) | 0x80;
		res[2] = (utf_val & 0x3F) | 0x80;
	}
	else
	{
		res[0] = utf_val >> 18 | 0xF0;
		res[1] = ((utf_val >> 12) & 0x3F) | 0x80;
		res[2] = ((utf_val >> 6) & 0x3F) | 0x80;
		res[3] = (utf_val & 0x3F) | 0x80;
	}
	return (res);
}

char			*ft_replace_empty_chars(char *str)
{
	char		*ret;
	char		*temp;

	ret = ft_strnew(ft_strlen(str));
	temp = ret;
	while (*str)
	{
		if (*str == -42)
			*ret = 0;
		else
			*ret = *str;
		str++;
		ret++;
	}
	ret = temp;
	return (ret);
}

void			ft_copy_to_the_right_side_of_the_str(char **ret,
	char *str, int size)
{
	char		*temp;
	int			str_size;

	str_size = ft_strlen(str);
	temp = *ret;
	temp += size - str_size;
	ft_memcpy(temp, str, str_size);
}

void			ft_add_ch_to_the_ft_printf_str(char ch, char **str, t_fwp *fwp)
{
	if (!(*str))
		*str = ft_strjoin(*str, ft_strnew(100));
	str[0][fwp->counter] = ch;
	fwp->counter++;
}
