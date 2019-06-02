/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validating.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aymhabib <aymhabib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 14:43:59 by aymhabib          #+#    #+#             */
/*   Updated: 2019/06/01 07:14:16 by oagrram          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		validchar(const char *file)
{
	int i;

	i = 0;
	while (file[i])
	{
		if (file[i] != '\n' && file[i] != '#' && file[i] != '.')
			return (0);
		i++;
	}
	if (i == (int)ft_strlen(file))
		return (1);
	return (0);
}

int		checkline(char **tetriminos)
{
	int i;
	int index;

	index = 0;
	while (tetriminos[index])
	{
		if (ft_strlen(tetriminos[index]) != 20)
		{
			return (0);
		}
		i = 0;
		while (tetriminos[index][i])
		{
			if ((tetriminos[index][i] == '\n') &&
				!(i == 4 || i == 9 || i == 14 || i == 19))
				return (0);
			i++;
		}
		index++;
	}
	return (1);
}

int		cousin(char **tetriminos)
{
	int index;
	int connections;

	index = 0;
	while (tetriminos[index])
	{
		if (ft_strlen(tetriminos[index]) != 20)
			return (0);
		connections = is_cousin(tetriminos[index]);
		if (!(connections == 3 || connections == 4))
			return (0);
		index++;
	}
	return (1);
}

int		length(const char *file, int nb)
{
	float	len;
	float	count;
	float	count2;
	int		count3;
	int		i;

	len = ft_strlen(file) - nb + 1;
	if (!(len / 20 == (float)nb))
		return (0);
	i = -1;
	count = 0;
	count2 = 1;
	count3 = 0;
	while (file[++i])
	{
		if (file[i] == '#')
			count++;
		if (file[i] == '\n')
			count2++;
		if (file[i] == '.')
			count3++;
	}
	if ((count3 / 12) != nb)
		return (0);
	return ((count / 4 != (float)nb) && (count2 / 5 != (float)nb) ? 0 : 1);
}

int		validating(char *file, char **tetriminos, int nb)
{
	if (nb <= 26)
	{
		if (validchar(file) != 1 || length(file, nb) != 1)
		{
			free(file);
			return (0);
		}
		if (!cousin(tetriminos) || !checkline(tetriminos))
		{
			free(file);
			return (0);
		}
		free(file);
		return (1);
	}
	return (0);
}
