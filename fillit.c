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
    char *tmpter;
    int c;
    //char **teriminos;
    int j = 0;

	c = 0; 
    i = 0;
   tmpter = ft_strdup("");
	while (get_next_line(fd, &line) > 0 )
    {
		tmpter = ft_strjoin(tmpter, line);
        //printf("i == %d\n",i);
        //printf("(line[%d] == %s\n",i,tmpter);
      	printf("tmpter == %s\n",tmpter);
        printf("i == %d\n",i);
        if(++i == 5)
        {
        	printf("tmpter == %s\n",tmpter);
        	while(j++ < 16)
        	{
        	     printf("j == %d\n",j);
				if(tmpter[j] == '\0')
				{
					tmpter[j] = '\n';
					printf("tmpter[%d] == %s\n",j,tmpter);
				}
        	}
        	j = 0;
        	
        	c++;
            if(!check_if_valid(tmpter))
            {
                printf("invalid\n");
                return (0);
            }
          //  get_next_line(fd, &line);
            printf("(line) == %s\n",line);
            printf("strlen (line) == %d\n",(int)ft_strlen(line));
            if(ft_strlen(line))
            {
            	printf("empty line\n");
            	return 0;
            }
            tmpter = ft_strdup("");
            i = 0;
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