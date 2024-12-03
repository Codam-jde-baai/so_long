/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strrchr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jde-baai <jde-baai@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/12 17:28:27 by jde-baai      #+#    #+#                 */
/*   Updated: 2023/05/10 13:42:50 by jde-baai      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned char	d;
	int				i;

	d = (unsigned char)c;
	i = 0;
	while (s[i] != '\0')
		i++;
	while (s[i] != d && i != 0)
		i--;
	if (s[i] == d)
		return ((char *)s + i);
	else
		return (NULL);
}
