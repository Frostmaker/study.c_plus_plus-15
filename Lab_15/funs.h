#ifndef LettersQuantity
#include <fstream>

using namespace std;

struct LettersQuantity
{
	char letter;
	int count{ 0 };
};
#endif

void count_letters_in_file(fstream& file);
string find_longest_row(fstream& file);
int count_words_in_file(fstream& file);
void delete_words_in_file(fstream& input_file, ofstream& output_file, string word);
void replace_words_in_file(fstream& input_file, ofstream& output_file, string word);