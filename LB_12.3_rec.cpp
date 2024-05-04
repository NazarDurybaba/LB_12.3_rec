#include <iostream>
#include <Windows.h>

using namespace std;

// Структура, що представляє вузол двунаправленого списку
struct Node {
    int data;   // Дані вузла
    Node* prev;   // Вказівник на попередній вузол
    Node* next;   // Вказівник на наступний вузол
};

// Функція для створення двунаправленого списку на основі масиву значень
Node* createListRecursive(Node* head, Node* tail, int values[], int index, int size) {
    if (index >= size) // Базовий випадок: коли досягнуто кінця масиву значень
        return head;

    Node* newNode = new Node(); // Створення нового вузла
    newNode->data = values[index]; // Присвоєння значення вузлу
    newNode->prev = tail; // Вказівник на попередній вузол
    newNode->next = nullptr; // Початкове значення вказівника на наступний вузол

    if (head == nullptr) // Якщо список порожній
        head = newNode;
    else
        tail->next = newNode; // Додавання нового вузла після кінцевого вузла

    return createListRecursive(head, newNode, values, index + 1, size); // Рекурсивний виклик для наступного елементу
}

// Функція для видалення кожного елементу списку, який слідує за елементом з заданим значенням
void removeNextElementsRecursive(Node* current, int targetValue) {
    if (current == nullptr || current->next == nullptr) // Базовий випадок: коли досягнуто кінця списку
        return;

    if (current->data == targetValue) { // Якщо значення поточного вузла співпадає з цільовим значенням
        Node* temp = current->next; // Тимчасовий вказівник на наступний вузол
        current->next = temp->next; // Видалення наступного вузла
        if (temp->next != nullptr) // Перевірка, чи існує наступний вузол
            temp->next->prev = current; // Встановлення вказівника на попередній вузол для наступного вузла
        delete temp; // Видалення тимчасового вузла
        removeNextElementsRecursive(current, targetValue); // Повторний виклик функції для перевірки наступного вузла
    }
    else {
        removeNextElementsRecursive(current->next, targetValue); // Рекурсивний виклик для наступного елементу
    }
}

// Функція для виведення значень усіх вузлів у списку
void printListRecursive(Node* current) {
    if (current == nullptr) // Базовий випадок: коли досягнуто кінця списку
        return;
    cout << current->data << " "; // Виведення значення поточного вузла
    printListRecursive(current->next); // Рекурсивний виклик для наступного елементу
}

// Функція для видалення всього списку та звільнення пам'яті
void deleteListRecursive(Node* current) {
    if (current == nullptr) // Базовий випадок: коли досягнуто кінця списку
        return;
    Node* temp = current; // Тимчасовий вказівник на поточний вузол
    deleteListRecursive(current->next); // Рекурсивний виклик для наступного елементу
    delete temp; // Звільнення пам'яті, щоб була виділена для поточного вузла
}

int main() {
    SetConsoleOutputCP(1251);
    int values[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };  // Масив значень для створення списку
    int size = sizeof(values) / sizeof(values[0]);  // Розмір масиву

    Node* head = createListRecursive(nullptr, nullptr, values, 0, size);  // Створення двунаправленого списку

    cout << "Список елементів:" << endl;
    printListRecursive(head);  // Виведення елементів списку
    cout << endl;

    int targetValue;
    cout << "Введіть значення, за яким слідує видалити елементи: ";
    cin >> targetValue; // Введення значення користувачем

    removeNextElementsRecursive(head, targetValue); // Видалення елементів, що слідують за заданим значенням

    cout << "Список елементів після видалення:" << endl;
    printListRecursive(head); // Виведення елементів списку після видалення
    cout << endl;

    deleteListRecursive(head);  // Видалення списку та звільнення пам'яті

    return 0;
}
