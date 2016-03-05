/*
** get_next_line.c for  in /home/thomas/Documents/get_next_line
** 
** Made by thomas
** Login   <thomas@epitech.net>
** 
** Started on  Wed Jan 13 10:27:48 2016 thomas
** Last update Sun Jan 17 11:31:50 2016 thomas
*/

#include "get_next_line.h"

int	get_carriage_return(char *buffer)
{
  int	i;

  if (!buffer)
    return (-1);
  i = 0;
  while (buffer[i])
    {
      if (buffer[i] == '\n')
	return (i);
      i++;
    }
  return (-1);
}

int	my_strlen(char *str)
{
  int	i;

  if (!str || *str == '\0')
    return (0);
  i = 0;
  while (str[i])
    i++;
  return (i);
}

char	*my_strcat(char *str1, char *str2)
{
  char	*str3;
  int	i;
  int	i2;

  if (NULL == (str3 = malloc(my_strlen(str1) + my_strlen(str2) + 1)))
    return (NULL);
  i = 0;
  if (str1)
    {
      while (str1[i])
	str3[i] = str1[i++];
    }
  i2 = 0;
  if (str2)
    {
      while (str2[i2])
	str3[i++] = str2[i2++];
    }
  str3[i] = '\0';
  return (str3);
}

char	*my_strdup(char *str1)
{
  char	*str2;
  int	i;

  if (!str1 || *str1 == '\0')
    return (NULL);
  if (NULL == (str2 = malloc(my_strlen(str1) + 1)))
    return (NULL);
  i = 0;
  while (str1[i])
    str2[i] = str1[i++];
  str2[i] = '\0';
  return (str2);
}

char		*get_next_line(const int fd)
{
  char		*buffer;
  static char	*save;
  static int	readv;
  static int	i;

  if (readv == 0 && i == -1)
    return (NULL);
  if (NULL == (buffer = malloc(READ_SIZE + 1)))
    return (NULL);
  i = 0;
  while (i < READ_SIZE+1)
    buffer[i++] = 0;
  if (-1 == (readv = read(fd, buffer, READ_SIZE)))
    return (NULL);
  save = my_strcat(save, buffer);
  if ((i = get_carriage_return(save)) != -1)
    {
      save[i] = '\0';
      buffer = save;
      save = my_strdup(&save[i + 1]);
      return (buffer);
    }
  if (readv == 0 && save && *save)
    return (save);
  return (get_next_line(fd));
}
