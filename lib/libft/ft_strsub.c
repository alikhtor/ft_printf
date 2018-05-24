/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alikhtor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 11:40:20 by alikhtor          #+#    #+#             */
/*   Updated: 2017/11/10 13:01:37 by alikhtor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;

	if (s)
	{
		if (start > ft_strlen(s))
			return (0);
		sub = ft_strnew(len);
		if (sub == 0)
			return (0);
		i = 0;
		while (i < len)
		{
			sub[i] = s[start + i];
			i++;
		}
		sub[i] = 0;
		return (sub);
	}
	return (0);
}
