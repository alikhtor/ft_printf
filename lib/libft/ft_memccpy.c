/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alikhtor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 16:49:40 by alikhtor          #+#    #+#             */
/*   Updated: 2017/11/15 16:40:53 by alikhtor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*src1;
	unsigned char	*dst1;
	unsigned char	ch;

	dst1 = (unsigned char*)dst;
	src1 = (unsigned char*)src;
	ch = (unsigned char)c;
	i = 0;
	while (n > 0)
	{
		if (src1[i] == ch)
		{
			dst1[i] = src1[i];
			return (dst + i + 1);
		}
		else
			dst1[i] = src1[i];
		i++;
		n--;
	}
	return (0);
}
