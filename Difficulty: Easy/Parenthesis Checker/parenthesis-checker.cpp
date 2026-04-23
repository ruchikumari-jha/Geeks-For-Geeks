class Solution {
public:
    bool isBalanced(string& s) {
        stack<char> st;

        for (char ch : s) {
            // Opening brackets
            if (ch == '(' || ch == '{' || ch == '[') {
                st.push(ch);
            }
            else {
                // Closing bracket but stack empty
                if (st.empty()) return false;

                char top = st.top();
                st.pop();

                // Check matching
                if ((ch == ')' && top != '(') ||
                    (ch == '}' && top != '{') ||
                    (ch == ']' && top != '[')) {
                    return false;
                }
            }
        }

        // Final check
        return st.empty();
    }
};