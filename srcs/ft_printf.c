/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alikhtor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 17:34:34 by alikhtor          #+#    #+#             */
/*   Updated: 2018/05/23 17:22:31 by alikhtor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void		ft_find_specification_3(char **fmt,\
		char **printf_str, va_list *ap, t_fwp *fwp)
{
	char		*temp;
	int			i;

	i = 0;
	if (**fmt == 'p')
	{
		fwp->flag_hashtag = 1;
		fwp->flag_mod_j = 1;
		fwp->flag_mod_l = 0;
		fwp->flag_pointer = 1;
		ft_x_specificator(printf_str, ap, fwp);
		*fmt += 1;
	}
	else if (**fmt == '%' || ft_isalpha(**fmt))
	{
		temp = ft_width_for_no_spec(**fmt, fwp);
		while (temp[i] != '\0')
			ft_add_ch_to_the_ft_printf_str(temp[i++], printf_str, fwp);
		ft_strdel(&temp);
		*fmt += 1;
	}
}

static void		ft_find_specification_2(char **fmt,\
		char **printf_str, va_list *ap, t_fwp *fwp)
{
	if (**fmt == 'x' || **fmt == 'X')
	{
		if (**fmt == 'X')
			fwp->upper_case = 1;
		ft_x_specificator(printf_str, ap, fwp);
		*fmt += 1;
	}
	else if (**fmt == 'o' || **fmt == 'O')
	{
		if (**fmt == 'O')
			fwp->flag_mod_l = 1;
		ft_o_specificator(printf_str, ap, fwp);
		*fmt += 1;
	}
	else if (**fmt == 'u' || **fmt == 'U')
	{
		if (**fmt == 'U')
			fwp->flag_mod_l = 1;
		ft_u_specificator(printf_str, ap, fwp);
		*fmt += 1;
	}
	else
		ft_find_specification_3(fmt, printf_str, ap, fwp);
}

static void		ft_find_specification(char **fmt,\
		char **printf_str, va_list *ap, t_fwp *fwp)
{
	if (**fmt == 'd' || **fmt == 'i' || **fmt == 'D')
	{
		if (**fmt == 'D')
			fwp->flag_mod_l = 1;
		ft_d_or_i_specificator(printf_str, ap, fwp);
		*fmt += 1;
	}
	else if (**fmt == 's' || **fmt == 'S')
	{
		if (**fmt == 'S' || fwp->flag_mod_l)
			ft_ls_specificator(printf_str, ap, fwp);
		else
			ft_s_specificator(printf_str, ap, fwp);
		*fmt += 1;
	}
	else if (**fmt == 'c' || **fmt == 'C')
	{
		if (**fmt == 'C' || fwp->flag_mod_l)
			ft_lc_specificator(printf_str, ap, fwp);
		else
			ft_c_specificator(printf_str, ap, fwp);
		*fmt += 1;
	}
	else
		ft_find_specification_2(fmt, printf_str, ap, fwp);
}

static void		ft_parse_fmt(char **fmt,\
		char **printf_str, va_list *ap, t_fwp *fwp)
{
	if (**fmt == '%')
	{
		*fmt += 1;
		ft_find_flags_width_precision(fmt, fwp);
		ft_find_specification(fmt, printf_str, ap, fwp);
	}
	else
	{
		ft_add_ch_to_the_ft_printf_str(**fmt, printf_str, fwp);
		*fmt += 1;
	}
}

int				ft_printf(char *fmt, ...)
{
	t_fwp		fwp;
	va_list		ap;
	char		*printf_str;
	char		*ret;
	int			len;

	fwp.counter = 0;
	printf_str = ft_strnew(100);
	va_start(ap, fmt);
	while (*fmt)
		ft_parse_fmt(&fmt, &printf_str, &ap, &fwp);
	va_end(ap);
	ret = ft_replace_empty_chars(printf_str);
	len = (int)write(1, ret, ft_strlen(printf_str));
	if (printf_str != NULL)
	{
		ft_strdel(&printf_str);
		ft_strdel(&ret);
	}
	return (len);
}
