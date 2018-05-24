/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   secondary_functions_part2.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alikhtor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 16:25:29 by alikhtor          #+#    #+#             */
/*   Updated: 2018/05/23 18:50:14 by alikhtor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char			*ft_width_for_no_spec(char temp, t_fwp *fwp)
{
	char		*ret;
	char		*tmp;

	tmp = ft_strnew(1);
	ft_memcpy(tmp, &temp, 1);
	if (fwp->width > 1)
	{
		ret = ft_strnew(fwp->width);
		ft_memset(ret, ' ', fwp->width);
		if (fwp->flag_minus)
			ft_memcpy(ret, tmp, 1);
		else if (fwp->flag_null)
		{
			ft_memset(ret, '0', fwp->width);
			ft_copy_to_the_right_side_of_the_str(&ret, tmp, fwp->width);
		}
		else
			ft_copy_to_the_right_side_of_the_str(&ret, tmp, fwp->width);
	}
	else
		ret = ft_strdup(tmp);
	ft_strdel(&tmp);
	return (ret);
}

static int		itoa_isnegative(int *len, intmax_t *n)
{
	intmax_t	nb;

	nb = *n;
	if (*n <= 0)
	{
		nb *= -1;
		*len += 1;
	}
	while (nb > 0)
	{
		nb /= 10;
		*len += 1;
	}
	if (*n < 0)
	{
		*n *= -1;
		return (1);
	}
	return (0);
}

char			*ft_itoa_singed(intmax_t n)
{
	char		*ret;
	int			negative;
	int			len;

	if (n < -9223372036854775807)
		return (ft_strdup("-9223372036854775808"));
	len = 0;
	negative = itoa_isnegative(&len, &n);
	if (!(ret = ft_strnew(len)))
		return (NULL);
	while (len--)
	{
		ret[len] = n % 10 + '0';
		n /= 10;
	}
	if (negative)
		ret[0] = '-';
	return (ret);
}

static int		itoa_u_len(size_t n, int base)
{
	int			len;

	len = 0;
	if (n <= 0)
		len = 1;
	while (n != 0)
	{
		n /= base;
		len++;
	}
	return (len);
}

char			*ft_itoa_base_unsigned(size_t n, int base, int up)
{
	char		*ret;
	int			len;
	char		*tab_l;
	char		*tab_u;

	tab_u = "0123456789ABCDEF";
	tab_l = "0123456789abcdef";
	len = itoa_u_len(n, base);
	if (!(ret = ft_strnew(len)))
		return (NULL);
	while (len--)
	{
		ret[len] = (up) ? tab_u[n % base] : tab_l[n % base];
		n /= base;
	}
	return (ret);
}
