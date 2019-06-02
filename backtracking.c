/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aymhabib <aymhabib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 01:29:12 by aymhabib          #+#    #+#             */
/*   Updated: 2019/05/25 22:49:15 by aymhabib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		min_possible(int nb)
{
	int i;

	i = 0;
	while (i < nb * 2)
	{
		if (i * i >= nb)
			return (i);
		i++;
	}
	return (0);
}

char	**creat_map(int nb)
{
	char	**map;
	int		i;
	int		j;

	map = (char **)malloc(sizeof(*map) * (nb + 1));
	if (!map)
		return (NULL);
	i = -1;
	while (++i < nb)
		map[i] = ft_strnew(nb);
	map[nb] = NULL;
	i = -1;
	while (++i < nb)
	{
		j = -1;
		while (++j < nb)
			map[i][j] = '.';
	}
	return (map);
}

int		can_put(char **tet, char **map, int x, int y)
{
	int i;
	int j;
	int count;

	count = 0;
	j = 0;
	while (j < 4 && map[j + y])
	{
		i = 0;
		while (i < 4 && map[i + x])
		{
			if (ft_isalpha(tet[j][i]) && map[j + y][i + x] == '.')
				count++;
			i++;
		}
		j++;
	}
	if (count == 4)
		return (1);
	return (0);
}

void	put_tetriminos(char **tet, char **map, int x, int y)
{
	int i;
	int j;

	j = 0;
	while (j < 4 && map[y + j])
	{
		i = 0;
		while (i < 4 && map[x + i])
		{
			if (ft_isalpha(tet[j][i]))
				map[y + j][x + i] = tet[j][i];
			i++;
		}
		j++;
	}
}

int		solve(char ***tetris, int nb)
{
	char	**map;
	int		i;

	nb = min_possible(nb * 4);
	if (!(map = creat_map(nb)))
		error();
	while (backtracking(tetris, map, 0, 0) == 0)
	{
		nb++;
		ft_free(map);
		map = creat_map(nb);
	}
	print_table(map);
	ft_free(map);
	i = 0;
	while (tetris[i])
	{
		ft_free(tetris[i]);
		i++;
	}
	free(tetris);
	return (0);
}
