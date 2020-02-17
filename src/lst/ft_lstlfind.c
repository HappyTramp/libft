/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlfind.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacharle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 03:04:52 by cacharle          #+#    #+#             */
/*   Updated: 2020/02/17 03:34:19 by cacharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_lst.h"

t_ftlst	*ft_lstlfind(t_ftlst *lst, t_ftcompar_func cmp, const void *ref)
{
	if (lst == NULL)
		return (NULL);
	if (cmp(ref, lst->content) == 0)
		return (lst);
	return (ft_lstlfind(lst->next, cmp, ref));
}
