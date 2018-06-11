/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_mod_part1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alikhtor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/26 16:42:57 by alikhtor          #+#    #+#             */
/*   Updated: 2018/05/26 16:53:12 by alikhtor         ###   ########.fr       */
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

static char		*ft_make_precision_str(char *str, t_fwp *fwp)
{
	char		*ret;

	ret = ft_strnew(fwp->precision);
	ft_memcpy(ret, str, fwp->precision);
	return (ret);
}

static char		*ft_make_utf_str(wchar_t *utf, t_fwp *fwp)
{
	char		*ret;
	char		*temp;
	char		*temp2;

	ret = ft_strnew(0);
	while (*utf)
	{
		temp = ft_make_utf(*utf);
		if (fwp->flag_precision && fwp->precision > 0)
		{
			if ((int)(ft_strlen(temp) + ft_strlen(ret)) > fwp->precision)
			{
				ft_strdel(&temp);
				return (ret);
			}
		}
		temp2 = ret;
		ret = ft_strjoin(temp2, temp);
		ft_strdel(&temp2);
		ft_strdel(&temp);
		utf++;
	}
	return (ret);
}

void			ft_ls_specificator(va_list *ap, t_fwp *fwp)
{
	wchar_t		*utf;
	char		*temp;
	char		*temp2;
	int			str_len;

	utf = va_arg(*ap, wchar_t*);
	if (utf != NULL && !(ft_strcmp((char*)utf, "")))
		temp = ft_strdup("");
	else
		temp = (utf != NULL) ? ft_make_utf_str(utf, fwp) : ft_strdup("(null)");
	if (fwp->flag_precision)
	{
		temp2 = ft_make_precision_str(temp, fwp);
		ft_strdel(&temp);
		temp = ft_strdup(temp2);
		ft_strdel(&temp2);
	}
	str_len = ft_strlen(temp);
	temp2 = (fwp->width > str_len) ?\
			ft_width(temp, str_len, fwp) : ft_strdup(temp);
	fwp->counter += write(1, temp2, ft_strlen(temp2));
	ft_strdel(&temp);
	ft_strdel(&temp2);
}

void			ft_s_specificator(va_list *ap, t_fwp *fwp)
{
	char		*str;
	char		*temp;
	char		*temp2;
	int			str_len;

	str = va_arg(*ap, char*);
	if (str != NULL && !(ft_strcmp(str, "")))
		temp = ft_strdup("");
	else
		temp = (str != NULL) ? ft_strdup(str) : ft_strdup("(null)");
	if (fwp->flag_precision)
	{
		temp2 = ft_make_precision_str(temp, fwp);
		ft_strdel(&temp);
		temp = ft_strdup(temp2);
		ft_strdel(&temp2);
	}
	str_len = ft_strlen(temp);
	temp2 = (fwp->width > str_len) ?\
			ft_width(temp, str_len, fwp) : ft_strdup(temp);
	fwp->counter += write(1, temp2, ft_strlen(temp2));
	ft_strdel(&temp);
	ft_strdel(&temp2);
}
