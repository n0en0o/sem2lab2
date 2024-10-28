#ifndef LAB2_STACK_H
#define LAB2_STACK_H

#include <iostream>
#include "MutableListSequence.h"

template <typename T>
class Stack{
private:
    MutableListSequence<T> *data;
public:

    Stack() {
        data = new MutableListSequence<T>;
    }

    Stack(Stack<T>& list) {
        data = new MutableListSequence<T>(*list.data);
    }


    Stack<T>* push(const T& item) {
        data->prepend(item);
        return this;
    }

    size_t getLength(){
        return data->getLength();
    }

    Stack<T>* pop() {
        if (data->getLength() != 0){
            T a = data->getFirst();
            data->remove(a);
        }
        return this;
    }

    Stack<T>* concatenation(const Stack<T>* arr1,const Stack<T>* arr2) {
        auto *newList = new Stack<T>;
        for (size_t i = 0; i < arr1->data->getLength(); i++){
            newList->data->append(arr1->data->get(i));
        }
        for (size_t i = 0; i < arr2->data->getLength(); i++){
            newList->data->append(arr2->data->get(i));
        }
        return newList;
    }


    Stack<T>* getSubsequence(int startIndex, int endIndex){
        auto* newList = data->getSubsequence(startIndex, endIndex);
        T* items1 = new T[newList->getLength()];
        for(int i = 0; i < newList->getLength(); i++){
            items1[i] = newList->get(i);
        }
        auto* s = new Stack<T>;
        s->data = new MutableListSequence<T>(items1, newList->getLength());
        return s;
    }


    Stack<T>* map(T (*func1)(T)) {
        data->map(func1);
        return this;
    }


    size_t find(const T& item) {
        size_t index = data->find(item);
        return index;
    }

    void show() {
        data->show();
    }


    ~Stack() {
        delete data;
    }

};

#endif //LAB2_STACK_H
