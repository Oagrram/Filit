/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_if_valid.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oagrram <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/12 02:40:17 by oagrram           #+#    #+#             */
/*   Updated: 2019/05/12 02:40:18 by oagrram          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int check_if_valid(char *Tetrimino)
{
    int i;

    i = -1;
    printf("len of ter = %d\n",(int)ft_strlen(Tetrimino));
    if(ft_strlen(Tetrimino) != 17)
        return (0);
    while(++i < 16)
    {
        if(Tetrimino[i] != '.' && Tetrimino[i] != '#')
        {
//        	printf("i = %d\n",i);
            return (0);
        }
    }
    return (1);
}


