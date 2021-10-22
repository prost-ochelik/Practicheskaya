#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <conio.h>
#include <cmath>
#include <bitset>

using namespace std;

void ex1() {
    cout << "int:\t\t" << sizeof(int) << " bytes" << endl;
    cout << "short int:\t" << sizeof(short int) << " bytes" << endl;
    cout << "long int:\t" << sizeof(long int) << " bytes" << endl;
    cout << "float:\t\t" << sizeof(float) << " bytes" << endl;
    cout << "double:\t\t" << sizeof(double) << " bytes" << endl;
    cout << "long double:\t" << sizeof(long double) << " bytes" << endl;
    cout << "char:\t\t" << sizeof(char) << " bytes" << endl;
    cout << "bool:\t\t" << sizeof(bool) << " bytes" << endl;
}

void ex2() {
    cout << "Введите число для перевода: ";

    int input;

    cin >> input;

    const int size_of_input = sizeof(input) * 8;
    int mask = 1 << size_of_input - 2;


    cout << "100% правильный ответ (для сравнения с ответом алгоритма)" << endl << bitset<size_of_input>(input) << endl << endl;
    cout << "\x1b[31mКрасный\x1b[0m - знаковый бит\n" << "\x1b[32mЗеёлный\x1b[0m - двоичный код числа\n";

    if (input < 0) {
        cout << "\x1b[31m1 \x1b[0m";
        input =- input;
    } else {
        cout << "\x1b[31m0 \x1b[0m";
    }


    for (int i = 1; i < size_of_input ; i++) {
        if (i % 8 == 0) {
            cout << " ";
        }
        cout << "\x1b[32m" << (input & mask ? '1' : '0') << "\x1b[0m";
        input <<= 1;
    }
}

void ex3() {
    cout << "Введите число для перевода: ";
    
    float input;
    cin >> input;

    int length_of_mantiss;
    cout << "Я глупенький, сколько там цифр после запятой? ";
    cin >> length_of_mantiss;

    cout << "\x1b[31mКрасный\x1b[0m - знаковый бит\n" << "\x1b[32mЗелёный\x1b[0m - порядок\n" << "\x1b[34mСиний\x1b[0m - мантисса\n";

    if (input < 0) {
        cout << "\x1b[31m1 \x1b[0m";
        input = -input;
    }
    else {
        cout << "\x1b[31m0 \x1b[0m";
    }

    int intpart, fractpart, size_of_input;
    size_of_input = sizeof(input) * 8;
    int mask = 1 << size_of_input / 2 - 2;

    intpart = input;
    fractpart = (input - intpart) * pow(10, length_of_mantiss);


    for (int i = 1; i < size_of_input / 2; i++) {
        if (i % 8 == 0) {
            cout << " ";
        }
        cout << "\x1b[32m" << (intpart & mask ? '1' : '0') << "\x1b[0m";
        intpart <<= 1;
    }

    cout << " ";
    mask = 1 << size_of_input / 2 - 2;

    for (int i = 1; i < size_of_input / 2; i++) {
        if (i % 8 == 0) {
            cout << " ";
        }
        cout << "\x1b[34m" << (fractpart & mask ? '1' : '0') << "\x1b[0m";
        fractpart <<= 1;
    }
}

void ex4() {
    cout << "Введите число для перевода: ";

    double input;
    cin >> input;

    int length_of_mantiss;
    cout << "Я глупенький, сколько там цифр после запятой? ";
    cin >> length_of_mantiss;

    cout << "\x1b[31mКрасный\x1b[0m - знаковый бит\n" << "\x1b[32mЗелёный\x1b[0m - порядок\n" << "\x1b[34mСиний\x1b[0m - мантисса\n";

    if (input < 0) {
        cout << "\x1b[31m1 \x1b[0m";
        input = -input;
    }
    else {
        cout << "\x1b[31m0 \x1b[0m";
    }

    int intpart, fractpart, size_of_input;
    size_of_input = sizeof(input) * 8;
    int mask = 1 << size_of_input / 2 - 2;

    intpart = input;
    fractpart = (input - intpart) * pow(10, length_of_mantiss);


    for (int i = 1; i < size_of_input / 2; i++) {
        if (i % 8 == 0) {
            cout << " ";
        }
        cout << "\x1b[32m" << (intpart & mask ? '1' : '0') << "\x1b[0m";
        intpart <<= 1;
    }

    cout << " ";
    mask = 1 << size_of_input / 2 - 2;

    for (int i = 1; i < size_of_input / 2; i++) {
        if (i % 8 == 0) {
            cout << " ";
        }
        cout << "\x1b[34m" << (fractpart & mask ? '1' : '0') << "\x1b[0m";
        fractpart <<= 1;
    }
}

int main()
{
    setlocale(LC_CTYPE, "rus"); //чтобы кириллица выводилась корректно

    for (;;) {
        cout << "Выберите пункт от 0 до 3, который вас интересует" << endl;
        cout << "1. Задание 1" << endl;
        cout << "2. Задание 2" << endl;
        cout << "3. Задание 3" << endl;
        cout << "4. Задание 4" << endl;
        cout << "0. Выход" << endl;
        char choice;
        cin >> choice;
        system("cls");
        switch (choice) {
        case '1':
            ex1();
            _getch();
            system("cls");
            break;

        case '2':
            ex2();
            _getch();
            system("cls");
            break;

        case '3':
            ex3();
            _getch();
            system("cls");
            break;

        case '4':
            ex4();
            _getch();
            system("cls");
            break;

        case '0':
            return 0;
            break;

        default:
            cout << "Incorrect input\n" << endl;
            break;
        }
    }
}