CC=gcc
FLAGS=-Wall -Wextra -Werror -pedantic -std=c99

make: tty_battery.c tty_battery.h args_parser.c args_parser.h tty_battery.c tty_battery.h
	$(CC) $(FLAGS) -c *.c
	$(CC) $(FLAGS) -o tty-battery *.o

run: tty-battery
	make clean && make && ./tty-battery

clean:
	rm -f tty-battery *.o