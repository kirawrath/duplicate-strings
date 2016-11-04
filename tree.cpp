#include "tree.h"
Node::Node(int n)
{
    v=n;
    visited=0;
}
Node::~Node()
{
    for( Node* c : children )
        delete c;
    children.clear();
}
Node* Node::find_num(int n)
{
    for( Node* c : children )
        if( c->v == n )
            return c;
    return nullptr;
}
Node* Node::insert( int n )
{
    Node* node = new Node(n);
    children.push_back(node);
    return node;
}
// return how many times this path was added;
int Node::add_path(const vector<int>& vec)
{
    Node* node = this; // root
    for( int n : vec )
    {
        Node* child = node->find_num(n);
        if(child)
        {
            node = child;
        }
        else
        {
            node = node->insert(n);
        }
    }

    return ++node->visited;
}
