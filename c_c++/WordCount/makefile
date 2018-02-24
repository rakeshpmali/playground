# the compiler: gcc for C & g++ for C++
CC = g++

# compiler flags:
#  -g    adds debugging information to the executable file
#  -Wall turns on most, but not all, compiler warnings
CFLAGS  = -g -Wall -o

# the build target executable:
WCAPP = wordCountApp
SERVERAPP = serverApp
CPPEXT = .cpp
HEXT = .h

all:
	$(CC) $(CFLAGS) $(WCAPP) $(WCAPP)$(CPPEXT) -lpthread
	$(CC) $(CFLAGS) $(SERVERAPP) $(SERVERAPP)$(CPPEXT) -lpthread

clean:
	$(RM) $(WCAPP) $(SERVERAPP)

