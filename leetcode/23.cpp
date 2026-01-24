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
class Solution {
    struct comp_vals {
        bool operator() (ListNode* a, ListNode* b) const noexcept {
            return a->val > b->val;
        }
    };
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, decltype(
            [](const auto& a, const auto& b) -> bool {
                return a->val > b->val;
            }
        )> pq;
        auto head = new ListNode();
        for (const auto& node : lists)
            if (node)
                pq.push(node);
        ListNode* cur = head;
        while (pq.size()) {
            cur->next = pq.top();
            pq.pop();
            if (cur->next->next)
                pq.push(cur->next->next);
            cur = cur->next;
        }
        auto res = head->next;
        delete head;
        return res;
    }
};

class Solution {
public:
    ListNode *mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (NULL == l1) return l2;
        else if (NULL == l2) return l1;
        if (l1->val <= l2->val) {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        }
        else {
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
    }
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        if (lists.empty()) return NULL;
        int len = lists.size();
        while (len > 1) {
            for (int i = 0; i < len / 2; ++i) {
                lists[i] = mergeTwoLists(lists[i], lists[len - 1 - i]);
            }
            len = (len + 1) / 2;
        }
        
        return lists.front();
    }
};