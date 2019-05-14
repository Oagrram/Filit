/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oagrram <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/12 01:12:57 by oagrram           #+#    #+#             */
/*   Updated: 2019/05/12 01:12:58 by oagrram          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	fillit(int fd)
{
 	int i;
    char *line;
    char *Tetrimino;
    int c;

	c = 0; 
    i = 0;
    Tetrimino = ft_strdup("");
	while (get_next_line(fd, &line) > 0)
    {
        Tetrimino = ft_strjoin(Tetrimino, line);
         printf("(line[%d] == %s\n",i,line);
        if(++i == 4)
        {
        	c++;
            if(!check_if_valid(Tetrimino))
            {
                printf("invalid\n");
                return (0);
            }
            get_next_line(fd, &line);
             printf("(line) == %s\n",line);
            printf("strlen (line) == %d\n",(int)ft_strlen(line));
            if(ft_strlen(line))
            {
            	printf("empty line\n");
            	return 0;
            }
            Tetrimino = ft_strdup("");
            i = -1;
        }
    }
   // if(c > 26 || )
    printf("valid\n");
    return 0;
}

int	main (int argc, char **argv)
{   
    int fd;

	argc = 1;
    fd = open(*(argv + 1) , O_RDONLY);
    return	(fillit(fd));
}