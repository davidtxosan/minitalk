# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: usuario <usuario@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/08 14:03:42 by usuario           #+#    #+#              #
#    Updated: 2022/06/08 14:26:56 by usuario          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Variables

NAME			= minitalk
SOURCES_CLIENT 	= /sources/client.c
OBJECT_CLIENT 	= $(SOURCES_CLIENT:.c=.o)
SOURCES_SERVER 	= /sources/server.c
OBJECT_SERVER 	= $(SOURCES_SERVER:.c=.o)


CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
RM			= rm -f
ARFLAGS		= ar rcs

# sources

CLIENT		= client
SERVER 		= server



all:		$(CLIENT) $(SERVER)

$(NAME):		all

$(CLIENT):	$(OBJECT_CLIENT)
		
			$(CC) $(CFLAGS)$(OBJECT_CLIENT) -o $(CLIENT)

$(SERVER):	$(OBJECT_SERVER)
		
			$(CC) $(CFLAGS)$(OBJECT_SERVER) -o $(SERVER)
			
clean:
		$(RM) $(OBJECT_CLIENT) $(OBJECT_SERVER)
		

fclean:	clean

		$(RM) $(CLIENT) $(SERVER)
		
re:		fclean all


.PHONY:	all clean fclean re
