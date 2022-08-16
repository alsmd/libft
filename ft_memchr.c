/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flavio <flavio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 19:44:11 by flavio            #+#    #+#             */
/*   Updated: 2021/07/31 07:42:52 by flavio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(void *s, int c, size_t n)
{
	unsigned char	*temp;
	unsigned char	find;
	size_t			index;

	index = 0;
	find = c;
	temp = s;
	while (index < n)
	{
		if (temp[index] == find)
			return (&temp[index]);
		index++;
	}
	return (0);
}
