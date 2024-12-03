/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memset.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jde-baai <jde-baai@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/06 13:51:49 by jde-baai      #+#    #+#                 */
/*   Updated: 2022/10/31 12:09:44 by jde-baai      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t i)
{
	unsigned char	*ptr;
	unsigned int	n;

	n = 0;
	ptr = (unsigned char *)str;
	if (i > 0)
	{
		while (n < i)
		{
			ptr[n] = c;
			n++;
		}
	}
	return (ptr);
}
