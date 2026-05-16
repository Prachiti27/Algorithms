#include <iostream>

using namespace std;

template<typename T>
class Stack {

private:

    class Node {
    public:
        T data;
        Node* next;

        Node(const T& value);
    };

    Node* topNode;
    size_t length;

public:

    Stack();

    ~Stack();

    void push(const T& value);

    void pop();

    T& top();

    bool empty() const;

    size_t size() const;

    void clear();

    void print() const;
};



template<typename T>
Stack<T>::Node::Node(const T& value) {
    data = value;
    next = nullptr;
}



template<typename T>
Stack<T>::Stack() {
    topNode = nullptr;
    length = 0;
}



template<typename T>
Stack<T>::~Stack() {
    clear();
}



template<typename T>
void Stack<T>::push(const T& value) {

    Node* newNode = new Node(value);

    newNode->next = topNode;

    topNode = newNode;

    length++;
}



template<typename T>
void Stack<T>::pop() {

    if (topNode == nullptr) {
        return;
    }

    Node* temp = topNode;

    topNode = topNode->next;

    delete temp;

    length--;
}



template<typename T>
T& Stack<T>::top() {
    return topNode->data;
}



template<typename T>
bool Stack<T>::empty() const {
    return length == 0;
}



template<typename T>
size_t Stack<T>::size() const {
    return length;
}



template<typename T>
void Stack<T>::clear() {

    while (topNode != nullptr) {

        Node* temp = topNode;

        topNode = topNode->next;

        delete temp;
    }

    length = 0;
}



template<typename T>
void Stack<T>::print() const {

    Node* current = topNode;

    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }

    cout << "\n";
}



int main() {

    Stack<int> st;

    st.push(10);
    st.push(20);
    st.push(30);

    st.print();

    st.pop();

    st.print();

    cout << st.top() << "\n";

    cout << st.size() << "\n";

    cout << st.empty() << "\n";

    return 0;
}