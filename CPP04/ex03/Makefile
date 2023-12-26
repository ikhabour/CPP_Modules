NAME = AMateria

CPP = c++

CPPFLAGS = -Wextra -Werror -Wall -std=c++98 -fsanitize=address -g3

SRCS = AMateria.cpp Cure.cpp Character.cpp Ice.cpp MateriaSource.cpp main.cpp 

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