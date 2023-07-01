#include <Windows.h>
#include "BI-3.h"
#include <fstream>
using namespace std;

int main() {

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	std::ifstream myFile;
	myFile.open("Words.txt");
	TreeSearch TreeWords;



	if (myFile.is_open()) {
		string W;
		while (!myFile.eof()) {
			myFile >> W; //���������� ����� ������� �� ����, ��� �� �������� ������
			TreeWords.Add(W);
		}
		TreeWords.Print();

		char S;
		std::cout << "\n������� ������� �����: ";
		std::cin >> S;
		std::cout << "\n���� ������������ �� �������� �����: " << TreeWords.CountWords(S) << "\n";
		TreeWords.Print_Color(S);

		//������� ����� ������ ���������� ���� �� �������� ����� � �����:
		double timeFILE;
		int count = 0;
		myFile.clear(); //������� ������� � ������ �����
		myFile.seekg(0);

		double start = clock(); //��������� ������
		string WORD;
		while (!myFile.eof()) {
			myFile >> WORD;
			if (WORD[0] == S) count++;
		}
		double end = clock(); //�������� ������
		timeFILE = end - start; //����� ������ ���������

		CompareTime(timeFILE, TreeWords, S);
	}
	else {
		cout << "\n�� ������� ������� ����\n";
		return -1;
	}
	myFile.close();
	return 0;
}