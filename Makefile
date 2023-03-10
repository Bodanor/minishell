# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mfinette <mfinette@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/26 15:04:30 by mfinette          #+#    #+#              #
#    Updated: 2023/01/11 15:27:58 by mfinette         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

CC		= cc
CFLAGS	= -Wall -Wextra -Werror
AR		= ar rcs
RM		= @rm -f
HEADER	= push_swap.h
DEF_COLOR = \033[0;39m
YELLOW = \033[0;93m
GREEN = \033[0;92m
BLUE = \033[0;94m
CYAN = \033[0;96m

FILES = parsing/command_parsing		\
		utils/parsing_utils		

all: $(NAME)

SRCS_DIR = ./
SRCS = $(addprefix $(SRCS_DIR), $(addsuffix .c, $(FILES)))

OBJS_DIR = ./
OBJS = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(FILES)))

%.o:%.c $(HEADER)
	@echo "$(YELLOW)Compiling: $< $(DEF_COLOR)"
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	@make -C libft
	@echo "$(GREEN)😳😎minishell compiled!😎😳$(DEF_COLOR)"
	@${CC} libft/libft.a ${FLAGS} ${SRCS} -o ${NAME}


clean:
	@$(RM) $(OBJS)
	@echo "$(CYAN)minishell object files cleaned!$(DEF_COLOR)"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(CYAN)3$(DEF_COLOR)"
	@sleep 0.2
	@echo "$(CYAN)2$(DEF_COLOR)"
	@sleep 0.2
	@echo "$(CYAN)1$(DEF_COLOR)"
	@sleep 0.2
	@echo "$(GREEN)minishell executable files cleaned!$(DEF_COLOR)"


re: fclean all

.PHONY: all clean fclean re