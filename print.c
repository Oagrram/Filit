/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aymhabib <aymhabib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 23:50:41 by aymhabib          #+#    #+#             */
/*   Updated: 2019/05/19 02:01:54 by aymhabib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_print_table(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
	{
		ft_putstr(tab[i++]);
		ft_putchar('\n');
	}
	return ;
}

void	ft_print_doubletable(char ***doubletable)
{
	int i;

	i = 0;
	while (doubletable[i])
	{
		ft_print_table(doubletable[i]);
		i++;
	}
}
