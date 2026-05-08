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
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto comp = [](ListNode* a,ListNode* b){return a->val >b->val;};
        priority_queue<ListNode*,vector<ListNode*>, decltype(comp)> minHeap(comp);

        for(ListNode* list:lists)
        {
          if(list)
          {
            minHeap.push(list);
          }
        }

        ListNode* res = new ListNode(0);
        ListNode* cur = res;

        while(!minHeap.empty())
        {
          ListNode* node = minHeap.top();
          minHeap.pop();
          cur->next = node;
          cur = cur->next;

          node = node->next;
          if(node)
          {
            minHeap.push(node);
          }
        }
        return res->next;
    }
};
