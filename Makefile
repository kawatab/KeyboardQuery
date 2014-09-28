CC = g++
CFLAGS = -Wall -O2
LOADLIBES = -lX11 -lxkbfile
OBJS = keyboardquery_test.o keyboardquery.o

keyboardquery_test: $(OBJS)


clean:
	rm -f $(OBJS)
