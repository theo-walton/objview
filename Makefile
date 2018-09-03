
NAME = scop

SRC = *.c

OBJ = *.o

FRAMEWORK = -framework OpenGl

GLFW_INC = -I ~/.brew/include 

MY_INC = -I ./include

GLFW_LINK = -L ~/.brew/lib -lglfw

FLAGS = -Wall -Wextra -Werror

make:
	gcc -c $(FLAGS) $(SRC) $(MY_INC) $(GLFW_INC)
	gcc $(OBJ) $(FLAGS) $(GLFW_LINK) $(FRAMEWORK) $(GLFW_INC) -o $(NAME)

clean:
	rm -f *.o

fclean: clean
	rm -rf $(NAME)
	rm -rf $(NAME).dSYM

re: fclean make
