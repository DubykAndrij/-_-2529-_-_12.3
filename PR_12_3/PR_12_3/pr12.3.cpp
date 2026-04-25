#include <iostream>
#include <windows.h>

using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

struct List {
    Node* head = nullptr;
    Node* tail = nullptr;
};

Node* createNode(int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->prev = nullptr;
    newNode->next = nullptr;
    return newNode;
}

void appendElement(List& list, int value) {
    Node* newNode = createNode(value);
    if (list.head == nullptr) {
        list.head = list.tail = newNode;
    }
    else {
        list.tail->next = newNode;
        newNode->prev = list.tail;
        list.tail = newNode;
    }
}

void printList(const List& list) {
    if (list.head == nullptr) {
        cout << "Список порожній." << endl;
        return;
    }
    Node* current = list.head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

void insertAfter(List& list, Node* current) {
    if (current == nullptr) return;

    Node* newNode = createNode(current->data);
    newNode->next = current->next;
    newNode->prev = current;

    if (current->next != nullptr) {
        current->next->prev = newNode;
    }
    else {
        list.tail = newNode;
    }
    current->next = newNode;
}

void duplicateElementsWithValue(List& list, int targetValue) {
    Node* current = list.head;
    while (current != nullptr) {
        if (current->data == targetValue) {
            insertAfter(list, current);
            current = current->next->next;
        }
        else {
            current = current->next;
        }
    }
}

void clearList(List& list) {
    Node* current = list.head;
    while (current != nullptr) {
        Node* next = current->next;
        delete current;
        current = next;
    }
    list.head = list.tail = nullptr;
}

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    List myList;
    int n, value, target;

    cout << "Введіть кількість елементів списку: ";
    cin >> n;

    cout << "Введіть елементи списку:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> value;
        appendElement(myList, value);
    }

    cout << "\nПочатковий список:" << endl;
    printList(myList);

    cout << "\nВведіть значення для дублювання: ";
    cin >> target;

    duplicateElementsWithValue(myList, target);

    cout << "\nРезультат після дублювання:" << endl;
    printList(myList);

    clearList(myList);
    return 0;
}