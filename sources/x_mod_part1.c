/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_mod_part1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alikhtor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/26 16:46:24 by alikhtor          #+#    #+#             */
/*   Updated: 2018/05/26 16:47:11 by alikhtor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static char		*ft_make_x_str(char *str, t_fwp *fwp)
{
	char		*temp;
	char		*temp2;

	temp2 = NULL;
	if (fwp->flag_hashtag)
	{
		temp = ft_strnew(ft_strlen(str) + 2);
		temp2 = temp;
		temp[0] = '0';
		if (fwp->upper_case)
			temp[1] = 'X';
		else
			temp[1] = 'x';
		temp2 += 2;
		temp2 = ft_strcpy(temp2, str);
	}
	else
		temp = ft_strdup(str);
	return (temp);
}

static char		*ft_width(char *temp, t_fwp *fwp)
{
	char		*ret;
	char		*h_str;
	int			str_size;

	h_str = NULL;
	ft_memset((ret = ft_strnew(fwp->width)), ' ', fwp->width);
	if (fwp->flag_minus)
		ft_memcpy(ret, temp, ft_strlen(temp));
	else if (fwp->flag_null && !fwp->flag_precision)
	{
		ft_strdel(&ret);
		str_size = fwp->width;
		if (fwp->flag_hashtag)
		{
			str_size = fwp->width - 2;
			temp += 2;
		}
		ft_memset((h_str = ft_strnew(str_size)), '0', str_size);
		ft_copy_to_the_right_side_of_the_str(&h_str, temp, str_size);
		ret = ft_make_x_str(h_str, fwp);
		ft_strdel(&h_str);
	}
	else
		ft_copy_to_the_right_side_of_the_str(&ret, temp, fwp->width);
	return (ret);
}

static char		*ft_search_fwp_for_x_spec(char *temp_str, t_fwp *fwp)
{
	char		*temp;
	char		*temp2;
	int			str_size;

	if (fwp->precision > (str_size = ft_strlen(temp_str)))
	{
		temp2 = ft_strnew(fwp->precision);
		ft_memset(temp2, '0', fwp->precision);
		ft_copy_to_the_right_side_of_the_str(&temp2, temp_str, fwp->precision);
		temp = ft_make_x_str(temp2, fwp);
		ft_strdel(&temp2);
		str_size = ft_strlen(temp);
		fwp->flag_hashtag = 0;
	}
	else
		temp = ft_strdup(temp_str);
	temp2 = (fwp->flag_hashtag) ? ft_make_x_str(temp, fwp) : ft_strdup(temp);
	str_size = ft_strlen(temp2);
	ft_strdel(&temp);
	temp = (fwp->width >= str_size) ? ft_width(temp2, fwp) : ft_strdup(temp2);
	ft_strdel(&temp2);
	return (temp);
}

void			ft_x_specificator(va_list *ap, t_fwp *fwp)
{
	char		*temp_str;
	char		*res_str;

	temp_str = ft_convert_u_o_x(ap, 16, fwp);
	if (*temp_str == '0')
	{
		if (fwp->flag_precision)
		{
			ft_strdel(&temp_str);
			temp_str = ft_strdup("");
		}
		else if (fwp->flag_hashtag)
			fwp->flag_hashtag = 0;
		fwp->flag_hashtag = (fwp->flag_pointer == 0) ? 0 : 1;
	}
	res_str = ft_search_fwp_for_x_spec(temp_str, fwp);
	fwp->counter += write(1, res_str, ft_strlen(res_str));
	ft_strdel(&temp_str);
	ft_strdel(&res_str);
}
