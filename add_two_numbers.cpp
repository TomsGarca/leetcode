#include <iostream>
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

ListNode* addTwoNumbers(ListNode *l1, ListNode *l2)
{
    ListNode* answer = new ListNode();
    ListNode* _answer = new ListNode();
    ListNode* a = l1;
    ListNode* b = l2;
    int aux = 0;

    while (a->next != nullptr && b->next != nullptr)
    {
        int aux2 = a->val + b->val + aux;
        if (aux2 > 10)
        {
            aux = (aux2 - aux2 % 10)/10;
        }
        else if (aux2 == 10)
        {
            aux = 1;
        }

        if (answer->next == nullptr && answer->val == 0)
        {
            answer->val = aux2 % 10;
        }
        else if (answer->next == nullptr)
        {
            answer = new ListNode(aux2 % 10, answer);
            //aux = 0;
        }
        a = a->next;
        b = b->next;
    }

    if (a->next == nullptr)
    {
        int aux2 = a->val + b->val + aux;
        if (aux2 > 10)
        {
            aux = (aux2 - aux2 % 10) / 10;
        }
        else if (aux2 == 10)
        {
            aux = 1;
        }

        if (answer->next == nullptr)
        {
            answer->val = aux2 % 10;
        }
        else 
        {
            answer = new ListNode(aux2 % 10 + aux, answer);
            aux = 0;
            b = b->next;
        }
        while (b->next != nullptr)
        {
            int aux2 = b->val + aux;
            if (aux2 > 10)
            {
                aux = (aux2 - aux2 % 10) / 10;
            }
            else if (aux2 == 10)
            {
                aux = 1;
            }
            answer = new ListNode(b->val, answer);
            b = b->next;
        }
        if (b->next == nullptr)
        {
            answer = new ListNode(b->val + aux, answer);
        }
        
    }
    else if (b->next == nullptr)
    {
        int aux2 = a->val + b->val + aux;
        if (aux2 > 10)
        {
            aux = (aux2 - aux2 % 10) / 10;
        }
        else if (aux2 == 10)
        {
            aux = 1;
        }

        if (answer->next == nullptr)
        {
            answer->val = aux2 % 10;
        }
        else
        {
            answer = new ListNode(aux2 % 10, answer);
            aux = 0;
            a = a->next;
        }

         while (a->next != nullptr)
        {
            int aux2 = a->val + aux;
            if (aux2 > 10)
            {
                aux = (aux2 - aux2 % 10) / 10;
            }
            else if (aux2 == 10)
            {
                aux = 1;
            }
            answer = new ListNode(b->val, answer);
            a = a->next;
        }
        if (a->next == nullptr)
        {
            answer = new ListNode(a->val + aux, answer);
        }
    }

    while (answer->next != nullptr)
    {
        if (_answer->next == nullptr && _answer->val == 0)
        {
            _answer->val = answer->val;
            answer = answer->next;
        }
        else
        {
            _answer = new ListNode(answer->val, _answer);
            answer = answer->next;
        }
    }

    if (answer->next == nullptr && _answer->next != nullptr)
    {
        _answer = new ListNode(answer->val, _answer);
    }
    answer = _answer;

    return _answer;
}

void pprint(ListNode* l1)
{
    ListNode* aux = l1;
    while (aux->next != nullptr)
    {
        cout << aux->val << " -> ";
        aux = aux->next;
    }
    if(aux->next == nullptr)
    {
        cout << aux->val << " -> null" << endl;
    }
}

int main()
{
    /* Suma 256 + 182 = 438*/
    ListNode* list1 = new ListNode(9);
    list1 = new ListNode(9, list1);
    list1 = new ListNode(9, list1);
    list1 = new ListNode(9, list1);
    list1 = new ListNode(9, list1);
    list1 = new ListNode(9, list1);
    list1 = new ListNode(9, list1);

    ListNode* list2 = new ListNode(9);
    list2 = new ListNode(9, list2);
    list2 = new ListNode(9, list2);
    list2 = new ListNode(9, list2);

    pprint(list1);
    pprint(list2);
    //pprint(answer);
    pprint(addTwoNumbers(list1,list2));
    return 0;
}