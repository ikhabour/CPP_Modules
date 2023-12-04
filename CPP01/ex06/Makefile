NAME = harlFilter

CC = c++

CPPFLAGS = -Wextra -Werror -Wall -std=c++98

SRCS = main.cpp Harl.cpp

OBJECTS = $(SRCS:.cpp=.o)

all : $(NAME)

%.o : %.cpp
	$(CC) -c $(CPPFLAGS) $< -o $@

$(NAME) : $(OBJECTS)
	$(CC) $(CPPFLAGS) $(SRCS) -o $(NAME)

clean :
	rm -rf $(OBJECTS)

fclean : clean
	rm -rf $(NAME)

re : fclean all