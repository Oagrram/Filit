/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtrack_hepler.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aymhabib <aymhabib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 01:29:12 by aymhabib          #+#    #+#             */
/*   Updated: 2019/05/20 23:13:43 by aymhabib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_free(char **map)
{
	int i;

	i = 0;
	while (map[i])
		free(map[i++]);
	free(map);
}

void	tet_del(char **tet, char **map, int x, int y)
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
				map[y + j][x + i] = '.';
			i++;
		}
		j++;
	}
}

int		backtrack(char ***tet, char **map, int x, int y)
{
	if (!(*tet))
		return (1);
	while (map[y])
	{
		while (map[y][x])
		{
			if (is_valid_put(*tet, map, x, y))
			{
				put_tet(*tet, map, x, y);
				if (backtrack(tet + 1, map, 0, 0))
					return (1);
				else
					tet_del(*tet, map, x, y);
			}
			x++;
		}
		y++;
		x = 0;
	}
	return (0);
}
