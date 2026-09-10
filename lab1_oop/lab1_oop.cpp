#include <iostream>
#include <fstream>
#include <windows.h>
#include "mod_2.h"

using namespace std;

int main(int argc, char* argv[])
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    // Перевірка наявності хоча б імені вихідного файлу
    if (argc < 2) {
        cout << "Помилка: Не вказано ім'я вихідного файлу." << endl;
        return 1;
    }

    const char* outputFile = argv[1];

    char inputBuffer[256];
    const char* inputFile = NULL;

    // Якщо передано лише один параметр (ім'я вихідного файлу)
    if (argc == 2) {
        cout << "Вхідний файл не задано в параметрах командного рядка." << endl;
        cout << "Введіть ім'я файлу, з якого треба прочитати вхідні дані: ";
        cin >> inputBuffer;
        inputFile = inputBuffer;
    }
    else {
        inputFile = argv[2];
    }

    char words[100][100];
    int wordCount = 0;

    ifstream fin(inputFile);
    if (!fin) {
        cout << "Помилка: неможливо відкрити вхідний файл " << inputFile << endl;
        return 1;
    }

    char buffer[100];
    // Читаємо слова, поки файл не закінчиться і не перевищено ліміт у 100 слів
    while (fin >> buffer && wordCount < 100) {
        copyString(words[wordCount], buffer);
        wordCount++;
    }
    fin.close();

    if (wordCount == 0) {
        cout << "Немає слів для обробки або файл порожній." << endl;
        return 0;
    }

    bubbleSort(words, wordCount, compareSumOfCodes);

    double arithMean, harmMean;
    calcMeans(words, wordCount, arithMean, harmMean);

    ofstream fout(outputFile);
    if (!fout) {
        cout << "Помилка створення вихідного файлу" << endl;
        return 1;
    }

    fout << "Відсортовані слова:" << endl;
    for (int i = 0; i < wordCount; ++i) {
        fout << "- " << words[i] << endl;
    }

    fout << "\nСереднє арифметичне довжин слів: " << arithMean << endl;
    fout << "Середнє гармонічне довжин слів: " << harmMean << endl;
    fout.close();

    cout << "Успішно виконано!" << endl;
    system("pause");
    return 0;
}

