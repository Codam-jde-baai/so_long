/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strdup.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jde-baai <jde-baai@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/16 14:32:08 by jde-baai      #+#    #+#                 */
/*   Updated: 2022/10/31 12:09:55 by jde-baai      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	unsigned int	i;
	char			*ptr;

	i = 0;
	while (s1[i] != '\0')
		i++;
	i++;
	ptr = malloc(i);
	if (ptr == NULL)
		return (NULL);
	while (i > 0)
	{
		i--;
		ptr[i] = s1[i];
	}
	return (ptr);
}
