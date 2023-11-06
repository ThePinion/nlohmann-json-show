CXX = clang++
CXXFLAGS = -std=c++11 -Iinclude
SOURCES = $(wildcard src/*.cpp)
OBJECTS = $(SOURCES:src/%.cpp=build/%)
EXEC = $(OBJECTS:build/%=build/%.out)

all: $(EXEC)

build/%.out: src/%.cpp
	$(CXX) $(CXXFLAGS) -o $@ $<

clean:
	rm -f build/*

.PHONY: all clean
