/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_with_flag_mod_part1.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alikhtor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 12:58:20 by alikhtor          #+#    #+#             */
/*   Updated: 2018/05/23 16:50:08 by alikhtor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static char		*ft_width(char *temp, int str_len, t_fwp *fwp)
{
	char		*ret;

	ret = ft_strnew(fwp->width);
	ft_memset(ret, ' ', fwp->width);
	if (fwp->flag_minus)
		ft_memcpy(ret, temp, str_len);
	else if (fwp->flag_null)
	{
		ft_memset(ret, '0', fwp->width);
		ft_copy_to_the_right_side_of_the_str(&ret, temp, fwp->width);
	}
	else
		ft_copy_to_the_right_side_of_the_str(&ret, temp, fwp->width);
	return (ret);
}

void			ft_lc_specificator(char **printf_str, va_list *ap, t_fwp *fwp)
{
	wint_t		utf;
	char		ch;
	char		*temp;
	char		*temp2;
	int			str_len;

	if ((utf = va_arg(*ap, wint_t)) == 0)
	{
		ch = -42;
		temp = ft_strnew(1);
		temp = ft_memcpy(temp, &ch, 1);
	}
	else
		temp = ft_make_utf(utf);
	str_len = ft_strlen(temp);
	temp2 = (fwp->width > str_len) ? ft_width(temp, str_len, fwp)\
			: ft_strdup(temp);
	ft_strdel(&temp);
	str_len = 0;
	while (temp2[str_len] != '\0')
		ft_add_ch_to_the_ft_printf_str(temp2[str_len++], printf_str, fwp);
	ft_strdel(&temp2);
}

void			ft_c_specificator(char **printf_str, va_list *ap, t_fwp *fwp)
{
	char		ch;
	char		*ret;
	char		*ch_str;
	int			str_len;

	ch = (char)va_arg(*ap, int);
	if (ch == 0)
		ch = -42;
	ch_str = ft_strnew(1);
	ch_str = ft_memcpy(ch_str, &ch, 1);
	str_len = ft_strlen(ch_str);
	ret = (fwp->width > str_len) ? ft_width(ch_str, str_len, fwp)\
			: ft_strdup(ch_str);
	str_len = 0;
	while (ret[str_len] != '\0')
		ft_add_ch_to_the_ft_printf_str(ret[str_len++], printf_str, fwp);
	ft_strdel(&ret);
	ft_strdel(&ch_str);
}
