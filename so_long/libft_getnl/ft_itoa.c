/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jde-baai <jde-baai@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/20 17:11:43 by jde-baai      #+#    #+#                 */
/*   Updated: 2022/11/03 16:10:57 by jde-baai      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		nb_len(long int nb);
static void		ft_rec(long int nb, char *ptr);

char	*ft_itoa(int n)
{
	int				i;
	long int		nb;
	int				len;
	char			*ptr;

	nb = n;
	len = nb_len(nb);
	i = 0;
	if (n <= 0)
		i++;
	ptr = malloc(len + i + 1);
	if (ptr == NULL)
		return (NULL);
	ptr[len + i] = '\0';
	if (n < 0)
	{
		ptr[0] = '-';
		nb = nb * -1;
	}
	ft_rec(nb, &ptr[len + i - 1]);
	return (ptr);
}

static void	ft_rec(long int nb, char *ptr)
{
	if (nb >= 10)
		ft_rec((nb / 10), &ptr[-1]);
	*ptr = nb % 10 + '0';
}

static int	nb_len(long int nb)
{
	int	len;

	len = 0;
	while (nb != 0)
	{
		nb = nb / 10;
		len++;
	}
	return (len);
}
