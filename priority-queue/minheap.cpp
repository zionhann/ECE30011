#include <iostream>
#include "./inc/minheap.h"

using std::cout, std::endl;
using MinHeap::PriorityQueue;

void PriorityQueue::Insert(const char* name, double score) {
    if (IsFull()) {
        cout << "Error: The queue is already full.\n" << endl;
        return;
    } else if (IsOutOfRange(score)) {
        cout << "Error: The key value must be greater than or equal to 0.0 and less than or equal to 100.0\n" << endl;
        return;
    }
    elements[++size].Add(name);
    ChangeKey(size, score);
    cout << "New element " << "[" << name << ", " << score << "] " << "is inserted.\n" << endl;
}

void PriorityQueue::Delete() {
    if (IsEmpty()) {
        cout << "Error: Elements are no longer in the queue.\n" << endl;
        return;
    }
    Swap(1, size);
    elements[size--].Remove();
    MinHeapify(1);
}

void PriorityQueue::ChangeKey(int base, double score) {
    if (elements[base].IsLessThan(score)) {
        cout << "Error: The new key value must be less than the current key value.\n" << endl;
        return;
    } else if (IsOutOfRange(score)) {
        cout << "Error: The key value must be greater than or equal to 0.0 and less than or equal to 100.0\n" << endl;
        return;
    }
    elements[base].Update(score);

    while (base > 1 && elements[base].IsLessThan(elements[ParentOf(base)])) {
        Swap(ParentOf(base), base);
        base = ParentOf(base);
    }
}

void PriorityQueue::PrintAll() {
    for (int i = 1; i <= size; i++) {
        elements[i].Print();
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

    if (left <= size && lchild.IsLessThan(curr))
        min = left;
    else min = base;

    if (right <= size && rchild.IsLessThan(elements[min]))
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