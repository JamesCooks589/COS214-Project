# Define the C++ compiler
CXX = g++

# Compiler flags
CXXFLAGS = -std=c++17 -Wall

# Source files
SRC_FILES = $(wildcard *.cpp)

# Object files
OBJ_FILES = $(SRC_FILES:.cpp=.o)

# Target executable
TARGET = myprogram

all: $(TARGET)

$(TARGET): $(OBJ_FILES)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJ_FILES)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

run: all
	./$(TARGET)

clean:
	rm -f $(OBJ_FILES) $(TARGET)
