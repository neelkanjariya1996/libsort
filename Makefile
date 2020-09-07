make:
	gcc -c -Werror -fpic ./lib/merge_sort.c ./lib/heap_sort.c
	gcc -shared -o libsort.so merge_sort.o heap_sort.o
	unset LD_LIBRARY_PATH
	gcc -L${CURDIR} -Wl,-rpath=${CURDIR} -o run_test ./test/test.c -lsort
clean:
	rm -rf run_test
	rm -rf merge_sort.o
	rm -rf heap_sort.o
	rm -rf libsort.so
