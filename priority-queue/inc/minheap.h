namespace MinHeap {
const int max_size = 30;

class PriorityQueue {
    public:
        PriorityQueue(): elements(new Element[max_size]), size(0) { elements -= 1; }

        void Insert(const char* name, double score);
        void Remove();
        void ChangeKey(int base, double score);
        void PrintAll();
    private:
        class Element {
            public:
                Element(): score(-1) {}
                Element(const char* name, double score): name(name), score(score) {}

                const char* name;
                double score;
        };
        Element* elements;
        int size;

        void MinHeapify(int base = 1);
        void Swap(int a, int b);
        int ParentOf(int i) { return i / 2; }
};
}