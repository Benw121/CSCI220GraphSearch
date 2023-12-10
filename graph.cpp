/*
 * graph.cpp
 *
 * Method definitions for the graph class.
 *
 * Author: <your name here>
 */

#include "graph.h"

#include <iostream>
#include <numeric>
#include <algorithm>

vector<vector<int>*> nodes;

graph::graph() {
    nodes.clear();
}

graph::graph(int vertex_count) {
    nodes.resize((size_t) vertex_count);
    for (int i = 0; i < vertex_count; i++) {
        nodes[i] = new vector<int>;
    }
}

void graph::add_edge(int from, int to) {
    if ((from > nodes.size()) || (to > nodes.size())) {
        cout << "Error add_edge" << endl;
        return;
    }
    nodes.at(from)->push_back(to);
    return;
}

vector<int> graph::find_shortest_path(int from, int to) {
    if (from == to) {
        return {from};
    }

    int currentInt;
    vector<bool> visited(nodes.size()); //all initialized as false

    graph* revGraph = new graph(nodes.size());
    vector<int> toVis;
    visited[from] = true;
    toVis.push_back(from);

    while (!toVis.empty() && !visited[to]) {
        currentInt = toVis[0];
        toVis.erase(toVis.begin());
        for (int i : *nodes[currentInt]) {
            //cout << visited[i];
            if (!visited[i]) {
                toVis.push_back(i);
                visited[i] = true;
                revGraph->add_edge(i, currentInt);
            }
        }
    }
    //revGraph->print();

    vector<int> result;
    if (visited[to]) {
        result.push_back(to);
        int current = revGraph->nodes[to]->at(0);
        while (current != from) {
            result.push_back(current);
            current = revGraph->nodes[current]->at(0);
        }
        result.push_back(from);
        reverse(result.begin(), result.end());
        delete revGraph;
        return result;
    }

    delete revGraph;
    return {};
}

bool graph::exists(int from, int to) {
    if (from > nodes.size()) {
        return false;
    }
    if (nodes.at(from) == nullptr){
        return false;
    }
    for (int i : *nodes.at(from)) {
        if (i == to) {
            return true;
        }
    }
    return false;
}

vector<int>* graph::getNode(int to) {
    return nodes.at(to);
}

size_t graph::size() {
    return nodes.size();
}

void graph::print() {
    int i = 0;
    for (vector<int>* node : nodes) {
        cout << i <<": ";
        for (int edge : *node) {
            cout << edge << ", ";
        }
        cout << endl;
        i++;
    }
}

graph::~graph() {
    for (vector<int>* vec : nodes) {
        delete vec;
    }
}