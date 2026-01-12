class FreqStack {
    unordered_map<int, int> count;
    unordered_map<int, stack<int>> freqGroup;
    int highestFreq;

public:
    FreqStack() {
        highestFreq = 0;
    }

    void push(int val) {
        int newFreq = ++count[val];
        highestFreq = max(highestFreq, newFreq);
        freqGroup[newFreq].push(val);
    }

    int pop() {
        int topValue = freqGroup[highestFreq].top();
        freqGroup[highestFreq].pop();

        count[topValue]--;

        if (freqGroup[highestFreq].empty())
            highestFreq--;

        return topValue;
    }
};


/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */