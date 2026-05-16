#include <iostream>

using namespace std;

template<typename T>
class CircularLinkedList {

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

    CircularLinkedList();

    ~CircularLinkedList();

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
CircularLinkedList<T>::Node::Node(const T& value) {
    data = value;
    next = nullptr;
}



template<typename T>
CircularLinkedList<T>::CircularLinkedList() {
    head = nullptr;
    tail = nullptr;
    length = 0;
}



template<typename T>
CircularLinkedList<T>::~CircularLinkedList() {
    clear();
}



template<typename T>
void CircularLinkedList<T>::push_front(const T& value) {

    Node* newNode = new Node(value);

    if (head == nullptr) {
        head = tail = newNode;
        tail->next = head;
    }
    else {
        newNode->next = head;
        head = newNode;
        tail->next = head;
    }

    length++;
}



template<typename T>
void CircularLinkedList<T>::push_back(const T& value) {

    Node* newNode = new Node(value);

    if (head == nullptr) {
        head = tail = newNode;
        tail->next = head;
    }
    else {
        tail->next = newNode;
        tail = newNode;
        tail->next = head;
    }

    length++;
}



template<typename T>
void CircularLinkedList<T>::insert(size_t index, const T& value) {

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
void CircularLinkedList<T>::pop_front() {

    if (head == nullptr) {
        return;
    }

    if (head == tail) {
        delete head;
        head = tail = nullptr;
        length = 0;
        return;
    }

    Node* temp = head;

    head = head->next;

    tail->next = head;

    delete temp;

    length--;
}



template<typename T>
void CircularLinkedList<T>::pop_back() {

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

    tail->next = head;

    length--;
}



template<typename T>
void CircularLinkedList<T>::erase(size_t index) {

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

    Node* prev = head;

    for (size_t i = 0; i < index - 1; i++) {
        prev = prev->next;
    }

    Node* temp = prev->next;

    prev->next = temp->next;

    delete temp;

    length--;
}



template<typename T>
T& CircularLinkedList<T>::front() {
    return head->data;
}



template<typename T>
T& CircularLinkedList<T>::back() {
    return tail->data;
}



template<typename T>
bool CircularLinkedList<T>::contains(const T& value) const {

    if (head == nullptr) {
        return false;
    }

    Node* current = head;

    do {

        if (current->data == value) {
            return true;
        }

        current = current->next;

    } while (current != head);

    return false;
}



template<typename T>
bool CircularLinkedList<T>::empty() const {
    return length == 0;
}



template<typename T>
size_t CircularLinkedList<T>::size() const {
    return length;
}



template<typename T>
void CircularLinkedList<T>::clear() {

    if (head == nullptr) {
        return;
    }

    Node* current = head->next;

    while (current != head) {

        Node* temp = current;

        current = current->next;

        delete temp;
    }

    delete head;

    head = nullptr;
    tail = nullptr;
    length = 0;
}



template<typename T>
void CircularLinkedList<T>::print() const {

    if (head == nullptr) {
        return;
    }

    Node* current = head;

    do {
        cout << current->data << " ";
        current = current->next;
    } while (current != head);

    cout << "\n";
}



int main() {

    CircularLinkedList<int> list;

    list.push_back(10);
    list.push_back(20);
    list.push_front(5);

    list.insert(1, 100);

    list.print();

    list.pop_front();

    list.print();

    list.pop_back();

    list.print();

    cout << list.contains(100) << "\n";

    cout << list.front() << "\n";

    cout << list.back() << "\n";

    cout << list.size() << "\n";

    return 0;
}