# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alikhtor <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/07 13:16:04 by alikhtor          #+#    #+#              #
#    Updated: 2018/05/30 16:58:47 by alikhtor         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# name of the executable file

NAME :=			libftprintf.a

# project directories

SRC_DIR :=		./sources/
OBJ_DIR :=		./objects/
INC_DIR :=		./includes/
LIBFT_DIR :=	./libft/

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
LIBFT_INC :=	$(LIBFT_DIR)includes/
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
	@ ar rc $(NAME) $(OBJ) libft/objects/*.o
	@ ranlib $(NAME)
#	@ printf "\e[32mLIBFTPRINTF DONE\n"

$(OBJ): | $(OBJ_DIR)

$(OBJ_DIR):
	@ mkdir $(OBJ_DIR)

$(OBJ_DIR)%.o: %.c
	@ gcc -c $< -o $@ $(FLAGS) $(HEADER_FLAGS)

$(LIBFT):
	@ make -C $(LIBFT_DIR)

clean:
	@ rm -rf $(OBJ_DIR)
	@ make clean -C $(LIBFT_DIR)
#	@ printf "\e[33mCLEANING DONE\n"

fclean:
	@ rm -f $(NAME)
	@ rm -rf $(OBJ_DIR)
	@ make fclean -C $(LIBFT_DIR)
#	@ printf "\e[31mFULL CLEANING DONE\n"

re: fclean all

vpath %.c $(SRC_DIR)

.PHONY: all clean fclean re
