#ifndef LAB2_TESTS_H
#define LAB2_TESTS_H

#include "MutableArraySequence.h"
#include "ImmutableArraySequence.h"
#include "MutableListSequence.h"
#include "ImmutableListSequence.h"
#include "Stack.h"
#include "Deque.h"
#include "Queue.h"
#include <string>

template <typename T>
T func(T item) {
    item++;
    return item;
}


template <typename T>
int tests(){

    ImmutableArraySequence<int> a1;
    MutableArraySequence<int> a2;
    MutableListSequence<int> a3;
    ImmutableListSequence<int> a4;

    if (a1.getLength() != 0 || a2.getLength() != 0 || a3.getLength() != 0 || a4.getLength() != 0){
        std::cout << "GetLength is not working." << std::endl;
        return -1;
    }
    a1.append(1);
    a2.append(2);
    a3.append(3);
    a4.append(4);

    if (a1.get(0) != 1 || a2.get(0) != 2 || a3.get(0) != 3 || a4.get(0) != 4){
        std::cout << "Get is not working." << std::endl;
        return -1;
    }

    if (a1.getLength() != 1 || a2.getLength() != 1 || a3.getLength() != 1 || a4.getLength() != 1){
        std::cout << "Append is not working." << std::endl;
        return -1;
    }

    if (a1.getLast() != 1 || a2.getLast() != 2 || a3.getLast() != 3 || a4.getLast() != 4){
        std::cout << "Get Last is not working." << std::endl;
        return -1;
    }

    if (a1.getFirst() != 1 || a2.getFirst() != 2 || a3.getFirst() != 3 || a4.getFirst() != 4){
        std::cout << "Get First is not working." << std::endl;
        return -1;
    }

    a1.prepend(1);
    a2.prepend(2);
    a3.prepend(3);
    a4.prepend(4);

    if (a1.getFirst() != 1 || a2.getFirst() != 2 || a3.getFirst() != 3 || a4.getFirst() != 4){
        std::cout << "Prepend is not working." << std::endl;
        return -1;
    }

    a1.insertAt(7,0);
    a2.insertAt(8,0);
    a3.insertAt(9,0);
    a4.insertAt(10,0);

    if (a1.getFirst() != 7 || a2.getFirst() != 8 || a3.getFirst() != 9 || a4.getFirst() != 10){
        std::cout << "InsertAt is not working." << std::endl;
        return -1;
    }

    a1.map(func);
    a2.map(func);
    a3.map(func);
    a4.map(func);

    if (a1.getFirst() != 8 || a2.getFirst() != 9 || a3.getFirst() != 10 || a4.getFirst() != 11){
        std::cout << "Map is not working." << std::endl;
        return -1;
    }

    if (a1.find(8) != 0 || a2.find(9) != 0 || a3.find(10) != 0 || a4.find(11) != 0){
        std::cout << "Find is not working." << std::endl;
        return -1;
    }

    Sequence<int>* array1 = a1.getSubsequence(0,1);
    Sequence<int>* array2 = a2.getSubsequence(0,1);
    Sequence<int>* array3 = a3.getSubsequence(0,1);
    Sequence<int>* array4 = a4.getSubsequence(0,1);

    if (array1->getLength() != 2 || array2->getLength() != 2 || array3->getLength() != 2 || array4->getLength() != 2){
        std::cout << "Get Subsequence is not working." << std::endl;
        return -1;
    }

    ImmutableArraySequence<int> a5;
    a5.append(1);
    Sequence<int>* arr1 = a1.concatenation(&a1, &a5);

    MutableArraySequence<int> a6;
    a6.append(2);
    Sequence<int>* arr2 = a2.concatenation(&a2,&a6);

    MutableListSequence<int> a7;
    a7.append(3);
    Sequence<int>* arr3 = a3.concatenation(&a3,&a7);

    ImmutableListSequence<int> a8;
    a8.append(4);
    Sequence<int>* arr4 = a4.concatenation(&a4,&a8);

    if (arr1->getLength() != 4 || arr2->getLength() != 4 || arr3->getLength() != 4 || arr4->getLength() != 4){
        std::cout << "Concatenation is not working." << std::endl;
        return -1;
    }



    auto* s = new Stack<int>;

    s->push(1);
    if (s->getLength() != 1){
        std::cout << "Push is not working." << std::endl;
        return -1;
    }

    s->pop();
    if (s->getLength() != 0){
        std::cout << "Pop is not working." << std::endl;
        return -1;
    }

    s->push(1);
    if (s->find(1) != 0){
        std::cout << "Find is not working." << std::endl;
        return -1;
    }

    s->map(func);
    if (s->find(2) != 0){
        std::cout << "Map is not working." << std::endl;
        return -1;
    }

    auto* s1 = new Stack<T>;
    s1->push(1);
    Stack<int>* st = s->concatenation(s,s1);
    if (st->getLength() != 2){
        std::cout << "Concatenation is not working." << std::endl;
        return -1;
    }

    st->push(3);
    Stack<int>* stack = st->getSubsequence(0,1);
    if (stack->getLength() != 2){
        std::cout << "GetSubsequence is not working." << std::endl;
        return -1;
    }


    auto* d = new Deque<int>;

    d->append(2);
    if (d->getLength() != 1){
        std::cout << "Append is not working." << std::endl;
        return -1;
    }

    d->prepend(1);
    if (d->getLength() != 2){
        std::cout << "Prepend is not working." << std::endl;
        return -1;
    }

    d->removeHead();
    if (d->find(2) != 0){
        std::cout << "RemoveHead is not working." << std::endl;
        return -1;
    }

    d->removeTail();
    if (d->getLength() != 0){
        std::cout << "RemoveTail is not working." << std::endl;
        return -1;
    }

    d->prepend(1);

    d->map(func);
    if (d->find(2) != 0){
        std::cout << "Map is not working." << std::endl;
        return -1;
    }

    auto* d1 = new Deque<T>;
    d1->append(1);
    Deque<int>* de = d->concatenation(d,d1);
    if (de->getLength() != 2){
        std::cout << "Concatenation is not working." << std::endl;
        return -1;
    }

    de->append(3);
    Deque<int>* deq = de->getSubsequence(0,1);
    if (deq->getLength() != 2){
        std::cout << "Concatenation is not working." << std::endl;
        return -1;
    }

    auto* q = new Queue<int>;

    q->enqueue(1);
    if (q->getLength() != 1){
        std::cout << "Enqueue is not working." << std::endl;
        return -1;
    }

    q->dequeue();
    if (q->getLength() != 0){
        std::cout << "Dequeue is not working." << std::endl;
        return -1;
    }

    q->enqueue(1);

    q->map(func);
    if (q->find(2) != 0){
        std::cout << "Map is not working." << std::endl;
        return -1;
    }

    auto* q1 = new Queue<T>;
    q1->enqueue(1);
    Queue<int>* que = q->concatenation(q,q1);
    if (que->getLength() != 2){
        std::cout << "Concatenation is not working." << std::endl;
        return -1;
    }

    que->enqueue(3);
    Queue<int>* queue = que->getSubsequence(0,1);
    if (queue->getLength() != 2){
        std::cout << "Concatenation is not working." << std::endl;
        return -1;
    }

    auto* w = new Stack<std::string>;
    w->push("wtgerge");
    w->push("wethyukrge");


   
    return 0;
}

#endif //LAB2_TESTS_H
