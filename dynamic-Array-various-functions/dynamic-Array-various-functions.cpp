//Завдання 1. Написати такі функції для роботи з дина_мічним масивом:
//■ Функція розподілу динамічної пам’яті;
//■ Функція ініціалізації динамічного масиву;
//■ Функція друку динамічного масиву;
//■ Функція видалення динамічного масиву;
//■ Функція додавання елемента в кінець масиву;
//■ Функція вставки елемента за вказаним індексом;
//■ Функція видалення елемента за вказаним індексом.
#include <iostream>
#include <ctime>
#include <Windows.h>// підключення заголовного файлу Windows.h, завдяки чому зможемо використовувати українську мову
using namespace std;
void divisionArr(int size);//■ Функція розподілу динамічної пам’яті;
void inputArr(int* arr, int size);//■ Функція ініціалізації динамічного масиву;
void printArr(const int* arr, const int size);//■ Функція друку динамічного масиву;
void deleteArr(const int* arr, const int size);//■ Функція видалення динамічного масиву;
void addArr(int*& arr, int& size);//■ Функція додавання елемента в кінець масиву;
void addArrIndex(int*& arr, int& size);//■ Функція вставки елемента за вказаним індексом;
void delArrIndex(int*& arr, int& size);//■ Функція видалення елемента за вказаним індексом.
int main()
{
    srand(time(NULL));//завдяки даній функції, рандомні числа будуть постійно змінюватись 
    SetConsoleCP(1251); // встановлення кодування Windows-1251 в  потік введення
    SetConsoleOutputCP(1251); // встановлення кодування Windows-1251 в  потік виведення
    int size = 1;//оголошуємо розмірність першого масиву size
    cout << "Введіть розмір   size  елементів  масиву" << endl;
    cin >> size;
    int* arr = new int[size];// оголошуємо вказівник  arr 
    divisionArr(size);// звертаємось до функції розподілу динамічної пам’яті;
    inputArr(arr, size);//звертаємось до функції inputArr 
    cout << "Елементи  масиву" << endl;
    printArr(arr, size);//звертаємось до функції printArr 
    addArr(arr, size);// звертаємось до функції додавання елемента в кінець масиву;
    cout << "Елементи  масиву з додавання елемента в кінець масиву" << endl;
    printArr(arr, size); //звертаємось до функції printArr
    addArrIndex(arr, size);// звертаємось до функції вставки елемента за вказаним індексом
    cout << "Елементи  масиву із вставкою елемента за вказаним індексом" << endl;
    printArr(arr, size); //звертаємось до функції printArr
    delArrIndex(arr, size);// звертаємось до функції видалення елемента за вказаним індексом.
    cout << "Елементи масиву із видаленням елемента за вказаним індексом" << endl;
    printArr(arr, size - 1); //звертаємось до функції printArr
    delete[]arr;//видаляємо вміст масиву
}
void divisionArr(int size) {//■ Функція розподілу динамічної пам’яті;
    int* arr = new int[size];
}
void inputArr(int* arr, int size) {//функція ініціалізації динамічного масиву;
    for (int i = 0; i < size; i++)
    {
        arr[i] = rand() % 100;//рандомно заповнюєм масив числами
    }
}
void printArr(const int* arr, const int size) {//функція друку динамічного масиву
    for (int i = 0; i < size; i++)
    {
        cout << "arr[" << i << "]=" << " " << arr[i] << "\t";
    }
    cout << endl;
}
void deleteArr(const int* arr, const int size) {//функція видалення динамічного масиву
    delete[] arr;
}
void addArr(int*& arr, int& size) {//Функція додавання елемента в кінець масиву;
    int element;//оголошуємо змінну element
    int* newArr = new int[size + 1];//створюємо вказівник на новий масив
    cout << "Введіть будь-яке число" << endl;
    cin >> element;

    for (int i = 0; i < size; i++)
    {
        newArr[i] = arr[i];//присвоюємо значенна масиву arr в новий масив newArr
    }
    newArr[size++] = element;//додаємо елемент до масиву newArr
    delete[]arr;//очищаємо масив arr
    arr = newArr;//присвоюємо значення масиву newArr до масиву arr

}
void delArrIndex(int*& arr, int& size) {//Функція видалення елемента за вказаним індексом;
    int index; //оголошуємо змінну index
    int* newArr = new int[size - 1]; //створюємо вказівник на новий масив
    cout << "Введіть індекс масиву" << endl;
    cin >> index;
    if (index >=0 and index<size) {//умова, при якій потрібно вводити індекс масиву
        for (int i = 0; i < size; i++)
        {
            newArr[i] = arr[i]; //присвоюємо значенна масиву arr в новий масив newArr
        }
        newArr[index] = arr[index + 1];//присвоюємо елементи масиву arr від індекса 0 до вказаного індексу +1 в масив newArr, який має розмірність index

        for (int i = index; i < size; i++)
        {
            newArr[i] = arr[i + 1];//присвоюємо значення елементів масиву, нерахуючи індекс, до size, тобто newArr не містить елемент, який знаходиться під вказаним індексом
        }
        arr = newArr; //присвоюємо значення масиву newArr до масиву arr
    }
    else {
        cout << " Невірний індекс" << endl;
    }
}
void addArrIndex(int*& arr, int& size) {//Функція вставки елемента за вказаним індексом;
    int element; //оголошуємо змінну element
    int index; //оголошуємо змінну index
    int* newArr = new int[size]; //створюємо вказівник на новий масив
    cout << "Введіть будь-яке число" << endl;
    cin >> element;
    cout << "Введіть індекс масиву" << endl;
    cin >> index;
    if (index >=0 and index < size) {//умова, при якій потрібно вводити індекс масиву
        for (int i = 0; i < size; i++)
        {
            newArr[i] = arr[i]; //присвоюємо значенна масиву arr в новий масив newArr
        }
        newArr[index] = arr[index - 1]; //присвоюємо елементи масиву arr від індекса 0 до вказаного індексу -1 в масив newArr, який має розмірність index, тобто елемента під вказаним індексом немає

        for (int i = size; i<index; i--)

        {
            newArr[i] = arr[i - 1]; //присвоюємо елементи масиву arr від size-1 до вказаного індексу в масив newArr, який має розмірність size
        }
        newArr[index] = element; //додаємо елемент до масиву newArr
        arr = newArr; //присвоюємо значення масиву newArr до масиву arr
    }
    else {
        cout << " Невірний індекс" << endl;
    }
}
