#include <stdio.h>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <stack>
#include <queue>

#pragma once
class Node
{
public:
	Node();
	~Node();
	int GetValue();
	void SetValue(int value);
	void SetNeighbour(Node* node);
	std::vector<Node*>& GetNeighbours();
private:
	int _value;
	bool _visited;
	std::vector<Node*> _neighbours;
	Node* _cameFrom;
};

class Graph
{
public:
	Graph();
	~Graph();
	bool LoadData(std::string inputPath);
	// Info about commenting style for Doxygen: https://www.doxygen.nl/manual/docblocks.html
	/**
	* This method print to standard output paths starting in given node to all other nodes in graph
	* @param node source node for all paths
	*/
	//void PrintPathsFromNodeToAll(Node* node);
	/**
	* Method find shortest path between pair of nodes in graph
	* @param from source node
	* @param to target node
	* @return sequence of nodes in shortest path
	*/
	//std::vector<Node*> FindShortestPath(Node* from, Node* to);
	int GetNodeCount();
	std::vector<Node*>& GetNodes();
private:
	std::vector<Node*> _nodes;
};