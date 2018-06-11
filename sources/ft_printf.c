/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alikhtor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/26 16:39:24 by alikhtor          #+#    #+#             */
/*   Updated: 2018/05/26 16:39:27 by alikhtor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void		ft_find_specification_3(char **fmt, va_list *ap, t_fwp *fwp)
{
	char		*temp;

	if (**fmt == 'p')
	{
		fwp->flag_hashtag = 1;
		fwp->flag_mod_j = 1;
		fwp->flag_mod_l = 0;
		fwp->flag_pointer = 1;
		ft_x_specificator(ap, fwp);
		*fmt += 1;
	}
	else if (**fmt == '%' || ft_isalpha(**fmt))
	{
		temp = ft_width_for_no_spec(**fmt, fwp);
		fwp->counter += write(1, temp, ft_strlen(temp));
		ft_strdel(&temp);
		*fmt += 1;
	}
}

static void		ft_find_specification_2(char **fmt, va_list *ap, t_fwp *fwp)
{
	if (**fmt == 'x' || **fmt == 'X')
	{
		if (**fmt == 'X')
			fwp->upper_case = 1;
		ft_x_specificator(ap, fwp);
		*fmt += 1;
	}
	else if (**fmt == 'o' || **fmt == 'O')
	{
		if (**fmt == 'O')
			fwp->flag_mod_l = 1;
		ft_o_specificator(ap, fwp);
		*fmt += 1;
	}
	else if (**fmt == 'u' || **fmt == 'U')
	{
		if (**fmt == 'U')
			fwp->flag_mod_l = 1;
		ft_u_specificator(ap, fwp);
		*fmt += 1;
	}
	else
		ft_find_specification_3(fmt, ap, fwp);
}

static void		ft_find_specification(char **fmt, va_list *ap, t_fwp *fwp)
{
	if (**fmt == 'd' || **fmt == 'i' || **fmt == 'D')
	{
		if (**fmt == 'D')
			fwp->flag_mod_l = 1;
		ft_d_or_i_specificator(ap, fwp);
		*fmt += 1;
	}
	else if (**fmt == 's' || **fmt == 'S')
	{
		if (**fmt == 'S' || fwp->flag_mod_l)
			ft_ls_specificator(ap, fwp);
		else
			ft_s_specificator(ap, fwp);
		*fmt += 1;
	}
	else if (**fmt == 'c' || **fmt == 'C')
	{
		if (**fmt == 'C' || fwp->flag_mod_l)
			ft_lc_specificator(ap, fwp);
		else
			ft_c_specificator(ap, fwp);
		*fmt += 1;
	}
	else
		ft_find_specification_2(fmt, ap, fwp);
}

static void		ft_parse_fmt(char **fmt, va_list *ap, t_fwp *fwp)
{
	if (**fmt == '%')
	{
		*fmt += 1;
		ft_find_flags_width_precision(fmt, fwp);
		ft_find_specification(fmt, ap, fwp);
	}
	else
	{
		fwp->counter += write(1, &(**fmt), 1);
		*fmt += 1;
	}
}

int				ft_printf(char *fmt, ...)
{
	t_fwp		fwp;
	va_list		ap;

	fwp.counter = 0;
	va_start(ap, fmt);
	while (*fmt)
		ft_parse_fmt(&fmt, &ap, &fwp);
	va_end(ap);
	return (fwp.counter);
}
