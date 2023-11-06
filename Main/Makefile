CXX = g++
CXXFLAGS = -std=c++11 -Wall

TARGET = main
SRC = $(wildcard *.cpp)
OBJ = $(SRC:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJ)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

lint: compile_commands.json
	clang-tidy -p . $(SRC) -- -std=c++11

compile_commands.json:
	bear make

clean:
	rm -f $(OBJ) $(TARGET) compile_commands.json

run:
	./$(TARGET)
