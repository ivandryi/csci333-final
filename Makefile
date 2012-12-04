CC = g++
CFLAGS = -Wall -Wextra -Werror

niceNaughtyList: niceNaughtyList.cpp
	$(CC) $(CFLAGS) -o niceNaughtyList niceNaughtyList.cpp

clean:
	rm -f *~
	rm -f niceNaughtyList
	rm -f *.o