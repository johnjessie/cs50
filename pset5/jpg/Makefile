#
# Makefile
#
# Computer Science 50
# Problem Set 5
#

all: recover

recover: Makefile recover.c
	gcc -ggdb -std=c99 -Wall -Werror -Wformat=0 -o recover recover.c 

clean:
	rm -f *.o a.out core.* recover *.jpg
