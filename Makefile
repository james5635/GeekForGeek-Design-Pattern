CXX := g++
CXXFLAGS := -Wall -Wextra -std=c++23 $(shell pkgconf --cflags fmt)
LDFLAGS := $(shell pkgconf --libs fmt)
SRC := FactoryMethod.cpp AbstractFactory.cpp Singleton.cpp Prototype.cpp Builder.cpp Builder_Pizza.cpp Adapter.cpp Bridge.cpp \
		Composite.cpp Composite_Wikipedia.cpp Composite_ProgrammingLanguage.cpp Decorator.cpp Decorator_Wikipedia.cpp \
		Facade.cpp Facade_Wikipedia.cpp AbstractFactory_Wikipedia.cpp
OUT_DIR := ./out
BINARIES := $(patsubst %.cpp, $(OUT_DIR)/%, $(SRC))

all: $(BINARIES) uml

$(OUT_DIR)/%: %.cpp | $(OUT_DIR)
	$(CXX) $(CXXFLAGS) -o $@ $< $(LDFLAGS)

$(OUT_DIR):
	mkdir -p $(OUT_DIR)
uml:
	# compatible with plantuml version 2020
	plantuml ./UML/*.puml
uml-clean:
	rm -f ./UML/*.png
clean: uml-clean
	rm -rf $(OUT_DIR)

.PHONY: all clean
