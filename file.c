/*
** file.c for file in /home/perinp_r/rendu/PSU_2014_myscript
** 
** Made by ravivarman perinpanathan
** Login   <perinp_r@epitech.net>
** 
** Started on  Tue Jul 28 16:45:45 2015 ravivarman perinpanathan
** Last update Fri Jul 31 09:39:26 2015 ravivarman perinpanathan
*/

#include "my_script.h"

FILE	*create_file()
{
  t_struct	*s;
  static FILE	*file = NULL;
  
  if (file != NULL)
    return (file);
  else
    {
      s = fill_mem_struct();
      if (s->opt_a == TRUE)
	{
	  if ((file = fopen(s->fname, "a")) == NULL)
	    perror("File Open Error");
	}
      else
	if ((file = fopen(s->fname, "w")) == NULL)
	  perror("File Open Error");
      return (file);
    }
  return (NULL);
}

int	header()
{
  FILE		*file;
  char		*dt;
  
  file = create_file();
  dt = date_and_time();
  fwrite("\nScript started on ", 18, sizeof(char), file);
  fwrite(dt, strlen(dt), sizeof(char), file);
  fwrite("\n", 1, sizeof(char), file);
  return (0);
}

int	read_fd(char **buff, ssize_t *rd, fd_set *fdset, int master, t_struct *s)
{
  if (FD_ISSET(0, fdset))
    {
      if ((*rd = read(0, *buff, sizeof(**buff))) <= 0)
        return (-1);
      write(master, *buff, *rd);
    }
  if ((gettimeofday(&s->timeval, NULL)) == -1)
    perror("Error on read_fd : Gettimeofday Failled");
  if (FD_ISSET(master, fdset))
    {
      if ((*rd = read(master, *buff, sizeof(**buff))) <= 0)
        return (-1);
      write(1, *buff, *rd);
      return (1);
    }
  return (0);
}

void	write_in_fd(int master, t_struct *s)
{
  s->read = 0;
  if ((ioctl(0, TCGETS, &s->ln)) != 0)
    perror("Error on write_in_fd : ioctl 1");
  s->ln.c_lflag &= ~(ICANON | ISIG | ECHO);
  if ((ioctl(0, TCSETS, &s->ln)) != 0)
    perror("Error on write_in_fd : ioctl 2");
  else if ((s->buff = malloc(4096 * sizeof(char))) == NULL)
    perror("Error on write_in_fd : Malloc Failled");
  while (s->r != -1)
    {
      if ((ioctl(1, TIOCGWINSZ, &s->winp)) != 0)
	perror("Error on write_in_fd : ioctl 3");
      else if ((ioctl(master, TIOCSWINSZ, &s->winp)) != 0)
	perror("Error on write_in_fd : ioctl 4");
      FD_ZERO(&s->fdset);
      FD_SET(0, &s->fdset);
      FD_SET(master, &s->fdset);
      if (select(master + 1, &s->fdset, NULL, NULL, NULL) >= 0)
	if ((s->r = read_fd(&s->buff, &s->read, &s->fdset, master, s)) == 1)
	  fwrite(s->buff, s->read, sizeof(char), create_file());
    }
  free(s->buff);
}

int	footer()
{
  FILE		*file;
  char		*dt;

  file = create_file();
  dt = date_and_time();
  fwrite("\nScript done on ", 17, sizeof(char), file);
  fwrite(dt, strlen(dt), sizeof(char), file);
  fwrite("\n", 1, sizeof(char), file);
  return (0);
}
