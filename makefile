ODIR=./build/objs
BDIR=./build/bin

IDIR=./src
SDIR=./src

CPP=clang++
LINK=clang++
DFLAGS=-g -O0 -fsanitize=undefined,address
RFLAGS=-O3
CFLAGS=-I$(IDIR) -Wall $(RFLAGS)
LIBS=-lSDL2

_SRC=$(wildcard $(SDIR)/*/*.cpp) $(wildcard $(SDIR)/*.cpp)
OBJ=$(patsubst $(SDIR)/%.cpp,$(ODIR)/%.o,$(_SRC))

DEPS=$(wildcard $(IDIR)/*/*.h) $(wildcard $(IDIR)/*.h)

_BIN=calc
BIN=$(patsubst %,$(BDIR)/%,$(_BIN))

.PHONY: all
all: $(BIN) 

.PHONY: install
install: all
	cp $(BIN) /usr/bin/

$(BDIR)/calc: $(OBJ)
	mkdir -p `dirname $@`
	$(LINK) $(CFLAGS) -o $@ $^ $(LIBS)

$(ODIR)/%.o: $(SDIR)/%.cpp $(DEPS)
	mkdir -p `dirname $@`
	$(CPP) $(CFLAGS) -c -o $@ $<
	
.PHONY: check
check: all
	bash ./test/run-test.sh ./test/tests/
	
.PHONY: clean
clean:
	rm -fr $(ODIR)/*

.PHONY: cleanall
cleanall:
	rm -fr $(ODIR)/* $(BDIR)/*

