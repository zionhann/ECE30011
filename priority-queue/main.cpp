/**
 * 2022-1 01 ECE30011
 * Algorithms Analysis
 * Professor Whanki Yong
 * HW1
 * 21800779 Sion Han
 * 
 */

#include <iostream>
#include "./inc/minheap.h"
#include "./inc/helper.h"

using namespace std;
using MinHeap::PriorityQueue;

int main() {
    PriorityQueue *queue = new PriorityQueue();

    while(1) {
        char input = Helper::ShowPrompt();

        switch (input) {
            case 'I': {
                char* name = new char[10+1];
                double value;

                cout << "Enter name of element: ";
                cin >> name;
                if (Helper::Length(name) > 10) {
                     cout << "Error: The length for a name must be less than or equal to 10 characters.\n" << endl;
                     delete[] name;
                     continue;
                }
                cout << "Enter key value of element: ";
                cin >> value;

                queue->Insert(name, value);

                break;
            }
            case 'D': 
                queue->Delete();
                break;

            case 'C': {
                int index;
                double value;

                cout << "Enter index of element: ";
                cin >> index;
                if (queue->Exists(index)) {
                    cout << "Enter new key value: ";
                    cin >> value;
                    queue->ChangeKey(index, value);
                } else {
                    cout << "Error: The index does not exist.\n" << endl;
                }
                break;
            }
            case 'P': 
                queue->PrintAll();
                break;
            case 'Q': 
                cout << "Thank you, Bye!\n" << endl;
                delete[] queue;
                return 0;
            default:
                cout << "Error: Invalid command" << " '" << input << "'.\n" << endl;
        }
    }
}