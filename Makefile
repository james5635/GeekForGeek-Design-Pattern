CXX := g++
CXXFLAGS := -Wall -Wextra -std=c++23 $(shell pkgconf --cflags fmt)
LDFLAGS := $(shell pkgconf --libs fmt)
SRC := FactoryMethod.cpp AbstractFactory.cpp Singleton.cpp Prototype.cpp Builder.cpp Builder_Pizza.cpp Adapter.cpp Bridge.cpp \
		Composite.cpp Composite_Wikipedia.cpp Composite_ProgrammingLanguage.cpp Decorator.cpp Decorator_Wikipedia.cpp \
		Facade.cpp Facade_Wikipedia.cpp AbstractFactory_Wikipedia.cpp Flyweight.cpp Flyweight_Guru.cpp Flyweight_Wikipedia.cpp \
		Proxy.cpp Proxy_Guru.cpp Chain_Of_Responsibility.cpp Chain_Of_Responsibility_Wikipedia.cpp
OUT_DIR := ./out
BINARIES := $(patsubst %.cpp, $(OUT_DIR)/%, $(SRC))

all: bin uml

bin: $(BINARIES) 

$(OUT_DIR)/%: %.cpp | $(OUT_DIR)
	$(CXX) $(CXXFLAGS) -o $@ $< $(LDFLAGS)

$(OUT_DIR):
	mkdir -p $(OUT_DIR)
# compatible with plantuml version 2020
uml:
	plantuml ./UML/*.puml
uml-clean:
	rm -f ./UML/*.png
bin-clean: 
	rm -rf $(OUT_DIR)
clean: bin-clean uml-clean
.PHONY: all clean
