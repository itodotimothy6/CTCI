// Given a directed graph, design an algorithm to find out whether there is a route between
// two nodes.

#include <iostream>
#include <vector>
using namespace std;

class DirGraph {
    int n; // no of vertices

    vector<vector<int> > adj;

public:

    DirGraph(int n) {
        this->n = n;
        adj.resize(n);
    }

    void addGraph(int x, int y) { // Add a link x -> y
        adj[x].push_back(y);
    }

    bool pathBetween(int s, int t) { // Is there a path from x to y
        if (s == t) return true;

        for(int i = 0; i < adj[s].size(); i++) {
            if(pathBetween(adj[s][i], t)) return true;
        }

        return false;
    }
};

int main() {

    DirGraph graph(9);

    graph.addGraph(1,2);
    graph.addGraph(1,3);
    graph.addGraph(1,4);
    graph.addGraph(1,8);

    graph.addGraph(3,4);

    graph.addGraph(4,5);
    graph.addGraph(4,7);

    graph.addGraph(7,8);

    cout << graph.pathBetween(3,7) << endl;
    return 0;
}


