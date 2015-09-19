/*
** my_script.c for my_script in /home/perinp_r/rendu/PSU_2014_myscript
** 
** Made by ravivarman perinpanathan
** Login   <perinp_r@epitech.net>
** 
** Started on  Fri Jul 17 10:09:26 2015 ravivarman perinpanathan
** Last update Fri Jul 31 00:01:08 2015 ravivarman perinpanathan
*/

#include "my_script.h"

char	*get_ptsname(int filedes)
{
  int		i;
  static char	name[NAMESIZE];

  i = 0;
  if (ioctl(filedes, TIOCGPTN, &i) != 0)
    perror("Error on ioctl");
  snprintf(name, NAMESIZE, "/dev/pts/%u", i);
  return (name);
}

int	my_openpty(int *amaster, int *aslave, char *name, s_termios *termp,
		   s_wsize *winp)
{
  char		*pname;
  int		i;

  i = 0;
  if ((*amaster = open("/dev/ptmx", O_RDWR)) == -1)
    perror("Error on my_openpty : Amaster Failled");
  if ((pname = get_ptsname(*amaster)) == NULL)
    perror("Error on my_openpty : Pname Failled");
  if (ioctl(*amaster, TIOCSPTLCK, &i) == -1)
    {
      perror("Error on my_openpty : TIOCSPTLCK");
      return (-1);
    }
  if ((*aslave = open(pname, O_RDWR)) == -1)
    perror("Error on my_openpty : Aslave Failled");
  if (name != NULL)
    name = strcpy(name, pname);
  (void)termp;
  (void)winp;
  return (0);
}

int	my_logintty(int aslave)
{
  int	i;

  i = 0;
  if (setsid() == -1)
    perror("Error on logintty : setsid");
  else if (ioctl(aslave, TIOCSCTTY, &i) == -1)
    perror("Error on logintty : ioctl");
  else if (dup2(aslave, 0) == -1)
    perror("Error on logintty : dup2 0");
  else if (dup2(aslave, 1) == -1)
    perror("Error on logintty : dup2 1");
  else if (dup2(aslave, 2) == -1)
    perror("Error on logintty : dup2 2");
  else if (aslave > 2)
    close(aslave);
  return (0);
}

pid_t	my_forkpty(int *amaster, char *name, s_termios *termp,
		   s_wsize *winp)
{
  t_struct	*s;

  s = fill_mem_struct();
  if ((my_openpty(&s->master, &s->slave, name, termp, winp)) == -1)
    perror("Error on forkpty : openpty");
  else if ((s->forkpid = fork()) == -1)
      return (-1);
  else if (s->forkpid == 0)
    {
      close(s->master);
      if (my_logintty(s->slave) == -1)
	perror("Error on forkpty : logintty Failed");
      return (0);
    }
  else
    {
      *amaster = s->master;
      close(s->slave);
    }
  return (s->forkpid);
}
