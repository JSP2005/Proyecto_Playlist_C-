/*
* queuePlaylist.h
* Jose Suberbie Pons
* A01713050
*/
#ifndef QUEUEPLAYLIST_H
#define QUEUEPLAYLIST_H

#include <iostream>
#include <sstream>
using namespace std;

template <class T>
struct Nodo {
    T valor;
    Nodo<T>* next;
    Nodo(const T& v);
};

template <class T>
class QueuePlaylist {
private:
    Nodo<T>* front;
    Nodo<T>* tail;
    int counter;

public:
    QueuePlaylist();
    ~QueuePlaylist();

    bool empty() const;
    void enqueue(const T& valor);
    void dequeue();
    T getFront() const;
    string toString() const;
};

template <class T>
Nodo<T>::Nodo(const T& v) : valor(v), next(nullptr) {}

template <class T>
QueuePlaylist<T>::QueuePlaylist() : front(nullptr), tail(nullptr), counter(0) {}

template <class T>
QueuePlaylist<T>::~QueuePlaylist() {
    while (!empty()) dequeue();
}

template <class T>
bool QueuePlaylist<T>::empty() const {
    return counter == 0;
}

template <class T>
void QueuePlaylist<T>::enqueue(const T& valor) {
    Nodo<T>* nuevo = new Nodo<T>(valor);
    if (empty()) {
        front = tail = nuevo;
    } else {
        tail->next = nuevo;
        tail = nuevo;
    }
    counter++;
}

template <class T>
void QueuePlaylist<T>::dequeue() {
    if (empty()) {
        cout << "La cola esta vacia.\n";
        return;
    }

    Nodo<T>* temp = front;
    front = front->next;
    delete temp;
    counter--;

    if (counter == 0)
        tail = nullptr;
}

template <class T>
T QueuePlaylist<T>::getFront() const {
    if (empty())
        throw runtime_error("La cola esta vacia.");
    return front->valor;
}

template <class T>
string QueuePlaylist<T>::toString() const {
    if (empty())
        return "La cola esta vacia.\n";

    stringstream ss;
    Nodo<T>* actual = front;
    int i = 1;

    while (actual != nullptr) {
        ss << i++ << ". " << actual->valor << "\n";
        actual = actual->next;
    }

    return ss.str();
}

#endif

