#ifndef LAB2_ImmutableArraySequence_H
#define LAB2_ImmutableArraySequence_H
//IMMUTABLE ARRAY

#include "DynamicArray.h"
#include "Sequence.h"
#include <iostream>

template <typename T>
class ImmutableArraySequence: public Sequence<T>{
private:
    DynamicArray<T>* items;

public:
    ImmutableArraySequence() {
        items = new DynamicArray<T>;
    }
    ImmutableArraySequence(T* data, int count) {
        items = new DynamicArray<T>(data,count);
    }
    ImmutableArraySequence(ImmutableArraySequence<T>& arr) {
        items = new DynamicArray<T>(*arr.Array);
    }


    T& get(int index) const override{
        try {
            if(index < 0 || index >= items->getLength()) {
                throw std::out_of_range("Index out of range");
            }
        } catch (const std::out_of_range& error) {
            throw std::out_of_range("Index out of range from catch");
        }
        return items->get(index);
    }


    T& operator[](size_t index) const {
        return get(index);
    }


    [[nodiscard]] size_t getLength() const {
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
        return items->get(items->getLength()-1);
    }


    ImmutableArraySequence<T>* append(const T& item) override {
        auto* newSequence = items;
        if (newSequence->getLength() + 1 > newSequence->getCapacity()) {
            newSequence->resize();
        }
        newSequence->newsize();
        newSequence->set(newSequence->getLength() - 1, item);
        T* items1 = new T[newSequence->getLength()];
        for (int i = 0; i < newSequence->getLength();i++) {
            items1[i] = newSequence->get(i);
        }
        return new ImmutableArraySequence<T>(items1, newSequence->getLength());
    }


    ImmutableArraySequence<T>* prepend(const T& item) override{
        auto* newSequence = items;
        if (newSequence->getLength() + 1 > newSequence->getCapacity()) {
            newSequence->resize();
        }
        newSequence->newsize();
        for (int i = newSequence->getLength() - 1; i > 0; i--){
            newSequence->set(i, newSequence->get(i-1));
        }
        newSequence->set(0, item);

        T* items1 = new T[newSequence->getLength()];
        for (int i = 0; i < newSequence->getLength(); i++) {
            items1[i] = newSequence->get(i);
        }
        return new ImmutableArraySequence<T>(items1, newSequence->getLength());
    }


    ImmutableArraySequence<T>* insertAt(const T& item, int index) override{
        if ((index < 0 || index >= items->getLength()) && items->getLength() != 0){
            throw std::out_of_range("Index out of range.");
        }

        auto* newSequence = items;
        if (newSequence->getLength() + 1 > newSequence->getCapacity()) {
            newSequence->resize();
        }
        newSequence->newsize();
        for (int i = newSequence->getLength() - 1; i > index; i--){
            newSequence->set(i, newSequence->get(i - 1));
        }
        newSequence->set(index, item);
        T* items1 = new T[newSequence->getLength()];
        for (int i = 0; i < newSequence->getLength(); i++) {
            items1[i] = newSequence->get(i);
        }
        return new ImmutableArraySequence<T>(items1, newSequence->getLength());
    }



    ImmutableArraySequence<T>* getSubsequence(int startIndex, int endIndex) override {
        if (startIndex < 0 || startIndex >= items->getLength() || endIndex < 0 || endIndex >= items->getLength()){
            throw std::out_of_range("Index out of range.");
        }
        int subsequenceSize = endIndex - startIndex + 1;
        T* subsequenceData = new T[subsequenceSize];
        for (int i = startIndex; i <= endIndex; i++){
            subsequenceData[i - startIndex] = items->get(i);
        }
        return new ImmutableArraySequence<T>(subsequenceData, subsequenceSize);
    }


    ImmutableArraySequence<T>* concatenation(const Sequence<T>* arr1,const Sequence<T>* arr2) override {
        size_t size1 = arr1->getLength();
        size_t size2 = arr2->getLength();
        T* items2 = new T[size1 + size2];
        for(int i = 0; i < size1; i++) {
            items2[i] = arr1->get(i);
        }
        for(int i = 0; i < size2; i++) {
            items2[i + size1] = arr2->get(i);
        }
        return new ImmutableArraySequence<T>(items2, size1 + size2);
    }


    ImmutableArraySequence<T>* map(T (*func1)(T)) override{
        auto* newSequence = items;
        for (int i = 0; i < newSequence->getLength(); i++) {
            newSequence->set(i,func1(newSequence->get(i)));
        }
        T* items1 = new T[newSequence->getLength()];
        for (int i = 0; i < newSequence->getLength(); i++) {
            items1[i] = newSequence->get(i);
        }
        return new ImmutableArraySequence<T>(items1, newSequence->getLength());
    }


    size_t find(const T& item) override {
        auto* newSequence = items;
        size_t index = -1;
        for (int i = 0; i < newSequence->getLength(); i++){
            if (newSequence->get(i) == item) {
                index = i;
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

    ~ImmutableArraySequence() {
        delete items;
    };
};

#endif //LAB2_IMMUTABLEARRAYSEQUENCE_H
