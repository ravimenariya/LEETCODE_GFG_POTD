class SpecialQueue {
    queue<int>q;
    multiset<int>mst;
  public:

    void enqueue(int x) {
        q.push(x);
        mst.insert(x);
    }

    void dequeue() {
        auto it=mst.find(q.front());
        mst.erase(it);
        q.pop();
    }

    int getFront() {
        return q.front();
    }

    int getMin() {
        return *mst.begin();
    }

    int getMax() {
        return *mst.rbegin();
    }
};
