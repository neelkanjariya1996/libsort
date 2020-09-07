make:
	gcc -c -Wall -Werror -fpic ./lib/merge_sort.c ./lib/heap_sort.c
	gcc -shared -o libsort.so merge_sort.o heap_sort.o
	unset LD_LIBRARY_PATH
	gcc -L/home/neel/Desktop/arrcus -Wl,-rpath=/home/neel/Desktop/arrcus -Wall -o output ./test/test.c -lsort
clean:
	rm -rf output
	rm -rf merge_sort.o
	rm -rf heap_sort.o
	rm -rf libsort.so
