NAME 		:=	megaphone

SRC			:=	megaphone.cpp

OBG			:= megaphone.o

COMPILER	:= c++

FLAGS		:= -Wall -Wextra -Werror  -std=c++98

all	:  $(NAME)

 $(NAME) : $(OBG)
	$(COMPILER) $(FLAGS) $(OBG) -o $(NAME)

$(OBG) : $(SRC)
	$(COMPILER) $(FLAGS) -c $< -o $@

clean :
	rm -rf $(OBG)

fclean : clean
	rm -rf $(NAME)

re		: fclean all

.PHONY	: all clean fclean re