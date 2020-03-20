CC = g++
CFLAGS = -g -Wall

SRC = test_$(src).cpp
PROG = test_$(src).exe

OPENCV = `pkg-config opencv --cflags --libs`
LIBS = $(OPENCV)

.PHONY: all clean

$(PROG):$(SRCS)
	$(CC) $(CFLAGS) -o $(PROG) $(SRC) $(LIBS)

all: $(PROG)

clean:
	rm -f $(OBJS) $(PROG) *.exe