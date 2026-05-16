#include <iostream>

using namespace std;

template<typename T>
class Queue {

private:

    class Node {
    public:
        T data;
        Node* next;

        Node(const T& value);
    };

    Node* frontNode;
    Node* rearNode;
    size_t length;

public:

    Queue();

    ~Queue();

    void push(const T& value);

    void pop();

    T& front();

    T& back();

    bool empty() const;

    size_t size() const;

    void clear();

    void print() const;
};



template<typename T>
Queue<T>::Node::Node(const T& value) {
    data = value;
    next = nullptr;
}



template<typename T>
Queue<T>::Queue() {
    frontNode = nullptr;
    rearNode = nullptr;
    length = 0;
}



template<typename T>
Queue<T>::~Queue() {
    clear();
}



template<typename T>
void Queue<T>::push(const T& value) {

    Node* newNode = new Node(value);

    if (frontNode == nullptr) {
        frontNode = rearNode = newNode;
    }
    else {
        rearNode->next = newNode;
        rearNode = newNode;
    }

    length++;
}



template<typename T>
void Queue<T>::pop() {

    if (frontNode == nullptr) {
        return;
    }

    Node* temp = frontNode;

    frontNode = frontNode->next;

    delete temp;

    length--;

    if (frontNode == nullptr) {
        rearNode = nullptr;
    }
}



template<typename T>
T& Queue<T>::front() {
    return frontNode->data;
}



template<typename T>
T& Queue<T>::back() {
    return rearNode->data;
}



template<typename T>
bool Queue<T>::empty() const {
    return length == 0;
}



template<typename T>
size_t Queue<T>::size() const {
    return length;
}



template<typename T>
void Queue<T>::clear() {

    while (frontNode != nullptr) {

        Node* temp = frontNode;

        frontNode = frontNode->next;

        delete temp;
    }

    rearNode = nullptr;
    length = 0;
}



template<typename T>
void Queue<T>::print() const {

    Node* current = frontNode;

    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }

    cout << "\n";
}



int main() {

    Queue<int> q;

    q.push(10);
    q.push(20);
    q.push(30);

    q.print();

    q.pop();

    q.print();

    cout << q.front() << "\n";

    cout << q.back() << "\n";

    cout << q.size() << "\n";

    cout << q.empty() << "\n";

    return 0;
}