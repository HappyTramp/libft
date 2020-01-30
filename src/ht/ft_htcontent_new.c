/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_htcontent_new.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacharle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 08:45:36 by cacharle          #+#    #+#             */
/*   Updated: 2020/01/30 09:52:28 by cacharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libft_ht.h"

t_ftht_content	*ft_htcontent_new(char *key, void *value)
{
	t_ftht_content	*content;

	if (key == NULL)
		return (NULL);
	if ((content = (t_ftht_content*)malloc(sizeof(t_ftht_content))) == NULL)
		return (NULL);
	if ((content->key = ft_strdup(key)) == NULL)
	{
		free(content);
		return (NULL);
	}
	content->value = value;
	return (content);
}
