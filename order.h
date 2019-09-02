#pragma once
#include"sorting.h"

void orderbyPublisherAndAuthor(LNode* L) {
	LinkList searchresult = new LNode;
	searchresult->next = NULL;//初始化搜索结果链表
	InitHeadNode(searchresult);
	LNode* p1 = L->next;//指向数据源的指针
	LNode* p2 = searchresult;//指向结果集的指针
	while (p1)//遍历数据源
	{
		//if (strcmp(p1->data.author, keywords) == 0) {//如果作者相同
			LNode* q = new LNode;
			q->data = p1->data;//数据源数据赋给结果集
			q->next = p2->next;
			p2->next = q;
		//}
		p1 = p1->next;
	}
	asc_PublisherAndAuthor(searchresult);
	AccessNodesData(searchresult);
}

void orderbyAuthorAndPrice(LNode* L) {
	LinkList searchresult = new LNode;
	searchresult->next = NULL;//初始化搜索结果链表
	InitHeadNode(searchresult);
	LNode* p1 = L->next;//指向数据源的指针
	LNode* p2 = searchresult;//指向结果集的指针
	while (p1)//遍历数据源
	{
		//if (strcmp(p1->data.author, keywords) == 0) {//如果作者相同
		LNode* q = new LNode;
		q->data = p1->data;//数据源数据赋给结果集
		q->next = p2->next;
		p2->next = q;
		//}
		p1 = p1->next;
	}
	asc_AuthorAndPrice(searchresult);
	AccessNodesData(searchresult);
}

