
ROOTDIR = $(shell pwd)

all:
	cd src; make ROOTDIR=$(ROOTDIR)

test:
	cd src/test; make ROOTDIR=$(ROOTDIR)

clean:
	cd src; make clean ROOTDIR=$(ROOTDIR)
	cd src/test; make clean ROOTDIR=$(ROOTDIR)
