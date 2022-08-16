/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flavio <flavio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 19:44:18 by flavio            #+#    #+#             */
/*   Updated: 2021/08/03 06:58:39 by flavio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	if (dest == 0 && src == 0)
		return (0);
	while (n > 0)
	{
		((char *) dest)[n - 1] = ((unsigned char *) src)[n - 1];
		n--;
	}
	return (dest);
}
