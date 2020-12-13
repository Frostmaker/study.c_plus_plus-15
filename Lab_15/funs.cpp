#include <fstream>
#include <iostream>
#include <string>

using namespace std;

struct LettersQuantity
{
	char letter;
	int count{ 0 };
};

/// <summary>
/// ‘ункци€ считает, сколько раз в файле встречаетс€ кажда€ буква латинского алфавита
/// </summary>
/// <param name="file"> Ч файл дл€ чтени€</param>
void count_letters_in_file(fstream& file)
{
	LettersQuantity arr[52];
	char let;
	for (int i{ 0 }; i < 26; ++i) {
		arr[i].letter = char(i + 97);
	}
	for (int i{ 26 }; i < 52; ++i) {
		arr[i].letter = char(i + 39);
	}
	
	while (!file.eof()) {
		let = file.get();
		if (isalpha(let)) {
			for (int i{ 0 }; i < 52; ++i) {
				if (let == arr[i].letter) {
					++arr[i].count;
					break;
				}
			}
		}
	}

	cout << " ол-во букв в файле:\n";
	for (int i{ 1 }; i <= 52; ++i) {
		cout << arr[i - 1].letter << " Ч " << arr[i - 1].count << "\t\t";
		if (i % 4 == 0) cout << '\n';
	}

	return;
}

/// <summary>
/// ‘ункци€ находит самую длинную строку в файле
/// </summary>
/// <param name="file"> Ч файл дл€ чтени€</param>
/// <returns>longest Ч сама€ длинна€ строка в файле</returns>
string find_longest_row(fstream& file)
{
	string longest, row;
	int len, longest_len = 0;
	while (!file.eof()) {
		getline(file, row);
		len = row.length();
		if (len > longest_len) {
			longest = row;
			longest_len = len;
		}
	}

	return longest;
}

/// <summary>
/// ‘ункци€ считает количество слов в файле
/// </summary>
/// <param name="file"> Ч файл дл€ чтени€</param>
/// <returns>count Ч количество слов в файле</returns>
int count_words_in_file(fstream& file)
{
	string s;
	int count{ 0 };
	while (!file.eof()) {
		getline(file, s);

		bool wrd = false;
		for (int i = 0; i < s.length(); ++i) {
			if (s[i] == ' ' && wrd) {
				wrd = false;
				++count;
			}
			else if (s[i] != ' ' && !wrd)
				wrd = true;
		}

		if (wrd) ++count;
	}

	return count;
}

/// <summary>
/// ‘ункци€ удал€ет из файла заданное словo
/// </summary>
/// <param name="input_file"> Ч файл дл€ чтени€</param>
/// <param name="output_file"> Ч файл, в который записываютс€ строки после удалени€ слов</param>
/// <param name="word"> Ч заданное слово дл€ удалени€</param>
void delete_words_in_file(fstream& input_file, ofstream& output_file, string word)
{
	string s;
	while (!input_file.eof()) {
		getline(input_file, s);
		while (s.find(word) != string::npos) {
			s.erase(s.find(word), word.length());
		}
		output_file << s << '\n';
	}

	return;
}

/// <summary>
/// ‘ункци€ замен€ет все вхождени€ заданного слова в исходном файле на номер вхождени€ (1, 2, 3 и т.д.)
/// </summary>
/// <param name="input_file"> Ч файл дл€ чтени€</param>
/// <param name="output_file"> Ч файл, в который записываютс€ строки после замены слов</param>
/// <param name="word"> Ч заданное слово дл€ замены</param>
void replace_words_in_file(fstream& input_file, ofstream& output_file, string word)
{
	string s;
	int len = word.length();
	int count{ 1 };
	while (!input_file.eof()) {
		getline(input_file, s);
		while (s.find(word) != string::npos) {
			s.replace(s.find(word), len, to_string(count));
			++count;
		}
		output_file << s << '\n';
	}

	return;
}