/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_i_mod_part2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alikhtor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/26 16:38:58 by alikhtor          #+#    #+#             */
/*   Updated: 2018/05/26 16:39:03 by alikhtor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	ft_set_sign_to_the_begining_of_the_str(char **ret,
		char sign, char *str, int size)
{
	char	*temp;
	char	*temp2;
	int		str_size;

	str_size = ft_strlen(str);
	temp = NULL;
	temp = *ret;
	*temp = sign;
	temp += size - str_size;
	temp2 = str;
	temp2++;
	temp = ft_memcpy(temp, temp2, str_size);
}

static void	ft_make_full_of_null_str(char **ret,\
		char *temp_str, t_fwp *fwp, int size)
{
	if (fwp->flag_precision && *temp_str != '0')
		size++;
	ft_memset(*ret, '0', size);
	if (temp_str[0] == '-')
		ft_set_sign_to_the_begining_of_the_str(ret, '-', temp_str, size + 1);
	else if (fwp->flag_plus)
		ft_set_sign_to_the_begining_of_the_str(ret, '+', temp_str, size + 1);
	else if (fwp->flag_space)
		ft_set_sign_to_the_begining_of_the_str(ret, ' ', temp_str, size + 1);
	else
		ft_copy_to_the_right_side_of_the_str(ret, temp_str, size);
}

static int	ft_make_precision_str(char **temp_str, char **temp, t_fwp *fwp)
{
	if (!(*temp_str[0] >= '1' && *temp_str[0] <= '9'))
	{
		*temp = ft_strnew(fwp->precision);
		ft_make_full_of_null_str(temp, *temp_str, fwp, fwp->precision);
	}
	else
	{
		*temp = ft_strnew(fwp->precision);
		ft_make_full_of_null_str(temp, *temp_str, fwp, fwp->precision - 1);
	}
	fwp->flag_precision = 0;
	fwp->flag_null = 0;
	return ((int)ft_strlen(*temp));
}

char		*ft_search_fwp_for_d_or_i_spec(char *temp_str, t_fwp *fwp)
{
	char	*ret;
	char	*temp;
	int		str_size;

	str_size = (int)ft_strlen(temp_str);
	if (fwp->flag_empty == 0 && fwp->precision >= str_size)
		str_size = ft_make_precision_str(&temp_str, &temp, fwp);
	else
		temp = ft_strdup(temp_str);
	if (fwp->width > str_size)
	{
		ret = ft_strnew(fwp->width);
		ft_memset(ret, ' ', fwp->width);
		if (fwp->flag_minus)
			ft_memcpy(ret, temp, str_size);
		else if (fwp->flag_null && fwp->flag_precision == 0)
			ft_make_full_of_null_str(&ret, temp, fwp, fwp->width);
		else
			ft_copy_to_the_right_side_of_the_str(&ret, temp, fwp->width);
	}
	else
		ret = ft_strdup(temp);
	ft_strdel(&temp);
	return (ret);
}
