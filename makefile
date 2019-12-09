# Author: Tyler Betley
# Date: 11/24/19
# Makefile for CS162 Final Project - Dark Labarinth

CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g

OBJS = main.o input.o menu.o game.o player.o space.o floor.o barrier.o monster.o escape.o item.o gun.o candle.o key.o
SRCS = main.cpp input.cpp menu.cpp game.cpp player.cpp space.cpp floor.cpp barrier.cpp monster.cpp escape.cpp item.cpp gun.cpp candle.cpp key.cpp
HEADERS = input.hpp menu.hpp game.hpp player.hpp space.hpp floor.hpp barrier.hpp monster.hpp escape.hpp item.hpp gun.hpp candle.hpp key.hpp


finalProject: ${OBJS} ${HEADERS}
	${CXX} ${OBJS} -o finalProject

# target: object files

${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

clean:
	rm *.o finalProject

zip: 
	zip -D FinalProject_Betley_Tyler.zip ${HEADERS} ${SRCS} makefile Design_Document.pdf
