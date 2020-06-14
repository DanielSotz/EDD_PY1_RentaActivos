#ifndef CIRCULARDOBRE_H
#define CIRCULARDOBRE_H

#include <iostream>
using namespace std;

template<class T>
class CircularDobre
{
    class Nodo{
    public:
        Nodo(T x)
        {
            next=0;
            before=0;
            dato=x;
        }

        Nodo* getNext() { return next; }
        Nodo* getBefore() { return before; }
        void setNext(Nodo* n) { next = n; }
        void setBefore(Nodo* n) { before = n; }
        T getDato() { return dato; }

    private:
        Nodo* next;
        Nodo* before;
        T dato;
    };


    public:
        CircularDobre()
        {
            first = 0;
            last = 0;
            size = 0;
        }

        int getSize() { return size; }
        void add_first(T dato);
        void add_last(T dato);
        void add_at(T dato, int index);
        T get_element_at(int index);

    private:

        bool isEmpty() { return size == 0; }
        int size;
        Nodo* first;
        Nodo* last;
};

template<class T>
void CircularDobre<T>::add_first(T dato)
{
    Nodo* n = new Nodo(dato);
    if (this->isEmpty())
    {
        this->first = n;
        this->last = n;
        n->setBefore(n);
        n->setNext(n);

        this->size++;
    }
    else
    {
        n->setNext(this->first);
        this->first->setBefore(n);
        n->setBefore(this->last);
        this->last->setNext(n);
        this->first = n;
        this->size++;
    }
}

template<class T>
void CircularDobre<T>::add_last(T dato)
{
    if (this->isEmpty())
    {
        this->add_first(dato);
    }
    else
    {
        Nodo* n = new Nodo(dato);

        n->setBefore(this->last);
        this->last->setNext(n);
        n->setNext(this->first);
        this->first->setBefore(n);

        this->last = n;
        this->size++;
    }
}

template<class T>
void CircularDobre<T>::add_at(T dato, int index)
{
    if (index >= 0 && index <= this->size)
    {
        if (index == 0) { this->add_first(dato); return; }
        if (index == this->size) { this->add_last(dato); return; }
        Nodo* aux = this->first;
        int x = 0;
        while (aux != 0)
        {
            if (x == index) { break; }
            aux = aux->getNext();
            x++;
        }
        Nodo* n = new Nodo(dato);
        aux->getBefore()->setNext(n);
        n->setBefore(aux->getBefore());
        n->setNext(aux);
        aux->setBefore(n);
        this->size++;
    }
}

template<class T>
T CircularDobre<T>::get_element_at(int index)
{
    if (index >= 0 && index < size)
    {
        Nodo* iterador = this->first;
        int x = 0;
        while (iterador != 0)
        {
            if (index == x) { return iterador->getDato(); }
            iterador = iterador->getNext();
            x++;
        }
    }
    return 0;
}


#endif // CIRCULARDOBRE_H
