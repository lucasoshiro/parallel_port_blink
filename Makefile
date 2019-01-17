.PHONY: all
all: led

led: led.c
	gcc $^ -Wall -O2 -o $@
