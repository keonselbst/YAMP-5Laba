#include "BI-3.h"


TreeSearch::TreeSearch() {
	root = nullptr;
}
TreeSearch::TreeSearch(std::string W) {
	root = new Node;
	root->left = root->right = nullptr;
	root->word = W;
	root->k = 1;
}
TreeSearch::~TreeSearch()
{
	DeleteTree(root);
}

bool TreeSearch::isEmpty() {
	return root == nullptr;
}
void TreeSearch::Add(std::string W, TNode p, int& k_) {
	if (isEmpty()) { //������ ������� ������
		root = new Node;
		root->left = root->right = nullptr;
		root->word = W;
		root->k = k_;
	}
	else {
		if (W > p->word) {
			if (p->right == nullptr) {
				p->right = new Node;
				p->right->left = p->right->right = nullptr;
				if (p->word[0] == W[0]) k_++;
				p->right->k = k_;
				p->right->word = W;
			}
			else Add(W, p->right, k_);
		}
		if (W < p->word) {
			if (p->left == nullptr) {
				p->left = new Node;
				p->left->right = p->left->left = nullptr;
				if (p->word[0] == W[0]) k_++;
				p->left->k = k_;
				p->left->word = W;
			}
			else Add(W, p->left, k_);
		}
		if (W[0] == p->word[0]) {
			p->k++;
			k_++;
		}
	}
}
void TreeSearch::Add(std::string W) { //�������
	int K = 1;
	Add(W, Getroot(), K);
}

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
void TreeSearch::Print_Color(TNode root, int level, char S) { //������ ������� ��� ����, ������� ����� ������ ����� S
	SetConsoleTextAttribute(hConsole, 15);
	if (Getroot() == nullptr) std::cout << "\n ������ �����!\n";
	if (root) {
		Print_Color(root->right, level + 1, S);
		for (int i = 0; i < level; i++)
			std::cout << "     ";

		if (root->k > 1 && root->word[0] == S)
		{
			SetConsoleTextAttribute(hConsole, 5);
			std::cout << root->word <</* "(" << root->k << ")" <<*/ std::endl;
			SetConsoleTextAttribute(hConsole, 15);
		}
		else std::cout << root->word << std::endl;
		Print_Color(root->left, level + 1, S);
	}
}
void TreeSearch::Print_Color(char S) { //�������
	Print_Color(root, 0, S);
}

void TreeSearch::Print(TNode root, int level) { //������ � ���� ������
	if (Getroot() == nullptr) std::cout << "\n ������ �����!\n";
	if (root) {
		Print(root->right, level + 1);
		for (int i = 0; i < level; i++)
			std::cout << "     ";
		std::cout << root->word << std::endl;
		Print(root->left, level + 1);
	}
}
void TreeSearch::Print() { //�������
	Print(root, 0);
}

void TreeSearch::DeleteTree(TNode& root) {
	if (root != nullptr) { 
		DeleteTree(root->left); //���������
		DeleteTree(root->right); 

		root->right = nullptr;
		root->left = nullptr;
		delete root;
		root = nullptr;
	}
}
int TreeSearch::CountWords(TNode root, char S) { //���������� ���������� ���� � ������ ������������ � ������ ����� S
	if (root) {
		if (root->word[0] == S) {
			return root->k;
		}
		CountWords(root->left, S);
		CountWords(root->right, S);
	}
}
int TreeSearch::CountWords(char S) {
	return CountWords(root, S);
}

double TimeSearchInTree(TreeSearch& tree, char S) { //������� ������� ������ � ������
	double start = clock(); 
	tree.CountWords(S);
	double end = clock(); 
	return end - start; //����� ������ ���������
}

void CompareTime(double timeFILE, TreeSearch& tree, char S) {  //��������� ������� ������ � ����� � � ������
	double timeTREE = TimeSearchInTree(tree, S);
	std::cout << "\n�������� ������ ���� � ��������� �������� " << S << " � ";
	timeFILE < timeTREE ? std::cout << "����� �������� �������\n" : std::cout << "������ �������� �������\n";
	std::cout << "� �����: " << timeFILE << " mc\n";
	std::cout << "� ������: " << timeTREE << " mc\n";
}