NAME = Notes

SRCS =  $(wildcard ./src/*.cpp)

OBJS = $(SRCS:.c=.o)

INCLUDES = -I ./inc

CC = g++ -std=c++17 

all : $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(INCLUDES) $(OBJS) -o $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) $< -c -o $@

clean :
	@rm -rf $(wildcard ./*.gch.*)
	@rm -rf $(wildcard ./*/*.gch.*)
	@rm -rf $(wildcard ./*/*/*.gch.*)

fclean : clean
	@rm -rf $(NAME)

re : fclean all