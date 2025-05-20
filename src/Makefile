CC = g++
CFLAGS = -Wall -Werror -Wextra -std=c++17 -pedantic
TARGET = notebook
OBJECTS = notebook.o menu.o

# default target builds the executable
all: $(TARGET)

# link object files into the executable
$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^

# compile notebook.cpp into notebook.o
notebook.o: notebook.cpp notebook.h
	$(CC) $(CFLAGS) -c notebook.cpp

# complile menu.cpp into notebook.o
menu.o: menu.cpp notebook.h
	$(CC) $(CFLAGS) -c menu.cpp

# clean up object files and executables
clean:
	rm -rf $(TARGET) $(OBJECTS)

.PHONY: all clean