#include "structures.h"
#include <fstream>


int main() {
	//write 100 random numbers to a text file
	std::ofstream fin("nums.txt");
	for (int i = 0; i < 100; i++) {

		fin << (rand() % 450) + 50 << "\n";
	}
	fin.close();

	//read the numbers and write them to a minHeap
	minHeap h(100);
	int a;

	std::ifstream fout("nums.txt");
	for (int i = 0; i < 100; i++) {
		fout >> a;
		h.add(a);
	}
	fout.close();
	h.print();

	//delete 10 numbers from the top of the min minHeap
	for (int i = 0; i < 10; i++) {
		h.del(0);
	}
	h.print();



	std::cin.get();
}
