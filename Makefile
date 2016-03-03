##
## Makefile for  in /home/frasse_l/Projets/202unsold
## 
## Made by loic frasse-mathon
## Login   <frasse_l@epitech.net>
## 
## Started on  Wed Mar  2 11:42:05 2016 loic frasse-mathon
## Last update Wed Mar  2 13:13:00 2016 loic frasse-mathon
##

CPP		= g++

CPPFLAGS	= -W -Wall -Werror -Wextra -pedantic -I./include -g

SRC		= src/main.cpp \
		src/unsold.cpp

OBJ		= $(SRC:.cpp=.o)

NAME		= 202unsold

RM		= rm -f

all:		$(NAME)

$(NAME):	$(OBJ)
		$(CPP) -o $(NAME) $(OBJ)

clean:
		$(RM) $(OBJ)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all
