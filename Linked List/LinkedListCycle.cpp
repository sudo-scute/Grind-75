bool hasCycle(ListNode *head) {
        ListNode *temp =head;

        map< ListNode* ,int> mapi;
        while( temp != nullptr){
            mapi[temp]++;
            temp = temp->next;

            if(mapi[temp] >= 2){
                return true;
            }
        }

        return false;
    }
