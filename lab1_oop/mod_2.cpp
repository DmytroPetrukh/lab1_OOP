#include "mod_2.h"

using namespace std;

void copyString(char* dest, const char* src) {
    int i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0'; // Обов'язковий нуль-термінатор в кінці
}

//Получает сумму кодов букв слова
int getSumOfCodes(const char* s) {
    int sum = 0;
    for (int i = 0; s[i] != '\0'; ++i) {
        sum += (unsigned char)s[i];
    }
    return sum;
}

// Сравнивает сумму кодов двух слов
bool compareSumOfCodes(const char* a, const char* b) {
    return getSumOfCodes(a) >= getSumOfCodes(b);
}


//Сортирует слова по сумме кодов: вызывается функция комп возвращающая тру если первое слово больше второго, если фолс сорт меняет их местами
void bubbleSort(char words[][100], int count, CompareFunc comp) {
    for (int i = 0; i < count - 1; i++) {
        char temp[100];
        for (int j = 0; j < count - i - 1; j++) {
            if (!comp(words[j], words[j + 1])) {
                copyString(temp, words[j]);
                copyString(words[j], words[j + 1]);
                copyString(words[j + 1], temp);
            }
        }
    }
}


// функция для вичисления среднего африфметичного и гармоничного
void calcMeans(char words[][100], int count, double& arithMean, double& harmMean) {

    double SumLengths = 0.0;
    double SumInverseLengths = 0.0;

    for (int i = 0; i < count; ++i) {
        int len = 0;
        while (words[i][len] != '\0') {
            len++;
        }
        if (len == 0) {
            continue;
        }

        SumLengths += len;
        SumInverseLengths += 1.0 / len;
    }

    arithMean = SumLengths / count;
    if (SumInverseLengths > 0) {
        harmMean = count / SumInverseLengths;
    }
    else {
        harmMean = 0.0;
    }

}