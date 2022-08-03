# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mayoub <mayoub@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/29 13:58:33 by mayoub            #+#    #+#              #
#    Updated: 2022/08/02 12:18:20 by mayoub           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	philo

FILE		=	main				\
				routine/routine		\
				routine/spaghettis	\
				routine/rompiche	\
				routine/dead		\
				utils/ft_atoi		\
				utils/ft_usleep		\
				parsing/parsing		\
				parsing/error		\




SRC_DIR		=	./

SRC			=	$(addprefix $(SRC_DIR), $(addsuffix .c, $(FILE)))

OBJ_DIR		=	./

OBJ			=	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(FILE)))

#LIBFT_DIR	=	./libft/

#LIBFT		=	$(addprefix $(LIBFT_DIR), libft.a)

CC			=	gcc

CFLAGS		=	-Werror -Wall -Wextra -g -pthread #-fsanitize=thread

#LIBRARIES	=	-lft -L$(LIBFT_DIR)

#HEADERS		=	-I$(LIBFT_DIR)

RM			=	rm -rf

.c.o		:
				${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}		:	${OBJ}
				@${CC} ${CFLAGS} ${OBJ} -o $@
				@echo "\033[0;37m\n##############################################\n"
				@echo "\033[1;32m 🥗 The philosophers files are ready 🥙 !!!\n\033[0;37m\n##############################################"
				@echo "\033[1;31m\nDONE !!! \033[1;32mHere your order 🍔 🍟 🍺 , Bon Appétit !!!\n"

#$(LIBFT)	:
#				@echo "\033[1;34m\n 😋 OKAY ! Let's do some good cook for dinner !!! 😋\n \033[0;37m\n##############################################\n\n\033[1;33m🥚 Let's fry the Libft 🥚 . . .\n"
#				@$(MAKE) -C $(LIBFT_DIR)
#				@echo "\033[1;32m \n🍳 Libft is cooked 🍳 !!!\n \033[0;37m\n##############################################\n"
#				
#				@echo "\033[1;35m🥕 Let's cook the push_swap files 🥬 . . .\n"			

all			:	${NAME}

clean		:
				@echo "\033[1;37m\n 😳 IT'S GROSS ??? 😳\n"
				${RM} ${OBJ}
#				@$(MAKE) clean -C $(LIBFT_DIR)
				@echo "\n 🗑  Your dish has been cleaned 🗑\n"

fclean		:	clean
				${RM} ${NAME}
#				@$(MAKE) fclean -C $(LIBFT_DIR)
				@echo "\n 🗑 💩 ALL our dish has been cleaned 💩 🗑\n"

re			:	fclean all
				@echo "\033[1;36m\n 👨‍🍳 Are you still hungry ? NO PROBLEMO ! 👩‍🍳\n"

sus			:
				@for (( i=1; i<=10000; i++ )) \
				do \
				clear \
				echo "\033[1;37m                                                        &&&&&###&&&&&&&&&"; \
				echo "                                                  &&##BBBBBBBBBBBBBBBBBBBBB###&&"; \
				echo "                                  &&&&###&    &&#BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB#&&"; \
				echo "                     &###&   &&##BBBBB#&  &&#BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB##&"; \
				echo "                &&##BB#&  &#BBBBBBB#&   &#BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB#&"; \
				echo "             &#BBBBB#&  &#B###BBB#   &#BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB#&"; \
				echo "          &#BBBBBBBB&  BBBB#&&&&  &#BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB#&"; \
				echo "        &BBBBBBBBBBB#&  &##BB#& &#BBBBBBBBBBBBBBBBBBBBBBBBBBBBB################BBBBBBBBBBBBBBB#"; \
				echo "      &BBBBBBBBBBBBBBBB#&&  & &#BBBBBBBBBBBBBBBBBBBBBBB#################################BBBBBBB#&"; \
				echo "     #BBBBBBBBBBBBBBBBBBBB####BBBBBBBBBBBBBBBBBBBB###########################################BBBB&"; \
				echo "    &BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB##################################################BB&"; \
				echo "    &BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB########################################################&"; \
				echo "     #BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB###########################################################"; \
				echo "      &&&&&&#BBBBBBBBBBBBBBBBBBBBBBBBBB#############################################################"; \
				echo "  &#BP55PG#  BBBBBBBBBBBBBBBBBBBBBBB################################################################"; \
				echo "B5YY55PGB#  #BBBBBB##BBBBBBBBBBBBB##################################################################"; \
				echo "BBB##&&  &#BBB########BBBBBBBBBB####################################################################"; \
				echo "         &###############BBBBB######################################################################"; \
				echo "          &#########################################################################################"; \
				echo "            &#######################################################################################"; \
				echo "             &######################################################################################"; \
				echo "               &###################################################################################&"; \
				echo "                 &################################################################################& "; \
				echo "                   &#############################################################################&  "; \
				echo "                     ###########################################################################&   "; \
				echo "                      &########################################################################&    "; \
				echo "                        ######################################################################&     "; \
				echo "                         &###################################################################       "; \
				echo "                          &###################################################&&&&#########&        "; \
				echo "                           &############################################&&&@@@@&#########&          "; \
				echo "                            &####################################&&&@@@@@@&&&##########&            "; \
				echo "                             &#############################&&&           &##########&               "; \
				echo "                              #####################&&&&                  &#######&                  "; \
				echo "                               #################&                        ###&&&                     "; \
				echo "                               &###############&                                                    "; \
				echo "                                &#############&                                                     "; \
				echo "                                 ############&                                                      "; \
				echo "                                 &#######&&&                                                        "; \
				echo "                                  ##&&                                                              "; \
				echo $$i 💀 SUSSY BAKA 💀\\n; \
				done

.PHONY		:	all clean fclean re sus debug
