NAME 		:=	BraiiiiiiiiinzzzzZ

COMPILER	:= c++
FLAGS		:= -Wall -Wextra -Werror  -std=c++98

HEADERS		:=	Zombie.hpp

SRC			:=	main.cpp\
				Zombie.cpp\
				newZombie.cpp\
			 	randomChump.cpp \

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