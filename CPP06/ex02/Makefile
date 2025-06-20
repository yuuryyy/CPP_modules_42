NAME	:= IRT

SRCS	:=	main.cpp		\
			Functions.cpp	 \
			Base.cpp		  \

OBJS	:= $(SRCS:.cpp=.o)

CXX		:= c++

CXXFLAGS	:= -Wall -Wextra -Werror -std=c++98

HEADERS	:= Base.hpp  \
			A.hpp	  \
			B.hpp	   \
			C.hpp		\

RM		:= rm -f

all: $(NAME)

$(NAME): $(OBJS)
	@$(CXX) $(CXXFLAGS) -o $@ $^
	@echo "Compilation complete: $(NAME)"
	@echo "Executable: $(NAME)"

%.o: %.cpp $(HEADERS)
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