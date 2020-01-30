# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jjerde <jjerde@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/15 15:17:26 by jjerde            #+#    #+#              #
#    Updated: 2019/11/05 15:25:47 by jjerde           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#======================P̶O̶N̶Y̶ PHONY==========================================#
.PHONY: all, clean, fclean, re, debmsg, debug, redebug

#======================Folders & Files=========================================#
NAME =		libft.a
SRC =		ft_flag_g.c ft_litoa.c ft_minus.c ft_strchr.c ft_strmap.c \
			ft_strstr.c check_hub.c ft_flag_i.c ft_lstadd.c \
			ft_strclen.c ft_strmapi.c ft_strsub.c checker.c ft_flag_o_u_x.c \
			ft_lstdel.c ft_proverka.c ft_strclr.c ft_strncat.c ft_strtrim.c \
			colors.c ft_flag_p.c ft_lstdelone.c ft_putchar.c ft_strcmp.c \
			ft_strncmp.c ft_tolower.c flag_checker.c ft_i_5.c ft_lstiter.c \
			ft_putchar_fd.c ft_strcpy.c ft_strncpy.c ft_toupper.c \
			flag_g_free.c ft_isalnum.c ft_lstmap.c ft_putendl.c ft_strdel.c \
			ft_strnequ.c ft_uitoa.c ft_atoi.c ft_isalpha.c ft_lstnew.c \
			ft_putendl_fd.c ft_strdup.c ft_strnew.c ft_width.c ft_bzero.c \
			ft_isascii.c ft_memalloc.c ft_putnbr.c ft_strequ.c ft_strnstr.c \
			 ft_chacc.c ft_isdigit.c ft_memccpy.c ft_putnbr_fd.c \
			ft_striter.c ft_strrchr.c main.c ft_clearone.c ft_isprint.c \
			ft_memchr.c ft_putstr.c ft_striteri.c ft_strrejoin.c \
			mod_redirect.c ft_count_words.c ft_isspace.c ft_memcmp.c \
			ft_putstr_fd.c ft_strjoin.c ft_strrejoinre.c modificators.c \
			ft_flag_e.c ft_isxdigit.c ft_memcpy.c ft_sqrt.c ft_strjoinfree.c \
			ft_strrejoinren.c printf_depleted.c ft_flag_e_2.c ft_itoa.c \
			ft_memdel.c ft_sstrlen.c ft_strjoinre.c ft_strreplchar.c \
			redirect_target_get.c ft_flag_f.c ft_list_last.c ft_memmove.c \
			ft_sswap.c ft_strlcat.c ft_strsearch.c redirect_target_icsf_.c \
			ft_flag_f_2.c ft_list_size.c ft_memset.c ft_strcat.c ft_strlen.c \
			ft_strsplit.c ft_linedelone.c get_next_line.c
WORKDIR =	../
HEADER =	$(WORKDIR)includes/ft_printf.h
OBJ =		$(SRC:.c=.o)
HFLAGS =	-I$(WORKDIR)includes/

#======================COLORS & Co=============================================#
GREEN =		\033[1;32m
RED =		\033[1;31m
RST =		\033[0m
BOLD =		\033[1m
CYAN =		\033[1;36m
PREFIX =	[$(CYAN)$(NAME)$(RST)]:\t

#======================Debug & Flags===========================================#
ifeq ($(DEBUGMODE), 1)
	FLAGS		:=	-Wall -Wextra -Werror -g
	DEBUGMSG	:= $(PREFIX)⚠️  \033[1;33mDebug mode $(GREEN)enabled.$(RST)\n
else
	FLAGS		:=	-Wall -Wextra -Werror
	DEBUGMSG	:= $(PREFIX)⚠️  \033[1;33mDebug mode $(RED)disabled.$(RST)\n
endif

#======================Rules===================================================#
%.o: %.c
		@printf "%-95c\r$(PREFIX)🕐  Compiling file:\t \
%-25s=>\t%-25s\r" ' ' "$<" "$@"
		@gcc -c $^ $(FLAGS) $(HFLAGS)

all: $(NAME)
		@echo "$(PREFIX)✅  $(GREEN)Done.$(RST)"

$(NAME): $(OBJ) $(SRC) $(HEADER)
		@printf "%-95c\r$(PREFIX)✅  $(GREEN)All \
obj-files accepted.$(RST)\n" ' '
		@printf "$(PREFIX)📦  Building $(NAME)...\n"
		@ar rc $(NAME) $(OBJ)
		@ranlib $(NAME)

clean:
		@echo "$(PREFIX)♻️  $(RED)Removing obj-files...$(RST)"
		@rm -f $(OBJ)

dellib:
		@echo "$(PREFIX)♻️  $(RED)Removing library file...$(RST)"
		@rm -f $(NAME)

fclean: clean dellib

re: fclean
		@make all

debug:
		@make all DEBUGMODE=1

redebug:
		@make re DEBUGMODE=1
