CC = gcc
CFLAGS = -I./libbloom -I./libbloom/murmur2 -I./zstd/lib -Werror -Wall -Wunused-variable
LDFLAGS = -L./libbloom/build -L./zstd/lib -Wl,-rpath,./libbloom/build:./zstd/lib -lbloom -lzstd
DEBUGFLAGS = -g -ggdb -O0

all: WizBloomZip

WizBloomZip: WizBloomZip.c
	$(CC) $(CFLAGS) -o $@ $< $(LDFLAGS)

debug: WizBloomZip.c
	$(CC) $(CFLAGS) $(DEBUGFLAGS) -o $@ $< $(LDFLAGS)

clean:
	rm -f WizBloomZip
	rm -rf debug
