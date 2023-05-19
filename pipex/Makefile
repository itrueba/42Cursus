# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: itrueba- <itrueba-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/06 14:12:07 by itrueba-          #+#    #+#              #
#    Updated: 2023/05/06 14:12:10 by itrueba-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= pipex
BONUS		= pipex_bonus
RM			= rm -rf
SRC_DIR		= Src
INCS		= Include Libft/Include
LIBS_TARGET	= Libft/libft.a
LIBS        = ft 
CC			= gcc
CFLAGS		= -Wall -Werror -Wextra -g3
CPPFLAGS    := $(addprefix -I,$(INCS)) -MMD -MP
LDFLAGS     := $(addprefix -L,$(dir $(LIBS_TARGET)))
LDLIBS      := $(addprefix -l,$(LIBS))
DIR_DUP     = mkdir -p $(@D)
BUILD_DIR   := .build

SRCS_MANDATORY	=	ft_free.c ft_lst.c ft_main_control.c ft_path.c mandatory.c
SRCS_MANDATORY	:=   $(SRCS_MANDATORY:%=$(SRC_DIR)/%)

SRCS_BONUS	=	ft_free.c ft_lst.c ft_main_control.c ft_path.c bonus.c 
SRCS_BONUS	:=   $(SRCS_BONUS:%=$(SRC_DIR)/%)

OBJS_MANDATORY	= $(SRCS_MANDATORY:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)

OBJS_BONUS	= $(SRCS_BONUS:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)

DEPS_MANDATORY		:= $(OBJS_MANDATORY:.o=.d)
DEPS_BONUS			:= $(OBJS_BONUS:.o=.d)

all:		$(NAME)

%.o: %.c
		$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

$(NAME):	$(OBJS_MANDATORY) $(LIBS_TARGET)
			$(CC) $(CFLAGS) $(LDFLAGS) $(OBJS_MANDATORY) $(LDLIBS) -o $@

$(BONUS):	$(OBJS_BONUS) $(LIBS_TARGET)
			$(CC) $(CFLAGS) $(LDFLAGS) $(OBJS_BONUS) $(LDLIBS) -o $@

$(LIBS_TARGET):
	$(MAKE) -C $(@D)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	$(DIR_DUP)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $<
	$(info CREATED $@)

-include $(DEPS_MANDATORY) $(DEPS_BONUS)

clean:
			make -C $(dir $(LIBS_TARGET)) clean
			$(RM) $(OBJS_MANDATORY)	$(OBJS_BONUS) $(DEPS_MANDATORY)	$(DEPS_BONUS)

fclean:		clean
			@make -C $(dir $(LIBS_TARGET)) fclean
			@$(RM) $(NAME) $(BONUS)

re:			fclean all

bonus:		$(BONUS)

.PHONY:		all clean fclean re

