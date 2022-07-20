# t:
# 	gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c main.c
# 	./a.out

tb:
	gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line_bonus.c get_next_line_utils_bonus.c main.c
	./a.out

test:
	gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 *.c -fsanitize=address -g3
	./a.out

btest:
	gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line_bonus.c get_next_line_utils_bonus.c main.c -fsanitize=address -g3
	./a.out
	
r:
	rm -f a.out


