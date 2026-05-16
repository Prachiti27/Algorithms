#include <iostream>

using namespace std;

template<typename T>
class Deque {

private:

    class Node {
    public:
        T data;
        Node* prev;
        Node* next;

        Node(const T& value);
    };

    Node* frontNode;
    Node* rearNode;
    size_t length;

public:

    Deque();

    ~Deque();

    void push_front(const T& value);

    void push_back(const T& value);

    void pop_front();

    void pop_back();

    T& front();

    T& back();

    bool empty() const;

    size_t size() const;

    void clear();

    void print() const;
};



template<typename T>
Deque<T>::Node::Node(const T& value) {
    data = value;
    prev = nullptr;
    next = nullptr;
}



template<typename T>
Deque<T>::Deque() {
    frontNode = nullptr;
    rearNode = nullptr;
    length = 0;
}



template<typename T>
Deque<T>::~Deque() {
    clear();
}



template<typename T>
void Deque<T>::push_front(const T& value) {

    Node* newNode = new Node(value);

    if (frontNode == nullptr) {
        frontNode = rearNode = newNode;
    }
    else {
        newNode->next = frontNode;
        frontNode->prev = newNode;
        frontNode = newNode;
    }

    length++;
}



template<typename T>
void Deque<T>::push_back(const T& value) {

    Node* newNode = new Node(value);

    if (rearNode == nullptr) {
        frontNode = rearNode = newNode;
    }
    else {
        rearNode->next = newNode;
        newNode->prev = rearNode;
        rearNode = newNode;
    }

    length++;
}



template<typename T>
void Deque<T>::pop_front() {

    if (frontNode == nullptr) {
        return;
    }

    Node* temp = frontNode;

    frontNode = frontNode->next;

    if (frontNode != nullptr) {
        frontNode->prev = nullptr;
    }
    else {
        rearNode = nullptr;
    }

    delete temp;

    length--;
}



template<typename T>
void Deque<T>::pop_back() {

    if (rearNode == nullptr) {
        return;
    }

    Node* temp = rearNode;

    rearNode = rearNode->prev;

    if (rearNode != nullptr) {
        rearNode->next = nullptr;
    }
    else {
        frontNode = nullptr;
    }

    delete temp;

    length--;
}



template<typename T>
T& Deque<T>::front() {
    return frontNode->data;
}



template<typename T>
T& Deque<T>::back() {
    return rearNode->data;
}



template<typename T>
bool Deque<T>::empty() const {
    return length == 0;
}



template<typename T>
size_t Deque<T>::size() const {
    return length;
}



template<typename T>
void Deque<T>::clear() {

    while (frontNode != nullptr) {

        Node* temp = frontNode;

        frontNode = frontNode->next;

        delete temp;
    }

    rearNode = nullptr;
    length = 0;
}



template<typename T>
void Deque<T>::print() const {

    Node* current = frontNode;

    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }

    cout << "\n";
}



int main() {

    Deque<int> dq;

    dq.push_front(10);
    dq.push_front(20);

    dq.push_back(30);
    dq.push_back(40);

    dq.print();

    dq.pop_front();

    dq.print();

    dq.pop_back();

    dq.print();

    cout << dq.front() << "\n";

    cout << dq.back() << "\n";

    cout << dq.size() << "\n";

    cout << dq.empty() << "\n";

    return 0;
}