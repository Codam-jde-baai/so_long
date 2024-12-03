/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnstr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jde-baai <jde-baai@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/14 20:59:47 by jde-baai      #+#    #+#                 */
/*   Updated: 2022/10/31 12:10:29 by jde-baai      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	unsigned int	i;
	unsigned int	n;
	char			*ptr;

	ptr = (char *)haystack;
	if (needle[0] == '\0')
		return (ptr);
	i = 0;
	while (haystack[i] != '\0' && i < len)
	{
		n = 0;
		if (haystack[i] == needle[n])
		{
			while ((haystack[i + n] == needle[n])
				&& (haystack[i + n] != '\0' && needle[n] != '\0'))
			{
				n++;
				if (needle[n] == '\0' && (i + n <= len))
					return (&ptr[i]);
			}	
		}
		i++;
	}
	return (NULL);
}
