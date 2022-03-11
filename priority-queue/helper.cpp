#include <iostream>
#include "./inc/helper.h"

using std::cout, std::endl, std::cin;

char Helper::ShowPrompt() {
    char menu;

    cout << 
    "I : Insert new element into queue.\n"
    "D : Delete element with smallest key from queue.\n"
    "C : Decrease key of element in queue.\n"
    "P : Print out all elements in queue.\n"
    "Q : Quit\n"
    << endl;

    cout << "Choose menu: ";
    cin >> menu;

    return toupper(menu);
}

int Helper::Length(char* str) {
    int count = 0;

    while (*str != '\0') {
        count++;
        str++;
    }
    return count;
}