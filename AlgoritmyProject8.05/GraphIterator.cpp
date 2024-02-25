#include "GraphIterator.h"

GraphIterator::GraphIterator(Graph* g)
{
	this->graph = g;
}

GraphIterator::~GraphIterator()
{
	this->graph = nullptr;
	this->visited.clear();
	this->currentOperated.clear();
}

BFSIterator::BFSIterator(Graph* g) : GraphIterator(g)
{
}

void BFSIterator::Reset()
{
	while (!queue.empty())
	{
		queue.pop();
	}
	std::vector<Node*> nodes = graph->GetNodes();
	queue.push(nodes.at(0));
	currentOperated.insert(nodes.at(0));
	visited.insert(nodes.at(0));
}

void BFSIterator::Next()
{
	Node* node = queue.front();
	visited.insert(node);
	queue.pop();
	currentOperated.erase(node);
	for (Node*& n : node->GetNeighbours())
	{
		if (visited.find(n) == visited.end()
			&& currentOperated.find(n) == currentOperated.end())
		{
			queue.push(n);
			currentOperated.insert(n);
		}
	}
	if (queue.empty())
	{
		if (visited.size() == graph->GetNodeCount())
		{
			return;
		}
		else
		{
			std::vector<Node*> nodes = graph->GetNodes();
			for (Node*& node : nodes)
			{
				if (visited.insert(node).second == true)
				{
					queue.push(node);
					return;
				}
			}
		}
	}
}

bool BFSIterator::IsEnd()
{
	return visited.size() == graph->GetNodeCount();
}

Node*& BFSIterator::CurrentKey()
{
	if (!IsEnd())
		return queue.front();
}



DFSIterator::DFSIterator(Graph* g) : GraphIterator(g)
{
}

void DFSIterator::Reset()
{
	while (!stack.empty())
	{
		stack.pop();
	}
	std::vector<Node*> nodes = graph->GetNodes();
	stack.push(nodes.at(0));
	currentOperated.insert(nodes.at(0));
	visited.insert(nodes.at(0));
}

void DFSIterator::Next()
{
	Node* node = stack.top();
	visited.insert(node);
	stack.pop();
	currentOperated.erase(node);
	for (Node*& n : node->GetNeighbours())
	{
		if (visited.find(n) == visited.end()
			&& currentOperated.find(n) == currentOperated.end())
		{
			stack.push(n);
			currentOperated.insert(n);
		}
	}
	if (stack.empty())
	{
		if (visited.size() == graph->GetNodeCount())
		{
			return;
		}
		else
		{
			std::vector<Node*> nodes = graph->GetNodes();
			for (Node*& node : nodes)
			{
				if (visited.insert(node).second == true)
				{
					stack.push(node);
					return;
				}
			}
		}
	}
}

bool DFSIterator::IsEnd()
{
	return visited.size() == graph->GetNodeCount();
}

Node*& DFSIterator::CurrentKey()
{
	if (!IsEnd())
		return stack.top();
}