class Solution {
public:
    bool isOp(string s) {
        return s == "*" || s == "+" || s == "-" || s == "/";
    }

    int evalRPN(vector<string>& tokens) {
        stack<int> s;

        for (int i = 0; i < tokens.size(); i++) {

            if (!isOp(tokens[i])) {
                s.push(stoi(tokens[i]));
                continue;
            }

            int b = s.top();
            s.pop();

            int a = s.top();
            s.pop();

            int result;

            if (tokens[i] == "+")
                result = a + b;
            else if (tokens[i] == "-")
                result = a - b;
            else if (tokens[i] == "*")
                result = a * b;
            else
                result = a / b;

            s.push(result);
        }

        return s.top();
    }
};