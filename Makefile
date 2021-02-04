##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## makefile
##

OUTPUTFILE = csnake

.PHONY = all
all:
	make -C src/ all
	cp src/$(OUTPUTFILE) ./

.PHONY = clean
clean:
	make -C src/ clean
	rm -f -- $(OUTPUTFILE)

.PHONY = re
re:
	rm -f -- $(OUTPUTFILE)
	make -C src/ re
	cp src/$(OUTPUTFILE) ./
