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
/// ������� �������, ������� ��� � ����� ����������� ������ ����� ���������� ��������
/// </summary>
/// <param name="file"> � ���� ��� ������</param>
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

	cout << "���-�� ���� � �����:\n";
	for (int i{ 1 }; i <= 52; ++i) {
		cout << arr[i - 1].letter << " � " << arr[i - 1].count << "\t\t";
		if (i % 4 == 0) cout << '\n';
	}

	return;
}

/// <summary>
/// ������� ������� ����� ������� ������ � �����
/// </summary>
/// <param name="file"> � ���� ��� ������</param>
/// <returns>longest � ����� ������� ������ � �����</returns>
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
/// ������� ������� ���������� ���� � �����
/// </summary>
/// <param name="file"> � ���� ��� ������</param>
/// <returns>count � ���������� ���� � �����</returns>
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
/// ������� ������� �� ����� �������� ����o
/// </summary>
/// <param name="input_file"> � ���� ��� ������</param>
/// <param name="output_file"> � ����, � ������� ������������ ������ ����� �������� ����</param>
/// <param name="word"> � �������� ����� ��� ��������</param>
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
/// ������� �������� ��� ��������� ��������� ����� � �������� ����� �� ����� ��������� (1, 2, 3 � �.�.)
/// </summary>
/// <param name="input_file"> � ���� ��� ������</param>
/// <param name="output_file"> � ����, � ������� ������������ ������ ����� ������ ����</param>
/// <param name="word"> � �������� ����� ��� ������</param>
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