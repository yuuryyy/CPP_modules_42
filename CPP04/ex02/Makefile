NAME 	:=  AbstractAnimal

SRCS 	:=  main.cpp AbstractAnimal.cpp\
		    Dog.cpp Cat.cpp     \
			WrongAnimal.cpp      \
			WrongCat.cpp          \
			Brain.cpp			   \

OBJS 	:= $(SRCS:.cpp=.o)

CC 		:= c++

HEADER 	:= AbstractAnimal.hpp Dog.hpp Cat.hpp WrongAnimal.hpp WrongCat.hpp Brain.hpp

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
