NAME 		:=	Unnecessary_violence

SRC			:=	main.cpp \
				HumanA.cpp\
				HumanB.cpp \
				Weapon.cpp  \

COMPILER	:= c++


HEADERS		:=	Weapon.hpp \
				HumanA.hpp  \
				HumanB.hpp   \

FLAGS		:= -Wall -Wextra -Werror  -std=c++98

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