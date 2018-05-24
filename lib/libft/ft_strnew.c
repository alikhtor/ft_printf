/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alikhtor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 14:17:58 by alikhtor          #+#    #+#             */
/*   Updated: 2017/11/10 13:01:35 by alikhtor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strnew(size_t size)
{
	char	*str;
	size_t	len;

	len = size + 1;
	str = (char*)malloc(sizeof(char) * len);
	if (str == 0)
		return (0);
	ft_memset(str, 0, len);
	return (str);
}
