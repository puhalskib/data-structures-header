#include <iostream>
#include "structures.h"

using std::cout;
using std::cin;

int main() {
	int* a;
	{

		a = new int[4];
		a[2] = 2;
		a[0] = 1;
		a[1] = 7;
	}
	std::cout << a[2] << ", " << a[0] << "\n";




	/*
	minHeap h(5);

	h.set(0, 4);
	h.set(1, 5);
	h.set(2, 7);
	std::cout << h.get(0) << ", " << h.get(1) << "\n";


	*/





	cin.get();
}