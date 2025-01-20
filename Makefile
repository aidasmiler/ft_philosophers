# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: airodrig <airodrig@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/07 14:50:36 by airodrig          #+#    #+#              #
#    Updated: 2022/03/28 20:02:02 by airodrig         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=		philo

S		=		src/

O		=		obj/

H		=		 -I inc/ -pthread

FILES	=		main.c \
				utils_philo.c \
				parser.c \
				create_philos.c \
				list_utils_ph.c \
				info_philo.c \
				eat_sleep_think.c

SRCS	=	$(addprefix $S, $(FILES))

OBJS	=		$(SRCS:$S%.c=$O%.o)

CC		=		gcc

RM		=		rm -rf

CFLAGS	=		-Wall -Werror -Wextra

NOCOL		=	\033[0m
RED			=	\033[1;31m
ORG			=	\033[0;33m
YEL			=	\033[1;33m
GRN			=	\033[1;32m
BLU			=	\033[0;34m
CYN			=	\033[0;36m
PUR			=	\033[0;35m

#Black        0;30     Dark Gray     1;30
#Red          0;31     Light Red     1;31
#Green        0;32     Light Green   1;32
#Brown/Orange 0;33     Yellow        1;33
#Blue         0;34     Light Blue    1;34
#Purple       0;35     Light Purple  1;35
#Cyan         0;36     Light Cyan    1;36
#Light Gray   0;37     White         1;37

all: $(NAME)

$O%.o: $S%.c
	@[ -d $O ] || mkdir $O
	@$(CC) $(CFLAGS) $H -c $< -o $@

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $H $(SRCS) -o $(NAME)
	@[ -e $(NAME) ] && echo "$(GRN) ✅✅✅ Compilation Succeeded! ✅✅✅ $(NOCOL)"

bonus: all

clean:
	@${RM} $O

fclean: clean
	@${RM} ${NAME}
	@echo "$(CYN) 🧼🧼🧼 All clean! 🧼🧼🧼 $(NOCOL)"

re: fclean all

normi:
	@echo "$(PUR) 🔍🔍 Checking Norminette 🔎🔎$(NOCOL)"
	@norminette $S

.PHONY: all clean fclean re normi bonus
