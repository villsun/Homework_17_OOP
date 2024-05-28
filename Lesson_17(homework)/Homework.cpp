#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>

using namespace std;

void Reading_File(multimap<string, string>& dictionary)
{
	ifstream inputFile("F:\\Visual Studio project object-oriented programming\\Lesson_17(homework)\\Dictionary.txt");
	if (!inputFile) {
		cerr << "Error opening file" << endl;
		return;
	}

	string line;
	while (getline(inputFile, line))
	{
		istringstream iss(line);
		string firstWord, secondWord;

		if (iss >> firstWord >> secondWord) {
			dictionary.insert({ firstWord, secondWord });
		}
		else {
			cerr << "Error parsing line" << endl;
		}
	}

	inputFile.close();
}

void Show_Dictionary(multimap<string, string>const& dictionary)
{
	for (auto& element : dictionary)
	{
		cout << "First word: " << element.first << endl;
		cout << "Second word: " << element.second << endl;
	}
}

int main() {

	multimap<string, string> dictionary;
	Reading_File(dictionary);
	Show_Dictionary(dictionary);

	return 0;
}
