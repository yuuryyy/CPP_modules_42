NAME        := btc

CXX         := g++

CXXFLAGS    := -std=c++98 -Wall -Wextra -Werror 

SRCS        :=  main.cpp \
                BitcoinExchange.cpp

HEADER      := BitcoinExchange.hpp

OBJS        := $(SRCS:.cpp=.o)

RM          := rm -rf

all: $(NAME)

$(NAME): $(OBJS)
	@$(CXX) $(CXXFLAGS) -o $@ $^
	@echo "Compilation complete: $(NAME)"
	@echo "Executable: $(NAME)"

%.o: %.cpp $(HEADER)
	@$(CXX) $(CXXFLAGS) -c $< -o $@
	@echo "Compiling: $<"

clean:
	@$(RM) $(OBJS)
	@echo "Cleaning up object files..."
	@echo "Object files cleaned."

fclean: clean
	@$(RM) $(NAME)
	@echo "Cleaning up executable..."
	@echo "Executable cleaned."

re: fclean all
	@echo "Recompiling..."
	@echo "Recompilation complete."

.PHONY: all clean fclean re