CC = g++
CFLAGS = -Wall -Wextra -Werror

all: clean tweetsList niceNaughtyList

tweetsList: tweetsList.cpp
	$(CC) $(CFLAGS) -o tweetsList tweetsList.cpp

niceNaughtyList: niceNaughtyList.cpp
	$(CC) $(CFLAGS) -o niceNaughtyList niceNaughtyList.cpp

clean:
	rm -f *~
	rm -f niceNaughtyList
	rm -f tweetsList
	rm -f *.o