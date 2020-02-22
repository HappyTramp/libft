/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_internal_htkey_equal.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacharle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 09:24:39 by cacharle          #+#    #+#             */
/*   Updated: 2020/02/19 02:03:14 by cacharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libft_ht.h"

int	ft_inter_htkey_cmp(const void *ref_key, const void *content)
{
	if (ref_key == NULL || content == NULL)
		return (-1);
	return (ft_strcmp((char*)ref_key, ((t_ftht_content*)content)->key));
}