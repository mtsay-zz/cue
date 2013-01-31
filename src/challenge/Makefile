SHELL = /bin/bash
OBJ = p1 p2 p3

all:
	make $(OBJ)

distclean:
	-rm $(OBJ)

%: %.c
	g++ $< -o $@
