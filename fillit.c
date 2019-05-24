/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aymhabib <aymhabib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 14:40:40 by aymhabib          #+#    #+#             */
/*   updated: 2019/05/22 23:55:36 by oagrram          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		tet_nb(char *file)
{
	int i;
	int nb;

	i = 0;
	nb = 1;
	while (file[i])
	{
		if (file[i + 1] == '\n' && file[i] == '\n')
			nb++;
		i++;
	}
	return (nb);
}

char	*read_file(int fd)
{
	char			buff[BUFF_SIZE + 1];
	char			*file;
	char			*tmp;
	int				i;

	i = 0;
	file = ft_strnew(0);
	while ((i = read(fd, buff, BUFF_SIZE)))
	{
		buff[i] = '\0';
		tmp = ft_strjoin(file, buff);
		free(file);
		file = ft_strdup(tmp);
		free(tmp);
	}
	return (file);
}

char	***if_valid(int nb, char **tetriminos)
{
	int		i;
	char	***tetris;

	tetris = (char ***)malloc(sizeof(**tetris) * (nb + 1));
	//printf("sizeof(tetris) == %lu\n",(sizeof(**tetris) * (nb + 1)));
	if (!tetris)
		return (NULL);
	i = 0;
	while (i < nb)
	{
	//	printf("tetriminos[%d] ==  \n%s",i,tetriminos[i]);
		tetris[i] = ft_spliiiit(tetriminos[i], 'A' + i);
		i++;
	}
	tetris[nb] = NULL;
	ft_free(tetriminos);
	return (tetris);
}

void	error(void)
{
	ft_putstr("error\n");
	exit(42);
}

int		main(int argc, char **argv)
{
	int				fd;
	char			**tetriminos;
	char			*file;
	int				nb;
	char			***tetris;

	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd < 0 || (read(fd, NULL, 0) < 0))
			error();
		file = read_file(fd);
		nb = tet_nb(file);
		tetriminos = split(file, nb);
		if (validating(file, tetriminos, nb))
		{
			tetris = if_valid(nb, tetriminos);
			ft_solve(tetris, nb);
		}
		else
			error();
	}
	else
		ft_putstr("usage: ./fillit source_file\n");
	return (0);
}
