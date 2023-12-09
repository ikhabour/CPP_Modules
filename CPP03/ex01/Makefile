NAME = ClapTrap

CPP = c++

CPPFLAGS = -Wextra -Werror -Wall -std=c++98

SRCS = ClapTrap.cpp main.cpp

OBJECTS = $(SRCS:.cpp=.o)

all : $(NAME)

%.o : %.cpp
	$(CPP) -c $(CPPFLAGS) $< -o $@

$(NAME) :$(OBJECTS)
	$(CPP) $(CPPFLAGS) $(SRCS) -o $(NAME)

clean :
	rm -rf $(OBJECTS)

fclean : clean
	rm -rf $(NAME)

re : fclean all