#include <iostream>

using namespace std;

template<typename T>
class DoublyLinkedList {

private:

    class Node {
    public:
        T data;
        Node* prev;
        Node* next;

        Node(const T& value);
    };

    Node* head;
    Node* tail;
    size_t length;

public:

    DoublyLinkedList();

    ~DoublyLinkedList();

    void push_front(const T& value);

    void push_back(const T& value);

    void insert(size_t index, const T& value);

    void pop_front();

    void pop_back();

    void erase(size_t index);

    T& front();

    T& back();

    bool contains(const T& value) const;

    bool empty() const;

    size_t size() const;

    void clear();

    void print_forward() const;

    void print_backward() const;
};



template<typename T>
DoublyLinkedList<T>::Node::Node(const T& value) {
    data = value;
    prev = nullptr;
    next = nullptr;
}



template<typename T>
DoublyLinkedList<T>::DoublyLinkedList() {
    head = nullptr;
    tail = nullptr;
    length = 0;
}



template<typename T>
DoublyLinkedList<T>::~DoublyLinkedList() {
    clear();
}



template<typename T>
void DoublyLinkedList<T>::push_front(const T& value) {

    Node* newNode = new Node(value);

    newNode->next = head;

    if (head != nullptr) {
        head->prev = newNode;
    }

    head = newNode;

    if (tail == nullptr) {
        tail = head;
    }

    length++;
}



template<typename T>
void DoublyLinkedList<T>::push_back(const T& value) {

    Node* newNode = new Node(value);

    if (head == nullptr) {
        head = tail = newNode;
    }
    else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }

    length++;
}



template<typename T>
void DoublyLinkedList<T>::insert(size_t index, const T& value) {

    if (index > length) {
        return;
    }

    if (index == 0) {
        push_front(value);
        return;
    }

    if (index == length) {
        push_back(value);
        return;
    }

    Node* current = head;

    for (size_t i = 0; i < index; i++) {
        current = current->next;
    }

    Node* newNode = new Node(value);

    newNode->prev = current->prev;
    newNode->next = current;

    current->prev->next = newNode;
    current->prev = newNode;

    length++;
}



template<typename T>
void DoublyLinkedList<T>::pop_front() {

    if (head == nullptr) {
        return;
    }

    Node* temp = head;

    head = head->next;

    if (head != nullptr) {
        head->prev = nullptr;
    }
    else {
        tail = nullptr;
    }

    delete temp;

    length--;
}



template<typename T>
void DoublyLinkedList<T>::pop_back() {

    if (tail == nullptr) {
        return;
    }

    Node* temp = tail;

    tail = tail->prev;

    if (tail != nullptr) {
        tail->next = nullptr;
    }
    else {
        head = nullptr;
    }

    delete temp;

    length--;
}



template<typename T>
void DoublyLinkedList<T>::erase(size_t index) {

    if (index >= length) {
        return;
    }

    if (index == 0) {
        pop_front();
        return;
    }

    if (index == length - 1) {
        pop_back();
        return;
    }

    Node* current = head;

    for (size_t i = 0; i < index; i++) {
        current = current->next;
    }

    current->prev->next = current->next;
    current->next->prev = current->prev;

    delete current;

    length--;
}



template<typename T>
T& DoublyLinkedList<T>::front() {
    return head->data;
}



template<typename T>
T& DoublyLinkedList<T>::back() {
    return tail->data;
}



template<typename T>
bool DoublyLinkedList<T>::contains(const T& value) const {

    Node* current = head;

    while (current != nullptr) {

        if (current->data == value) {
            return true;
        }

        current = current->next;
    }

    return false;
}



template<typename T>
bool DoublyLinkedList<T>::empty() const {
    return length == 0;
}



template<typename T>
size_t DoublyLinkedList<T>::size() const {
    return length;
}



template<typename T>
void DoublyLinkedList<T>::clear() {

    Node* current = head;

    while (current != nullptr) {

        Node* temp = current;

        current = current->next;

        delete temp;
    }

    head = nullptr;
    tail = nullptr;
    length = 0;
}



template<typename T>
void DoublyLinkedList<T>::print_forward() const {

    Node* current = head;

    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }

    cout << "\n";
}



template<typename T>
void DoublyLinkedList<T>::print_backward() const {

    Node* current = tail;

    while (current != nullptr) {
        cout << current->data << " ";
        current = current->prev;
    }

    cout << "\n";
}



int main() {

    DoublyLinkedList<int> list;

    list.push_back(10);
    list.push_back(20);
    list.push_front(5);

    list.insert(1, 100);

    list.print_forward();

    list.print_backward();

    list.pop_front();

    list.pop_back();

    list.print_forward();

    cout << list.contains(100) << "\n";

    cout << list.front() << "\n";

    cout << list.back() << "\n";

    cout << list.size() << "\n";

    return 0;
}