/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jde-baai <jde-baai@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/31 16:39:32 by jde-baai      #+#    #+#                 */
/*   Updated: 2022/11/21 12:46:52 by jde-baai      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_splitsize(char const *s, char c);
static size_t	ft_splitlen(char const *s, char c);
static void		ft_freeall(char **ptr, unsigned int n);
char			**ft_splitloop(char **ptr, char const *s, char c, size_t size);

char	**ft_split(char const *s, char c)
{
	char	**ptr;
	size_t	size;

	size = ft_splitsize(s, c);
	ptr = malloc((size + 1) * sizeof(char **));
	if (ptr == NULL)
		return (NULL);
	ptr[size] = NULL;
	ptr = ft_splitloop(ptr, s, c, size);
	return (ptr);
}

static size_t	ft_splitsize(char const *s, char c)
{
	int		i;
	size_t	word;

	i = 0;
	word = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && s[i] != '\0')
		{
			word++;
			while (s[i] != c && s[i] != '\0')
				i++;
			if (s[i] == '\0')
				i--;
		}
		i++;
	}
	return (word);
}

static size_t	ft_splitlen(char const *s, char c)
{
	unsigned int	i;

	i = 0;
	while (s[i] != '\0' && s[i] != c)
		i++;
	return (i);
}

char	**ft_splitloop(char **ptr, char const *s, char c, size_t size)
{
	unsigned int	main;
	size_t			n;
	size_t			len;

	main = 0;
	n = 0;
	while (n < size)
	{
		if (n > 0)
			main = main + ft_splitlen(&s[main], c);
		while (s[main] == c && s[main] != '\0')
			main++;
		len = ft_splitlen(&s[main], c);
		ptr[n] = malloc(len + 1);
		if (ptr[n] == NULL)
		{
			ft_freeall(ptr, n);
			return (NULL);
		}
		ptr[n][len] = '\0';
		ft_memcpy(ptr[n], &s[main], len);
		n++;
	}
	return (ptr);
}

static void	ft_freeall(char **ptr, unsigned int n)
{
	while (n > 0)
	{
		free(ptr[n]);
		n--;
	}
	free(ptr[n]);
	free(ptr);
}
