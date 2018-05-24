/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   o_u_x_with_flag_mod_part1.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alikhtor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 17:36:37 by alikhtor          #+#    #+#             */
/*   Updated: 2018/05/23 18:56:08 by alikhtor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char			*ft_convert_u_o_x(va_list *ap, int base, t_fwp *fwp)
{
	if (fwp->flag_mod_l)
		return (ft_itoa_base_unsigned(va_arg(*ap, unsigned long),\
					base, fwp->upper_case));
	else if (fwp->flag_mod_j)
		return (ft_itoa_base_unsigned(va_arg(*ap, uintmax_t),\
					base, fwp->upper_case));
	else if (fwp->flag_mod_ll)
		return (ft_itoa_base_unsigned(va_arg(*ap, unsigned long long),\
					base, fwp->upper_case));
	else if (fwp->flag_mod_hh)
		return (ft_itoa_base_unsigned((unsigned char)va_arg(*ap,\
						unsigned int), base, fwp->upper_case));
	else if (fwp->flag_mod_h)
		return (ft_itoa_base_unsigned((unsigned short)va_arg(*ap,\
						unsigned int), base, fwp->upper_case));
	else if (fwp->flag_mod_z)
		return (ft_itoa_base_unsigned(va_arg(*ap, size_t),\
					base, fwp->upper_case));
	else
		return (ft_itoa_base_unsigned(va_arg(*ap, unsigned int),\
					base, fwp->upper_case));
}

static char		*ft_width(char *temp, int str_size, t_fwp *fwp)
{
	char		*ret;

	if (fwp->width > str_size)
	{
		ret = ft_strnew(fwp->width);
		ft_memset(ret, ' ', fwp->width);
		if (fwp->flag_minus)
			ft_memcpy(ret, temp, str_size);
		else if (fwp->flag_null && fwp->flag_precision == 0)
		{
			ft_memset(ret, '0', fwp->width);
			ft_copy_to_the_right_side_of_the_str(&ret, temp, fwp->width);
		}
		else
			ft_copy_to_the_right_side_of_the_str(&ret, temp, fwp->width);
	}
	else
		ret = ft_strdup(temp);
	return (ret);
}

static char		*ft_search_fwp_for_u_spec(char *temp_str, t_fwp *fwp)
{
	char		*ret;
	char		*temp;
	int			str_size;

	str_size = ft_strlen(temp_str);
	if (fwp->precision > str_size)
	{
		temp = ft_strnew(fwp->precision);
		ft_memset(temp, '0', fwp->precision);
		ft_copy_to_the_right_side_of_the_str(&temp, temp_str, fwp->precision);
		str_size = ft_strlen(temp);
		fwp->flag_null = 0;
	}
	else
		temp = ft_strdup(temp_str);
	ret = ft_width(temp, str_size, fwp);
	ft_strdel(&temp);
	return (ret);
}

void			ft_u_specificator(char **printf_str, va_list *ap, t_fwp *fwp)
{
	char		*temp_str;
	char		*res_str;
	int			i;

	temp_str = ft_convert_u_o_x(ap, 10, fwp);
	if (*temp_str == '0' && fwp->flag_precision)
	{
		ft_strdel(&temp_str);
		temp_str = ft_strdup("");
		fwp->flag_precision = 0;
	}
	res_str = ft_search_fwp_for_u_spec(temp_str, fwp);
	ft_strdel(&temp_str);
	i = 0;
	while (res_str[i] != '\0')
		ft_add_ch_to_the_ft_printf_str(res_str[i++], printf_str, fwp);
	ft_strdel(&res_str);
}
