#pragma once
#include"sort.h"
/*
	����
*/

void SearchBookByNo(LNode* L);
void SearchBookByName(LNode* L);

void SearchBook(LNode* L) {
	
	int inputOption = 0;
	while (1) {
		cout << "�����������Ϣ 1.��� 2.���� 3.�˳�" << endl;
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
			cout << "��������������" << endl;
			break;
		}
	}
}

void SearchBookByNo(LNode* L) {// ͨ����ž�ȷ����
	LNode* p = L->next;
	char inputNo[50];
	cout << "���������:";
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
		cout << "û�ҵ�" << endl;
	}
}

void SearchBookByName(LNode* L) {// ͨ��������ȷ����
	LNode* p = L->next;
	char bookName[50];
	int flag = 0, count = 0;
	cout << "����������:";
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
		cout << "û�ҵ�" << endl;
	}
	cout << "���ҳ���Ϊ" << count << endl;
}

void SearchBookByPrice(LNode* L) {
	float min = 0, max = 0;
	LNode* p = L->next;
	LNode* waitSortList = new LNode;
	InitHeadNode(waitSortList);
	LNode* pw = waitSortList;
	cout << "������һ����С�����ļ۸�:";
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
	printf("���������Խ��в��ң�");
	char keywords[10];
	scanf("%s", keywords);
	LinkList searchresult = new LNode;
	searchresult->next = NULL;//��ʼ�������������
	InitHeadNode(searchresult);
	LNode* p1 = L->next;//ָ������Դ��ָ��
	LNode* p2 = searchresult;//ָ��������ָ��
	while (p1)//��������Դ
	{
		if (strcmp(p1->data.author, keywords) == 0) {//���������ͬ
			LNode* q = new LNode;
			q->data = p1->data;//����Դ���ݸ��������
			q->next = p2->next;
			p2->next = q;
		}
		p1 = p1->next;
	}
	asc_price(searchresult);
	AccessNodesData(searchresult);
}

void searchbybookname(LNode* L) {
	printf("���������Խ��в��ң�");
	char keywords[10];
	scanf("%s", keywords);
	LinkList searchresult = new LNode;
	searchresult->next = NULL;//��ʼ�������������
	InitHeadNode(searchresult);
	LNode* p1 = L->next;//ָ������Դ��ָ��
	LNode* p2 = searchresult;//ָ��������ָ��
	while (p1)//��������Դ
	{
		if (BF(p1->data.bookName, keywords) == 1) {//ģ������
			LNode* q = new LNode;
			q->data = p1->data;//����Դ���ݸ��������
			q->next = p2->next;
			p2->next = q;
		}
		p1 = p1->next;
	}
	AccessNodesData(searchresult);
}
