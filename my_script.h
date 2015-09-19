/*
** my_script.h for my_script in /home/perinp_r/rendu/PSU_2014_myscript
** 
** Made by ravivarman perinpanathan
** Login   <perinp_r@epitech.net>
** 
** Started on  Thu Jul 16 11:52:36 2015 ravivarman perinpanathan
** Last update Fri Jul 31 07:20:17 2015 ravivarman perinpanathan
*/

#ifndef MY_SCRIPT_H
# define MY_SCRIPT_H

# define START "Script started, file is"
# define END "Script done, file is"
# define INVALID "script: invalid option -- "
# define USAGE "\nUsage:\n script [options] [file]\n\nOptions:\n"
# define OPA "-a, --append\tappend the output\n"
# define OPQ "-q, --quiet\tbe quiet\n"
# define OPV "-V, --version\toutput version information and exit\n"
# define OPH "-h, --help\tdisplay this help and exit\n"
# define OPTV "script from Perinpanathan Ravivarman 0.1"
# define TRUE 1
# define NAMESIZE 100
	
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>
#include <termios.h>
#include <sys/ioctl.h>
#include <fcntl.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/time.h>

typedef struct termios		s_termios;
typedef struct winsize		s_wsize;
typedef	struct sigaction	s_sig;
typedef	struct timeval		s_timeval;
typedef struct tm		s_tm;

typedef struct s_struct
{
  int		opt_a;
  int		opt_q;
  double	otime;
  pid_t		childpid;
  pid_t		forkpid;
  int		childstat;
  int		r;
  char		*buff;
  char		*shell;
  char		*fname;
  int		master;
  int		slave;
  char		*command;
  s_termios	ln;
  ssize_t	read;
  fd_set	fdset;
  s_wsize	winp;
  s_timeval     timeval;
}		t_struct; 

int		header();
int		footer();
FILE		*create_file();
t_struct	*fill_mem_struct();
int		receive();
char		*date_and_time();
int		my_script(char *);
int		all_args(int, char **);
int		no_arguments();
int		no_options(char *);
int		parse_all(char **, int, int);
int		arg_a(char *);
int		arg_q(char *);
void		arg_h();
void		arg_v();
void		sighandler();
void		childsignal();
int		my_ulockpt(int);
char		*get_ptsname(int);
int		my_openpty(int *, int *, char *, s_termios *, s_wsize *);
pid_t		my_forkpty(int *, char *, s_termios *, s_wsize *);
int		call_to_fonctions(int, t_struct *);
int		read_fd(char **, ssize_t *, fd_set *, int, t_struct *);
void		write_in_fd(int, t_struct *);

#endif /* !MY_SCRIPT_H */
