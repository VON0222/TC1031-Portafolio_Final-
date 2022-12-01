// =================================================================
//
// File: main.cpp
// Authors: Daniel Emilio Fuentes Portaluppi - A01708302
//          José Diego Llaca Castro - A01704793
//			Ivan Ricardo Paredes Aviles - A01705083
//
// Date: 21/11/2022
//
// =================================================================
#include <iostream>
#include <fstream>
#include "heap.h"

int main(int argc, char* argv[]) {
	
	std::ifstream input;
	std::ofstream output;

	if (argc != 3) {
		std::cout << "Usage: " << argv[0] << " <input_file> <output_file>" << std::endl;
		return -1;
	}

	input.open(argv[1]);
	if (input.fail()) {
		std::cout << "Error: could not open file " << argv[1] << std::endl;
		return -1;
	}

	output.open(argv[2]);
	if (output.fail()) {
		std::cout << "Error: could not open file " << argv[2] << std::endl;
		return -1;
	}

	int n, e;
	input >> n;

	MinHeap<int> heap;
	for (int i = 0; i < n; i++) {
		input >> e;
		heap.push(e);
	}

	int k = 0;
	int sum;
	while (heap.size() > 1) {
		sum = heap.pop() + heap.pop();
		heap.push(sum);
		k += sum - 1;
	}
	output << k << std::endl;

	return 0;
}
