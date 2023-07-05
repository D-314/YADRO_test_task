CC = g++
CFLAGS = -std=c++11 -Wall
LDFLAGS =

SRCDIR = .
INCDIR = ../QAM_lib/inc
LIBDIR = ../QAM_lib
BINDIR = .

SOURCES = main.cpp \
          $(LIBDIR)/src/awgn.cpp \
          $(LIBDIR)/src/qamdemodulator.cpp \
          $(LIBDIR)/src/qammodulator.cpp

HEADERS = $(INCDIR)/awgn.h \
          $(INCDIR)/QAM.h \
          $(INCDIR)/qamdemodulator.h \
          $(INCDIR)/qammodulator.h

TARGET = YADRO_test_task

$(TARGET): $(SOURCES) $(HEADERS)
	$(CC) $(CFLAGS) $(LDFLAGS) -I$(INCDIR) -L$(LIBDIR) -o $(BINDIR)/$(TARGET) $(SOURCES)
	chmod +x $(BINDIR)/$(TARGET)

clean:
	rm -f $(BINDIR)/$(TARGET)
