# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dajeon <dajeon@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/16 09:00:32 by dajeon            #+#    #+#              #
#    Updated: 2023/09/01 17:50:06 by dajeon           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = parser
BONUS = 

SOURCES = parser/redi.c \
		  parser/ft_parse_redi.c \
		  parser/ft_parse_text.c \
		  parser/ft_parse_env.c \
		  parser/ft_error.c \
		  parser/ft_parse.c \
		  parser/utils.c \
		  parser/test.c \
		  parser/ft_convert.c \
		  parser/ft_conv_redi.c \
		  parser/vars.c \
		  parser/cmd.c  \
		  parser/text.c \
		  parser/temp.c


DIRS = parser env ex

SOURCES_MANDA = main.c 
SOURCES_BONUS = main_test.c \
				error.c \
				ft_cd.c \
				ft_pwd.c \
				ft_exit.c \
				util.c \
				ft_echo.c \
				env/envset.c \
				env/ft_env.c \
				env/ft_unset.c \
				env/envpmkr.c \
				env/envutil.c \
				env/ft_export.c \
				ex/exfree.c \
				ex/exbuiltin.c \
				ex/expipe.c \
				ex/exnode.c \
				ex/exreal.c

INCLUDES = 
INCLUDES_MANDA =
INCLUDES_BONUS =

LIBFT = libft.a
LIB = ft 

# **************************************************************************** #

LIB_DIR = libft
SRC_DIR = srcs
OBJ_DIR = objs
INC_DIR = incs

SRCS := $(addprefix $(SRC_DIR)/, $(SOURCES))
SRCS_MANDA := $(addprefix $(SRC_DIR)/, $(SOURCES_MANDA))
SRCS_BONUS := $(addprefix $(SRC_DIR)/, $(SOURCES_BONUS))

OBJ_DIRS = $(addprefix $(OBJ_DIR)/, $(DIRS))

OBJS = $(addprefix $(OBJ_DIR)/, $(SOURCES:.c=.o))
OBJS_MANDA = $(addprefix $(OBJ_DIR)/, $(SOURCES_MANDA:.c=.o))
OBJS_BONUS = $(addprefix $(OBJ_DIR)/, $(SOURCES_BONUS:.c=.o))

INCS := $(addprefix $(INC_DIR)/, $(INCLUDES))
INCS_BONUS := $(addprefix $(INC_DIR)/, $(INCLUDES_BONUS))
INCS_MANDA := $(addprefix $(INC_DIR)/, $(INCLUDES_MANDA))

LIBFT := $(addprefix $(LIB_DIR)/, $(LIBFT))

ifdef WITH_BONUS
	OBJS_NEW = $(OBJS_BONUS) $(OBJS) 
	INCS_NEW = $(INCS_BONUS) $(INCS)
else
	OBJS_NEW = $(OBJS_MANDA) $(OBJS) 
	INCS_NEW = $(INCS_MANDA) $(INCS)
endif

# **************************************************************************** #

MAKE = make
CC = gcc
AR = ar
RM = rm

CFLAGS = -Wall -Wextra -Werror -fsanitize=address
LIBFLAGS = -l$(LIB) -L$(LIB_DIR) -lreadline

ARFLAGS = crus
RMFLAGS = -rf

# Commands ******************************************************************* #

all : 
	$(RM) $(RMFLAGS) $(OBJS_BONUS)
	$(MAKE) $(NAME) 

bonus : 
	$(RM) $(RMFLAGS) $(OBJS_MANDA)
	$(MAKE) $(NAME) WITH_BONUS=1

clean :
	$(RM) $(RMFLAGS) objs
	$(MAKE) -C libft clean

fclean : 
	$(RM) $(RMFLAGS) objs
	$(RM) -f $(NAME)
	$(MAKE) -C libft fclean

re : 
	$(MAKE) fclean
	$(MAKE) all

.PHONY: all bonus clean fclean re

# Dependency ***************************************************************** #

$(NAME) $(BONUS) : $(OBJS_NEW) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS_NEW) -o $@ $(LIBFLAGS)

$(LIBFT): 
	$(MAKE) -j3 -C $(LIB_DIR) all

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INCS_NEW) | $(OBJ_DIR) $(OBJ_DIRS)
	$(CC) $(CFLAGS) $< -c -I $(INC_DIR) -o $@

$(OBJ_DIR):
	mkdir $@

$(OBJ_DIRS):
	mkdir $@
