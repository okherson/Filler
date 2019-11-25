NAME	=	okherson.filler

SRC_F	=	filler.c place_search.c alg_congestion.c dop_f.c alg_position.c analyze_map.c

SRC = $(addprefix ./src/, $(SRC_F))

OBJ_F 	=	filler.o place_search.o alg_congestion.o dop_f.o alg_position.o analyze_map.o

OBJ_DIR = ./obj/

OBJ = $(addprefix ./obj/, $(OBJ_F))

LIB = ./libft
LIB_OBJ = ./libft/*.o

HEADER = ./includes/o_filler.h

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJ) $(HEADER)
		@make -C $(LIB)
		@gcc $(FLAGS) $(OBJ) $(LIB_OBJ) -o $(NAME)

$(OBJ_DIR):
		@mkdir -p $(OBJ_DIR)

$(addprefix ./obj/, %.o): $(addprefix ./src/, %.c)
		@clang -g -o $@ -c $< $(FLAGS)

clean:
	@make -C $(LIB) clean
	@rm -f $(OBJ)
	@rm -rf $(OBJ_DIR)

fclean: clean
	@make -C $(LIB) fclean
	@rm -f $(NAME)

re: fclean all
