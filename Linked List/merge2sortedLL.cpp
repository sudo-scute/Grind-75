ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    if (list1 == nullptr)
        {
            return list2;
        }

        if (list2 == nullptr)
        {
            return list1;
        }

        ListNode *ans = new ListNode(-1);

        ListNode *temp = ans;

        while (list1 != nullptr && list2 != nullptr)
        {

            if (list1->val < list2->val)
            {
                temp->next = list1;
                temp = list1;
                list1 = list1->next;
            }

            else
            {
                temp->next = list2;
                temp = list2;
                list2 = list2->next;
            }
        }

        // copying the remaining ll
        while (list1 != nullptr)
        {
            temp->next = list1;
            temp = list1;
            list1 = list1->next;
        }

        while (list2 != nullptr)
        {
            temp->next = list2;
            temp = list2;
            list2 = list2->next;
        }

        // ans was started with -1
        ans = ans->next;
        return ans;
    }
