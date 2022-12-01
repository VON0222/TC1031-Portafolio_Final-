// =================================================================
//
// File: main.cpp
// Author: Daniel Emilio Fuentes Portaluppi - A01708302
//         José Diego Llaca Castro - A01704793
//
// Date: 26/11/2022
//
// =================================================================
#include <iostream>
#include <fstream>
#include "graph.h"


int main(int argc, char *argv[])
{
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

	int n;
	std::string from, to;

	input >> n;

	Graph<std::string> graph;
	for(int i = 0; i < n; i++)
	{
		input >> from >> to;
		graph.addEdge(from, to);
	}

	int nQueries, depth;
	std::string start;

	input >> nQueries;
	
	for(int i = 0; i < nQueries; i++)
	{
		input >> start >> depth;
		std::set<std::string> result = graph.getNeighbors(start);
		result.insert(start);
		int currentDepth = 1;

		for(int i = 0; currentDepth < depth; i++)
		{
			std::set<std::string> aux;
			for(std::string vertex : result)
			{
				std::set<std::string> neighbors = graph.getNeighbors(vertex);
				aux.insert(neighbors.begin(), neighbors.end());
			}
			result.insert(aux.begin(), aux.end());
			currentDepth++;
		}

		output << "Case " << i + 1 << ": " << graph.graphSize() - result.size()
						<< " ports not reachable from port " << start << " with MNP = "
						<< depth << "." << std::endl;
	}

	return 0;
}