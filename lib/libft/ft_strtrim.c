/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alikhtor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 13:00:05 by alikhtor          #+#    #+#             */
/*   Updated: 2017/11/23 11:20:53 by alikhtor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*res;
	size_t	st;
	size_t	fn;

	if (!s)
		return (NULL);
	fn = ft_strlen(s);
	st = 0;
	while (s[st] == ' ' || s[st] == '\t' || s[st] == '\n')
		st++;
	if (st == fn)
		res = ft_strnew(0);
	while (s[fn - 1] == ' ' || s[fn - 1] == '\t' || s[fn - 1] == '\n')
		fn--;
	res = ft_strsub(s, st, fn - st);
	if (!res)
		return (ft_strdup(""));
	return (res);
}
