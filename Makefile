test:
	gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 *.c
	./a.out
