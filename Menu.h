#ifndef LAB2_MENU_H
#define LAB2_MENU_H

class Menu{
public:
    static void get_menu(){
        std::cout << "*---Menu---*" << std::endl;
        std::cout << "1.Show sequence" << std::endl;
        std::cout << "2.Add to sequence" << std::endl;
        std::cout << "3.Concatenate sequences" << std::endl;
        std::cout << "4.Map sequence" << std::endl;
        std::cout << "5.Find in sequence" << std::endl;
        std::cout << "6.Get Subsequence" << std::endl;
        std::cout << "Enter 'stop' to exit." << std::endl;
    }
};

#endif //LAB2_MENU_H
