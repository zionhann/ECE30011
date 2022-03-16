/**
 * 2022-1 01 ECE30011
 * Algorithms Analysis
 * Professor Whanki Yong
 * HW1
 * 21800779 Sion Han
 * 
 * @references
 * Whanki Yong. ECE30011. Class Lecture, Topic:"Chapter 6-Heapsort."
 * School of Computer Science and Electrical Engineering, 
 * Handong Global University, Pohang, Mar., 2022, pp.26-35.
 * 
 * [Online].
 * Available:
 * https://google.github.io/styleguide/cppguide.html [Accessed Mar. 12, 2022].
 * https://docs.microsoft.com/ko-kr/cpp/cpp/header-files-cpp?view=msvc-170 [Accessed Mar. 12, 2022].
 * https://docs.microsoft.com/ko-kr/cpp/cpp/namespaces-cpp?view=msvc-170 [Accessed Mar. 12, 2022].
 * https://gist.github.com/Lokno/b0f9ee0b802d8be78fb79e70a3db52eb [Accessed Mar. 12, 2022].
 * https://stackoverflow.com/questions/1452721/why-is-using-namespace-std-considered-bad-practice [Accessed Mar. 12, 2022].
 * https://stackoverflow.com/questions/66977448/c11-char-array-intializations-and-string-literals [Accessed Mar. 12, 2022].
 * https://stackoverflow.com/questions/2361927/pointer-to-1th-index-of-array [Accessed Mar. 12, 2022].
 * https://stackoverflow.com/questions/1239938/accessing-an-array-out-of-bounds-gives-no-error-why [Accessed Mar. 12, 2022].
 * https://blog.naver.com/PostView.nhn?isHttpsRedirect=true&blogId=tipsware&logNo=221054714926 [Accessed Mar. 12, 2022].
 * https://makefiletutorial.com/ [Accessed Mar. 14, 2022].
 * https://stackoverflow.com/questions/10363646/compiling-c11-with-g [Accessed Mar. 14, 2022].
 * https://kldp.org/node/23920 [Accessed Mar. 16, 2022].
 * 
 * 최호성, "이것이 C++이다", 한빛미디어, 2019, pp.75-83, pp.98-133.
 * 
 */

#include <iostream>
#include "./inc/minheap.h"
#include "./inc/helper.h"

using std::cout;
using std::endl;
using std::cin;
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
                if (Helper::LengthOf(name) > 10) {
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
                    cout << endl;
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
                delete queue;
                return 0;
            default:
                cout << "Error: Invalid command" << " '" << input << "'.\n" << endl;
        }
    }
}