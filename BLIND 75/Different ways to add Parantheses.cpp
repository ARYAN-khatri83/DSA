class Solution {
public:
    // Helper function to evaluate an operation between two integers
    int compute(int a, int b, char op) {
        if (op == '+') return a + b;
        if (op == '-') return a - b;
        if (op == '*') return a * b;
        return 0;
    }

    vector<int> diffWaysToCompute(string expression) {
        vector<int> result;

        // Loop through the expression to find operators
        for (int i = 0; i < expression.size(); ++i) {
            char c = expression[i];

            // When an operator is found, divide the expression
            if (c == '+' || c == '-' || c == '*') {
                // Recursive call on left part and right part of the expression
                vector<int> left = diffWaysToCompute(expression.substr(0, i));
                vector<int> right = diffWaysToCompute(expression.substr(i + 1));

                // Combine the results of left and right parts using the operator
                for (int l : left) {
                    for (int r : right) {
                        result.push_back(compute(l, r, c));
                    }
                }
            }
        }

        // Base case: if no operators are found, the expression is a number
        if (result.empty()) {
            result.push_back(stoi(expression));
        }

        return result;
    }
};
