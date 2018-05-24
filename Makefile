# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alikhtor <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/07 13:16:04 by alikhtor          #+#    #+#              #
#    Updated: 2018/05/23 16:26:40 by alikhtor         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# name of the executable file

NAME :=			libftprintf.a

# project directories

SRC_DIR :=		./srcs/
OBJ_DIR :=		./objects/
INC_DIR :=		./includes/
LIB_DIR :=		./lib/

# project source files

#
# need to add all c files by name
#

SRC :=			ft_printf.c \
				flags_width_precision.c \
				x_mod_part1.c \
				o_mod_part1.c \
				u_mod_part1.c \
				c_mod_part1.c \
				s_mod_part1.c \
				d_i_mod_part1.c \
				d_i_mod_part2.c \
				secondary_functions_part1.c \
				secondary_functions_part2.c

# project object files

OBJ = 			$(addprefix $(OBJ_DIR), $(SRC:.c=.o))

# libraries

LIBFT =			$(LIBFT_DIR)libft.a
LIBFT_DIR :=	$(LIB_DIR)libft/
LIBFT_INC :=	$(LIBFT_DIR)
LIBFT_FLAGS :=	-lft -L $(LIBFT_DIR)

# compilation flags

FLAGS := -Wall -Wextra -Werror -O3

# linking flags

LINK_FLAGS :=	$(LIBFT_FLAGS)

# header flags

HEADER_FLAGS :=	-I $(INC_DIR) -I $(LIBFT_INC)

# rules

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
		@ ar rc $(NAME) $(OBJ) lib/libft/*.o
		@ ranlib $(NAME)

$(OBJ): | $(OBJ_DIR)

$(OBJ_DIR):
	@ mkdir $(OBJ_DIR)

$(OBJ_DIR)%.o: %.c
	@ gcc -c $< -o $@ -I $(FLAGS) $(HEADER_FLAGS)

$(LIBFT):
	@ make -C $(LIBFT_DIR)

clean:
	@ rm -f $(OBJ)
	@ make clean -C $(LIBFT_DIR)

fclean:
	@ rm -f $(NAME)
	@ rm -rf $(OBJ_DIR)
	@ make fclean -C $(LIBFT_DIR)

re: fclean all

vpath %.c $(SRC_DIR)

.PHONY: all clean fclean re
