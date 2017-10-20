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
        priority_queue<ListNode*, vector<ListNode*>, compare> pq; // define a priority_queue where the nodes with smaller values come first;
        // push the head of all the lists into the heap;
        for (auto ln : lists) {
            if (ln != nullptr) {
                pq.push(ln);
            }
        }
        // a dummy node pointing to the head of the new linkedlist;
        ListNode* d = new ListNode(0);
        // c is the pointer of the current node
        ListNode* c = d;
        // As long as the heap is non-empty, pop the nodes at the top, and let the current node c point to it as the next node;
        // Meanwhile, push the next pointer of the nodes that poped out (if the next pointer is not a nullptr);
        while (!pq.empty()) {
            ListNode* temp = pq.top();
            pq.pop();
            c->next = temp;
            if (temp->next) {
                pq.push(temp->next);
            }
            c = c->next;
        }
        // we reach the end of the list, so we let current node c point to a nullptr; and return d->next;
        c->next = nullptr;
        return d->next;
    }
};
