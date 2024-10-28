#ifndef LAB2_ImmutableLinkedList_H
#define LAB2_ImmutableLinkedList_H

#include "Sequence.h"
#include "LinkedList.h"
#include <iostream>

template <typename T>
class ImmutableListSequence: public Sequence<T>{
private:
    LinkedList<T> * items;

public:

    ImmutableListSequence() {
        items = new LinkedList<T>;
    }

    ImmutableListSequence(T* data,int count) {
        items = new LinkedList<T>(data, count);
    }

    explicit ImmutableListSequence(ImmutableArraySequence<T>& list) {
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



    ImmutableListSequence<T>* append(const T& item) override {
        auto* newList = items;
        newList->append(item);
        T* items1 = new T[newList->getLength()];
        for(int i = 0; i < newList->getLength(); i++){
            items1[i] = newList->get(i);
        }
        return new ImmutableListSequence<T>(items1, newList->getLength());
    }


    ImmutableListSequence<T>* prepend(const T& item) override {
        auto* newList = items;
        newList->prepend(item);
        T* items1 = new T[newList->getLength()];
        for(int i = 0; i < newList->getLength(); i++){
            items1[i] = newList->get(i);
        }
        return new ImmutableListSequence<T>(items1, newList->getLength());
    }



    ImmutableListSequence<T>* insertAt(const T& item, int index) override {
        auto* newList = items;
        newList->insertAt(item, index);
        T* items1 = new T[newList->getLength()];
        for(int i = 0; i < newList->getLength(); i++){
            items1[i] = newList->get(i);
        }
        return new ImmutableListSequence<T>(items1, newList->getLength());
    }


    ImmutableListSequence<T>* concatenation(const Sequence<T>* arr1,const Sequence<T>* arr2) override {
        auto *newList = new ImmutableListSequence<T>;
        for (size_t i = 0; i < arr1->getLength(); i++){
            newList->append(arr1->get(i));
        }
        for (size_t i = 0; i < arr2->getLength(); i++){
            newList->append(arr2->get(i));
        }
        return newList;
    }


    ImmutableListSequence<T>* getSubsequence(int startIndex, int endIndex){
        auto* newList = items->getSubsequence(startIndex, endIndex);
        T* items1 = new T[newList->getLength()];
        for(int i = 0; i < newList->getLength(); i++){
            items1[i] = newList->get(i);
        }
        return new ImmutableListSequence<T>(items1, newList->getLength());
    }


    ImmutableListSequence<T>* map(T (*func1)(T)) override {
        auto* newList = items;
        newList->map(func1);
        T* items1 = new T[newList->getLength()];
        for(int i = 0; i < newList->getLength(); i++){
            items1[i] = newList->get(i);
        }
        return new ImmutableListSequence<T>(items1, newList->getLength());
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


    ~ImmutableListSequence() {
        delete items;
    }


};



#endif //LAB2_ImmutableLinkedList_H
