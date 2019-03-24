#include <vector>
#include <string>
#include <map>
#include <bits/stdc++.h>
#include "Node.h"

class Huffman
{
private:
  Node *root;
  map<char, string> codes;
  string source;
  string destination;

public:
  Huffman(string _source,string _destination)
  {
    this->source = _source;
    this->destination = _destination;
    // cout << this->destination << endl << _destination;
    map<char, int> frequency;
    char letter;
    freopen(source.c_str(), "r", stdin);
    while (scanf("%c", &letter) != EOF)
      ++frequency[letter];
    fclose(stdin);
    map<char, int>::iterator itr;
    vector<Node *> nodes;
    for (itr = frequency.begin(); itr != frequency.end(); ++itr)
      nodes.push_back(new Node(itr->first, itr->second));

    this->root = generate_tree(nodes);
    generate_codes(this->root, "");
    writeFile(this->codes);
  }
  Node *generate_tree(vector<Node *> &);
  void generate_codes(Node * , string);
  void writeFile(map<char, string>&);
};


Node *Huffman::generate_tree(vector<Node *> &nodes)
{
  priority_queue<Node *, vector<Node *>, decltype(&compare)> min_heap(&compare);
  for (int i = 0; i < nodes.size(); ++ i)
  {
    min_heap.push(nodes[i]);
  }
  while (min_heap.size() != 1)
  {
    Node *left = min_heap.top();
    min_heap.pop();
    Node *right = min_heap.top();
    min_heap.pop();
    Node * parent = new Node ();
    parent ->merge(left, right);
    min_heap.push (parent);
  }
  return min_heap.top();
}

void Huffman::generate_codes(Node * root, string currCode){ 
    if (root->getLeft() == NULL && root->getRight() == NULL){
        this->codes[root->getData()] = currCode;
        // cout << root->getData() << " " << currCode << endl;
        return;
    }  
    generate_codes(root->getLeft(), currCode + "0"); 
    generate_codes(root->getRight(), currCode + "1");

}

int binaryToDecimal(string bin) {
	while ((int)bin.size() < 8) bin += "0";
	int dec = 0;
	reverse(bin.begin(), bin.end());
	for (int i = 0; i < (int)bin.size(); ++i)
		dec += (bin[i] == '1') * (1 << i);
	return dec;
}

void Huffman::writeFile(map<char, string> &codes){
	string result = "";
	char letter;
	freopen(source.c_str(), "r", stdin);
	while(scanf("%c", &letter) != EOF)
		result += codes[letter];
	fclose(stdin);
	string tmp = result;
	result = "";

	for (int i = 0; i < (int)tmp.size(); i += 8) {
		result += char(binaryToDecimal(tmp.substr(i, 8)));
	}

	size_t size = result.size();
	cout<<destination;
	fstream outFile;
	outFile.open(destination.c_str(), ios::out | ios::binary);
	outFile.write(result.c_str(), size);
	outFile.close();
}