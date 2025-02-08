NAME	:= Scavtrap

SRCS	:= ClapTrap.cpp main.cpp ScavTrap.cpp

OBJS	:= $(SRCS:.cpp=.o)

HEADERS	:= ClapTrap.hpp \
			ScavTrap.hpp \

CXX		:= c++

CXXFLAGS	:= -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
