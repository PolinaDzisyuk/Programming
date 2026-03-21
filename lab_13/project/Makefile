.PHONY: all clean rebuild run

TARGET = book
CC = gcc
CFLAGS = -Wall -Wextra
LDFLAGS = -L. -lMY_BOOK
RPATH = -Wl,-rpath,.

all: $(TARGET)

libMY_BOOK.so: book_func.o
	$(CC) -shared book_func.o -o libMY_BOOK.so
main.o: src/main.c include/book.h
	$(CC) -c src/main.c -o main.o -I ./include
book_func.o: src/book_func.c include/book.h
	$(CC) -c src/book_func.c -o book_func.o -I ./include -fPIC

book: main.o libMY_BOOK.so
	$(CC) main.o -o $(TARGET) $(LDFLAGS) -lMY_BOOK $(RPATH)

clean:
	rm -rf *o $(TARGET) libMY_BOOK.so

rebuild: clean all

run: $(TARGET)
	./$(TARGET)