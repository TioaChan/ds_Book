#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
#include<io.h>
using namespace std;

#define OK 1
#define ERROR 0
#define OVERFLOW -2
#define MAXSIZE 200

typedef int Status;

typedef struct {
	char no[50];
	char bookName[50];
	char author[50];
	char publisher[50];
	float price;
} Book;

typedef struct LNode {
	Book data; // 数据域
	struct LNode* next; // 指针域
} LNode, * LinkList;// *LinkList为Lnode类型的指针

typedef struct {
	char pName[50];
	int count;
} Publisher;

typedef struct PNode {
	Publisher data;
	struct PNode* next;
} PNode;

typedef struct {
	char aName[50];
	int count;
} Author;

typedef struct ANode {
	Author data;
	struct ANode* next;
} ANode;

Status ClearList(LinkList L);
Status InitList(LNode** L);
Status InitHeadNode(LNode* L);
Status ListInsert(LNode* L, int i, Book e);
Status SuperListInsert(LNode* L, int i, const char* no, const char* bookName, const char* author, const char* publisher, float price);
int ListLength(LinkList L);
void AccessNodesData(LNode* L);
void BatchInsert(LNode* p);
void JudgeResponseCode(Status ResponseCode);
Status WriteStructToFile(LNode* L);
Status ReadStructFromFile(LNode* L);
void Console();


#include"order.h"
#include"InitData.h"
#include"search.h"
#include"common.h"
#include"counting.h"
#include"adding.h"
#include"editing.h"
#include"deleting.h"

Status ListInsert(LNode* L, int i, Book e) {
	LNode* p = L;
	int j = 0;
	while (p && j < i - 1) {
		p = p->next;
		j++;  // 寻找i-1个结点
	}
	if (!p || j > i - 1) {
		return ERROR; //i大于表长+1或者小于1
	}
	LNode* Node = (LNode*)malloc(sizeof(LNode));
	//首先LNode是局部变量，在栈里，函数消亡的时候LNode也跟着消亡
	// 所以不能LNode Node声明在函数里，然后让插入单链表中

	// 使用malloc是在堆中申请长度为 LNode的连续空间
	// 进而申请到一个结点
	// 这个结点系统不会自动回收，需要程序员自己进行释放
	// 这样就可以保证结点不会被消亡
	// 同时即将消亡的Node指针，因为及时的链接到了上一个节点指针上
	// 因此得到了保留

	Node->data = e;
	Node->next = p->next;
	p->next = Node;

	// ====================================
	//  以下为错误代码
	//	LNode N;
	//	LNode *q=&N;
	//	q->data=e;
	//	q->next=p->next;
	//	p->next=q;
	//	printf("%s",p->next->data.name);
	//	printf("%s",p->next->data.no);
	//	printf("%f",p->next->data.price);
	// ====================================
	return OK;
}

Status SuperListInsert(LNode* L, int i, const char* no, const char* bookName, const char* author, const char* publisher, float price) {
	Book book = BookFactory(no, bookName, author, publisher, price);
	if (ListInsert(L, i, book) == OK) {
		return OK;
	}
}


void Console() {
	cout << "欢迎来到图书管理软件Ver1.0版本" << endl;
	LNode* p;  // p为指向LNode的指针体
	LNode** q = &p; // q指向指针的指针
	InitList(q);
	ReadStructFromFile(p);
	while (1) {
		int input = 0;
		cout << "1.增加图书" <<
			endl << "2.修改图书信息" <<
			endl << "3.删除指定图书" <<
			endl << "4.查询图书信息" <<//
			endl << "5.按照价格范围查找" <<//
			endl << "6.查找某个作者出版的所有信息，按价格升序输出 " <<//
			endl << "7.书名模糊查找" <<//
			endl << "8 输出图书所有信息" <<
			endl << "9.统计" << endl << endl;
		cin >> input;
		switch (input) {
		case 1:
			// 可以增加新图书。
			AddNewBook(p);
			break;
		case 2:
			if (ChangeBookInfo(p) == OK) {
				cout << "修改成功" << endl;
			}
			else {
				cout << "修改失败" << endl;
			}
			// 可以修改某个图书信息（书号不能改）。
			break;
		case 3:
			DeleteBookInfo(p);
			// 可以删除某些图书信息（分别按书号、书名进行删除）。
			break;
		case 4:
			SearchBook(p);
			// 可以按书号或书名进行精确查找（按书名查找时，如果有多本图书，则全部查找出来，并输出其查找长度）。
			break;
		case 5:
			SearchBookByPrice(p);
			// 可以按价格范围进行查找（结果按价格降序输出）。
			break;
		case 6:
			SearchBookByAuthor(p);
			// 查找某个作者出版的所有图书信息，按价格升序输出。
			break;
		case 7:searchbybookname(p);
			// 可以按书名进行模糊查找。
			break;
		case 8:
			// 输出所有图书信息。
			orderbyPublisherAndAuthor(p);
			orderbyAuthorAndPrice(p);
			break;
		case 9:
			Statistics(p);
			break;
		default:
			cout << "输入错误，轻重新输入" << endl;
			Console();
			break;
		}
	}
}

int main() {
	if (((_access("a.dat", 0)) != -1)&&(_filelength(_open("a.dat", 0x0100)) > 0))//文件存在且文件大小大于0
	{
		Console();
	}
	else
	{
		InitData();
		Console();
	}

}
