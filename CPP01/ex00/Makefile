NAME 		:=	BraiiiiiiiiinzzzzZ

SRC			:=	main.cpp\
				Zombie.cpp\
				newZombie.cpp\
			 	randomChump.cpp \

COMPILER	:= c++

HEADERS		:=	Zombie.hpp

FLAGS		:= -Wall -Wextra -Werror  -std=c++98 -fsanitize=address -g

OBG			:= $(SRC:.cpp=.o)


all	:  $(NAME)

 $(NAME) : $(OBG)
	$(COMPILER) $(FLAGS) $(OBG) -o $(NAME)

%.o: %.cpp  $(HEADERS)
	$(COMPILER) $(FLAGS) -c $< -o $@

clean :
	rm -rf $(OBG)

fclean : clean
	rm -rf $(NAME)

re		: fclean all

.PHONY	: all clean fclean re