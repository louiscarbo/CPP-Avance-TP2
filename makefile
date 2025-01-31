# Compiler and linker
CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra
SANITIZE_FLAGS = -fsanitize=address -g

# Target executable
TARGET = log

# Source files
SRCS = main.cpp Lecture.cpp Statistiques.cpp
HDRS = Lecture.h Statistiques.h Traitement.h

# Object files
OBJS = $(SRCS:.cpp=.o)

# Default target
all: $(TARGET)

# Build the project
log: $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $^

# Build the project with fsanitize
logS: CXXFLAGS += $(SANITIZE_FLAGS)
logS: $(TARGET)

# Clean the project
clean:
	rm -f $(TARGET) $(OBJS)

# Dependencies
%.o: %.cpp $(HDRS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

.PHONY: all log logS clean