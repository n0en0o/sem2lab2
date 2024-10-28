cmake_minimum_required(VERSION 3.27)
project(lab2)

set(CMAKE_CXX_STANDARD 17)

add_executable(lab2 main.cpp
        Sequence.h
        ImmutableArraySequence.h
        ImmutableListSequence.h
        Menu.h
        MutableArraySequence.h
        Tests.h
        MutableListSequence.h
        DynamicArray.h
        DynamicArray.h
        LinkedList.h
        Stack.h
        Deque.h
        Queue.h
        Pointer.h)
