SOURCES=$(wildcard src/*.cpp)
OBJECTS=$(patsubst %.cpp,%.o,$(SOURCES))

TEST_SOURCES=$(wildcard test/*.cpp)
TEST_OBJECTS=$(patsubst %.cpp,%.o,$(TEST_SOURCES))

LOG=$(wildcard *.txt)

APPS=$(wildcard *.out)

LDFLAGS= -std=c++11 -Wall

all: $(OBJECTS) $(TEST_OBJECTS)
	g++ -o $@ $^ $(LDFLAGS)

source: $(OBJECTS)
	g++ $(LDFLAGS) -o $@ $^ 

tests: $(TEST_OBJECTS)
	g++ $(LDFLAGS) -o $@ $^ 

.PHONY: clean
clean:
	rm -f $(OBJECTS) $(TEST_OBJECTS) $(LOG) source tests