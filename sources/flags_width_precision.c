/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_width_precision.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alikhtor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/26 16:39:44 by alikhtor          #+#    #+#             */
/*   Updated: 2018/05/26 16:39:47 by alikhtor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	ft_find_width(char **fmt, t_fwp *fwp)
{
	unsigned short	pointer_step;
	char			*step;

	fwp->width = ft_atoi(*fmt);
	step = ft_itoa(fwp->width);
	pointer_step = (unsigned short)ft_strlen(step);
	ft_strdel(&step);
	*fmt += pointer_step;
}

static void	ft_find_precision(char **fmt, t_fwp *fwp)
{
	unsigned short	pointer_step;
	char			*step;

	if (fwp->precision)
		fwp->precision = 0;
	fwp->flag_precision = 1;
	*fmt += 1;
	while (**fmt == '0')
		*fmt += 1;
	if (!(**fmt >= '1' && **fmt <= '9'))
		return ;
	fwp->precision = ft_atoi(*fmt);
	step = ft_itoa(fwp->precision);
	pointer_step = (unsigned short)ft_strlen(step);
	ft_strdel(&step);
	*fmt += pointer_step;
}

static void	ft_find_flag_modifier_p2(char **fmt, t_fwp *fwp)
{
	if (**fmt == 'j' && fwp->flag_mod_j != 1)
		fwp->flag_mod_j = 1;
	else if (**fmt == 'l' && (fwp->flag_mod_l != 1 ||
				fwp->flag_mod_ll != 1))
	{
		*fmt += 1;
		if (**fmt == 'l')
			fwp->flag_mod_ll = 1;
		else
		{
			fwp->flag_mod_l = 1;
			*fmt -= 1;
		}
	}
}

static void	ft_find_flag_modifier_p1(char **fmt, t_fwp *fwp)
{
	if (**fmt == 'h' && (fwp->flag_mod_h != 1 ||
				fwp->flag_mod_hh != 1))
	{
		*fmt += 1;
		if (**fmt == 'h')
			fwp->flag_mod_hh = 1;
		else
		{
			fwp->flag_mod_h = 1;
			*fmt -= 1;
		}
	}
	else if (**fmt == 'z' && fwp->flag_mod_z != 1)
		fwp->flag_mod_z = 1;
	else
		ft_find_flag_modifier_p2(fmt, fwp);
}

void		ft_find_flags_width_precision(char **fmt, t_fwp *fwp)
{
	ft_set_all_flags_to_null(fwp);
	while (**fmt == '+' || **fmt == '-' || **fmt == ' ' || **fmt == '.' ||
			**fmt == 'h' || **fmt == 'l' || **fmt == 'j' || **fmt == 'z' ||
			**fmt == '#' || (**fmt >= '0' && **fmt <= '9'))
	{
		if (**fmt == '+')
			fwp->flag_plus = 1;
		else if (**fmt == ' ')
			fwp->flag_space = 1;
		else if (**fmt == '-')
			fwp->flag_minus = 1;
		else if (**fmt == '0')
			fwp->flag_null = 1;
		else if (**fmt == '#')
			fwp->flag_hashtag = 1;
		else
			ft_find_flag_modifier_p1(fmt, fwp);
		if (**fmt >= '1' && **fmt <= '9')
			ft_find_width(fmt, fwp);
		else if (**fmt == '.')
			ft_find_precision(fmt, fwp);
		else
			*fmt += 1;
	}
}
