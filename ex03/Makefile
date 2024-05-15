CXX:= c++
CXXFLAGS:= -Wall -Wextra -Werror -std=c++98

NAME:= prog

SRC:= main.cpp Fixed.cpp Point.cpp bsp.cpp

OBJ:= $(SRC:.cpp=.o)

all: $(NAME)

%.o:	%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(NAME):	$(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $@

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re: fclean $(NAME)
