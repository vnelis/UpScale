
OBJS = die.o xcalloc.o xmalloc.o xrealloc.o xstrdup.o

all: libcc.a

libcc.a: $(OBJS)
	ar r $@ $?

uninstall install:

clean:
	rm -f *.o *.a
