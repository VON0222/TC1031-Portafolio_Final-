// =================================================================
//
// File: main.cpp
// Author:
// Date:
//
// =================================================================
#include <iostream>
#include <fstream>
#include <string>
#include <map>


int main(int argc, char* argv[]) {
	
	std::ifstream input;
	std::ofstream output;

	if (argc != 3)
	{
		std::cout << "Usage: " << argv[0] << " <input_file> <output_file>" << std::endl;
		return -1;
	}

	input.open(argv[1]);
	if (input.fail())
	{
		std::cout << "Error: could not open file " << argv[1] << std::endl;
		return -1;
	}

	output.open(argv[2]);
	if (output.fail())
	{
		std::cout << "Error: could not open file " << argv[2] << std::endl;
		return -1;
	}

	int n, m;

	input >> n >> m;

	std::map<std::string, int> map;

	for (int i = 0; i < n; i++)
	{
		std::string key;
		int value;

		input >> key >> value;
		map[key] = value;
	}

	for (int i = 0; i < m; i++)
	{
		std::string key;
		int value = 0;

		for (int j = 0; input>>key; j++)
		{
			if (key == ".")
				break;

			value += map[key];
		}

		output << value << std::endl;
	}

	input.close();
	output.close();
}

