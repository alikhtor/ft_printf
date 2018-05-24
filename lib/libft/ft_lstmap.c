/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alikhtor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 17:30:32 by alikhtor          #+#    #+#             */
/*   Updated: 2017/11/23 10:49:41 by alikhtor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *new;
	t_list *tmp;
	t_list *ret;

	if (!lst || !f)
		return (NULL);
	new = f(lst);
	ret = new;
	lst = lst->next;
	while (lst != NULL)
	{
		tmp = f(lst);
		new->next = tmp;
		new = new->next;
		lst = lst->next;
	}
	return (ret);
}
