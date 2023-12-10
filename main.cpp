/*
 * main.cpp
 *
 * Includes the main() function for the graph BFS project.
 *
 * This code creates the executable run-main.
*/

#include <iostream>

#include "graph.h"

using namespace std;

int main() {
    // You can use this main() to run your own analysis or testing code.
    cout << "If you are seeing this, you have successfully run main!" << endl;
    graph test = graph(4);
    test.add_edge(0, 1);
    cout << test.exists(0,1) << endl;
    cout << test.size() << endl;
    //test.print();
    vector<int> res = test.find_shortest_path(0, 1);
    cout << res.size() << endl;
    for (int i : res) {
        cout << i << ", ";
    }
    cout << endl;
    cout << "Main finished" << endl;
    return 0;
}
