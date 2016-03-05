/*
** main.c for  in /home/thomas/Documents/epitech/CPE_2015_getnextline
** 
** Made by thomas
** Login   <thomas@epitech.net>
** 
** Started on  Sat Jan 16 23:32:40 2016 thomas
** Last update Sat Jan 16 23:33:26 2016 thomas
*/

#include "get_next_line.h"

int main()
{
  char *s;
  int fd = open("test", O_RDONLY);

  while ((s = get_next_line(fd)) != NULL)
    {
      printf("%s\n", s);
      free(s);
    }

  close(fd);
}
