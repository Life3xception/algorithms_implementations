linear_search_it: linear_search_it.c
	$(CC) linear_search_it.c -o linear_search_it

linear_search_rec: linear_search_rec.c
	$(CC) linear_search_rec.c -o linear_search_rec

clean: 
	$(RM) linear_search_it
	$(RM) linear_search_rec

run_iterative: clean linear_search_it
	./linear_search_it

run_recursive: clean linear_search_rec
	./linear_search_rec