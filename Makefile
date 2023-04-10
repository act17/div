OBJS = src/main.c src/tarot/gematria.c src/tarot/tarotgen.c src/tarot/tarotprint.c
CFLAG = -Wall -Werror -Wpedantic
CC = gcc
INCLUDE =
LIBS =
# Formatting Options
FM = astyle
FFLAG = -s2 -n


div:${OBJ}
	${CC} ${CFLAG} ${INCLUDES} -o $@ ${OBJS} ${LIBS}

format:${OBJ}
	${FM} ${OBJS} ${FFLAG}
clean:
	rm div
