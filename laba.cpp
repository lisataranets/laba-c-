﻿#include <iostream>
#include <set>
#include <string>
#include <cctype>
using namespace std;

void printset(const set<char>& unique_chars) {
    if (unique_chars.empty()) {
        cout << "В строке не найдено ни одного символа." << endl;
    }
    else {
        cout << "Множество символов:\n";
        for (char ch : unique_chars) {
            cout << ch << endl;
        }
        cout << "Количество элементов в множестве: " << unique_chars.size() << endl;
    }
}

bool punctuation_or_comparison(char ch) {
    const string punctuations = ".,!?;:()[]{}\"'";
    const string comparisons = "==!=<><=>=";
    return punctuations.find(ch) != string::npos || comparisons.find(ch) != string::npos;
}

int main() {
    string input;
    setlocale(LC_ALL, "Russian");
    cout << "Введите строку: ";
    while (true) {
        getline(cin, input);
        if (!input.empty()) {
            break;
        }
        cout << "Строка не должна быть пустой. Введите еще раз: ";
    }

    set<char> unique_chars;
    for (char ch : input) {
        if (punctuation_or_comparison(ch)) {
            unique_chars.insert(ch);
        }
    }

    printset(unique_chars);
    return 0;
}