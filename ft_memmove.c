/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacharle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 10:03:21 by cacharle          #+#    #+#             */
/*   Updated: 2019/10/07 12:20:25 by cacharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

#define BUF_SIZE (2 << 12)

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	size_t			j;
	size_t			k;
	unsigned char	tmp[BUF_SIZE];

	if (dst == NULL && src == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		j = 0;
		while (j < BUF_SIZE && i < len)
		{
			tmp[j] = ((unsigned char*)src)[i];
			j++;
			i++;
		}
		k = -1;
		while (++k < j)
			((unsigned char*)dst)[k] = tmp[k];
		i++;
	}
	return (dst);
}
