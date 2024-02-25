#include "Graph.h"
#include <iostream>

Node::Node()
{
    this->_value = 0;
    this->_cameFrom = nullptr;
    this->_visited = false;
}

Node::~Node()
{
}

void Node::SetValue(int value)
{
    this->_value = value;
}

int Node::GetValue()
{
    return this->_value; //0
}

void Node::SetNeighbour(Node* node)
{
    _neighbours.push_back(node);
}

std::vector<Node*>& Node::GetNeighbours()
{
    return this->_neighbours;
}


Graph::Graph()
{
}

Graph::~Graph()
{
    for (Node* node : this->_nodes) {
        delete node;
    }
}

bool Graph::LoadData(std::string inputPath)
{
    std::ifstream inputFile(inputPath);
    if (!inputFile.is_open()) {
        std::cerr << "Failed to open input file: " << inputPath << std::endl;
        return false;
    }

    std::string line;
    while (std::getline(inputFile, line)) {
        std::istringstream lineStream(line);
        int from, to;
        lineStream >> from >> to;

        Node* fromNode = nullptr;
        Node* toNode = nullptr;
        for (Node* node : _nodes) {
            if (node->GetValue() == from) {
                fromNode = node;
            }
            if (node->GetValue() == to) {
                toNode = node;
            }
        }
        if (!fromNode) {
            fromNode = new Node();
            fromNode->SetValue(from);
            _nodes.push_back(fromNode);
        }
        if (!toNode) {
            toNode = new Node();
            toNode->SetValue(to);
            _nodes.push_back(toNode);
        }

        fromNode->SetNeighbour(toNode);
    }

    inputFile.close();
    return true;
}

std::vector<Node*>& Graph::GetNodes()
{
    return this->_nodes;
}

int Graph::GetNodeCount()
{
    return _nodes.size();
}
