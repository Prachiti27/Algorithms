#include <iostream>

using namespace std;

template<typename T>
class SinglyLinkedList {

private:

    class Node {
    public:
        T data;
        Node* next;

        Node(const T& value);
    };

    Node* head;
    Node* tail;
    size_t length;

public:

    SinglyLinkedList();

    ~SinglyLinkedList();

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

    void print() const;
};

template<typename T>
SinglyLinkedList<T>::Node::Node(const T& value) {
    data = value;
    next = nullptr;
}

template<typename T>
SinglyLinkedList<T>::SinglyLinkedList() {
    head = nullptr;
    tail = nullptr;
    length = 0;
}

template<typename T>
SinglyLinkedList<T>::~SinglyLinkedList() {
    clear();
}

template<typename T>
void SinglyLinkedList<T>::push_front(const T& value) {

    Node* newNode = new Node(value);

    newNode->next = head;

    head = newNode;

    if (tail == nullptr) {
        tail = head;
    }

    length++;
}

template<typename T>
void SinglyLinkedList<T>::push_back(const T& value) {

    Node* newNode = new Node(value);

    if (head == nullptr) {
        head = tail = newNode;
    }
    else {
        tail->next = newNode;
        tail = newNode;
    }

    length++;
}

template<typename T>
void SinglyLinkedList<T>::insert(size_t index, const T& value) {

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

    Node* prev = head;

    for (size_t i = 0; i < index - 1; i++) {
        prev = prev->next;
    }

    Node* newNode = new Node(value);

    newNode->next = prev->next;

    prev->next = newNode;

    length++;
}

template<typename T>
void SinglyLinkedList<T>::pop_front() {

    if (head == nullptr) {
        return;
    }

    Node* temp = head;

    head = head->next;

    delete temp;

    length--;

    if (head == nullptr) {
        tail = nullptr;
    }
}

template<typename T>
void SinglyLinkedList<T>::pop_back() {

    if (head == nullptr) {
        return;
    }

    if (head == tail) {
        delete head;
        head = tail = nullptr;
        length = 0;
        return;
    }

    Node* prev = head;

    while (prev->next != tail) {
        prev = prev->next;
    }

    delete tail;

    tail = prev;

    tail->next = nullptr;

    length--;
}

template<typename T>
void SinglyLinkedList<T>::erase(size_t index) {

    if (index >= length) {
        return;
    }

    if (index == 0) {
        pop_front();
        return;
    }

    Node* prev = head;

    for (size_t i = 0; i < index - 1; i++) {
        prev = prev->next;
    }

    Node* temp = prev->next;

    prev->next = temp->next;

    if (temp == tail) {
        tail = prev;
    }

    delete temp;

    length--;
}

template<typename T>
T& SinglyLinkedList<T>::front() {
    return head->data;
}

template<typename T>
T& SinglyLinkedList<T>::back() {
    return tail->data;
}

template<typename T>
bool SinglyLinkedList<T>::contains(const T& value) const {

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
bool SinglyLinkedList<T>::empty() const {
    return length == 0;
}

template<typename T>
size_t SinglyLinkedList<T>::size() const {
    return length;
}

template<typename T>
void SinglyLinkedList<T>::clear() {

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
void SinglyLinkedList<T>::print() const {

    Node* current = head;

    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }

    cout << "\n";
}

int main() {

    SinglyLinkedList<int> list;

    list.push_back(10);
    list.push_back(20);
    list.push_front(5);

    list.insert(1, 100);

    list.print();

    list.pop_front();

    list.print();

    list.pop_back();

    list.print();

    cout << list.contains(20) << "\n";

    cout << list.front() << "\n";

    cout << list.back() << "\n";

    cout << list.size() << "\n";

    return 0;
}