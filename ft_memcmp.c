/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flavio <flavio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 19:44:14 by flavio            #+#    #+#             */
/*   Updated: 2021/07/31 08:48:21 by flavio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				index;
	const unsigned char	*str1;
	const unsigned char	*str2;

	str1 = s1;
	str2 = s2;
	index = 0;
	if (n == 0)
		return (0);
	while (n--)
	{
		if (*str1 != *str2)
			break ;
		if (n)
		{
			str1++;
			str2++;
		}
		index++;
	}
	return (*str1 - *str2);
}
