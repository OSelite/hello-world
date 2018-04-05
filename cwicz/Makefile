.PHONY: clean

program: thebeatles.o libjp.a libgr.so
	gcc -o program thebeatles.o libjp.a libgr.so

program.o: thebeatles.c
	gcc -c thebeatles.c
	
pj.o: pj.c
	gcc -c pj.c
	
pp.o: pp.c
	gcc -c pp.c
	
libjp.a: pj.o pp.o
	ar rs  libjp.a pj.o pp.o
	
pg.o: pg.c
	gcc -fPIC -c pg.c
	
pr.o: pr.c
	gcc -fPIC -c pr.c
	
libgr.so: pg.o pr.o
	gcc -shared -o libgr.so pg.o pr.o
	
clean:
	- rm program *.o *.a *.so
