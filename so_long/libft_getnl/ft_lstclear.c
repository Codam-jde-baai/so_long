/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstclear.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jde-baai <jde-baai@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/01 15:30:39 by jde-baai      #+#    #+#                 */
/*   Updated: 2022/11/03 15:06:31 by jde-baai      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*next_node;

	if (lst == NULL)
		return ;
	while (*lst != NULL)
	{
		next_node = (*lst)-> next;
		del((*lst)-> content);
		free(*lst);
		*lst = NULL;
		*lst = next_node;
	}
}
