#include <iostream>
#include "./inc/minheap.h"

using std::cout, std::endl;
using MinHeap::PriorityQueue;

void PriorityQueue::Insert(const char* name, double score) {
    if (size == max_size) {
        cout << "Out of range" << endl;
        return;
    }
    size += 1;
    elements[size].name = name;
    ChangeKey(size, score);
    cout << "New element " << "[" << name << ", " << score << "] " << "is inserted.\n" << endl;
}

void PriorityQueue::Remove() {
    if (size < 1)
        cout << "underflow" << endl;

    Swap(1, size);
    elements[size].score = -1;
    size -= 1;
    MinHeapify();
}

void PriorityQueue::ChangeKey(int base, double score) {
    if (elements[base].score != -1 && elements[base].score < score) {
        cout << "error" << endl;
        return;
    }
    elements[base].score = score;

    while (base > 1 && elements[ParentOf(base)].score > elements[base].score) {
        Swap(ParentOf(base), base);
        base = ParentOf(base);
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
    int min;
    Element curr = elements[base];
    Element lchild = elements[left];
    Element rchild = elements[right];

    if (left <= size && lchild.score < curr.score)
        min = left;
    else min = base;

    if (right <= size && rchild.score < elements[min].score)
        min = right;
    
    if (min != base) {
        Swap(min, base);
        MinHeapify(min);
    }
}

void PriorityQueue::Swap(int a, int b) {
    Element temp = elements[a];
    elements[a] = elements[b];
    elements[b] = temp;
}