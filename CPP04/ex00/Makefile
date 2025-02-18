NAME 	:=  animal

SRCS 	:=  main.cpp Animal.cpp\
		    Dog.cpp Cat.cpp     \
			WrongAnimal.cpp      \
			WrongCat.cpp          \

OBJS 	:= $(SRCS:.cpp=.o)

CC 		:= c++

HEADER 	:= Animal.hpp Dog.hpp Cat.hpp WrongAnimal.hpp WrongCat.hpp

CFLAGS 	:= -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
