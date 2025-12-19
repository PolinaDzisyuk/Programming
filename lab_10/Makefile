CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -O2
LDFLAGS = -lm
TARGET = triangle

SRCS = lb10.c lb_10_func.c
OBJS = $(SRCS:.c=.o)
HEADERS = lb10.h

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET) $(LDFLAGS)
%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)

rebuild: clean all

run: $(TARGET)
	./$(TARGET)

.PHONY: all clean rebuild run