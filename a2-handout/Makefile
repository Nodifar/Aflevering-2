CFLAGS?=-std=c99 -Wall -Wextra -pedantic
CC?=cc

# The backslashes are for line continuation, so we can have a program per line.
PROGRAMS= \
	uint_le_to_uint_ascii \
	uint_be_to_uint_ascii \
	uint_le_to_uint_be \
	uint_be_to_uint_le \
	uint_ascii_to_uint_le \
	uint_ascii_to_uint_be \
	uint_ascii_to_uint_ascii \
	double_bin_to_double_ascii \
	double_ascii_to_double_ascii \
	double_ascii_to_double_bin \
	uint_le_to_double_bin \
	avg_doubles \
	test_numlib

all: numlib.o $(PROGRAMS)

numlib.o: numlib.c
	$(CC) -c $< -o $@ $(CFLAGS)

%: %.c numlib.o
	$(CC) $< numlib.o -o $@ $(CFLAGS)

clean:
	rm -f $(PROGRAMS) numlib.o