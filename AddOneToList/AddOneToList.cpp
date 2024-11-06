// AddOneToList.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

class ListNode
{
public:
    int data;
    ListNode* next;
    ListNode(int data)
        : data(data)
        , next(nullptr)
    {}
};

ListNode* GetListFromInput(ListNode** ppHead, int count)
{
    if (count == 0)
        return nullptr;

    std::cout << "Enter " << count << " numbers of the list: ";
    ListNode* pTail = *ppHead;
    for (int i = 0; i < count; ++i)
    {
        int data = 0;
        std::cin >> data;
        if (*ppHead == nullptr)
        {
            *ppHead = new ListNode(data);
            pTail = *ppHead;
        }
        else
        {
            pTail->next = new ListNode(data);
            pTail = pTail->next;
        }
    }

    return pTail;
}

void PrintList(ListNode* pHead)
{
    if (pHead == nullptr)
        return;

    std::cout << pHead->data;
    pHead = pHead->next;

    while (pHead != nullptr)
    {
        std::cout << ", " << pHead->data;
        pHead = pHead->next;
    }
}

void FreeList(ListNode* pNode)
{
    if (pNode == nullptr)
        return;

    FreeList(pNode->next);
    delete pNode;
}

bool AddOne(ListNode* head)
{
    if (head == nullptr)
        return false;

    bool resultIsTen = false;
    if (head->next == nullptr)
    {
        head->data++;
        if (head->data == 10)
        {
            resultIsTen = true;
            head->data = 0;
        }
        return resultIsTen;
    }

    if (AddOne(head->next))
    {
        head->data++;
        if (head->data == 10)
        {
            resultIsTen = true;
            head->data = 0;
        }
    }

    return resultIsTen;
}

ListNode* AddOneToList(ListNode* head)
{
    if (AddOne(head))
    {
        ListNode* pNode = new ListNode(1);
        pNode->next = head;
        return pNode;
    }

    return head;
}

int main()
{
    while (true)
    {
        int count = 0;
        std::cout << "Number of nodes in list: ";
        std::cin >> count;
        if (count <= 0)
            break;

        ListNode* pHead = nullptr;
        ListNode* pTail = GetListFromInput(&pHead, count);
        
        pHead = AddOneToList(pHead);

        std::cout << "The list after added one: ";
        PrintList(pHead);
        std::cout << std::endl;

        FreeList(pHead);
    }
}
