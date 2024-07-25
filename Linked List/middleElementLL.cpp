ListNode* middleNode(ListNode* head) {

        if(head == nullptr || head->next == nullptr){
            return head;
        }

        if(head->next->next == nullptr){
            return head->next;
        }
        ListNode *slow = head;
        ListNode *fast = head->next;
        while(fast != nullptr){
            fast = fast->next;
            if(fast!= nullptr){
                fast = fast->next;
            }

            slow = slow->next;
        }

        return slow;
}
