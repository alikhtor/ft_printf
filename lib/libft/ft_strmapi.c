/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alikhtor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 21:45:05 by alikhtor          #+#    #+#             */
/*   Updated: 2017/11/10 11:11:08 by alikhtor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*res;
	size_t	len;
	size_t	i;

	if (s && f)
	{
		len = ft_strlen(s);
		res = (char*)malloc(sizeof(char) * (len + 1));
		if (res == 0)
			return (0);
		i = 0;
		while (i < len)
		{
			res[i] = f(i, s[i]);
			i++;
		}
		res[i] = 0;
		return (res);
	}
	return (0);
}
