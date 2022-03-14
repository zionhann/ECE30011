namespace MinHeap {
const int max_size = 30;

class PriorityQueue {
    public:
        PriorityQueue(): elements(new Element[max_size]), size(0) { elements -= 1; }

        void Insert(const char* name, double score);
        void Delete();
        void ChangeKey(int base, double score);
        void PrintAll();
        bool Exists(int index) { return index > 0 && index <= size; }
    private:
        class Element {
            public:
                Element(): score(-1) {}
                Element(const char* name, double score): name(name), score(score) {}

                void Add(const char* key) { name = key; }
                void Remove() { std::cout << "[" << name << ", " << score << "] " << "is deleted.\n" << std::endl; score = -1; }
                void Update(double value) { score = value; }
                bool IsLessThan(double value) { return score != -1 && score < value; }
                bool IsLessThan(Element e) { return score < e.score; }
                void Print() { std::cout << "[" << name << ", " << score << "] "; }
            private:
                const char* name;
                double score;
        };
        Element* elements;
        int size;

        void MinHeapify(int base);
        void Swap(int a, int b);
        int ParentOf(int i) { return i / 2; }
        bool IsEmpty() { return size == 0; }
        bool IsFull() { return size == max_size; }
        bool IsOutOfRange(double value) { return value < 0.0 || value > 100.0; }
};
}