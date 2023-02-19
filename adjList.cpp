#include <iostream>
#include <list>

using namespace std;

class Graph {
private:
    int V;
    list<int> *l;

public:
    Graph (int nodes) {
        this->V = nodes;
        this->l = new list<int>[this->V];
    }

    void addEdge(int i, int j, bool undir = true) {
        l[i].push_back(j);
        if (undir) l[j].push_back(i);
    }

    void print() {
        for (int i = 0; i < this->V; i++) {
            cout << i << " : ";
            for (int n: this->l[i]) {
                cout << n << ", ";
            }
            cout << endl;
        }
    }

};

int main(void) {
    Graph myGraph(6);

    myGraph.addEdge(0,1);
    myGraph.addEdge(0,4);
    myGraph.addEdge(2,1);
    myGraph.addEdge(3,4);
    myGraph.addEdge(4,5);
    myGraph.addEdge(2,3);
    myGraph.addEdge(3,5);

    myGraph.print();

    return 0;
}