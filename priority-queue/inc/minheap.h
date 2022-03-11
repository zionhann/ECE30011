#define MAX_SIZE 30

namespace MinHeap {
    class PriorityQueue {
        public:
            PriorityQueue(): elements(new Element[MAX_SIZE]), size(0) { elements -= 1; }

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
    };
}