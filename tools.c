/*
** tools.c for tools in /home/perinp_r/rendu/PSU_2014_myscript
** 
** Made by ravivarman perinpanathan
** Login   <perinp_r@epitech.net>
** 
** Started on  Tue Jul 28 16:50:08 2015 ravivarman perinpanathan
** Last update Fri Jul 31 00:06:47 2015 ravivarman perinpanathan
*/

#include "my_script.h"

t_struct	*fill_mem_struct()
{
  static	int	i = 0;
  static	t_struct s;

  if (i == 0)
    {    
      memset(&s, 0, sizeof(s));
      s.otime = time(NULL);
      i = 1;
    }
  return (&s);
}

char	*date_and_time()
{
  time_t	c;
  static char	dt[100];
  const s_tm	*tm;

  if (time(&c) != (time_t) -1)
    {
      tm = localtime(&c);
      strftime(dt, 100, "%c", tm);
      return (dt);
    }
  return (0);
}
