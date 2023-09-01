NAME = libft.a

SRC_DIR = srcs
OBJ_DIR = objs
INC_DIR = incs

INCLUDES = get_next_line.h libft.h

SOURCES = \
		  ft_ltoa.c \
		  ft_iseq.c ft_iseqlen.c ft_iseqmv.c \
		  ft_isin.c ft_isinlen.c ft_isinmv.c \
		  \
		  ft_strncmp.c ft_memchr.c ft_atoi.c ft_memcmp.c ft_strnstr.c \
		  ft_strrchr.c ft_strchr.c ft_toupper.c ft_tolower.c ft_strlcpy.c \
		  ft_strlcat.c \
		  \
		  ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
		  ft_isspace.c \
		  ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c \
		  \
		  ft_calloc.c ft_strdup.c \
		  \
		  ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c \
		  ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c \
		  ft_putnbr_fd.c \
		  \
		  get_next_line.c get_next_line_utils.c \
		  \
		  ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c \
		  ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c \

OBJS = $(addprefix $(OBJ_DIR)/, $(SOURCES:.c=.o))
SRCS = $(addprefix $(SRC_DIR)/, $(SOURCES))
INCS = $(addprefix $(INC_DIR)/, $(INCLUDES))

MAKE = make
CC = gcc
AR = ar
RM = rm

CFLAGS = -Wall -Werror -Wextra
ARFLAGS = crs
RMFLAGS = -rf

all : $(NAME)

clean : 
	$(RM) $(RMFLAGS) $(OBJS)
	$(RM) $(RMFLAGS) $(OBJ_DIR)

fclean : 
	$(MAKE) clean
	$(RM) $(RMFLAGS) $(NAME)

re : 
	$(MAKE) fclean
	$(MAKE) all

.PHONY: all clean fclean re

$(NAME) : $(OBJS)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c $(INCS) | $(OBJ_DIR)
	$(CC) $(CFLAGS) $< -c -I $(INC_DIR) -o $@

$(OBJ_DIR) :
	mkdir $(OBJ_DIR)
