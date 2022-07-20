# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: usuario <usuario@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/08 14:03:42 by usuario           #+#    #+#              #
#    Updated: 2022/07/12 15:24:10 by usuario          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Variables

NAME			= minitalk
SOURCES_CLIENT 	= client.c minitalk_utils.c
OBJECT_CLIENT 	= $(SOURCES_CLIENT:.c=.o)
SOURCES_SERVER 	= server.c minitalk_utils.c
OBJECT_SERVER 	= $(SOURCES_SERVER:.c=.o)

SOURCES_CLIENT_BONUS 	= client_bonus.c minitalk_utils_bonus.c
OBJECT_CLIENT_BONUS 	= $(SOURCES_CLIENT_BONUS:.c=.o)
SOURCES_SERVER_BONUS 	= server_bonus.c minitalk_utils_bonus.c
OBJECT_SERVER_BONUS 	= $(SOURCES_SERVER_BONUS:.c=.o)


CC			= gcc
CFLAGS		= -Wall -Wextra -Werror 
RM			= rm -f
ARFLAGS		= ar rcs

# sources

CLIENT		= client
SERVER 		= server

CLIENT_BONUS = client_bonus
SERVER_BONUS = 	server_bonus



all:		$(CLIENT) $(SERVER)

$(NAME):		all

$(CLIENT):	$(OBJECT_CLIENT)
		
			$(CC) $(CFLAGS)$(OBJECT_CLIENT) -o $(CLIENT)

$(SERVER):	$(OBJECT_SERVER)
		
			$(CC) $(CFLAGS)$(OBJECT_SERVER) -o $(SERVER)

$(CLIENT_BONUS):	$(OBJECT_CLIENT_BONUS)
		
			$(CC) $(CFLAGS)$(OBJECT_CLIENT_BONUS) -o $(CLIENT_BONUS)

$(SERVER_BONUS):	$(OBJECT_SERVER_BONUS)
		
			$(CC) $(CFLAGS)$(OBJECT_SERVER_BONUS) -o $(SERVER_BONUS)


clean:
		@$(RM) $(OBJECT_CLIENT) $(OBJECT_SERVER) $(OBJECT_CLIENT_BONUS) $(OBJECT_SERVER_BONUS)
		

fclean:	clean

		@$(RM) $(CLIENT) $(SERVER) $(CLIENT_BONUS) $(SERVER_BONUS)
		
re:		fclean all

bonus:	$(SERVER_BONUS) $(CLIENT_BONUS)


.PHONY:	all clean fclean re
