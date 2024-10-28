#ifndef LAB2_MUTABLELISTSEQUENCE_H
#define LAB2_MUTABLELISTSEQUENCE_H

#include "Sequence.h"
#include "LinkedList.h"
#include <iostream>

template <typename T>
class MutableListSequence: public Sequence<T>{
private:
    LinkedList<T> * items;

public:

    MutableListSequence() {
        items = new LinkedList<T>;
    }

    MutableListSequence(T* data,int count) {
        items = new LinkedList<T>(data, count);
    }

    explicit MutableListSequence(MutableArraySequence<T>& list) {
        items = new LinkedList<T>(*list.items);
    }

    [[nodiscard]] size_t getLength() const{
        return items->getLength();
    }


    T& operator[](size_t index) const {
        return get(index);
    }


    T& get(int index) const override{
        try {
            if(index < 0 || index >= items->getLength()) {
                throw std::out_of_range("Index out of range.");
            }
        } catch (const std::out_of_range& error) {
            throw std::out_of_range("Index out of range from catch.");
        }
        return items->get(index);
    }


    T& getFirst() const{
        try {
            if(items->getLength() == 0) {
                throw std::out_of_range("Index out of range");
            }
        } catch (const std::out_of_range& error) {
            throw std::out_of_range("Index out of range from catch");
        }
        return get(0);
    }


    T& getLast() const{
        try {
            if(items->getLength() == 0) {
                throw std::out_of_range("Index out of range");
            }
        } catch (const std::out_of_range& error) {
            throw std::out_of_range("Index out of range from catch");
        }
        return items->get(items->getLength() - 1);
    }



    MutableListSequence<T>* append(const T& item) override {
        items->append(item);
        return this;
    }


    MutableListSequence<T>* prepend(const T& item) override {
        items->prepend(item);
        return this;
    }


    MutableListSequence<T>* insertAt(const T& item, int index) override {
        items->insertAt(item, index);
        return this;
    }

    MutableListSequence<T>* remove(const T& item) {
        items->remove(item);
        return this;
    }


    MutableListSequence<T>* concatenation(const Sequence<T>* arr1,const Sequence<T>* arr2) override {
        auto *newList = new MutableListSequence<T>;
        for (size_t i = 0; i < arr1->getLength(); i++){
            newList->append(arr1->get(i));
        }
        for (size_t i = 0; i < arr2->getLength(); i++){
            newList->append(arr2->get(i));
        }
        return newList;
    }


    MutableListSequence<T>* getSubsequence(int startIndex, int endIndex){
        auto* newList = items->getSubsequence(startIndex, endIndex);
        T* items1 = new T[newList->getLength()];
        for(int i = 0; i < newList->getLength(); i++){
            items1[i] = newList->get(i);
        }
        return new MutableListSequence<T>(items1, newList->getLength());
    }


    MutableListSequence<T>* map(T (*func1)(T)) override {
        items->map(func1);
        return this;
    }


    size_t find(const T& item) override {
        size_t index = items->find(item);
        return index;
    }

    void show() override {
        for(size_t i = 0; i < items->getLength(); i++){
            std::cout << get(i) << " ";
        }
        std::cout << std::endl;
    }


    ~MutableListSequence() {
        delete items;
    }

};



#endif //LAB2_MUTABLELISTSEQUENCE_H
