
all: cpu mem threads io

clean:
	rm -f cpu mem threadsv0 threadsv1 io

cpu: cpu.c common.h
	gcc -o cpu cpu.c -Wall

mem: mem.c common.h
	gcc -o mem mem.c -Wall

threads: threads.v1.c threads.v0.c common.h common_threads.h
	gcc -o threadsv0 threads.v0.c -Wall -pthread
	gcc -o threadsv1 threads.v1.c -Wall -pthread

io: io.c common.h
	gcc -o io io.c -Wall

