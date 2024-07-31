/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class compare {
public:
    bool operator()(ListNode* a, ListNode* b) { return a->val > b->val; }
};
class Solution {
public:
    // given vector of heads of linked lists
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k = lists.size();
        if (k == 0) {
            return nullptr;
        }

        // min heap to store smallest node at top of it
        priority_queue<ListNode*, vector<ListNode*>, compare> minHeap;

        for (int i = 0; i < k; i++) {
            // pushing non null heads in min heap
            if (lists[i]) {
                minHeap.push(lists[i]);
            }
        }

        // ans creation
        ListNode* head = nullptr;
        ListNode* tail = nullptr;
        while (minHeap.size() > 0) {

            ListNode* topNode = minHeap.top();
            minHeap.pop();

            if (topNode->next) {
                minHeap.push(topNode->next);
            }

            // first time
            if (head == nullptr) {
                head = topNode;
                tail = topNode;
            } else {
                tail->next = topNode;
                tail = topNode;
            }
        }

        return head;
    }
};
