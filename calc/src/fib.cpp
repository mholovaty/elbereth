#include <iostream>
#include <cassert>


int fib1(int n) {
	if (n == 0)
		return 0;
	if (n == 1)
		return 1;
	if (n == 2)
		return 1;

	return fib1(n - 1) + fib1(n - 2);
};


int fib_iter(int n1, int n2, int c, int max) {
	if (c > max)
		return n1;

	return fib_iter((n1 + n2), n1, (c + 1), max);
}


int fib2(int n) {
	if (n == 0)
		return 0;
	if (n == 1)
		return 1;

	return fib_iter(1, 0, 2, n);
}


int fib3(int n) {
	return 0;
}


int main(void) {

	assert(fib1(3) == 2);
	assert(fib2(3) == 2);
	assert(fib1(10) == 55);
	assert(fib2(10) == 55);

	std::cout<< "OK" << std::endl;
}
