/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alikhtor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 11:06:34 by alikhtor          #+#    #+#             */
/*   Updated: 2017/11/23 11:08:24 by alikhtor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	char	*h;
	size_t	i;
	size_t	j;

	h = (char*)haystack;
	if (*needle == 0)
		return (h);
	i = 0;
	while (h[i] != '\0')
	{
		j = 0;
		while (needle[j] == h[i + j])
		{
			if (needle[j + 1] == '\0')
				return (h + i);
			j++;
		}
		i++;
	}
	return (NULL);
}
