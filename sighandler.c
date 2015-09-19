/*
** sighandler.c for sighandler in /home/perinp_r/rendu/PSU_2014_myscript
** 
** Made by ravivarman perinpanathan
** Login   <perinp_r@epitech.net>
** 
** Started on  Thu Jul 30 13:54:02 2015 ravivarman perinpanathan
** Last update Fri Jul 31 09:25:16 2015 ravivarman perinpanathan
*/

#include "my_script.h"

void	childsignal()
{
  t_struct	*s;
  int		pid;
  int		stat;

  s = fill_mem_struct();
  while ((pid = wait3(&stat, WNOHANG, 0)) > 0)
    {
      if (pid == s->childpid)
	s->childstat = stat;
    }
}

void	sighandler()
{
  s_sig	setup_action;
  
  sigemptyset(&setup_action.sa_mask);
  setup_action.sa_flags = 0;
  setup_action.sa_handler = childsignal;
  sigaction(SIGCHLD, &setup_action, NULL);
}
