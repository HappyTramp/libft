/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacharle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 09:54:30 by cacharle          #+#    #+#             */
/*   Updated: 2019/10/20 13:03:23 by cacharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define MAX_CHAR ((1 << 7) - 1)

int	ft_isascii(int c)
{
	return (c >= 0 && c <= MAX_CHAR);
}