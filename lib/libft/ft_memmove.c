/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alikhtor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 14:56:58 by alikhtor          #+#    #+#             */
/*   Updated: 2017/11/22 16:42:39 by alikhtor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*dst1;
	unsigned char	*src1;

	src1 = (unsigned char*)src;
	dst1 = (unsigned char*)dst;
	if (dst == src)
		return (dst);
	if (src1 < dst1)
	{
		while (len > 0)
		{
			dst1[len - 1] = src1[len - 1];
			len--;
		}
	}
	else if (src1 > dst1)
	{
		while (len-- > 0)
		{
			*dst1 = *src1;
			dst1++;
			src1++;
		}
	}
	return (dst);
}
