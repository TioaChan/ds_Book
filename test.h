#pragma once
#include "sort.h"
int BF(char* source, char* target);

void searchbyauthor(LNode* L) {
	printf("输入作者以进行查找：");
	char keywords[10];
	scanf("%s", keywords);
	LinkList searchresult = new LNode;
	searchresult->next = NULL;//初始化搜索结果链表
	InitHeadNode(searchresult);
	LNode* p1 = L->next;//指向数据源的指针
	LNode* p2 = searchresult;//指向结果集的指针
	while (p1)//遍历数据源
	{
		if (strcmp(p1->data.author, keywords) == 0) {//如果作者相同
			LNode* q = new LNode;
			q->data=p1->data;//数据源数据赋给结果集
			q->next=p2->next;
			p2->next=q;
		}
		p1 = p1->next;
	}
	asc_price(searchresult);
	AccessNodesData(searchresult);
}

void searchbybookname(LNode* L) {
	printf("输入书名以进行查找：");
	char keywords[10];
	scanf("%s", keywords);
	LinkList searchresult = new LNode;
	searchresult->next = NULL;//初始化搜索结果链表
	InitHeadNode(searchresult);
	LNode* p1 = L->next;//指向数据源的指针
	LNode* p2 = searchresult;//指向结果集的指针
	while (p1)//遍历数据源
	{
		if (BF(p1->data.bookName, keywords)==1) {//模糊查找
			LNode* q = new LNode;
			q->data = p1->data;//数据源数据赋给结果集
			q->next = p2->next;
			p2->next = q;
		}
		p1 = p1->next;
	}
	AccessNodesData(searchresult);
}

int BF(char* source, char* target) {
	int j = 0;
	int t_len = strlen(target);
	int s_len = strlen(source);
	for (int i = 0; i < s_len; i++) {
		if (source[i] == target[j]) {
			j++;//记录相同的长度,若长度与target相同，则表示已完全匹配 
		}
		else if (j != 0) {//回溯
			i -= j;//将i回溯至source中target的第一个元素的位置（最近的）,i++ 后将移向下一个位置进行比较 
			j = 0;//将j归0，寻找source中下一个与target第一个元素相等的位置
		}
		if (j == t_len) {
			return 1;
		}
	}
	return 0;
}


