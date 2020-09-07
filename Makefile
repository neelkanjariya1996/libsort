make:
	gcc ./lib/merge_sort.c ./lib/heap_sort.c ./test/test.c -o output
clean:
	rm -rf output
