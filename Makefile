CC=gcc
FLAGS=-Wall -Wextra -Werror -pedantic -std=c99

make: tty_battery.c tty_battery.h
	$(CC) $(FLAGS) -o tty-battery *.c

clean:
	rm -f tty-battery