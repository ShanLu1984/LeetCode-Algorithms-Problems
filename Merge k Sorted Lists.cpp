// Method: using priority_queue n: length of lists, m: average length of each linked list
// Space Complexity:  O(n)
// Time complexity (access + deletion + insertion): O(n * m) * (O(1) + 2 * O(logn)) -> O(n * m) O(logn) if(m small), O(n logn)

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    struct compare{
        bool operator()(const ListNode* n1, const ListNode* n2) const {
            return n1->val > n2->val;
        }
    };
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, compare> pq;
        for (auto ln : lists) {
            if (ln != nullptr) {
                pq.push(ln);
            }
        }
        ListNode* d = new ListNode(0);
        ListNode* c = d;
        while (!pq.empty()) {
            ListNode* temp = pq.top();
            pq.pop();
            c->next = temp;
            if (temp->next) {
                pq.push(temp->next);
            }
            c = c->next;
        }
        c->next = nullptr;
        return d->next;
    }
};