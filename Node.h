#include <vector>
#include <string>
#include <map>

using namespace std;

class Node
{
    private:
        char data;
        int frequency;
        Node * left;
        Node * right;
    public:
        Node () {};
        Node (char data, int frequency)
        {
            this->data = data;
            this->frequency = frequency;
            this->left = NULL;
            this->right = NULL;
        };
        inline char getData() { return this->data; }
        inline int getFrequency() {return this->frequency; }
        inline Node * getLeft() { return this->left; }
        inline Node * getRight() { return this->right; }
        void merge (Node * leftNode, Node * rightNode)
        {
            this->left = leftNode;
            this->right = rightNode;
            this->frequency = leftNode->frequency + rightNode->frequency;
        }

};

bool compare(Node *&left, Node *&right)
{
  if (left->getFrequency() > right->getFrequency())
    return true;
  return false;
}

        