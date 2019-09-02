#pragma once
#include"sort.h"
/*
	查找
*/

void SearchBookByNo(LNode* L);
void SearchBookByName(LNode* L);

void SearchBook(LNode* L) {
	
	int inputOption = 0;
	while (1) {
		cout << "请输入查找信息 1.书号 2.书名 3.退出" << endl;
		cin >> inputOption;
		if (inputOption == 3) {
			break;
		}
		switch (inputOption) {
		case 1:
			SearchBookByNo(L);
			break;
		case 2:
			SearchBookByName(L);
			break;
		case 3:
			Console();
			break;
		default:
			cout << "请重新输入数字" << endl;
			break;
		}
	}
}

void SearchBookByNo(LNode* L) {// 通过书号精确查找
	LNode* p = L->next;
	char inputNo[50];
	cout << "请输入书号:";
	cin >> inputNo;
	while (p) {
		if (strcmp(inputNo, p->data.no) == 0) {
			break;
		};
		p = p->next;
	}
	if (p) {
		printf("%-15s|%-15s|%-15s|%-15s|%-2.0f|\n", p->data.no, p->data.bookName, p->data.author, p->data.publisher, p->data.price);
	}
	else {
		cout << "没找到" << endl;
	}
}

void SearchBookByName(LNode* L) {// 通过书名精确查找
	LNode* p = L->next;
	char bookName[50];
	int flag = 0, count = 0;
	cout << "请输入书名:";
	cin >> bookName;
	while (p) {
		if (strcmp(bookName, p->data.bookName) == 0) {
			printf("%-15s|%-15s|%-15s|%-15s|%-2.0f|\n", p->data.no, p->data.bookName, p->data.author, p->data.publisher, p->data.price);
			flag = 1;
			count++;
		};
		p = p->next;
	}
	if (flag == 0) {
		cout << "没找到" << endl;
	}
	cout << "查找长度为" << count << endl;
}

void SearchBookByPrice(LNode* L) {
	float min = 0, max = 0;
	LNode* p = L->next;
	LNode* waitSortList = new LNode;
	InitHeadNode(waitSortList);
	LNode* pw = waitSortList;
	cout << "请输入一个最小和最大的价格:";
	cin >> min >> max;
	if (min > max) {
		int temp;
		temp = min;
		min = max;
		max = temp;
	}
	while (p) {
		if (p->data.price <= max && p->data.price >= min) {
			LNode* temp = new LNode;
			temp->data = p->data;
			pw->next = temp;
			//pw->next = p;
			pw = pw->next;
		}
		p = p->next;
	}
	Book t;
	pw->next = NULL;
	for (LNode* temp = waitSortList->next; temp->next != NULL; temp = temp->next) {
		for (LNode* p = waitSortList->next; p->next != NULL; p = p->next) {
			if (p->data.price < p->next->data.price) {
				t = p->data;
				p->data = p->next->data;
				p->next->data = t;
			}
		}
	}
	AccessNodesData(waitSortList);
}

void SearchBookByAuthor(LNode* L) {
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
			q->data = p1->data;//数据源数据赋给结果集
			q->next = p2->next;
			p2->next = q;
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
		if (BF(p1->data.bookName, keywords) == 1) {//模糊查找
			LNode* q = new LNode;
			q->data = p1->data;//数据源数据赋给结果集
			q->next = p2->next;
			p2->next = q;
		}
		p1 = p1->next;
	}
	AccessNodesData(searchresult);
}
