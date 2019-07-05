/*******************************************************************
Copyright(c) 2016, Harry He
All rights reserved.

Distributed under the BSD license.
(See accompanying file LICENSE.txt at
https://github.com/zhedahht/CodingInterviewChinese2/blob/master/LICENSE.txt)
*******************************************************************/

//==================================================================
// ����ָOffer�����������Թپ������ͱ���⡷����
// ���ߣ��κ���
//==================================================================

// ������22�������е�����k�����
// ��Ŀ������һ����������������е�����k����㡣Ϊ�˷��ϴ�����˵�ϰ�ߣ�
// �����1��ʼ�������������β����ǵ�����1����㡣����һ��������6����㣬
// ��ͷ��㿪ʼ���ǵ�ֵ������1��2��3��4��5��6���������ĵ�����3�������
// ֵΪ4�Ľ�㡣

#include <cstdio>
//#include "..\Utilities\List.h"
#include <stdio.h>
#include <stdlib.h>
struct ListNode
{
    int       m_nValue;
    ListNode* next;
};
ListNode* CreateListNode(int value)
{
    ListNode* pNode = new ListNode();
    pNode->m_nValue = value;
    pNode->next = nullptr;

    return pNode;
}

void ConnectListNodes(ListNode* pCurrent, ListNode* pNext)
{
    if(pCurrent == nullptr)
    {
        printf("Error to connect two nodes.\n");
        exit(1);
    }

    pCurrent->next = pNext;
}

void PrintListNode(ListNode* pNode)
{ 
    if(pNode == nullptr)
    {
        printf("The node is nullptr\n");
    }
    else
    {
        printf("The key in node is %d.\n", pNode->m_nValue);
    }
}

void PrintList(ListNode* pHead)
{
    printf("PrintList starts.\n");
    
    ListNode* pNode = pHead;
    while(pNode != nullptr)
    {
        printf("%d\t", pNode->m_nValue);
        pNode = pNode->next;
    }

    printf("\nPrintList ends.\n");
}

void DestroyList(ListNode* pHead)
{
    ListNode* pNode = pHead;
    while(pNode != nullptr)
    {
        pHead = pHead->next;
        delete pNode;
        pNode = pHead;
    }
}

void AddToTail(ListNode** pHead, int value)
{
    ListNode* pNew = new ListNode();
    pNew->m_nValue = value;
    pNew->next = nullptr;

    if(*pHead == nullptr)
    {
        *pHead = pNew;
    }
    else
    {
        ListNode* pNode = *pHead;
        while(pNode->next != nullptr)
            pNode = pNode->next;

        pNode->next = pNew;
    }
}

void RemoveNode(ListNode** pHead, int value)
{
    if(pHead == nullptr || *pHead == nullptr)
        return;

    ListNode* pToBeDeleted = nullptr;
    if((*pHead)->m_nValue == value)
    {
        pToBeDeleted = *pHead;
        *pHead = (*pHead)->next;
    }
    else
    {
        ListNode* pNode = *pHead;
        while(pNode->next != nullptr && pNode->next->m_nValue != value)
            pNode = pNode->next;

        if(pNode->next != nullptr && pNode->next->m_nValue == value)
        {
            pToBeDeleted = pNode->next;
            pNode->next = pNode->next->next;
        }
    }

    if(pToBeDeleted != nullptr)
    {
        delete pToBeDeleted;
        pToBeDeleted = nullptr;
    }
}


// ListNode* FindKthToTail(ListNode* pListHead, unsigned int k)
// {
//     if(pListHead == nullptr || k == 0)
//         return nullptr;

//     ListNode *pAhead = pListHead;
//     ListNode *pBehind = nullptr;

//     for(unsigned int i = 0; i < k - 1; ++ i)
//     {
//         if(pAhead->next != nullptr)
//             pAhead = pAhead->next;
//         else
//         {
//             return nullptr;
//         }
//     }

//     pBehind = pListHead;
//     while(pAhead->next != nullptr)
//     {
//         pAhead = pAhead->next;
//         pBehind = pBehind->next;
//     }

//     return pBehind;
// }

ListNode* FindKthToTail(ListNode* head, unsigned int k)
{
    if(head == nullptr || k == 0)
        return nullptr;
    ListNode *pre = head, *ahead = head;
    int i = 0;
    while(ahead->next)
    {
        ++i;
        ahead = ahead->next;
        if(i > k-1)
            pre = pre->next;
    }
    if(i < k-1) return nullptr;/* ���Ȳ���k�� */
    return pre;
}

// ====================���Դ���====================
// ����Ҫ�ҵĽ���������м�
void Test1()
{
    printf("=====Test1 starts:=====\n");
    ListNode* pNode1 = CreateListNode(1);
    ListNode* pNode2 = CreateListNode(2);
    ListNode* pNode3 = CreateListNode(3);
    ListNode* pNode4 = CreateListNode(4);
    ListNode* pNode5 = CreateListNode(5);

    ConnectListNodes(pNode1, pNode2);
    ConnectListNodes(pNode2, pNode3);
    ConnectListNodes(pNode3, pNode4);
    ConnectListNodes(pNode4, pNode5);

    printf("expected result: 4.\n");
    ListNode* pNode = FindKthToTail(pNode1, 2);
    PrintListNode(pNode);

    DestroyList(pNode1);
}

// ����Ҫ�ҵĽ���������β���
void Test2()
{
    printf("=====Test2 starts:=====\n");
    ListNode* pNode1 = CreateListNode(1);
    ListNode* pNode2 = CreateListNode(2);
    ListNode* pNode3 = CreateListNode(3);
    ListNode* pNode4 = CreateListNode(4);
    ListNode* pNode5 = CreateListNode(5);

    ConnectListNodes(pNode1, pNode2);
    ConnectListNodes(pNode2, pNode3);
    ConnectListNodes(pNode3, pNode4);
    ConnectListNodes(pNode4, pNode5);

    printf("expected result: 5.\n");
    ListNode* pNode = FindKthToTail(pNode1, 1);
    PrintListNode(pNode);

    DestroyList(pNode1);
}

// ����Ҫ�ҵĽ���������ͷ���
void Test3()
{
    printf("=====Test3 starts:=====\n");
    ListNode* pNode1 = CreateListNode(1);
    ListNode* pNode2 = CreateListNode(2);
    ListNode* pNode3 = CreateListNode(3);
    ListNode* pNode4 = CreateListNode(4);
    ListNode* pNode5 = CreateListNode(5);

    ConnectListNodes(pNode1, pNode2);
    ConnectListNodes(pNode2, pNode3);
    ConnectListNodes(pNode3, pNode4);
    ConnectListNodes(pNode4, pNode5);

    printf("expected result: 1.\n");
    ListNode* pNode = FindKthToTail(pNode1, 5);
    PrintListNode(pNode);

    DestroyList(pNode1);
}

// ���Կ�����
void Test4()
{
    printf("=====Test4 starts:=====\n");
    printf("expected result: nullptr.\n");
    ListNode* pNode = FindKthToTail(nullptr, 100);
    PrintListNode(pNode);
}

// ��������ĵڶ���������������Ľ������
void Test5()
{
    printf("=====Test5 starts:=====\n");
    ListNode* pNode1 = CreateListNode(1);
    ListNode* pNode2 = CreateListNode(2);
    ListNode* pNode3 = CreateListNode(3);
    ListNode* pNode4 = CreateListNode(4);
    ListNode* pNode5 = CreateListNode(5);

    ConnectListNodes(pNode1, pNode2);
    ConnectListNodes(pNode2, pNode3);
    ConnectListNodes(pNode3, pNode4);
    ConnectListNodes(pNode4, pNode5);

    printf("expected result: nullptr.\n");
    ListNode* pNode = FindKthToTail(pNode1, 6);
    PrintListNode(pNode);

    DestroyList(pNode1);
}

// ��������ĵڶ�������Ϊ0
void Test6()
{
    printf("=====Test6 starts:=====\n");
    ListNode* pNode1 = CreateListNode(1);
    ListNode* pNode2 = CreateListNode(2);
    ListNode* pNode3 = CreateListNode(3);
    ListNode* pNode4 = CreateListNode(4);
    ListNode* pNode5 = CreateListNode(5);

    ConnectListNodes(pNode1, pNode2);
    ConnectListNodes(pNode2, pNode3);
    ConnectListNodes(pNode3, pNode4);
    ConnectListNodes(pNode4, pNode5);

    printf("expected result: nullptr.\n");
    ListNode* pNode = FindKthToTail(pNode1, 0);
    PrintListNode(pNode);

    DestroyList(pNode1);
}

int main(int argc, char* argv[])
{
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();
    Test6();

    return 0;
}

