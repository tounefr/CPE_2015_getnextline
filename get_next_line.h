/*
** get_next_line.h for  in /home/thomas/Documents/get_next_line
** 
** Made by thomas
** Login   <thomas@epitech.net>
** 
** Started on  Wed Jan 13 10:28:02 2016 thomas
** Last update Sun Jan 17 11:26:35 2016 thomas
*/

#ifndef READ_SIZE
# define READ_SIZE 100
#endif

#ifndef __GET_NEXT_LINE_H__
# define __GET_NEXT_LINE_H__

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int	get_carriage_return(char *buffer);
int	my_strlen(char *str);
char	*my_strcat(char *str1, char *str2);
char	*my_strdup(char *str1);
char	*get_next_line(const int fd);

#endif
