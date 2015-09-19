##
## Makefile for make in /home/perinp_r/rendu/PSU_2014_myscript
## 
## Made by ravivarman perinpanathan
## Login   <perinp_r@epitech.net>
## 
## Started on  Thu Jul 16 11:20:46 2015 ravivarman perinpanathan
## Last update Thu Jul 30 14:03:32 2015 ravivarman perinpanathan
##

CC	=	gcc

NAME	=	my_script

SRCS	=	main.c \
		parseur.c \
		fonctions.c \
		fonctions_bonus.c \
		sighandler.c \
		my_script.c \
		file.c \
		tools.c

OBJS	=	$(SRCS:.c=.o)

RM	=	rm -f

CFLAGS	+=	-Wall -Wextra -Werror

all	:	$(NAME)

$(NAME)	:	$(OBJS)
		$(CC) $(OBJS) -o $(NAME) $(CFLAGS)

clean	:
		$(RM) $(OBJS)

fclean	:	clean
		$(RM) $(NAME)

re	:	fclean all

.PHONY	:	all clean fclean re
