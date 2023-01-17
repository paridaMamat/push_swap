CC		= gcc
CFLAGS	= -Wall -Werror -Wextra -g3
NAME	= push_swap
NAME_B  = checker 


SRC		= main.c \
		  cost.c index_position.c input_1.c\
		  input_check.c move.c position.c\
		  push.c reverse_rotation.c rotation.c\
		  sort_three_plus.c sort_three.c stack.c\
		  swap.c utils.c

SRC_B   = checker.c checker_make_list.c checker_utils.c\
		  input_1.c input_check.c push.c reverse_rotation.c\
		  rotation.c stack.c swap.c utils.c

OBJ		= $(SRC:.c=.o)
OBJ_B   = $(SRC_B:.c=.o)

OPTIONS = -c -I.

all: $(NAME) $(NAME_B)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

$(NAME_B): $(OBJ_B)
	$(CC) $(CFLAGS) $(OBJ_B) -o $(NAME_B)

clean:
	rm -rf $(OBJ) $(OBJ_B)

fclean: clean
	rm -f $(NAME) $(NAME_B)

re: fclean all

test2:				$(NAME)	
					$(eval ARG = $(shell shuf -i 0-100 -n 2))
					./push_swap $(ARG) | ./checker_linux $(ARG)
					@echo -n "Instructions: "
					@./push_swap $(ARG) | wc -l

test3:				$(NAME)	
					$(eval ARG = $(shell shuf -i 0-100 -n 3))
					./push_swap $(ARG) | ./checker_linux $(ARG)
					@echo -n "Instructions: "
					@./push_swap $(ARG) | wc -l

test5:				$(NAME)	
					$(eval ARG = $(shell shuf -i 0-5000 -n 5))
					./push_swap $(ARG) | ./checker_linux $(ARG)
					@echo -n "Instructions: "
					@./push_swap $(ARG) | wc -l

test100:			$(NAME)	
					$(eval ARG = $(shell shuf -i 0-5000 -n 100))
					./push_swap $(ARG) | ./checker_linux $(ARG)
					@echo -n "Instructions: "
					@./push_swap $(ARG) | wc -l

test500:			$(NAME)	
					$(eval ARG = $(shell shuf -i 0-5000 -n 500))
					./push_swap $(ARG) | ./checker_linux $(ARG)
					@echo -n "Instructions: "
					@./push_swap $(ARG) | wc -l

test1000:			$(NAME)	
					$(eval ARG = $(shell shuf -i 0-5000 -n 1000))
					./push_swap $(ARG) | ./checker_linux $(ARG)
					@echo -n "Instructions: "
					@./push_swap $(ARG) | wc -l


.PHONY: all clean fclean re test2 test3 test5 test100 test500 test1000
