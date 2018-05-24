/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_of_specifires_d_or_i_with_flag_mo          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alikhtor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 14:50:54 by alikhtor          #+#    #+#             */
/*   Updated: 2018/05/23 17:07:59 by alikhtor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static char			*ft_make_singed_str(char *str, t_fwp *fwp)
{
	char			*temp;
	char			*temp2;

	temp = NULL;
	temp2 = NULL;
	if (str[0] != '-' && (fwp->flag_plus || fwp->flag_space))
	{
		temp = ft_strnew(ft_strlen(str) + 1);
		temp2 = temp;
		if (fwp->flag_plus)
			temp2[0] = '+';
		else if (fwp->flag_space)
			temp2[0] = ' ';
		temp2++;
		temp2 = ft_strcpy(temp2, str);
	}
	else
		temp = ft_strdup(str);
	ft_strdel(&str);
	return (temp);
}

static char			*ft_work_with_zero(char *temp, t_fwp *fwp)
{
	char			*ret;

	if (fwp->width && *temp == '0' && !fwp->flag_precision)
		ret = ft_strdup(temp);
	else if ((!fwp->width || !fwp->precision) &&\
			*temp == '0' && !fwp->flag_plus)
	{
		ret = ft_strdup("");
		fwp->flag_empty = 1;
	}
	else
		ret = ft_strdup(temp);
	ft_strdel(&temp);
	return (ret);
}

static char			*ft_convert_d_or_i(va_list *ap, t_fwp *fwp)
{
	if (fwp->flag_mod_z)
		return (ft_itoa_singed(va_arg(*ap, ssize_t)));
	else if (fwp->flag_mod_j)
		return (ft_itoa_singed((intmax_t)va_arg(*ap, intmax_t)));
	else if (fwp->flag_mod_ll)
		return (ft_itoa_singed(va_arg(*ap, long long)));
	else if (fwp->flag_mod_l)
		return (ft_itoa_singed(va_arg(*ap, long)));
	else if (fwp->flag_mod_h)
		return (ft_itoa((short int)va_arg(*ap, int)));
	else if (fwp->flag_mod_hh)
		return (ft_itoa((signed char)va_arg(*ap, int)));
	else
		return (ft_work_with_zero(ft_itoa_singed(\
						(int)va_arg(*ap, long long int)), fwp));
}

void				ft_d_or_i_specificator(char **printf_str,\
		va_list *ap, t_fwp *fwp)
{
	char			*res_num_as_str;
	char			*temp_str;
	int				i;

	temp_str = ft_make_singed_str(ft_convert_d_or_i(ap, fwp), fwp);
	res_num_as_str = ft_search_fwp_for_d_or_i_spec(temp_str, fwp);
	i = 0;
	while (res_num_as_str[i] != '\0')
		ft_add_ch_to_the_ft_printf_str(res_num_as_str[i++], printf_str, fwp);
	ft_strdel(&res_num_as_str);
	ft_strdel(&temp_str);
}
