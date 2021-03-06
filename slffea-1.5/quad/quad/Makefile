# SLFFEA Makefile
# Version:  1.5
# Copyright (C) 1999, 2000  San Le (slffea@yahoo.com)
# http://slffea.com/
#
# This library is free software; you can redistribute it and/or
# modify it under the terms of the GNU Library General Public
# License as published by the Free Software Foundation; either
# version 2 of the License, or (at your option) any later version.
#
# This library is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
# Library General Public License for more details.
#
# You should have received a copy of the GNU Library General Public
# License along with this library; if not, write to the Free
# Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.

#May work on Sun
#C = /usr/lang/gcc  -g

#Dubugging Compile for Linux
CC = /usr/bin/gcc  -g

#Optimization Compile for Linux
#CC = /usr/bin/gcc  -O3

LIBS = -lm
COMMON = ../../common
OBJECTS = $(COMMON)/matxt.o $(COMMON)/matx.o $(COMMON)/dotx.o \
	$(COMMON)/lm.o $(COMMON)/idiag.o $(COMMON)/kasmbl.o \
	$(COMMON)/sky.o $(COMMON)/qr.o $(COMMON)/eigen.o \
	$(COMMON)/eigenprint.o $(COMMON)/crossx.o \
	$(COMMON)/rotate2.o $(COMMON)/rotate3.o $(COMMON)/local_vec.o

PROGS = qd qdp

all: qd qdp

qd: femqd.o \
		memory.o \
		qdreader.o \
		id.o \
		qdshape.o \
		quadb.o \
		qdkasmbl.o\
		qdconj.o\
		bound.o \
		qdstress.o\
		qdmasmbl.o\
		qdlanczos.o\
		qdmassp.o\
		qdwriter.o\
		qdarea.o\
		qdconst.h \
		qdstruct.h
	$(CC) -o qd femqd.o \
		memory.o \
		qdreader.o \
		id.o \
		qdshape.o \
		quadb.o \
		qdkasmbl.o\
		qdconj.o\
		bound.o \
		qdstress.o\
		qdmasmbl.o\
		qdlanczos.o\
		qdmassp.o\
		qdwriter.o \
		qdarea.o $(OBJECTS) $(LIBS)

qdp: qdp.o \
		qdpatch.o
	$(CC) -o qdp qdpatch.o $(LIBS) 

qdp.o: qdpatch.c
	$(CC) -c qdpatch.c

qdarea.o: qdarea.c
	$(CC) -c qdarea.c 

qdwriter.o: qdwriter.c
	$(CC) -c qdwriter.c 

qdmassp.o: qdmassp.c
	$(CC) -c qdmassp.c 

qdlanczos.o: qdlanczos.c
	$(CC) -c qdlanczos.c 

qdmasmbl.o: qdmasmbl.c
	$(CC) -c qdmasmbl.c 

qdstress.o: qdstress.c
	$(CC) -c qdstress.c

bound.o: $(COMMON)/bound.c
	$(CC) -c $(COMMON)/bound.c -DQUAD1

qdconj.o: qdconj.c
	$(CC) -c qdconj.c

qdkasmbl.o: qdkasmbl.c
	$(CC) -c qdkasmbl.c

quadb.o: quadb.c
	$(CC) -c quadb.c 

qdshape.o: qdshape.c
	$(CC) -c qdshape.c 

id.o: $(COMMON)/id.c
	$(CC) -c $(COMMON)/id.c -DQUAD1

qdreader.o: qdreader.c
	$(CC) -c qdreader.c

memory.o: $(COMMON)/memory.c
	$(CC) -c $(COMMON)/memory.c -DQUAD1

femqd.o: femqd.c
	$(CC) -c femqd.c

clean:
	-rm *.o $(PROGS)
