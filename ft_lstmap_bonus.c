/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacharle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 09:03:57 by cacharle          #+#    #+#             */
/*   Updated: 2019/11/20 01:56:47 by cacharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*mapped;
	t_list	*tmp;

	if (lst == NULL || f == NULL)
		return (NULL);
	mapped = NULL;
	while (lst != NULL)
	{
		if ((tmp = ft_lstnew((*f)(lst->content))) == NULL)
		{
			ft_lstclear(&mapped, del);
			return (NULL);
		}
		ft_lstadd_back(&mapped, tmp);
		lst = lst->next;
	}
	return (mapped);
}

/*
** Rest in peace, my beautiful recursion.
**
** t_list  *tmp;
**
** if (lst == NULL)
**     return (NULL);
** if ((tmp = ft_lstnew(lst->content)) == NULL)
** 	return (NULL);
** tmp->content = (*f)(tmp->content);
** tmp->next = ft_lstmap(lst->next, f);
** return (tmp);
*/
