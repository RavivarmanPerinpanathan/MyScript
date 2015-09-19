/*
** fonctions.c for fonctions in /home/perinp_r/rendu/PSU_2014_myscript
** 
** Made by ravivarman perinpanathan
** Login   <perinp_r@epitech.net>
** 
** Started on  Mon Jul 20 23:48:12 2015 ravivarman perinpanathan
** Last update Fri Jul 31 07:25:37 2015 ravivarman perinpanathan
*/

#include "my_script.h"

int	no_arguments()
{
  t_struct	*fname;
  char		*name;
  
  name = "typescript";
  printf("%s %s\n",START, name);
  fname = fill_mem_struct();
  fname->fname = name;
  receive();
  printf("%s %s\n",END, name);
  return (0);
}

int	no_options(char *arg)
{
  t_struct	*fname;
  
  printf("%s %s\n",START, arg);
  fname = fill_mem_struct();
  fname->fname = arg;
  receive();
  printf("%s %s\n",END, arg);
  return (0);
}

int	arg_a(char *arg)
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
      printf("%s %s\n",START, name);
      fname->fname = name;
    }
  fname->opt_a = TRUE;
  receive();
  printf("%s %s\n",END, fname->fname);
  return (0);
}

void	arg_h()
{
  printf("%s%s%s%s%s\n",USAGE, OPA, OPQ, OPV, OPH);
}

void	arg_v()
{
  printf("%s\n", OPTV);
}
