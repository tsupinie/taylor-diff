
LIBDIR = $(ROOTDIR)/lib

LIBNAME = libtaylor
CFLAGS = -fPIC
OBJS = taylor.o

.c.o:
	gcc $(CFLAGS) -c $<

all: $(OBJS)
	-mkdir $(LIBDIR)
	ar rcs $(LIBDIR)/$(LIBNAME).a $(OBJS)
	gcc -shared -o $(LIBDIR)/$(LIBNAME).so $(OBJS)

clean:
	rm -f $(LIBDIR)/$(LIBNAME).a $(LIBDIR)/$(LIBNAME).so
	rm -f $(OBJS)
