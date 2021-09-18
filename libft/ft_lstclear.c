/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalves-p <dalves-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 17:17:06 by dalves-p          #+#    #+#             */
/*   Updated: 2021/06/09 15:31:52 by dalves-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*curr;
	t_list	*next;

	if (!lst || !*lst || !del)
		return ;
	curr = *lst;
	while (curr != NULL)
	{
		next = curr->next;
		ft_lstdelone(curr, del);
		curr = next;
	}
	*lst = NULL;
}
