#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// Функция для вычисления факториала числа n
string factorial(int n) {
    vector<int> result(1, 1); // вектор для хранения результата, инициализируем его 1 (0!)

    for (int i = 2; i <= n; ++i) {
        int carry = 0;

        // Умножаем каждый элемент результата на i
        for (int j = 0; j < result.size(); ++j) {
            int product = result[j] * i + carry;
            result[j] = product % 10; // оставляем последнюю цифру
            carry = product / 10; // перенос
        }

        // Добавляем перенос, если он остался
        while (carry > 0) {
            result.push_back(carry % 10);
            carry /= 10;
        }
    }

    // Результат получается в обратном порядке, переворачиваем
    reverse(result.begin(), result.end());

    // Преобразуем в строку
    string factorial_result;
    for (int digit : result) {
        factorial_result.push_back(digit + '0');
    }

    return factorial_result;
}

// Функция для вычисления (n!)! для n >= 3
string factorialOfFactorial(int n) {
    // Сначала вычисляем n!
    string n_factorial = factorial(n);

    // Выводим n!
    cout << n << "! = " << n_factorial << endl;

    // Теперь вычисляем (n!)!
    int m = 0;

    // Преобразуем строку в число, чтобы выполнить (n!)!
    for (char c : n_factorial) {
        m = m * 10 + (c - '0');
    }

    // Вычисляем (n!)!
    string factorial_of_factorial = factorial(m);

    return factorial_of_factorial;
}

// Функция для проверки, является ли строка числом
bool isNumber(const string& str) {
    for (char c : str) {
        if (!isdigit(c)) {
            return false;
        }
    }
    return true;
}

// Функция для получения корректного ввода от пользователя
int getInput() {
    string input;
    int n;

    while (true) {
        cout << "Введите значение n (n >= 3): ";
        getline(cin, input); // Считываем ввод в строку

        // Проверка на корректность ввода
        if (isNumber(input)) {
            n = stoi(input); // Преобразуем строку в число
            if (n >= 3) {
                break; // Ввод корректен, выходим из цикла
            }
        }
        cout << "Ошибка: n должно быть целым числом и больше или равно 3." << endl;
    }
    return n;
}

// Основная функция
int main() {
    setlocale(LC_ALL, "rus");

    int n = getInput(); // Получаем корректный ввод
    string result = factorialOfFactorial(n); // Вычисляем (n!)!

    if (!result.empty()) {
        cout << "(" << n << "!)! = " << result << endl;
    }

    return 0;
}
