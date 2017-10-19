// Space Complexity:  O(n)
// Time complexity: O(n)


class Solution {
public:
    // pushPound: used to push a pound “#” into the stack.
    bool pushPound (stack<string> &stk) {
        // if the stack is empty, or the top element is not a “#”, just push it into the stack;
        if (stk.empty() || stk.top() != "#") {
            stk.push("#"); 
            return true;
        }
        // Otherwise, we need to pop 2 elements out; and then push a pound into the stack;
        if (stk.size() < 2) return false;
        stk.pop();
        stk.pop();
        return pushPound(stk);
    }
        
    bool isValidSerialization(string preorder) {
        // push a ‘,’ at the back to make the parse process easier.
        preorder.push_back(',');
        stack<string> stk;
        int start = 0;
        while (start != preorder.size()) {
            int pos = start;
            while (preorder[pos] != ',') pos++;
            string temp = preorder.substr(start, pos - start);
            // if the string push into the stack is a “#”, call pushPound function.
            if (temp != "#") stk.push(temp);
            else {
                if(!pushPound(stk)) return false;
            }
            start = pos + 1;
        }
        if (stk.size() == 1 && stk.top() == "#") return true;
        return false;
    }
    
};

