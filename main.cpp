
#include "Huffman.h"
#include <bits/stdc++.h> 
using namespace std;

void compress(string source, string destination){
	Huffman * huffman = new Huffman(source, destination);
}

int main(int argc, char const *argv[]){
	string cmd="", source="", distination="";
	if (argc != 3){
		cout<<"Invalid!!"<<endl;
		cout<<"[-] Usage"<<endl;
		cout<<"- operation type <-d, -c> (compress/decompress)"<<endl;
		cout<<"- source file <filename>"<<endl;
		cout<<"- destination file <filename>"<<endl;
		return 1;
	}
	else{
		source=argv[1];
		distination=argv[2];
	}

	compress(source, distination);
	return 0;
}