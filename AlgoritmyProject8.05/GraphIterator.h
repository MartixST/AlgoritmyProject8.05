#ifndef GRAPHITERATOR_H
#define GRAPHITERATOR_H

#include <unordered_set>
#include <stack>
#include <queue>
#include "Graph.h"

class GraphIterator {
protected:
    Graph* graph;
    std::unordered_set<Node*> visited;
    std::unordered_set<Node*> currentOperated;

public:
    GraphIterator(Graph* g);
    virtual ~GraphIterator();
    virtual void Reset() = 0;
    virtual void Next() = 0;
    virtual bool IsEnd() = 0;
    virtual Node*& CurrentKey() = 0;
};

class BFSIterator : public GraphIterator {
private:
    std::queue<Node*> queue;

public:
    BFSIterator(Graph* g);
    void Reset() override;
    void Next() override;
    bool IsEnd() override;
    Node*& CurrentKey() override;
};

class DFSIterator : public GraphIterator {
private:
    std::stack<Node*> stack;

public:
    DFSIterator(Graph* g);
    void Reset() override;
    void Next() override;
    bool IsEnd() override;
    Node*& CurrentKey() override;
};

#endif //GRAPHITERATOR_H