#include <iostream>

using std::cout;
using std::endl;

typedef int vertex;

class GraphMatrix {
    int numVertices;
    int numEdges;
    bool** matrix;

public:
    GraphMatrix(int iNumVertices)
    : numVertices(iNumVertices)
    , numEdges(0) {
        matrix = new bool*[numVertices];

        for (int i = 0; i < numVertices; i++) {
            matrix[i] = new bool[numVertices];

            for (int j = 0; j < numVertices; j++)
                matrix[i][j] = false;
        }
    }

    ~GraphMatrix() {
        for (int i = 0; i < numVertices; i++) {
            delete[] matrix[i];
        }
        
        delete[] matrix;
    }

    bool hasEdge(vertex v1, vertex v2) {
        return matrix[v1][v2];
    }

    void addEdge(vertex v1, vertex v2) {
        v1 -= 1;
        v2 -= 1;

        matrix[v1][v2] = true;
        matrix[v2][v1] = true;
        ++numEdges;
    }

    void removeEdge(vertex v1, vertex v2) {
        v1 -= 1;
        v2 -= 1;

        matrix[v1][v2] = false;
        matrix[v2][v1] = false;
        --numEdges;
    }

    void printGraph() {
        for (vertex i = 0; i < numVertices; i++) {
            for (vertex j = 0; j < numVertices; j++) {
                if (hasEdge(i, j)) {
                    printf("(%d, %d) ", i + 1, j + 1);
                }
            }

            printf("\n");
        }
    }

    void printMatrix() {
        for (vertex i = 0; i < numVertices; i++) {
            for (vertex j = 0; j < numVertices; j++) {
                printf("%d ", hasEdge(i, j));
            }
            
            printf("\n");
        }
    }

    bool isSubGraph(GraphMatrix& g) {
        if (numVertices < g.numVertices) {
            return false;
        }

        for (vertex i = 0; i < g.numVertices; i++) {
            for (vertex j = i; j < g.numVertices; j++) {
                if (g.hasEdge(i, j) && !hasEdge(i, j)) {
                    return false;
                }
            }
        }

        return true;
    }

    bool isPath(vertex* path, int pathLength) {
        for (int i = 0; i < pathLength - 1; i++) {
            if (!hasEdge(path[i] - 1, path[i + 1] - 1)) {
                return false;
            }
        }

        return true;
    }
};

// Node for the list of edges of a vertex
class EdgeNode {
    vertex adjacentVertex;
    EdgeNode* next;

public:
    EdgeNode(vertex iAdjacentVertex, EdgeNode* ptrNext)
    : adjacentVertex(iAdjacentVertex)
    , next(ptrNext) {}

    vertex getAdjacentVertex() {
        return adjacentVertex;
    }

    EdgeNode* getNext() {
        return next;
    }

    void setNext(EdgeNode* ptrNext) {
        next = ptrNext;
    }
};

class GraphAdjList {
    int numVertices;
    int numEdges;
    EdgeNode** adjList;
    
public:
    GraphAdjList(int iNumVertices)
    : numVertices(iNumVertices)
    , numEdges(0)
    , adjList(nullptr) {
        adjList = new EdgeNode*[numVertices];

        for (vertex i = 0; i < numVertices; i++) {
            adjList[i] = nullptr;
        }
    }

    ~GraphAdjList() {
        for (vertex i = 0; i < numVertices; i++) {
            EdgeNode* ptrEdge = adjList[i];

            while (ptrEdge != nullptr) {
                EdgeNode* tempEdge = ptrEdge;
                ptrEdge = ptrEdge->getNext();
                delete tempEdge;
            }
        }

        delete[] adjList;
    }

    void addEdge(vertex v1, vertex v2) {
        v1 -= 1;
        v2 -= 1;

        EdgeNode* ptrEdge = adjList[v1];

        while (ptrEdge != nullptr && ptrEdge->getNext() != nullptr) {
            if (ptrEdge->getAdjacentVertex() == v2) {
                return;
            }

            ptrEdge = ptrEdge->getNext();
        }

        adjList[v1] = new EdgeNode(v2, adjList[v1]);
        adjList[v2] = new EdgeNode(v1, adjList[v2]);

        numEdges++;
    }

    void removeEdge(vertex v1, vertex v2) {
        v1 -= 1;
        v2 -= 1;

        EdgeNode* ptrEdge = adjList[v1];
        EdgeNode* prevEdge = nullptr;

        while (ptrEdge != nullptr) {
            if (ptrEdge->getAdjacentVertex() == v2) {
                if (prevEdge == nullptr) {
                    adjList[v1] = ptrEdge->getNext();
                } else {
                    prevEdge->setNext(ptrEdge->getNext());
                }

                delete ptrEdge;
                break;
            }
        }

        ptrEdge = adjList[v2];
        prevEdge = nullptr;

        while (ptrEdge != nullptr) {
            if (ptrEdge->getAdjacentVertex() == v1) {
                if (prevEdge == nullptr) {
                    adjList[v2] = ptrEdge->getNext();
                } else {
                    prevEdge->setNext(ptrEdge->getNext());
                }

                delete ptrEdge;
                break;
            }
        }
    }

    void print() {
        for (vertex i = 0; i < numVertices; i++) {
            EdgeNode* ptrEdge = adjList[i];

            while (ptrEdge != nullptr) {
                printf("(%d, %d) ", i + 1, ptrEdge->getAdjacentVertex() + 1);
                ptrEdge = ptrEdge->getNext();
            }

            printf("\n");
        }
    }

    bool hasEdge(vertex v1, vertex v2) {
        EdgeNode* ptrEdge = adjList[v1];

        while (ptrEdge != nullptr) {
            if (ptrEdge->getAdjacentVertex() == v2) {
                return true;
            }

            ptrEdge = ptrEdge->getNext();
        }

        return false;
    }

    bool isSubGraph(GraphAdjList& g) {
        EdgeNode** gAdjList = g.adjList;

        for (vertex i = 0; i < g.numVertices; i++) {
            EdgeNode* ptrEdge = gAdjList[i];

            while (ptrEdge != nullptr) {
                if (!hasEdge(i, ptrEdge->getAdjacentVertex())) {
                    return false;
                }

                ptrEdge = ptrEdge->getNext();
            }
        }

        return true;
    }

    bool isPath(vertex* path, int pathLength) {
        for (int i = 0; i < pathLength - 1; i++) {
            if (!hasEdge(path[i] - 1, path[i + 1] - 1)) {
                return false;
            }
        }

        return true;
    }
};

int main(){
    cout << "Testing GraphMatrix: \n" << endl;
    GraphMatrix g(6);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 5);
    g.addEdge(2, 4);
    g.addEdge(3, 5);
    g.addEdge(5, 4);
    g.addEdge(5, 6);
    g.addEdge(6, 1);

    g.removeEdge(6, 1);

    g.printGraph();
    g.printMatrix();

    cout << "\nTesting GraphAdjList: \n" << endl;
    GraphAdjList g2(6);
    g2.addEdge(1, 2);
    g2.addEdge(1, 3);
    g2.addEdge(2, 5);
    g2.addEdge(2, 4);
    g2.addEdge(3, 5);
    g2.addEdge(5, 4);
    g2.addEdge(5, 6);
    g2.addEdge(6, 1);

    g2.removeEdge(6, 1);

    g2.print();

    cout << "\nTesting isSubGraph: \n" << endl;
    GraphMatrix g3(4);
    g3.addEdge(1, 2);
    g3.addEdge(1, 3);
    g3.addEdge(2, 4);
    
    cout << g.isSubGraph(g3) << endl;

    g3.addEdge(3, 4);

    cout << g.isSubGraph(g3) << endl;

    GraphAdjList g4(4);
    g4.addEdge(1, 2);
    g4.addEdge(1, 3);
    g4.addEdge(2, 4);

    cout << g2.isSubGraph(g4) << endl;

    g4.addEdge(3, 4);

    cout << g2.isSubGraph(g4) << endl;

    g4.removeEdge(3, 4);

    cout << g2.isSubGraph(g4) << endl;

    cout << "\nTesting isPath: \n" << endl;

    int path[4] = {1, 2, 4, 5};
    int path2[3] = {1, 3, 6};

    cout << g.isPath(path, 4) << endl;
    cout << g.isPath(path2, 3) << endl;

    cout << g2.isPath(path, 4) << endl;
    cout << g2.isPath(path2, 3) << endl;

    return 0;
}