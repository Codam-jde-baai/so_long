/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcpy.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jde-baai <jde-baai@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/10 12:21:31 by jde-baai      #+#    #+#                 */
/*   Updated: 2022/10/31 12:09:24 by jde-baai      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t i)
{
	unsigned char		*ptrdst;
	const unsigned char	*ptrsrc;

	ptrsrc = src;
	ptrdst = dst;
	if (src == NULL && dst == NULL)
		return (NULL);
	while (i > 0)
	{
		*ptrdst = *ptrsrc;
		ptrsrc++;
		ptrdst++;
		i--;
	}
	return (dst);
}
