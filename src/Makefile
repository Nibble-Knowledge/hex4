SRC=hex4.c
EXE=hex4
EXTRACFLAGS=
EXTRALDFLAGS=-lncurses
export SRC
export EXE
export EXTRACFLAGS
export EXTRALDFLAGS

all: debug

fast: phony
	$(MAKE) -f Makefile.fast.gcc

debug: phony
	$(MAKE) -f Makefile.dev.gcc

distw32: phony
	$(MAKE) -f Makefile.dist.mingw32

clean:
	rm -rf $(SRC:.c=.gcno) $(SRC:.c=.gcda) $(SRC:.c=.gcov) $(SRC:.c=.o) getline.o
	rm -rf html gmon.out docs.html $(EXE) *.dyn *.dpi *.lock *.stackdump *.db

phony: 
	true
