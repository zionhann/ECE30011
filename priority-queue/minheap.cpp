#include <iostream>
#include "./inc/minheap.h"

#define SWAP(a, b) { Element temp; temp = elements[a]; elements[a] = elements[b]; elements[b] = temp; }
#define PARENT(a) a / 2

using std::cout, std::endl;
using MinHeap::PriorityQueue;

void PriorityQueue::Insert(const char* name, double score) {
    if (size == MAX_SIZE) {
        cout << "Out of range" << endl;
        return;
    }
    size += 1;

    // Element* node = new Element(name, score);
    elements[size].name = name;
    // elements[size].score = score;
    ChangeKey(size, score);

    cout << "New element " << "[" << name << ", " << score << "] " << "is inserted.\n" << endl;
}

void PriorityQueue::Remove() {

    if (size < 1)
        cout << "underflow";

    SWAP(1, size);
    size -= 1;
    MinHeapify();

}

void PriorityQueue::ChangeKey(int base, double score) {
    if (elements[base].score != -1 && elements[base].score < score) {
        cout << "error";
        return;
    }
    elements[base].score = score;

    while (base > 1 && elements[PARENT(base)].score > elements[base].score) {
        SWAP(PARENT(base), base)
        base = PARENT(base);
    }
}

void PriorityQueue::PrintAll() {
    for (int i = 1; i <= size; i++) {
        cout << "[" << elements[i].name << ", " << elements[i].score << "] ";
    }
    cout << endl;
}

void PriorityQueue::MinHeapify(int base) {
    int left = base * 2;
    int right = left + 1;
    Element curr = elements[base];
    Element lchild = elements[left];
    Element rchild = elements[right];
    int min;

    if (left <= size && lchild.score < curr.score)
        min = left;
    else min = base;

    if (right <= size && rchild.score < elements[min].score)
        min = right;
    
    if (min != base) {
        SWAP(min, base);
        MinHeapify(min);
    }
}