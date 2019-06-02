/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_and_cord.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aymhabib <aymhabib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 23:50:16 by aymhabib          #+#    #+#             */
/*   Updated: 2019/05/30 01:28:13 by aymhabib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**split(char *file, int nb)
{
	char	**tetriminos;
	int		index;
	int		i;

	tetriminos = (char **)malloc(sizeof(*tetriminos) * (nb + 1));
	if (!tetriminos)
		return (NULL);
	i = 0;
	index = 0;
	tetriminos[index] = ft_strsub(file, 0, 20);
	while (file[i] && tetriminos[index])
	{
		if (file[i] == '\n' && file[i + 1] == '\n')
		{
			index++;
			tetriminos[index] = ft_strsub(file, i + 2, 20);
			i = i + 15;
		}
		i++;
	}
	tetriminos[index + 1] = NULL;
	return (tetriminos);
}

void	cordination(int *x, int *y, int n)
{
	*y = n / 5;
	*x = n % 5;
}

int		is_cousin(char *tet)
{
	int count;
	int i;

	count = 0;
	i = 0;
	while (tet[i])
	{
		if (tet[i] == '#')
		{
			if (tet[i + 1] == '#')
				count++;
			if (tet[i + 5] == '#' && i < 15)
				count++;
		}
		i++;
	}
	return (count);
}
