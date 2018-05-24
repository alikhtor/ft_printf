/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alikhtor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 15:31:13 by alikhtor          #+#    #+#             */
/*   Updated: 2017/11/21 19:51:17 by alikhtor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	size_t				i;
	size_t				j;
	unsigned long long	res;
	size_t				neg;

	res = 0;
	neg = 0;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-')
		neg = 1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	j = 0;
	while (str[i + j] >= '0' && str[i + j] <= '9')
	{
		res = res * 10 + (str[i + j] - '0');
		j++;
	}
	if (j > 19 || res > 9223372036854775807)
		return ((neg == 1) ? 0 : -1);
	return ((neg == 1) ? (int)res * -1 : (int)res);
}
