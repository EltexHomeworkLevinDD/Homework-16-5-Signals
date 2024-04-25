CC := gcc
CFLAGS := -Wall -Wextra -g

.PHONY: clean

main: main.c
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -f main