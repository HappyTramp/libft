/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtoupper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacharle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 04:12:04 by cacharle          #+#    #+#             */
/*   Updated: 2020/02/10 05:05:38 by cacharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_str.h"
#include "libft_ctype.h"

char	*ft_strtolower(char *s)
{
	int	i;

	if (s == NULL)
		return (NULL);
	i = -1;
	while (s[i])
		s[i] = ft_tolower(s[i]);
	return (s);
}
