CXX = g++
CXXFLAGS = -Wall -pedantic -MMD --std=c++03

SRC = ${shell find src -name '*.cc'}
OBJ = ${SRC:.cc=.o}
DEP = ${OBJ:.o=.d}

MAIN = bin/cc3k

build: ${SRC} ${MAIN}

debug: CXXFLAGS += -DDEBUG -g
debug: ${MAIN}

${MAIN}: ${OBJ}
	${CXX} ${CFLAGS} ${OBJ} -o $@

-include ${DEP}

.PHONY: run memcheck test clean

run: ${MAIN}
	./${MAIN}

memcheck: ${MAIN}
	valgrind --leak-check=full ./${MAIN}

test: ${MAIN}
	runSuite ./${MAIN}

clean:
	${RM} ${DEP} ${OBJ} ${MAIN}
