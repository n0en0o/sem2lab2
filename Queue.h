#ifndef LAB2_QUEUE_H
#define LAB2_QUEUE_H

#include <iostream>
#include "MutableListSequence.h"

template <typename T>
class Queue{
private:
    MutableListSequence<T> *data;
public:

    Queue() {
        data = new MutableListSequence<T>;
    }

    Queue(Queue<T> &list) {
        data = new MutableListSequence<T>(*list.data);
    }

    size_t getLength(){
        return data->getLength();
    }

    Queue<T>* enqueue(const T &item) {
        data->append(item);
        return this;
    }

    Queue<T>* dequeue(){
        if (data->getLength() != 0){
            T a = data->getFirst();
            data->remove(a);
        }
        return this;
    }

    Queue<T> *concatenation(const Queue<T> *arr1, const Queue<T> *arr2) {
        auto *newList = new Queue<T>;
        for (size_t i = 0; i < arr1->data->getLength(); i++) {
            newList->enqueue(arr1->data->get(i));
        }
        for (size_t i = 0; i < arr2->data->getLength(); i++) {
            newList->enqueue(arr2->data->get(i));
        }
        return newList;
    }


    Queue<T> *getSubsequence(int startIndex, int endIndex) {
        auto *newList = data->getSubsequence(startIndex, endIndex);
        T *items1 = new T[newList->getLength()];
        for (int i = 0; i < newList->getLength(); i++) {
            items1[i] = newList->get(i);
        }
        auto* s = new Queue<T>;
        s->data = new MutableListSequence<T>(items1, newList->getLength());
        return s;
    }


    Queue<T>* map(T (*func1)(T)) {
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

    ~Queue() {
        delete data;
    }

};

#endif //LAB2_QUEUE_H
