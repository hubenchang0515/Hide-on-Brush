libHB.a: brush.o
	ar rc libHB.a brush.o

brush.o: brush.c brush.h
	gcc -c brush.c -O2

install: libHB.a
	mkdir -p /usr/local/include/HB
	cp brush.h /usr/local/include/HB/brush.h
	cp libHB.a /usr/local/lib/libHB.a
