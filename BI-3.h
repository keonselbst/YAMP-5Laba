#pragma once
#pragma once
#include <iostream>
#include <Windows.h>
#include <string>

struct Node {
	std::string word;
	Node* right;
	Node* left;
	int k = 0; 
};
typedef Node* TNode;

class TreeSearch
{
	TNode root;

	void Add(std::string W, TNode p, int& KRAT);
	void Print_Color(TNode root, int level, char S);
	void DeleteTree(TNode& root);
	int CountWords(TNode root, char s);
	void Print(TNode root, int level);

public:
	TreeSearch();
	TreeSearch(std::string W);
	~TreeSearch();
	bool isEmpty();
	void Add(std::string W);
	TNode& Getroot() { return root; }
	void Print_Color(char S);
	int CountWords(char S);
	void Print();
};
void CompareTime(double timeFILE, TreeSearch& tree, char S);
double TimeSearchInTree(TreeSearch& tree, char S);