/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alikhtor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 14:17:43 by alikhtor          #+#    #+#             */
/*   Updated: 2018/04/27 14:54:24 by alikhtor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*temp;
	unsigned char	*dst2;

	if (dst == src)
		return (dst);
	temp = (unsigned char*)src;
	dst2 = (unsigned char*)dst;
	i = 0;
	while (n > 0)
	{
		dst2[i] = temp[i];
		i++;
		n--;
	}
	return (dst);
}
