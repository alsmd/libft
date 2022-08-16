/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flavio <flavio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 08:06:39 by flavio            #+#    #+#             */
/*   Updated: 2021/08/01 11:33:11 by flavio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*begin;
	t_list	*tmp;

	begin = *lst;
	while (begin)
	{
		tmp = begin;
		begin = begin->next;
		del(tmp->content);
		free(tmp);
	}
	*lst = 0;
}
