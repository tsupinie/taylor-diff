
OBJS = test.o

LIBDIR = $(ROOTDIR)/lib
BINDIR = $(ROOTDIR)/bin

.c.o:
	gcc -c $<

all: lib objs
	-mkdir $(BINDIR)
	gcc -o $(BINDIR)/test $(OBJS) -L$(ROOTDIR)/lib -ltaylor -lm
	$(BINDIR)/test

clean:
	rm $(BINDIR)/test
	rm $(OBJS)

objs: $(OBJS)

lib:
	cd $(ROOTDIR)/src; make
