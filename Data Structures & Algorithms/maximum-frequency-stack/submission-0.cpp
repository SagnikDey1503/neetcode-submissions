class FreqStack {
public:
    unordered_map<int,int> f;
    unordered_map<int,stack<int>> group;
    int maxF;

    FreqStack() {
        maxF = -1;
    }

    void push(int val) {
        f[val]++;
        int freq = f[val];

        group[freq].push(val);
        maxF = max(maxF, freq);
    }

    int pop() {
        int top = group[maxF].top();
        group[maxF].pop();

        f[top]--;

        if(group[maxF].empty())   // follows the return top for same
            maxF--;

        return top;
    }
};