/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jde-baai <jde-baai@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/16 13:46:12 by jde-baai      #+#    #+#                 */
/*   Updated: 2022/10/31 12:08:19 by jde-baai      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	output;
	int	negpos;
	int	i;

	i = 0;
	negpos = 0;
	output = 0;
	if ((str[i] < 48 && str[i] > 57) && (str[i] != 45 && str[i] != 43)
		&& (str[i] < 9 && str[i] > 13))
		return (output);
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == 45)
		negpos--;
	if (str[i] == 45 || str[i] == 43)
		i++;
	while ((str[i] >= 48 && str[i] <= 57) && str[i] != '\0')
	{
		output = output * 10 + (str[i] - '0');
		i++;
	}
	if (negpos < 0)
		output = output * -1;
	return (output);
}
