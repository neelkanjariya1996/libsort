make:
	gcc merge_sort.c heap_sort.c test.c -o output
clean:
	rm -rf output
