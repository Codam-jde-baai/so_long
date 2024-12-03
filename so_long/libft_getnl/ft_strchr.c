/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jde-baai <jde-baai@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/12 17:21:43 by jde-baai      #+#    #+#                 */
/*   Updated: 2023/05/10 13:09:18 by jde-baai      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char	d;
	int				i;

	d = (unsigned char)c;
	i = 0;
	while (s[i] != '\0' && s[i] != d)
		i++;
	if (s[i] == d)
		return ((char *)s + i);
	return (NULL);
}
