all: cppcheck compile run

cppcheck:
	cppcheck --enable=all --suppress=missingIncludeSystem --check-config .

compile:
	@echo "--------------------------------------------------------------------------";
	g++ main.cpp -o main.out -Wall -Wextra -Wshadow -Wpedantic

run:
	@echo "--------------------------------------------------------------------------";
	./main.out