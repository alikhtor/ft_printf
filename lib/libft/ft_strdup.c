/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alikhtor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 16:29:57 by alikhtor          #+#    #+#             */
/*   Updated: 2017/11/15 16:55:49 by alikhtor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	size_t			i;
	size_t			len;
	unsigned char	*ss1;
	char			*ss2;

	ss1 = (unsigned char*)s1;
	len = ft_strlen(s1);
	ss2 = (char*)malloc(sizeof(unsigned char) * (len + 1));
	if (!ss2)
		return (NULL);
	i = 0;
	while (i < len)
	{
		ss2[i] = ss1[i];
		i++;
	}
	ss2[i] = '\0';
	return (ss2);
}
