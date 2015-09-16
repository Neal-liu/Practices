CFLAGS = -Wall -Werror -std=gnu99 -O0 -g
LDFLAGS = `pkg-config --libs --cflags libpng`
PNGLIBS := $(shell pkg-config libpng --libs)

bit:
	gcc BIT.c
	./a.out

rotateimg:
	gcc RotateImg.c
	./a.out

palindrome:
	gcc palindrome.c
	./a.out

reverse:
	gcc reverse.c
	./a.out

endian:
	gcc endian.c
	./a.out
clz:
	gcc clz.c
	./a.out

gray: rgba.c
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^ -DOUTPUT=\"gray.png\" $(PNGLIBS)
	./gray && display gray.png

level: level.c
	gcc level.c
	./a.out 10

malloc: malloc0.c
	gcc malloc0.c
	./a.out

bubblesort: bubblesort.c
	gcc bubblesort.c
	./a.out

trailing: trailingZero.c
	gcc trailingZero.c
	./a.out

add: add.c
	gcc add.c
	./a.out

test: test.c
	gcc test.c
	./a.out

stair: stairs.c
	gcc stairs.c
	./a.out

isMultipleOf3: 
	gcc isMultipleOf3.c
	./a.out

findMiddleNode:
	gcc findMiddleNode.c
	./a.out

insertSort:
	gcc insertSort.c
	./a.out

heapSort:
	gcc heapSort.c
	./a.out

binarySearch:
	gcc binarySearch.c
	./a.out

selectionSort:
	gcc selectionSort.c
	./a.out

itoa:
	gcc itoa.c
	./a.out

clean:
	rm -r gray gray.png
