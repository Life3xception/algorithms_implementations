CFLAGS				= -g -O1 -Wall -Wextra -Wpedantic -Wconversion
COMMON_DEPS			= list.h Makefile
UNITY_BIN			= ../../lib/unity.o

# rule to make file for testing and finally runs tests
run_tests: tests
	./bin/list_tests

create_dir: 
	mkdir -p bin
	mkdir -p build

# rule to make file for testing
tests: create_dir bin/list_tests

build/%.o: %.c $(COMMON_DEPS)
	$(CC) $(CFLAGS) -c $< -o $@

bin/list_tests: build/list_tests.o build/list.o $(UNITY_BIN) $(COMMON_DEPS)
	$(CC) -o bin/list_tests build/list_tests.o $(UNITY_BIN) build/list.o

clean:
	$(RM) bin/*
	$(RM) build/*
