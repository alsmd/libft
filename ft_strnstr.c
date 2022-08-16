/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flavio <flavio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 19:45:34 by flavio            #+#    #+#             */
/*   Updated: 2021/08/04 09:02:07 by flavio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	index;
	size_t	sub_i;

	index = 0;
	sub_i = 0;
	if (*little == '\0')
		return ((char *)big);
	if (len == 0)
		return (0);
	while (big[index])
	{
		len--;
		while (little[sub_i] && big[index + sub_i] == little[sub_i])
			sub_i++;
		if (sub_i == ft_strlen(little) && len + 1 >= ft_strlen(little))
			return ((char *)&big[index]);
		if (len == 0)
			return (0);
		sub_i = 0;
		index++;
	}
	return (0);
}
