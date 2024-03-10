# -----------------------------------Makefile------------------------------------
NAME 	 = libft.a
DEBUG 	 = debug.out
# -----------------------------------Sources-------------------------------------
INCLUDES =  -Iincludes
OBJS	 = ${PREV_PROJ:.c=.o}
# -----------------------------------Compilation---------------------------------
CC			= cc
FLAGS		= -Wall -Wextra -Werror
RM			= rm -f
FSANITIZE	= -fsanitize=address -g
# ---------------------------------Librairies------------------------------------
LIBFT	= ft_atoi.c \
			ft_bzero.c \
			ft_calloc.c \
			ft_isalnum.c \
			ft_isalpha.c \
			ft_isascii.c \
			ft_isdigit.c \
			ft_isprint.c \
			ft_itoa.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_memcpy.c \
			ft_memmove.c \
			ft_memset.c \
			ft_putchar_fd.c \
			ft_putendl_fd.c \
			ft_putnbr_fd.c \
			ft_putstr_fd.c \
			ft_split.c \
			ft_striteri.c \
			ft_strlcat.c \
			ft_strlcpy.c \
			ft_strmapi.c \
			ft_strncmp.c \
			ft_strnstr.c \
			ft_strrchr.c \
			ft_strtrim.c \
			ft_tolower.c \
			ft_toupper.c \
			ft_lstnew_bonus.c \
			ft_lstadd_front_bonus.c \
			ft_lstsize_bonus.c \
			ft_lstlast_bonus.c \
			ft_lstadd_back_bonus.c \
			ft_lstdelone_bonus.c \
			ft_lstclear_bonus.c \
			ft_lstiter_bonus.c \
			ft_lstmap_bonus.c \

LIBFT_SRC = ${addprefix libft/, ${LIBFT}}

GNL		= get_next_line.c \
			get_next_line_utils.c \
			utils.c \

GNL_SRC  = ${addprefix gnl/, ${GNL}}

PRINTF	= ft_printf.c \
			ft_prt_ch.c \
			ft_prt_dec.c \
			ft_prt_hex.c \
			ft_prt_str.c \
			ft_prt_uns_dec.c \
			ft_utils.c \

PRINTF_SRC = ${addprefix printf/, ${PRINTF}}

PREV_PROJ = $(LIBFT_SRC) $(GNL_SRC) $(PRINTF_SRC)
# ----------------------------------En LEGENDE------------------------------------
GREEN = \033[0;32m
GREEN_BOLD = \033[1;32m
RED = \033[0;31m
RED_BOLD = \033[1;31m
MAGENTA = \033[0;35m
BLUE = \033[0;34m
ORANGE = \033[0;38;5;214m
YELLOW = \033[0;33m
CLIGNOT = \033[5m
CLOSE = \033[0m

TOTAL_FILES 	:= $(words $(PREV_PROJ))
CURRENT_FILE 	:= 0

define progress_bar_libft
    @$(eval CURRENT_FILE=$(shell echo $$(($(CURRENT_FILE) + 1))))
    @printf "\r$(MAGENTA)Compiling Libft... ⌛⌛⌛[%-$(TOTAL_FILES)s] %d/%d $(NC)" $$(for i in $$(seq 1 $(CURRENT_FILE)); do printf "="; done) $(CURRENT_FILE) $(TOTAL_FILES)
	@if [ $(CURRENT_FILE) -eq $(TOTAL_FILES) ]; then echo "$(YELLOW)\n\nLibft c'est bon ma gueule 👌$(CLOSE)\n"; fi
endef

# -----------------------------------Rules---------------------------------------
all: $(NAME)

$(NAME): $(OBJS)
	@ar rcs $(NAME) $(OBJS)

%.o: %.c
	@$(CC) $(FLAGS) $(INCLUDES) -c $< -o $@
	$(call progress_bar_libft)

debug: $(OBJS)
	$(CC) $(FLAGS) $(INCLUDES) $(FSANITIZE) $(OBJS) -o $(DEBUG)

clean:
	@$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME) $(DEBUG)

re: fclean all
# -----------------------------------.phony-------------------------------------
.PHONY: all clean fclean re debug