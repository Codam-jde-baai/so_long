/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strncmp.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jde-baai <jde-baai@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/14 14:50:19 by jde-baai      #+#    #+#                 */
/*   Updated: 2022/11/21 16:48:35 by jde-baai      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int	output;
	int	i;

	i = 0;
	output = 0;
	while ((s1[i] != '\0' || s2[i] != '\0') && (n > 0 && output == 0))
	{
		if ((s1[i] == '\0' || s2[i] == '\0') && n > 0)
		{
			output = (unsigned char)s1[i] - (unsigned char)s2[i];
			return (output);
		}
		output = (unsigned char)s1[i] - (unsigned char)s2[i];
		n--;
		i++;
	}
	return (output);
}
