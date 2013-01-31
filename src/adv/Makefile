SHELL = /bin/bash
OBJ = p1 p2 p3 b1 b2

all:
	make $(OBJ)

distclean:
	-rm $(OBJ)

%: %.c
	g++ $< -o $@
