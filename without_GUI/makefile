CC	= g++
CFLAGS	= -std=c++11 -Wall
LDFLAGS	=

LIBS	= ../QAM_lib asciichart/include

SOURCES	= main.cpp \
			$(foreach lib,$(LIBS),$(shell find $(lib) -type f -name "*.cpp"))

SRCDIR	= .
BINDIR	= .


TARGET	= YADRO_test_task

$(TARGET): $(SOURCES) $(HEADERS)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $(BINDIR)/$(TARGET) $(SOURCES)
	chmod +x $(BINDIR)/$(TARGET)
	
.PHONY: clean all debug echo_files run

run:
	 ./$(TARGET)

echo_files:
	@echo $(SOURCES) $(HEADERS)

debug:
	$(CC) $(CFLAGS) $(LDFLAGS) -o $(BINDIR)/$(TARGET) $(SOURCES) -DDEBUG
	chmod +x $(BINDIR)/$(TARGET)

all: $(TARGET)

clean:
	rm -f $(BINDIR)/$(TARGET)
