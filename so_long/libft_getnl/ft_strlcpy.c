/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcpy.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jde-baai <jde-baai@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/12 12:53:06 by jde-baai      #+#    #+#                 */
/*   Updated: 2022/10/31 12:10:07 by jde-baai      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	int				i;
	unsigned int	output;

	output = 0;
	while (src[output] != '\0')
		output++;
	if (size == 0)
		return (output);
	i = 0;
	if (size > 0)
		size--;
	while (size > 0 && src[i] != '\0')
	{
		dst[i] = src[i];
		size--;
		i++;
	}
	dst[i] = '\0';
	return (output);
}
