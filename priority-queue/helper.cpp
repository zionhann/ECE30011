#include <iostream>
#include "./inc/helper.h"

char Helper::ShowPrompt() {
    char menu;

    std::cout << 
    "*********** MENU ****************\n"
    "I : Insert new element into queue.\n"
    "D : Delete element with smallest key from queue.\n"
    "C : Decrease key of element in queue.\n"
    "P : Print out all elements in queue.\n"
    "Q : Quit\n"
    << std::endl;

    std::cout << "Choose menu: ";
    std::cin >> menu;

    return toupper(menu);
}

int Helper::LengthOf(char* str) {
    int count = 0;

    while (*str != '\0') {
        count++;
        str++;
    }
    return count;
}