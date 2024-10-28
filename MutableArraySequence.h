#ifndef LAB2_MUTABLEARRAYSEQUENCE_H
#define LAB2_MUTABLEARRAYSEQUENCE_H

#include "DynamicArray.h"
#include "Sequence.h"
#include <iostream>


template <typename T>
class MutableArraySequence: public Sequence<T> {
private:
    DynamicArray<T> *items;

public:
    MutableArraySequence() {
        items = new DynamicArray<T>;
    }

    MutableArraySequence(T* data,int count) {
        items = new DynamicArray<T>(data, count);
    }

    MutableArraySequence(MutableArraySequence<T>& arr) {
        items = new DynamicArray<T>(*arr.items);
    }



    T& get(int index) const override {
        try {
            if(index < 0 || index >= items->getLength()) {
                throw std::out_of_range("Index out of range.");
            }
        } catch (const std::out_of_range& error) {
            throw std::out_of_range("Index out of range from catch.");
        }
        return items->get(index);
    }


    T& operator[](size_t index) const {
        return get(index);
    }


    [[nodiscard]] size_t getLength() const{
        return items->getLength();
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

    MutableArraySequence<T>* append(const T& item) override {
        if (items->getLength() + 1 > items->getCapacity()) {
            items->resize();
        }
        items->newsize();
        items->set(items->getLength() - 1, item);
        return this;
    }


    MutableArraySequence<T>* prepend(const T& item) override{
        if (items->getLength() + 1 > items->getCapacity()) {
            items->resize();
        }
        items->newsize();
        for (int i = items->getLength() -1; i >= 1; i--){
            items->set(i, items->get(i-1));
        }
        items->set(0,item);
        return this;
    }


    MutableArraySequence<T>* insertAt(const T& item, int index) override{
        if ((index < 0 || index >= items->getLength()) && items->getLength() != 0){
            throw std::out_of_range("Index out of range.");
        }
        if (items->getLength() + 1 > items->getCapacity()) {
            items->resize();
        }
        items->newsize();
        for (int i = items->getLength() - 1; i > index; i--){
            items->set(i, items->get(i-1));
        }
        items->set(index, item);
        return this;
    }


    MutableArraySequence<T>* getSubsequence(int startIndex, int endIndex) override {
        try {
            if(startIndex < 0 || startIndex >= items->getLength() || endIndex < 0 || endIndex >= items->getLength() || startIndex > endIndex) {
                throw std::out_of_range("Index out of range");
            }
        } catch(const std::out_of_range& error) {
            throw std::out_of_range("Index out of range from catch");
        }

        int subsequenceSize = endIndex - startIndex + 1;
        T* subsequenceData = new T[subsequenceSize];
        for (int i = startIndex; i <= endIndex; i++){
            subsequenceData[i - startIndex] = items->get(i);
        }
        auto* newSequence = new MutableArraySequence<T>(subsequenceData, subsequenceSize);
        return newSequence;
    }


    MutableArraySequence<T>* concatenation(const Sequence<T>* arr1, const Sequence<T>* arr2) override {
        size_t size1 = arr1->getLength();
        size_t size2 = arr2->getLength();
        T* items2 = new T[size1 + size2];
        for(int i = 0; i < size1; i++) {
            items2[i] = arr1->get(i);
        }
        for(int i = 0; i < size2; i++) {
            items2[i + size1] = arr2->get(i);
        }
        return new MutableArraySequence<T>(items2, size1 + size2);
    }


    MutableArraySequence<T>* map(T (*func1)(T)) override{
        for (int i = 0; i < items->getLength(); i++){
            items->set(i, func1(items->get(i)));
        }
        return this;
    }


    size_t find(const T& item) override {
        size_t index = -1;
        int n = 0;
        auto it = items->begin();
        while (it != items->end()){
            if(items->get(n) == item){
                index = n;
                break;
            }
        }
        return index;
    }


    void show() override {
        auto it = items->begin();
        while (it != items->end()){
            std::cout << *it << " ";
        }
        std::cout << std::endl;
    }


    ~MutableArraySequence() {
        delete items;
    };
};
#endif //LAB2_MUTABLEARRAYSEQUENCE_H
