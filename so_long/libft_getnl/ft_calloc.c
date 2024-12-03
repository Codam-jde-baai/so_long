/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_calloc.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jde-baai <jde-baai@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/16 13:55:07 by jde-baai      #+#    #+#                 */
/*   Updated: 2022/10/31 12:08:28 by jde-baai      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void			*ptr;
	unsigned int	comb;

	if (count == 0 || size == 0)
		return (malloc(0));
	comb = count * size;
	ptr = malloc(comb);
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, comb);
	return (ptr);
}
