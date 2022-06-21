using namespace std;
/**
 * Definition for singly-linked list.
*/
struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        ListNode* answer;
        if(l1->next == nullptr)
        {
            int a = l1->val;
            if(l2->next == nullptr)
            {
                int b = l2->val;


            }
        }
        return answer;
    }
};

int main()
{
    ListNode* list1 = new ListNode();
    return 0;
}