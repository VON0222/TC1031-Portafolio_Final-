// =================================================================
//
// Description: This file contains the definition of the class Graph
//              and the implementation of its methods.
//
// Author: Daniel Emilio Fuentes Portaluppi - A01708302
//         José Diego Llaca Castro - A01704793
//
// Date: 26/11/2022
//
// =================================================================

#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <map>
#include <string>
#include <sstream>
#include <set>

// =================================================================
// Class: Graph
// =================================================================
template <class T>
class Graph
{
private:
  std::vector<std::vector<bool> > gMatrix;
  std::vector<T> vertexes;

public:
  Graph() {};
  ~Graph() {};

  void addVertex(T);
  void addEdge(T, T);

  std::set<T> getNeighbors(T);
  int graphSize();

  std::string toString();
  
};

// =================================================================
// Add a vertex to the graph
//
// @complexity O(1)
// @param vertex Vertex to be added
// =================================================================
template <class T>
void Graph<T>::addVertex(T vertex)
{
  vertexes.push_back(vertex);
  for (int i = 0; i < gMatrix.size(); i++)
  {
    gMatrix[i].push_back(false);
  }
  std::vector<bool> temp;
  for (int i = 0; i < gMatrix.size() + 1; i++)
  {
    temp.push_back(false);
  }
  gMatrix.push_back(temp);
}

// =================================================================
// Add an edge to the graph
//
// @complexity O(n)
// @param vertex1 First vertex of the edge
// @param vertex2 Second vertex of the edge
// =================================================================
template <class T>
void Graph<T>::addEdge(T vertex1, T vertex2)
{
  int index1 = -1;
  int index2 = -1;
  for (int i = 0; i < vertexes.size(); i++)
  {
    if (vertexes[i] == vertex1)
      index1 = i;

    if (vertexes[i] == vertex2)
      index2 = i;
  }
  if (index1 == -1)
  {
    addVertex(vertex1);
    index1 = vertexes.size() - 1;
  }
  if (index2 == -1)
  {
    addVertex(vertex2);
    index2 = vertexes.size() - 1;
  }
  gMatrix[index1][index2] = true;
  gMatrix[index2][index1] = true;
}

// =================================================================
// Get the neighbors of a vertex
//
// @complexity O(n)
// @param vertex Vertex to get the neighbors of
// @return Set of neighbors
// =================================================================
template <class T>
std::set<T> Graph<T>::getNeighbors(T vertex)
{
  std::set<T> neighbors;
  int index = -1;
  for (int i = 0; i < vertexes.size(); i++)
  {
    if (vertexes[i] == vertex)
      index = i;
  }
  if (index == -1)
    return neighbors;

  for (int i = 0; i < gMatrix[index].size(); i++)
  {
    if (gMatrix[index][i])
      neighbors.insert(vertexes[i]);
  }
  return neighbors;
}

// =================================================================
// Get the number of vertexes in the graph
//
// @complexity O(1)
// @return Number of vertexes
// =================================================================
template <class T>
int Graph<T>::graphSize()
{
  return vertexes.size();
}

// =================================================================
// Get a string representation of the graph
//
// @complexity O(n^2)
// @return String representation of the graph
// =================================================================
template <class T>
std::string Graph<T>::toString()
{
  std::stringstream aux;
  for (int i = 0; i < vertexes.size(); i++)
  {
    aux << vertexes[i] << ": ";
    for (int j = 0; j < vertexes.size(); j++)
    {
      if (gMatrix[i][j])
        aux << vertexes[j] << " ";
    }
    aux << std::endl;
  }
  return aux.str();
}

#endif