#include <iostream>
#include <string>
#include <stdarg.h>
#include <chrono>


// 1. Создайте класс Phone, который содержит переменные number, model и weight.

using namespace std;

class Phone {
public:
    string number;
    string model;
    int weight{};

    // г) Добавить конструктор в класс Phone, который принимает на вход три параметра для
    // инициализации переменных класса - number, model и weight.
//    Phone(string num, string mod, int wgt) {
//        number = num;
//        model = mod;
//        weight = wgt;
//    }
    // ж) Вызвать из конструктора с тремя параметрами конструктор с двумя.
    Phone(string num, string mod, int wgt) : Phone(mod, wgt) {
        if (num.empty()) {
            throw invalid_argument("Номер телефона не может быть пустым");
        }
        if (mod.empty()) {
            throw invalid_argument("Модель телефона не может быть пустой");
        }
        if (wgt <= 0) {
            throw invalid_argument("Вес должен быть больше 0");
        }

        number = num;
    }

    // д) Добавить конструктор, который принимает на вход два параметра для
    // инициализации переменных класса - number, model.
    Phone(string mod, int wgt) {
        model = mod;
        weight = wgt;
    }

    // е) Добавить конструктор без параметров.
    Phone() = default;


    // в) Добавить в класс Phone методы: receiveCall, имеет один параметр – имя звонящего.
    // Выводит на консоль сообщение “Звонит {name}”.
    static void receiveCall(string name) {
        cout << "Звонит: " << name << endl;
    }

    // в) Метод getNumber – возвращает номер телефона. Вызвать эти методы для каждого из объектов.
    string getNumber() {
        return number;
    }

    // з) Добавьте перегруженный метод receiveCall, который принимает два параметра -
    // имя звонящего и номер телефона звонящего. Вызвать этот метод.
    static void receiveCall(string caller_name, string caller_number) {
        cout << "Звонит: " << caller_name << " Номер телефона: " << caller_number << endl;
    }

    void sendMessage(int num, ...) {
        va_list args;
        va_start(args, num);

        for (int i = 0; i < num; i++) {
            const char *phoneNumber = va_arg(args, const char*);
            cout << "Отправляю сообщение на номер: " << phoneNumber << " с номера: " << number << endl;
        }

        va_end(args);
    }


};

void ex_1() {
    // а) Создайте три экземпляра этого класса.
    Phone phone1{"+7(598)455-86-87", "iPhone 15 Pro Max", 150};
    Phone phone2{"+7(904)935-52-98", "Galaxy S23 Ultra", 120};
    Phone phone3{"+7(377)582-79-97", "Pixel 8 Pro", 110};

    // б) Выведите на консоль значения их переменных.
    cout << "Телефон 1: " << phone1.number << ", " << phone1.model << ", " << phone1.weight << endl;
    cout << "Телефон 2: " << phone2.number << ", " << phone2.model << ", " << phone2.weight << endl;
    cout << "Телефон 3: " << phone3.number << ", " << phone3.model << ", " << phone3.weight << endl;

    // в) Добавить в класс Phone методы: receiveCall, имеет один параметр – имя звонящего.
    // Выводит на консоль сообщение “Звонит {name}”.
    // Метод getNumber – возвращает номер телефона. Вызвать эти методы для каждого из объектов.
    phone1.receiveCall("Иванушка");
    cout << phone1.getNumber() << endl;
    phone2.receiveCall("Машенька");
    cout << phone2.getNumber() << endl;
    phone3.receiveCall("Васенька");
    cout << phone3.getNumber() << endl;

    // з) Добавьте перегруженный метод receiveCall, который принимает два параметра -
    // имя звонящего и номер телефона звонящего. Вызвать этот метод.
    phone1.receiveCall("Альфа-банк", "+7(904)935-52-98");

    // и) Создать метод sendMessage с аргументами переменной длины. Данный метод принимает на вход номера телефонов,
    // которым будет отправлено сообщение. Метод выводит на консоль номера этих телефонов.
    phone1.sendMessage(3, "555-1234", "555-5678", "555-9012");
}

// Linear search
int linearSearch(long arr[], int n, int x) {
    for (int i = 0; i < n; i++)
        if (arr[i] == x)
            return i;
    return -1;
}

// Binary search
int binarySearch(long arr[], int l, int r, int x) {
    if (r >= l) {
        int mid = l + (r - l) / 2;
        if (arr[mid] == x)
            return mid;
        if (arr[mid] > x)
            return binarySearch(arr, l, mid - 1, x);
        return binarySearch(arr, mid + 1, r, x);
    }
    return -1;
}

void ex_2() {
    // 2. Напишите метод, который проверяет, входит ли в массив заданный элемент или нет.
    // Используйте перебор и двоичный поиск для решения этой задачи.
    // Сравните время выполнения обоих решений для больших массивов (например, 100000000 элементов).
    cout << endl << "Задание 2." << endl;
    const long n = 100000000L;
    long *arr = new long[n];
    for (long i = 0; i < n; i++) {
        arr[i] = i;
    }

    int x = 9999999;

    auto start = chrono::high_resolution_clock::now();
    int index = linearSearch(arr, n, x);
    auto stop = chrono::high_resolution_clock::now();
    auto linear_duration = chrono::duration_cast<chrono::microseconds>(stop - start);

    start = chrono::high_resolution_clock::now();
    index = binarySearch(arr, 0, n - 1, x);
    stop = chrono::high_resolution_clock::now();
    auto binary_duration = chrono::duration_cast<chrono::microseconds>(stop - start);

    cout << "Время линейного поиска: " << linear_duration.count() << " микросекунд" << endl;
    cout << "Время бинарного поиска: " << binary_duration.count() << " микросекунд" << endl;
}

int main() {
    ex_1();
    ex_2();
    return 0;
}