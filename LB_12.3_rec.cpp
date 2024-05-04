#include <iostream>
#include <Windows.h>

using namespace std;

// ���������, �� ����������� ����� ��������������� ������
struct Node {
    int data;   // ��� �����
    Node* prev;   // �������� �� ��������� �����
    Node* next;   // �������� �� ��������� �����
};

// ������� ��� ��������� ��������������� ������ �� ����� ������ �������
Node* createListRecursive(Node* head, Node* tail, int values[], int index, int size) {
    if (index >= size) // ������� �������: ���� ��������� ���� ������ �������
        return head;

    Node* newNode = new Node(); // ��������� ������ �����
    newNode->data = values[index]; // ��������� �������� �����
    newNode->prev = tail; // �������� �� ��������� �����
    newNode->next = nullptr; // ��������� �������� ��������� �� ��������� �����

    if (head == nullptr) // ���� ������ �������
        head = newNode;
    else
        tail->next = newNode; // ��������� ������ ����� ���� �������� �����

    return createListRecursive(head, newNode, values, index + 1, size); // ����������� ������ ��� ���������� ��������
}

// ������� ��� ��������� ������� �������� ������, ���� ���� �� ��������� � ������� ���������
void removeNextElementsRecursive(Node* current, int targetValue) {
    if (current == nullptr || current->next == nullptr) // ������� �������: ���� ��������� ���� ������
        return;

    if (current->data == targetValue) { // ���� �������� ��������� ����� ������� � �������� ���������
        Node* temp = current->next; // ���������� �������� �� ��������� �����
        current->next = temp->next; // ��������� ���������� �����
        if (temp->next != nullptr) // ��������, �� ���� ��������� �����
            temp->next->prev = current; // ������������ ��������� �� ��������� ����� ��� ���������� �����
        delete temp; // ��������� ����������� �����
        removeNextElementsRecursive(current, targetValue); // ��������� ������ ������� ��� �������� ���������� �����
    }
    else {
        removeNextElementsRecursive(current->next, targetValue); // ����������� ������ ��� ���������� ��������
    }
}

// ������� ��� ��������� ������� ��� ����� � ������
void printListRecursive(Node* current) {
    if (current == nullptr) // ������� �������: ���� ��������� ���� ������
        return;
    cout << current->data << " "; // ��������� �������� ��������� �����
    printListRecursive(current->next); // ����������� ������ ��� ���������� ��������
}

// ������� ��� ��������� ������ ������ �� ��������� ���'��
void deleteListRecursive(Node* current) {
    if (current == nullptr) // ������� �������: ���� ��������� ���� ������
        return;
    Node* temp = current; // ���������� �������� �� �������� �����
    deleteListRecursive(current->next); // ����������� ������ ��� ���������� ��������
    delete temp; // ��������� ���'��, ��� ���� ������� ��� ��������� �����
}

int main() {
    SetConsoleOutputCP(1251);
    int values[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };  // ����� ������� ��� ��������� ������
    int size = sizeof(values) / sizeof(values[0]);  // ����� ������

    Node* head = createListRecursive(nullptr, nullptr, values, 0, size);  // ��������� ��������������� ������

    cout << "������ ��������:" << endl;
    printListRecursive(head);  // ��������� �������� ������
    cout << endl;

    int targetValue;
    cout << "������ ��������, �� ���� ���� �������� ��������: ";
    cin >> targetValue; // �������� �������� ������������

    removeNextElementsRecursive(head, targetValue); // ��������� ��������, �� ������� �� ������� ���������

    cout << "������ �������� ���� ���������:" << endl;
    printListRecursive(head); // ��������� �������� ������ ���� ���������
    cout << endl;

    deleteListRecursive(head);  // ��������� ������ �� ��������� ���'��

    return 0;
}
