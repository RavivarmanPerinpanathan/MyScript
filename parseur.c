/*
** parseur.c for pars in /home/perinp_r/rendu/PSU_2014_myscript
** 
** Made by ravivarman perinpanathan
** Login   <perinp_r@epitech.net>
** 
** Started on  Thu Jul 16 11:38:19 2015 ravivarman perinpanathan
** Last update Fri Jul 31 07:50:34 2015 ravivarman perinpanathan
*/

#include <stdio.h>
#include <string.h>
#include "my_script.h"

int	all_args(int argc, char **argv)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  if (argc <= 1)
    no_arguments();
  else if (argc >= 2)
    parse_all(argv, i, j);
  return (0);
}

int	parse_all(char **argv, int i, int j)
{
  i = 0;
  while (argv[++i])
    {
      if (strncmp(argv[i], "-", 1) == 0)
	{
	  j = 1;
	  if (argv[i][j] == 'a')
	    arg_a(argv[i + 1]);
	  else if (argv[i][j] == 'q')
	    arg_q(argv[i + 1]);
	  else if (argv[i][j] == 'h')
	    arg_h();
	  else if (argv[i][j] == 'V')
	    arg_v();
	  else
	    printf("%s'%s'\n%s%s%s%s%s\n", INVALID, argv[i],
		   USAGE, OPA, OPQ, OPH, OPV);
	  return (0);
	}
      else
	{
	  no_options(argv[i]);
	  return (0);
	}
    }
  return (0);
}
