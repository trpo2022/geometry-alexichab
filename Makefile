CFLAGS = -Wall -Wextra -Werror
CPPFLAGS = -I sorce -MMD
DIR_GUARD = @mkdir -p $(@D)

all: bin/geometry

-include obj/inputread.d obj/circle.d obj/point.d obj/triangle.d obj/main.d

bin/geometry: obj/inputread.o obj/circle.o obj/point.o obj/triangle.o obj/main.o obj/library.a
	$(DIR_GUARD)
	gcc $(CFLAGS) $(CPPFLAGS) -o $@ $^ -lm

obj/library.a: obj/circle.o obj/point.o obj/triangle.o
	ar rcs $@ $^

obj/inputread.o: sorce/geometry/inputread.c
	$(DIR_GUARD)
	gcc $(CFLAGS) $(CPPFLAGS) -c -o $@ $<

obj/circle.o: sorce/library/circle.c
	gcc $(CFLAGS) $(CPPFLAGS) -c -o $@ $<

obj/point.o: sorce/library/point.c
	gcc $(CFLAGS) $(CPPFLAGS) -c -o $@ $<

obj/triangle.o: sorce/library/triangle.c
	gcc $(CFLAGS) $(CPPFLAGS) -c -o $@ $<

obj/main.o: sorce/geometry/main.c
	gcc $(CFLAGS) $(CPPFLAGS) -c -o $@ $<

clean:
	rm bin/* obj/*
