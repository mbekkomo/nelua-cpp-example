CXX= c++
CXXFLAGS= -W -Wall -g -fPIC -shared
NELUA= nelua
NELUACFLAGS= ./$(O_FILE)
NELUAFLAGS= --cflags="$(NELUACFLAGS)"

ifeq ($(shell uname),Darwin)
	EXT= dylib
else
	EXT= so
endif

O_FILE= libhello.$(EXT)

$(O_FILE):
	$(CXX) $(CXXFLAGS) hello.cpp -o $(O_FILE)

build: $(O_FILE)
	$(NELUA) $(NELUAFLAGS) hello.nelua

all: build

# vim: set noexpandtab autoindent ts=4 sw=4:
