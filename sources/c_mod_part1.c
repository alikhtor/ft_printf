/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_mod_part1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alikhtor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/26 16:21:19 by alikhtor          #+#    #+#             */
/*   Updated: 2018/05/26 16:26:52 by alikhtor         ###   ########.fr       */
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

static void		ft_print_char(char *str, t_fwp *fwp)
{
	int			i;

	i = 0;
	while (str[i] != '\0')
	{
		fwp->counter += (str[i] == -42) ? write(1, "\0", 1)\
				: write(1, &str[i], 1);
		i++;
	}
}

void			ft_lc_specificator(va_list *ap, t_fwp *fwp)
{
	wint_t		utf;
	char		ch;
	char		*temp;
	char		*ret;
	int			l;

	if ((utf = va_arg(*ap, int)) == 0)
	{
		ch = -42;
		temp = ft_strnew(1);
		temp = ft_memcpy(temp, &ch, 1);
		ret = (fwp->width > 1) ? ft_width(temp, 1, fwp) : ft_strdup(temp);
		ft_print_char(ret, fwp);
	}
	else
	{
		temp = ft_make_utf(utf);
		l = ft_strlen(temp);
		ret = (fwp->width > l) ? ft_width(temp, l, fwp) : ft_strdup(temp);
		fwp->counter += write(1, ret, ft_strlen(ret));
	}
	ft_strdel(&temp);
	ft_strdel(&ret);
}

void			ft_c_specificator(va_list *ap, t_fwp *fwp)
{
	char		ch;
	char		*temp;
	char		*ret;

	ch = (char)va_arg(*ap, int);
	if (ch == 0)
		ch = -42;
	temp = ft_strnew(1);
	temp = ft_memcpy(temp, &ch, 1);
	ret = (fwp->width > 1) ? ft_width(temp, 1, fwp) : ft_strdup(temp);
	ft_print_char(ret, fwp);
	ft_strdel(&temp);
	ft_strdel(&ret);
}
