/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alikhtor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 12:44:06 by alikhtor          #+#    #+#             */
/*   Updated: 2017/11/09 12:59:48 by alikhtor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	size_t	len;
	size_t	i;

	if (s1 && s2)
	{
		len = ft_strlen(s1) + ft_strlen(s2);
		new = (char*)malloc(sizeof(char) * (len + 1));
		if (new == 0)
			return (0);
		i = 0;
		while (s1[i] != 0)
		{
			new[i] = s1[i];
			i++;
		}
		new[i] = 0;
		new = ft_strcat(new, s2);
		return (new);
	}
	return (0);
}
