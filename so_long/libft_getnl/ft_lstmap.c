/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstmap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jde-baai <jde-baai@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/01 15:51:11 by jde-baai      #+#    #+#                 */
/*   Updated: 2022/11/10 18:31:19 by jde-baai      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*node;
	t_list	*newlist;
	t_list	*ncontent;

	newlist = NULL;
	while (lst != NULL)
	{
		ncontent = (*f)(lst -> content);
		if (ncontent == NULL)
		{
			ft_lstclear(&newlist, del);
			return (NULL);
		}
		node = ft_lstnew(ncontent);
		if (node == NULL)
		{
			del(ncontent);
			ft_lstclear(&newlist, del);
			return (NULL);
		}
		ft_lstadd_back(&newlist, node);
		lst = lst -> next;
	}
	return (newlist);
}
