CC = gcc
CFLAGS = -Wall -Wextra -O2

# Nom de l'executable 
TARGET = Game

# Fichiers sources
SOURCES = Game.c

# Fichiers Header
HEADERS = Choice212.h Choice121.h Choice11.h Choice1.h Choice2.h FightEvent.h Functions.h Stat.h Programmefile.h

all: $(TARGET)

$(TARGET): $(SOURCES) $(HEADERS)
	$(CC) $(CFLAGS) -o $(TARGET) $(SOURCES)

clean:
	rm -f $(TARGET)

