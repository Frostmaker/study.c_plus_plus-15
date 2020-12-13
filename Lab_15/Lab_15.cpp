/*
1. Дан текстовый файл, состоящий из строк. Посчитать, сколько раз в файле встречается каждая буква латинского алфавита.
2. Дан текстовый файл, состоящий из строк. Вывести самую длинную строку в файле.
3. Дан текстовый файл, содержащий строки слов. Слова в строке разделены пробелами. Посчитать количество слов в файле.
4. Дан текстовый файл, содержащий строки слов. Слова в строке разделены пробелами. Удалить из файла заданное словo.
5. Дан текстовый файл, содержащий строки слов. Слова в строке разделены пробелами. 
    Заменить все вхождения заданного слова в исходном файле на номер вхождения (1, 2, 3 и т.д.).
*/

#include <iostream>
#include "funs.h"
#include <string>
#include <stdio.h>

void menu()
{
    cout << "/================== MENU ==================\\\n";
    cout << "| 1. Посчитать кол-во букв в файле         |\n";
    cout << "| 2. Самая длинная строка                  |\n";
    cout << "| 3. Посчитать кол-во слов в файле         |\n";
    cout << "| 4. Удалить из файла заданное слово       |\n";
    cout << "| 5. Заменить слова на цифры               |\n";
    cout << "| 9. Вывод меню                            |\n";
    cout << "| 0. Выход                                 |\n";
    cout << "\\==========================================/\n";
}


int main()
{
    setlocale(LC_ALL, "rus");

    menu();
    string filename;
    cout << "Введите название файла:\n>> ";
    cin >> filename;  // testfile0 || testfile1 || testfile2 || testfile3 || testfile4
    int p;
    bool ext{ true };

    while (ext)
    {
        cout << "\nВыберите пункт меню: ";
        cin >> p;
        cout << "\n";

        fstream file(filename + ".txt");
        if (!file.is_open())
            cout << "Error: file cannot be open!\n";
        else {
            switch (p) {
            case 1:
            {
                count_letters_in_file(file);
                cout << "Файл успешно обработан!\n";
                break;
            }
            case 2:
            {
                cout << "Самая длинная строка — \"" << find_longest_row(file) << "\"\n";
                break;
            }
            case 3:
            {
                cout << "Кол-во слов в файле — " << count_words_in_file(file) << '\n';
                break;
            }
            case 4:
            {
                string word;
                cout << "Введите слово, которое хотите удалить:\n>> ";
                cin >> word;
                ofstream output_file("ResultForDelete.txt", ios::out);
                if (output_file.is_open()) {
                    delete_words_in_file(file, output_file, word);
                    output_file.close();
                }
                cout << "Файл успешно обработан!\n";
                break;
            }
            case 5:
            {
                string word;
                cout << "Введите слово, которое хотите заменить:\n>> ";
                cin >> word;
                ofstream output_file("ResultForReplace.txt", ios::out);
                if (output_file.is_open()) {
                    replace_words_in_file(file, output_file, word);
                    output_file.close();
                }
                cout << "Файл успешно обработан!\n";
                break;
            }
            case 9:
            {
                menu();
                break;
            }
            case 0:
            {
                ext = false;
                break;
            }
            default:
            {
                cout << "Нет такого пункта меню!\n";
            }
            }

            
            file.close();
        }
    }


    //system("pause");
    return 0;
}