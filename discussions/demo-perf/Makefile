all: sum sum_nt

sum: sum.c
	gcc -o sum ./sum.c

sum_nt: sum_nt.c
	gcc -o sum_nt ./sum_nt.c -pthread

clean:
	rm -rf sum_nt
	rm -rf sum
