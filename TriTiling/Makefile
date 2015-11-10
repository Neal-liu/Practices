CFLAGS = -Wall -Werror -std=gnu99 -O0 -g
LDFLAGS = `pkg-config --libs --cflags libpng`
PNGLIBS := $(shell pkg-config libpng --libs)

all:
	gcc TriTiling.c
	./a.out 
test:
	gcc test.c
	./a.out 
