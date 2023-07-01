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
			myFile >> W; //Считывание слова целиком до того, как не встретит пробел
			TreeWords.Add(W);
		}
		TreeWords.Print();

		char S;
		std::cout << "\nВведите искомую букву: ";
		std::cin >> S;
		std::cout << "\nСлов начинающихся на заданную букву: " << TreeWords.CountWords(S) << "\n";
		TreeWords.Print_Color(S);

		//Считаем время поиска количества слов на заданную букву в файле:
		double timeFILE;
		int count = 0;
		myFile.clear(); //Перенос курсора в начало файла
		myFile.seekg(0);

		double start = clock(); //Начальный момент
		string WORD;
		while (!myFile.eof()) {
			myFile >> WORD;
			if (WORD[0] == S) count++;
		}
		double end = clock(); //Конечный момент
		timeFILE = end - start; //Время работы алгоритма

		CompareTime(timeFILE, TreeWords, S);
	}
	else {
		cout << "\nНе удалось открыть файл\n";
		return -1;
	}
	myFile.close();
	return 0;
}