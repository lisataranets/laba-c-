#include <iostream>
#include <cstdlib> 
#include <ctime>  
#include <string>
using namespace std;
struct PointerInfo {
    void* ptr;   
    size_t size;  
};

const int MAX_SEGMENT_SIZE = 100;
PointerInfo staticSegment[MAX_SEGMENT_SIZE];
int segmentSize = 0; 

void* NewPointer(size_t byte) {
    if (segmentSize >= MAX_SEGMENT_SIZE) {
        cout << "Ошибка: статический сегмент переполнен!" << endl;
        return nullptr;
    }

    void* ptr = malloc(byte); 
    if (ptr == nullptr) {
        cout << "Ошибка: не удалось выделить память!" << endl;
        return nullptr;
    }

    staticSegment[segmentSize].ptr = ptr;
    staticSegment[segmentSize].size = byte;
    segmentSize++;

    cout << "Память успешно выделена и сохранена в сегменте." << endl;
    return ptr;
}

template <typename T>
void WritePointer(T* p, T value) {
    if (p == nullptr) {
        cout << "Ошибка: указатель равен null!" << endl;
        return;
    }
    *p = value;
}

template <typename T>
T ReadPointer(T* p) {
    if (p == nullptr) {
        cout << "Ошибка: указатель равен null!" << endl;
        return T();
    }
    return *p;
}

template <typename T>
void SetPointer(T* p, T* b) {
    if (p == nullptr || b == nullptr) {
        cout << "Ошибка: один из указателей равен null!" << endl;
        return;
    }
    *p = *b;
}

void FreePointer(void* ptr) {
    for (int i = 0; i < segmentSize; i++) {
        if (staticSegment[i].ptr == ptr) {
            free(ptr);
            staticSegment[i].ptr = nullptr; 
            staticSegment[i].size = 0; 
            cout << "Память успешно освобождена." << endl;
            return;
        }
    }
    cout << "Ошибка: указатель не найден в сегменте!" << endl;
}

int countMultiplesOfThree(int* arr, int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (*(arr + i) % 3 == 0) {
            count++;
        }
    }
    return count;
}

int main() {
    setlocale(LC_ALL, "Russian");
    srand(time(0));
    string n;
    while (true) {
        cout << "Введите размер массива: ";
        getline(cin, n);
        if (n.empty() || n.find_first_not_of("0123456789") != string::npos) {
            cout << "Ошибка! Введите число" << endl;
            continue;
        }
        int number = stoi(n);
        if (number <= 0) {
            cout << "Ошибка! Введите положительное число." << endl;
            continue;
        }
        break;
    }

    int arraySize = stoi(n); 

    int* A = (int*)NewPointer(arraySize * sizeof(int));
    if (A == nullptr) {
        return 1;
    }

    for (int i = 0; i < arraySize; i++) {
        WritePointer(A + i, rand() % 100);
    }

    cout << "Массив: ";
    for (int i = 0; i < arraySize; i++) {
        cout << ReadPointer(A + i) << " ";
    }
    cout << endl;

    int count = countMultiplesOfThree(A, arraySize);
    cout << "Количество элементов, кратных 3: " << count << endl;

    FreePointer(A);

    return 0;
}