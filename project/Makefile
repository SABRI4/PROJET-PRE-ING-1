CC = gcc
CFLAGS = -Wall -Wextra -O2

TARGET = Game

SOURCES = Game.c

HEADERS = Choice212.h Choice121.h Choice11.h Choice1.h Choice2.h FightEvent.h Functions.h Stat.h Programmefile.h

TEXT_DIR1 = F:\project\Histoire
TEXT_DIR2 = F:\project\stat

TEXT_FILES1 = $(wildcard $(TEXT_DIR1)/*.txt)
TEXT_FILES2 = $(wildcard $(TEXT_DIR2)/*.txt)

all: $(TARGET)

$(TARGET): $(SOURCES) $(HEADERS)
	$(CC) $(CFLAGS) -o $(TARGET) $(SOURCES) -DTEXT_DIR1=\"$(TEXT_DIR1)\" -DTEXT_DIR2=\"$(TEXT_DIR2)\"

.PHONY: copy_text_files
copy_text_files:
	for %%f in ($(TEXT_FILES1)) do powershell -Command "Copy-Item -Path '%%f' -Destination '.'"
	for %%f in ($(TEXT_FILES2)) do powershell -Command "Copy-Item -Path '%%f' -Destination '.'"

.PHONY: clean_text_files
clean_text_files:
	del /Q *.txt

.PHONY: clean_text_memory
clean_text_memory:
	for file in $(TEXT_FILES1); do del /Q "$$file"; done
	for file in $(TEXT_FILES2); do del /Q "$$file"; done

clean:
	del /Q $(TARGET) *.txt
