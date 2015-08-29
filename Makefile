CFLAGS = -Wall -Werror -std=gnu99 -O0 -g
LDFLAGS = `pkg-config --libs --cflags libpng`
PNGLIBS := $(shell pkg-config libpng --libs)

endian:
	gcc endian.c
	./a.out
clz:
	gcc clz.c
	./a.out

gray: rgba.c
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^ -DOUTPUT=\"gray.png\" $(PNGLIBS)
	./gray && display gray.png

clean:
	rm -r gray gray.png
