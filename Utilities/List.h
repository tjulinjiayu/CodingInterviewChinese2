/*******************************************************************
Copyright(c) 2016, Harry He
All rights reserved.

Distributed under the BSD license.
(See accompanying file LICENSE.txt at
https://github.com/zhedahht/CodingInterviewChinese2/blob/master/LICENSE.txt)
*******************************************************************/

//==================================================================
// 《剑指Offer——名企面试官精讲典型编程题》代码
// 作者：何海涛
//==================================================================
#ifndef _LIST_HEADER_
#define _LIST_HEADER_

struct ListNode
{
    int       m_nValue;
    ListNode* m_pNext;
};

ListNode* CreateListNode(int value);
void ConnectListNodes(ListNode* pCurrent, ListNode* pNext);
void PrintListNode(ListNode* pNode);
void PrintList(ListNode* pHead);
void DestroyList(ListNode* pHead);
void AddToTail(ListNode** pHead, int value);
void RemoveNode(ListNode** pHead, int value);

// __declspec( dllexport ) ListNode* CreateListNode(int value);
// __declspec( dllexport ) void ConnectListNodes(ListNode* pCurrent, ListNode* pNext);
// __declspec( dllexport ) void PrintListNode(ListNode* pNode);
// __declspec( dllexport ) void PrintList(ListNode* pHead);
// __declspec( dllexport ) void DestroyList(ListNode* pHead);
// __declspec( dllexport ) void AddToTail(ListNode** pHead, int value);
// __declspec( dllexport ) void RemoveNode(ListNode** pHead, int value);
#endif