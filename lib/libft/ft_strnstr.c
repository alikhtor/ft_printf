/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alikhtor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 21:33:43 by alikhtor          #+#    #+#             */
/*   Updated: 2017/11/23 11:58:06 by alikhtor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*h;
	size_t	i;
	size_t	j;

	h = (char*)haystack;
	if (*needle == 0)
		return (h);
	i = 0;
	while (h[i] && i < len)
	{
		j = 0;
		while ((h[i + j] == needle[j]) && i + j < len)
		{
			if (needle[j + 1] == '\0')
				return (h + i);
			j++;
		}
		i++;
	}
	return (NULL);
}
