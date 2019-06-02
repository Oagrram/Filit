/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aymhabib <aymhabib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 22:47:24 by aymhabib          #+#    #+#             */
/*   Updated: 2019/05/25 22:49:49 by aymhabib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# define BUFF_SIZE 1

# include "libft/libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

int		validating(char *file, char **tetriminos, int nb);
void	error(void);
int		number_of_tetriminos(char *file);
int		is_cousin(char *tet);
char	**split(char *file, int nb);
void	print_table_x2(char ***doubletable);
void	print_table(char **tab);
void	cordination(int *x, int *y, int n);
char	**fill(char *tetriminos, char c);
void	ft_free(char **map);
int		solve(char ***tetris, int nb);
int		backtracking(char ***tet, char **map, int x, int y);
int		can_put(char **tet, char **map, int x, int y);
void	put_tetriminos(char **tet, char **map, int x, int y);

#endif
