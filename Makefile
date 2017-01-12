##
## Makefile for  in /home/mathias/Bureau/picine/wolf3d
## 
## Made by Mathias
## Login   <mathias.descoin@epitech.eu@epitech.net>
## 
## Started on  Thu Jan 12 17:59:54 2017 Mathias
## Last update Thu Jan 12 18:05:03 2017 Mathias
##

SRC	=	test.c

OBJ	=	$(SRC:.c=.o)

NAME	=	wolf3d

all: $(NAME)

$(NAME): $(OBJ)
	gcc -o $(NAME) $(OBJ) -lcsfml-graphics -lcsfml-window

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: flcean all
