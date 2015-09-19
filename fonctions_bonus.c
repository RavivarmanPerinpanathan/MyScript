/*
** fonctions_bonus.c for bonus in /home/perinp_r/rendu/PSU_2014_myscript
** 
** Made by ravivarman perinpanathan
** Login   <perinp_r@epitech.net>
** 
** Started on  Thu Jul 30 13:37:50 2015 ravivarman perinpanathan
** Last update Fri Jul 31 07:23:04 2015 ravivarman perinpanathan
*/

#include "my_script.h"

int	arg_q(char *arg)
{
  t_struct	*fname;
  char		*name;

  name = "typescript";
  fname = fill_mem_struct();
  if (arg != NULL)
    {
      printf("%s %s\n",START, arg);
      fname->fname = arg;
    }
  else
    {
      printf("%s %s\n", START, name);
      fname->fname = name;
    }
  fname->opt_q = TRUE;
  receive();
  printf("%s %s\n",END, name);
  return (0);
}
