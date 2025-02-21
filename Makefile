CXX := g++
CXXFLAGS := -Wall -Wextra -Werror -std=c++17
SRC := FactoryMethod.cpp AbstractFactory.cpp
OUT_DIR := ./out
BINARIES := $(patsubst %.cpp, $(OUT_DIR)/%, $(SRC))

all: $(BINARIES)

$(OUT_DIR)/%: %.cpp | $(OUT_DIR)
	$(CXX) $(CXXFLAGS) -o $@ $<

$(OUT_DIR):
	mkdir -p $(OUT_DIR)

clean:
	rm -rf $(OUT_DIR)

.PHONY: all clean
