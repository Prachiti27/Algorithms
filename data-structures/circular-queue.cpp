#include <iostream>

using namespace std;

template<typename T>
class CircularQueue {

private:

    T* arr;

    size_t capacity;
    size_t frontIndex;
    size_t rearIndex;
    size_t length;

public:

    CircularQueue(size_t size);

    ~CircularQueue();

    void push(const T& value);

    void pop();

    T& front();

    T& back();

    bool empty() const;

    bool full() const;

    size_t size() const;

    void clear();

    void print() const;
};



template<typename T>
CircularQueue<T>::CircularQueue(size_t size) {

    capacity = size;

    arr = new T[capacity];

    frontIndex = 0;

    rearIndex = capacity - 1;

    length = 0;
}



template<typename T>
CircularQueue<T>::~CircularQueue() {
    delete[] arr;
}



template<typename T>
void CircularQueue<T>::push(const T& value) {

    if (full()) {
        return;
    }

    rearIndex = (rearIndex + 1) % capacity;

    arr[rearIndex] = value;

    length++;
}



template<typename T>
void CircularQueue<T>::pop() {

    if (empty()) {
        return;
    }

    frontIndex = (frontIndex + 1) % capacity;

    length--;
}



template<typename T>
T& CircularQueue<T>::front() {
    return arr[frontIndex];
}



template<typename T>
T& CircularQueue<T>::back() {
    return arr[rearIndex];
}



template<typename T>
bool CircularQueue<T>::empty() const {
    return length == 0;
}



template<typename T>
bool CircularQueue<T>::full() const {
    return length == capacity;
}



template<typename T>
size_t CircularQueue<T>::size() const {
    return length;
}



template<typename T>
void CircularQueue<T>::clear() {

    frontIndex = 0;

    rearIndex = capacity - 1;

    length = 0;
}



template<typename T>
void CircularQueue<T>::print() const {

    if (empty()) {
        return;
    }

    size_t index = frontIndex;

    for (size_t i = 0; i < length; i++) {

        cout << arr[index] << " ";

        index = (index + 1) % capacity;
    }

    cout << "\n";
}



int main() {

    CircularQueue<int> q(5);

    q.push(10);
    q.push(20);
    q.push(30);

    q.print();

    q.pop();

    q.print();

    q.push(40);
    q.push(50);
    q.push(60);

    q.print();

    cout << q.front() << "\n";

    cout << q.back() << "\n";

    cout << q.size() << "\n";

    cout << q.empty() << "\n";

    cout << q.full() << "\n";

    return 0;
}