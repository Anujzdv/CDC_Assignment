class CustomStack {
    vector<int> data;
    int maxSize;

public:
    CustomStack(int maxSizeValue) {
        maxSize = maxSizeValue;
    }

    void push(int x) {
        if (data.size() < maxSize)
            data.push_back(x);
    }

    int pop() {
        if (data.empty())
            return -1;

        int topValue = data.back();
        data.pop_back();
        return topValue;
    }

    void increment(int k, int val) {
        int upto = min(k, (int)data.size());
        for (int i = 0; i < upto; i++) {
            data[i] += val;
        }
    }
};


/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */