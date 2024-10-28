#include <iostream>
#include "ImmutableArraySequence.h"
#include "MutableArraySequence.h"
#include "MutableListSequence.h"
#include "ImmutableListSequence.h"
#include "Tests.h"
#include "Menu.h"
#include <algorithm>

template <typename T>
T func1(T item) {
    item++;
    return item;
}

int main() {

    if(tests<int>() != 0){
        std::cout << "Tests crushed." << std::endl;
        return -1;
    }

    ImmutableArraySequence<int> array;

    while(true) {
        char input[20];
        Menu::get_menu();

        std::cin >> input;
        if (std::string(input) == "stop") {
            std::cout << "Bye!" << std::endl;
            break;
        }

        

        int action = std::atoi(input);

       switch (action) {
            case 1:
            {
                array.show();
                break;
            }

            case 2:
            {
                std::cout << "Enter element to add:" << std::endl;
                char item[20], choice[10];
                std::cin >> item;
                std::cout << "Enter 1 to add to beginning, 2 to add to end, 3 to add by index:" << std::endl;
                std::cin >> choice;
                int item1 = std::atoi(item);
                int choice1 = std::atoi(choice);
                switch(choice1) {
                    case 1:{
                        array.prepend(item1);
                        break;
                    }
                    case 2:{
                        array.append(item1);
                        break;
                    }
                    case 3:{
                        int index;
                        std::cout << "Enter index to insert:" << std::endl;
                        std::cin >> index;
                        array.insertAt(item1, index);
                        break;
                    }
                    default: {
                        std::cout << "Unknown command." << std::endl;
                        break;
                    }
                }
                break;
            }

            case 3:
            {
                size_t sidesize;
                std::cout << "Enter size of side sequence:" << std::endl;
                ImmutableArraySequence<int> sidearray;
                std::cin >> sidesize;
                std::cout << "Enter elements to side sequence:" << std::endl;
                for (size_t i = 0; i < sidesize; i++){
                    int item;
                    std::cin >> item;
                    sidearray.append(item);
                }
                Sequence<int>* conarr = array.concatenation(&array,&sidearray);
                std::cout << "Result:" << std::endl;
                conarr->show();
                break;
            }

            case 4:
            {
                array.map(func1);
                std::cout << "Action completed." << std::endl;
                break;
            }

            case 5:
            {
                int item;
                std::cout << "Enter element to find:" << std::endl;
                std::cin >> item;
                std::cout << "Index: " << array.find(item) << std::endl;
                break;
            }

            case 6:
            {
                int start, end;
                std::cout << "Enter start and end:" << std::endl;
                std::cin >> start >> end;
                array = *array.getSubsequence(start, end);
                break;
            }
            default: {
                std::cout << "Unknown command." << std::endl;
                break;
            }
        }
    }
    return 0;
}


/*if (std::all_of(input.begin(), input.end(), [](unsigned char c){ return std::isdigit(c); })) {
            action = std::stoi(input);
        }
        else
        {
            throw std::out_of_range("Unknown command.");
        }*/