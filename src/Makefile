##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## makefile
##

OUTPUTFILE      =       csnake

SRCC            =       main.c

SRCO            =       $(SRCC:.c=.o)

LIB 		= 	-lncurses

.PHONY = all
all:            compile

.PHONY = compile
compile:        $(SRCO)
	gcc $(SRCO) $(LIB) -I include -Wall -o $(OUTPUTFILE)

.PHONY = clean
clean:
	rm -f -- $(SRCO)
	rm -f -- $(SRCO)
	rm -f -- $(OUTPUTFILE)

.PHONY = re
re:             clean compile
