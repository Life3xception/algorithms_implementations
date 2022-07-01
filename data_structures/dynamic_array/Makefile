CFLAGS				= -g -O1 -Wall -Wextra -Wpedantic -Wconversion
COMMON_DEPS			= dynamic_array.h Makefile
UNITY_BIN			= ../../lib/unity.o

# rule to make file for testing and finally runs tests
run_tests: tests
	./bin/dynamic_array_tests

create_dir: 
	mkdir -p bin
	mkdir -p build

# rule to make file for testing
tests: create_dir bin/dynamic_array_tests

build/%.o: %.c $(COMMON_DEPS)
	$(CC) $(CFLAGS) -c $< -o $@

bin/dynamic_array_tests: build/dynamic_array_tests.o build/dynamic_array.o $(UNITY_BIN) $(COMMON_DEPS)
	$(CC) -o bin/dynamic_array_tests build/dynamic_array_tests.o $(UNITY_BIN) build/dynamic_array.o

clean:
	$(RM) bin/*
	$(RM) build/*
