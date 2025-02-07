# Compilation et édition des liens
CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra
SANITIZE_FLAGS = -fsanitize=address -g

# Target
TARGET = analog

# Fichiers sources
SRCS = main.cpp Lecture.cpp Statistiques.cpp Traitement.cpp
HDRS = Lecture.h Statistiques.h Traitement.h

# Fichiers objets
OBJS = $(SRCS:.cpp=.o)

# Target par défaut
all: $(TARGET)

# Compilation
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $^

# Compilation avec fsanitize (équivalent de valgrind pour macOS)
sanitize: CXXFLAGS += $(SANITIZE_FLAGS)
sanitize: $(TARGET)

# Clean le projet
clean:
	rm -f $(TARGET) $(OBJS)
	rm -f *.dot

# Dépendances
%.o: %.cpp $(HDRS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

.PHONY: all sanitize clean