/*
** main.c for main in /home/perinp_r/rendu/PSU_2014_myscript
** 
** Made by ravivarman perinpanathan
** Login   <perinp_r@epitech.net>
** 
** Started on  Thu Jul 16 11:20:29 2015 ravivarman perinpanathan
** Last update Thu Jul 30 23:59:55 2015 ravivarman perinpanathan
*/

#include "my_script.h"

int	call_to_fonctions(int amaster, t_struct *s)
{
  if (s->opt_q == TRUE)
    {
      sighandler();   
      write_in_fd(amaster, s);
    }
  else
    {
      header();
      sighandler();    
      write_in_fd(amaster, s); 
      footer();
    }
  return (0);
}

int	receive()
{
  t_struct	*s;
  int		amaster;

  s = fill_mem_struct();
  if ((s->childpid = my_forkpty(&amaster, NULL, NULL, NULL)) < -1)
    perror("Error On aff_shell : childpid");
  s->shell = getenv("SHELL");
  if (s->shell)
    s->shell = s->shell;
  else
    s->shell = "/bin/sh";
  if (s->childpid > 0)
    return (call_to_fonctions(amaster, s));
  else
    {
      if (s->command)
	execl(s->shell, s->shell, "-c", s->command, NULL);
      else
	execlp(s->shell, s->shell, NULL);
      printf("Shell Not Found\n");
      exit(EXIT_FAILURE);
    }
  return (0);
}

int	main(int argc, char** argv)
{
  all_args(argc, argv);
  return (0);
}
