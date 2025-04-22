CC = gcc
CFLAGS = -Wall -Iinclude/
LDFLAGS = -lraylib -lGL -lm -lpthread -ldl -lrt -lX11

TARGET = main
SRCS = $(wildcard *.c)
OBJS = $(SRCS:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS) $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(TARGET) $(OBJS)
