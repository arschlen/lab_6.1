#include <iostream>
#include <ctime>  
#include <iomanip> 
using namespace std;

const int SIZE = 25;

void COUT(int mas[], int size, int i = 0) {
    if (i == size) {
        cout << endl;
        return;
    }
    cout << setw(4) << mas[i] << " ";
    COUT(mas, size, i + 1);
}

int ValidElCount(int mas[], int size, int i = 0) {
    if (i == size) return 0;
    return ((mas[i] % 6 == 0 || i % 5 != 0) ? 1 : 0) + ValidElCount(mas, size, i + 1);
}

int SUMValidEl(int mas[], int size, int i = 0) {
    if (i == size) return 0;
    return ((mas[i] % 6 == 0 || i % 5 != 0) ? mas[i] : 0) + SUMValidEl(mas, size, i + 1);
}

void Nulls(int mas[], int size, int i = 0) {
    if (i == size) return;
    if (mas[i] % 6 == 0 || i % 5 != 0) {
        mas[i] = 0;
    }
    Nulls(mas, size, i + 1);
}

int main() {
    srand((unsigned)time(0));
    setlocale(LC_CTYPE, "ukr");
    int a[SIZE];

    // ���������� ������ ���������� �� 4 �� 73
    for (int i = 0; i < SIZE; i++) {
        a[i] = rand() % 70 + 4; // ��������� ������� � ������� [4, 73]
    }

    cout << "���������� �����: " << endl;
    COUT(a, SIZE);

    int count = ValidElCount(a, SIZE);
    int sum = SUMValidEl(a, SIZE);

    cout << "�i���i��� �������i�, �� �����i 6 ��� i������ ���� �� �����i 5: " << count << endl;
    cout << "���� ��� �������i�: " << sum << endl;

    Nulls(a, SIZE);

    cout << "�����i������� �����: " << endl;
    COUT(a, SIZE);

    return 0;
}
