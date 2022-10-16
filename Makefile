PROGRAM=ilogxi
CC  ?= gcc
CXX ?= g++
RM ?= rm
PREFIX ?= /usr/local
INCLUDEDIR ?= include
CFLAGS ?= -std=gnu2x -march=native -mfpmath=sse+387 -O2 -pipe
CXXFLAGS ?= -std=gnu++23 -march=native -mfpmath=sse+387 -O2 -pipe
INSTALL = install

all: $(PROGRAM)

ilogxi: test.c
	$(CXX) $(CXXFLAGS) test.c -o $(PROGRAM)-test-cpp$(EXECUTABLE_EXT)
	$(CC) $(CFLAGS) test.c -o $(PROGRAM)-test-c$(EXECUTABLE_EXT)
clean:
	$(RM) -rf $(PROGRAM)-*$(EXECUTABLE_EXT)

install: $(PROGRAM)
	$(INSTALL) -d $(PREFIX)/$(INCLUDEDIR)/$(PROGRAM)

uninstall: $(PROGRAM)
	$(RM) -rf $(PREFIX)/$(INCLUDEDIR)/$(PROGRAM)

