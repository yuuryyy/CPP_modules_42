NAME 	:= Interface


SRCS	:=	Ice.cpp     \
			Cure.cpp     \
			main.cpp      \
		    AMateria.cpp   \
			Character.cpp   \
			MateriaSource.cpp \

OBJS 	:= $(SRCS:.cpp=.o)

CC 		:= c++

HEADER 	:= AMateria.hpp Ice.hpp Character.hpp ICharacter.hpp Cure.hpp \
			IMateriaSource.hpp MateriaSource.hpp \

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
