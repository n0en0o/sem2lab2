#ifndef LAB2_DYNAMICARRAY_H
#define LAB2_DYNAMICARRAY_H

#include <iostream>

template <typename T>
class DynamicArray {
private:
    T* data;
    size_t capacity;
    size_t size;

public:

    class Iterator {
        T* cur;
    public:
        Iterator(T* first): cur(first){}

        T& operator + (T n) { return *(cur + n); }
        T& operator - (T n) { return *(cur - n); }
        T& operator ++ (T) { return *cur++; }
        T& operator -- (T) { return *cur--; }
        T& operator ++ () { return *++cur; }
        T& operator -- () { return *--cur; }

        bool operator != (const Iterator& it) { return cur != it.cur; }
        bool operator == (const Iterator& it) { return cur == it.cur; }
        T& operator * () { return *cur; }
    };

    Iterator begin() {
        return& getData();
    }

    Iterator end(){
        return& getData() + getLength();
    }

    DynamicArray(): data(new T[1]), size(0), capacity(1){}

    explicit DynamicArray(const int size): size(size), capacity(size) {
        data = new T[capacity];
    }

    DynamicArray(T* items, const int count): size(count), capacity(count) {
        data = new T[size];
        for (size_t i = 0; i <  size; i++) {
            data[i] = items[i];
        }
    }

    DynamicArray(DynamicArray<T>& other ): size(other.size), capacity(other.capacity){
        data = new T[capacity];
        for (size_t i = 0;i <  size;i++) {
            data[i] = other.data[i];
        }
    }

    [[nodiscard]] size_t getLength() const {
        return size;
    }

    [[nodiscard]] size_t getCapacity() const {
        return capacity;
    }

    T& getData(){
        return *data;
    }


    void newsize(){
        size++;
    }

    void resize(){
        capacity *= 2;
        T* newData = new T[capacity];
        for (size_t i = 0; i < size; i++){
            newData[i] = data[i];
        }
        delete [] data;
        data = newData;
    }

    void set(int index, T value) {
        if (index < 0 || index >= size){
            throw std::out_of_range("Index out of range.");;
        }
        data[index] = value;
    }

    T& get(int index) const {
        if (index < 0 || index >= size) {
            throw std::out_of_range("Index out of range!");
        }
        return data[index];
    }


    T& operator[](size_t index) const {
        return get(index);
    }


    ~DynamicArray(){
        delete [] data;
    }

};


#endif //LAB2_DYNAMICARRAY_H
