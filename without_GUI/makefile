CC	= g++
CFLAGS	= -std=c++11 -Wall
LDFLAGS	=

LIBS	= QAM_lib asciichart

SOURCES	= main.cpp \
			$(foreach lib,$(LIBS),$(shell find ../$(lib) -type f -name "*.cpp"))
# Пути к заголовочным файлам
HEADERS	= $(shell find ../$(LIBS) -type f -name "*.h" -exec dirname {} \; | sort | uniq)

SRCDIR	= .
BINDIR	= .


TARGET	= YADRO_test_task

$(TARGET): $(SOURCES) $(HEADERS)
	$(CC) $(CFLAGS) $(LDFLAGS) -I$(HEADERS) -o $(BINDIR)/$(TARGET) $(SOURCES)
	chmod +x $(BINDIR)/$(TARGET)
	
.PHONY: clean all debug echo_files

echo_files:
	@echo $(SOURCES) $(HEADERS)

debug:
	$(CC) $(CFLAGS) $(LDFLAGS)  -I$(HEADERS) -o $(BINDIR)/$(TARGET) $(SOURCES) -DDEBUG
	chmod +x $(BINDIR)/$(TARGET)

all: $(TARGET)

clean:
	rm -f $(BINDIR)/$(TARGET)
