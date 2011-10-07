# +AMDG
#
# This document was begun on 13 January 2009, the
# commemoration of the Baptism of Our Lord, and it is humbly
# dedicated to the Immaculate Heart of Mary for her prayers,
# and to the Sacred Heart of Jesus for His mercy.
#
# Makefile for the decimal to dozenal converter.

dozdate: main.o conv.h conv.o doz.o dec.o
	gcc -g -lm -o dozdate main.o conv.o doz.o dec.o

main.o : conv.h main.c conv.o doz.o
	gcc -g -lm -c main.c

doz.o : conv.o conv.h doz.c
	gcc -g -std=c99 -lm -c doz.c

dec.o : conv.o conv.h dec.c
	gcc -g -c dec.c

conv.o : conv.c conv.h
	gcc -g -lm -c conv.c

doc : doz.1
	rman -fHTML dozdate.1 > dozdate_man.html

prefix = /usr/local
bindir = /usr/local/bin
mandir = /usr/local/share/man/man1

install : dozdatedoz.1
	cp ./dozdate $(bindir)
	cp ./dozdate.1 $(mandir)

uninstall :
	rm $(bindir)/dozdate
	rm $(mandir)/dozdate.1