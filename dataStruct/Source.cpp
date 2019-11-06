#include <iostream>
#include "structures.h"

using std::cout;
using std::cin;



int main() {
	
	
	minHeap h(8);
	int c;

	for (int i = 0; i < 8; i++) {
		cin >> c;
		h.add(c);
		h.print();
	}



	cin.get();
}