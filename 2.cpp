#include <iostream>
#include <set>
#include <utility> 
#include <string>
#include <limits>  

using namespace std;

void printset(const set<pair<char, char>>& result_set) {
    int count = 1;
    for (const auto& element : result_set) {
        cout << count++ << ": (" << element.first << ", " << element.second << ")\n";
    }
}

int main() {
    setlocale(LC_ALL, "Russian");
    set<char> A, B;
    char input;
    string n, m;
    while (true) {
        cout << "Введите количество элементов множества A: ";
        getline(cin, n);
        if (n.empty() || n.find_first_not_of("0123456789") != string::npos) {
            cout << "Ошибка! Введите число" << endl;
            continue;
        }
        break;
    }
    int numA = stoi(n);
    cout << "Введите элементы множества A (по одному символу):\n";
    for (int i = 0; i < numA; ++i) {
        cin >> input;
        A.insert(input);
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    while (true) {
        cout << "Введите количество элементов множества B: ";
        getline(cin, m);
        if (m.empty() || m.find_first_not_of("0123456789") != string::npos) {
            cout << "Ошибка! Введите число" << endl;
            continue;
        }
        break;
    }
    int numB = stoi(m);
    cout << "Введите элементы множества B (по одному символу):\n";
    for (int i = 0; i < numB; ++i) {
        cin >> input;
        B.insert(input);
    }

    set<pair<char, char>> A_cross_B;
    set<pair<char, char>> B_cross_A;

    for (const auto& a : A) {
        for (const auto& b : B) {
            A_cross_B.insert(make_pair(a, b));
        }
    }
    for (const auto& b : B) {
        for (const auto& a : A) {
            B_cross_A.insert(make_pair(b, a));
        }
    }
    cout << "A x B:\n";
    printset(A_cross_B);
    cout << "B x A:\n";
    printset(B_cross_A);
    return 0;
}