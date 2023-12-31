/*
 * graph.h
 *
 * Declaration of the graph class.
 * 
 * Author: <your name here>
 */

#ifndef _GRAPH_BFS_H
#define _GRAPH_BFS_H

#include <vector>

using namespace std;

class graph {
public:
    graph();
    graph(int vertex_count);

    void add_edge(int from, int to);
    vector<int> find_shortest_path(int from, int to);
    //diagnostic functions
    bool exists(int from, int to);
    vector<int>* getNode(int to);
    size_t size();
    void print();

    ~graph();

private:
    vector<vector<int>*> nodes;
};

#endif
