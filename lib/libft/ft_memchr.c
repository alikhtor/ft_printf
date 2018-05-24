/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alikhtor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 18:08:09 by alikhtor          #+#    #+#             */
/*   Updated: 2017/11/16 11:56:19 by alikhtor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*s1;
	unsigned char	c1;

	s1 = (unsigned char*)s;
	c1 = (unsigned char)c;
	i = 0;
	while (n > 0)
	{
		if (s1[i] == c1)
			return (s1 + i);
		i++;
		n--;
	}
	return (0);
}
