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
	for (const auto& pair : dictionary)
	{
		cout << "First word: " << pair.first << endl;
		cout << "Second word: " << pair.second << endl;
	}
}


void Show_Popular_Pair(multimap<string, string>const& dictionary)
{
	auto it = dictionary.begin();
	int counter = dictionary.count(it->first);
	string word_1 = it->first;
	string word_2 = it->second;
	for (const auto& pair : dictionary)
	{
		if (counter < dictionary.count(pair.first))
		{
			counter = dictionary.count(pair.first);
			word_1 = pair.first;
			word_2 = pair.second;
		}
	}

	cout <<"Popular Pair: " << word_1 << ' ' << word_2;
}


void Save_Dictionary(multimap<string, string>const& dictionary)
{
	ofstream outputFile("F:\\Visual Studio project object-oriented programming\\Lesson_17(homework)\\Dictionary.txt");
	if (!outputFile) {
		cerr << "Error opening output file" << endl;
		return;
	}

	for (const auto& pair : dictionary) {
		outputFile << pair.first << ' ' << pair.second << endl;
	}
}

int main() {

	multimap<string, string> dictionary;
	Reading_File(dictionary);
	dictionary.insert({ "cat", "katt" });
	dictionary.insert({ "dog", "hund" });
	dictionary.insert({ "dog", "hund" });
	Show_Dictionary(dictionary);
	Show_Popular_Pair(dictionary);
	Save_Dictionary(dictionary);
	
	return 0;
}
