#ifndef LAB2_DEQUE_H
#define LAB2_DEQUE_H

#include <iostream>
#include "MutableListSequence.h"

template <typename T>
class Deque{
private:
    MutableListSequence<T> *data;
public:

    Deque() {
        data = new MutableListSequence<T>;
    }

    Deque(T *data, int count) {
        data = new MutableListSequence<T>(data, count);
    }

    Deque(Deque<T> &list) {
        data = new MutableListSequence<T>(*list.data);
    }

    size_t getLength(){
        return data->getLength();
    }

    Deque<T> *append(const T &item)  {
        data->append(item);
        return this;
    }


    Deque<T> *prepend(const T &item)  {
        data->prepend(item);
        return this;
    }

    Deque<T>* removeHead(){
        if (data->getLength() != 0){
            T a = data->getFirst();
            data->remove(a);
        }
        return this;
    }

    Deque<T>* removeTail() {
        if (data->getLength() != 0){
            T a = data->getLast();
            data->remove(a);
        }
        return this;
    }


    Deque<T> *concatenation(const Deque<T> *arr1, const Deque<T> *arr2) {
        auto *newList = new Deque<T>;
        for (size_t i = 0; i < arr1->data->getLength(); i++) {
            newList->data->append(arr1->data->get(i));
        }
        for (size_t i = 0; i < arr2->data->getLength(); i++) {
            newList->data->append(arr2->data->get(i));
        }
        return newList;
    }


    Deque<T> *getSubsequence(int startIndex, int endIndex) {
        auto *newList = data->getSubsequence(startIndex, endIndex);
        T *items1 = new T[newList->getLength()];
        for (int i = 0; i < newList->getLength(); i++) {
            items1[i] = newList->get(i);
        }
        auto* s = new Deque<T>;
        s->data = new MutableListSequence<T>(items1, newList->getLength());
        return s;
    }


    Deque<T> *map(T (*func1)(T)) {
        data->map(func1);
        return this;
    }


    size_t find(const T &item) {
        size_t index = data->find(item);
        return index;
    }

    void show() {
        data->show();
    }

    ~Deque() {
        delete data;
    }

};

#endif //LAB2_DEQUE_H
