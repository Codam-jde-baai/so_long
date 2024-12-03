/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: jde-baai <jde-baai@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/13 12:46:46 by jde-baai      #+#    #+#                 */
/*   Updated: 2022/12/24 16:26:42 by juliusdebaa   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* string length */
int	getnl_strlen(const char *s)
{
	unsigned int	i;

	if (s == NULL)
		return (0);
	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

/* string duplicate */
char	*getnl_strdup(const char *s1)
{
	int		i;
	char	*ptr;

	i = 0;
	while (s1[i] != '\0')
		i++;
	ptr = malloc(i + 1);
	if (ptr == NULL)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		ptr[i] = s1[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

/*copies string for len length and frees ptr */
char	*getnl_copy(char *input, int len, char **ptr)
{
	char	*output;
	int		i;

	if (len == 0 && input == NULL)
		return (NULL);
	if (len == 0 && input != NULL)
	{
		free(*ptr);
		*ptr = NULL;
		return (NULL);
	}
	output = malloc((len + 1) * sizeof(char));
	if (output == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		output[i] = input[i];
		i++;
	}
	output[i] = '\0';
	free(*ptr);
	*ptr = NULL;
	return (output);
}

/* appends str2 to str1 and frees ptr */
char	*getnl_join(char *str1, char *str2, char **ptr)
{
	int		len1;
	int		len2;
	char	*output;
	int		i;

	len1 = getnl_strlen(str1);
	len2 = getnl_strlen(str2);
	if (len1 == 0 && len2 == 0)
		return (free_return(ptr));
	output = malloc((len1 + len2 + 1) * sizeof(char));
	if (!output)
		return (free_return(ptr));
	i = -1;
	while (i++ < len1 && len1 != 0)
		output[i] = str1[i];
	i = 0;
	while (i < len2 && len2 != 0)
	{
		output[len1 + i] = str2[i];
		i++;
	}
	output[len1 + i] = '\0';
	if (*ptr)
		free(*ptr);
	return (output);
}

/* frees ptr and returns NULL */
char	*free_return(char **ptr)
{
	if (*ptr)
	{
		free(*ptr);
		*ptr = NULL;
	}
	return (NULL);
}
