NAME 		:=	phonebook

SRC			:=	PhoneBook.cpp \
				Contact.cpp \
				main.cpp \


COMPILER	:= c++

HEADERS		:=	PhoneBook.hpp \
				Contact.hpp \

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