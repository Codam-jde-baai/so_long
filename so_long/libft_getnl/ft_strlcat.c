/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcat.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jde-baai <jde-baai@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/12 13:52:15 by jde-baai      #+#    #+#                 */
/*   Updated: 2022/11/03 16:12:40 by jde-baai      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	srccount;
	size_t	dstcount;
	size_t	i;

	srccount = ft_strlen(src);
	dstcount = ft_strlen(dst);
	if (dstcount > dstsize)
		return (srccount + dstsize);
	i = 0;
	while ((dstcount + i + 1) < dstsize && src[i] != '\0')
	{
		dst[dstcount + i] = src[i];
		i++;
	}
	dst[dstcount + i] = '\0';
	return (srccount + dstcount);
}
