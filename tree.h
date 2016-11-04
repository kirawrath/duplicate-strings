#ifndef TREE_H
#define TREE_H
#include<vector>
using namespace std;
class Node
{
    public:
    Node(int n);
    ~Node();
    int add_path(const vector<int>& vec);

    private:
    Node* find_num(int n);
    Node* insert( int n );
    vector<Node*> children;
    int v;
    int visited;
};
#endif
