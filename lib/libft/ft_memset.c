/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alikhtor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 17:25:39 by alikhtor          #+#    #+#             */
/*   Updated: 2017/11/15 16:35:55 by alikhtor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*temp;
	unsigned char	ch;

	ch = (unsigned char)c;
	temp = (unsigned char*)b;
	while (len > 0)
	{
		*temp = ch;
		temp++;
		len--;
	}
	return (b);
}
