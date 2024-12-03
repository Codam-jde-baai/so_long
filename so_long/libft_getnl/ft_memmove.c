/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memmove.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jde-baai <jde-baai@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/10 12:43:32 by jde-baai      #+#    #+#                 */
/*   Updated: 2022/10/31 12:09:31 by jde-baai      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*ptrsrc;
	unsigned char	*ptrdst;
	unsigned int	i;

	ptrsrc = (unsigned char *)src;
	ptrdst = (unsigned char *)dst;
	if (!dst && !src)
		return (NULL);
	if (dst > src)
	{
		while (len-- > 0)
			ptrdst[len] = ptrsrc[len];
	}
	else
	{
		i = 0;
		while (i < len)
		{
			ptrdst[i] = ptrsrc[i];
			i++;
		}
	}
	return (ptrdst);
}
