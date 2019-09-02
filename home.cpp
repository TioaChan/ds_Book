#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
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

Status ListDelete(LinkList L, int i) {
	// 在带头结点的单链表，删除第i个元素
	LNode* p = L;
	int j = 0;
	while ((p->next) && (j < i - 1)) { // 查找第i-1个结点，p指向该结点
		p = p->next;
		j++;
	}
	if (!(p->next) || (j > i - 1)) {	// 当i>n或i<1时，删除位置不合理
		return ERROR;
	}
	LNode* q = p->next;
	p->next = q->next;
	free(q);
	return OK;
}

Status WriteStructToFile(LNode* L) {
	LNode* p = L->next;
	FILE* pf;
	int count = 0;
	if ((pf = (fopen(".\\a.dat", "w+"))) == 0)
		return ERROR;
	while (p) {
		fprintf(pf, "%s %s %s %s %f\n", p->data.no, p->data.bookName, p->data.author, p->data.publisher, p->data.price);
		p = p->next;
		count++;
	}
	cout << "共有" << count << "条数据" << endl;
	fclose(pf);
	return OK;
}

Status ReadStructFromFile(LNode* L) {
	ClearList(L);
	FILE* pf;
	if ((pf = (fopen(".\\a.dat", "r"))) == 0)
		return ERROR;
	Book b;
	int i = 0;
	while (!feof(pf)) {
		int res = fscanf(pf, "%s%s%s%s%f", b.no, b.bookName, b.author, b.publisher, &b.price);
		if (res == -1)break;
		ListInsert(L, ++i, b);
		// !Debug重要性
	}
	fclose(pf);
	return OK;
}



Status AddNewBook(LNode* L) {
	float price;
	int flag; // 检测no
	LNode* p = L->next;
	char name[50], au[50], pub[50], no[50];
	cout << "请分别输入书号、书名、作者（1个）、出版社、价格五个部分" << endl;
	int length = ListLength(L);
	cin >> no >> name >> au >> pub >> price;
	while (1) {
		flag = 1;
		while (p) {
			if (strcmp(no, p->data.no) == 0) {
				flag = 0;
				break;
			}
			p = p->next;
		}
		p = L->next;
		if (flag == 0) {
			cout << "书号重复,请重新输入书号:";
			cin >> no;
		}
		else {
			break;
		}
	}
	Book e = BookFactory(no, name, au, pub, price);
	for (int i = 0; i < length - 1; i++) {
		p = p->next;
	}
	LNode* q = new LNode;
	q->data = e;
	q->next = NULL;
	p->next = q;
	WriteStructToFile(L);
	return OK;
}

Status ChangeBookInfo(LNode* L) {
	LNode* p=L->next;
	char inputNo[50];
	int inputOption = 0, flag = 0;
	cout << "请输入需要修改的书号" << endl;
	cin >> inputNo;
	while (p) {
		if (strcmp(p->data.no, inputNo) == 0) {
			break;
		}
		p = p->next;
	}
	if (p) {
		while (1) {
			cout << "请输入需要修改的数据 1.书名 2.作者 3.出版社 4.价钱 5.退出" << endl;
			cin >> inputOption;
			switch (inputOption) {
			case 1:
				char bookname[50];
				cout << "请输入书名:";
				cin >> bookname;
				strcpy(p->data.bookName, bookname);
				// 修改书名
				break;
			case 2:
				char author[50];
				cout << "请输入作者:";
				cin >> author;
				strcpy(p->data.author, author);
				// 修改作者
				break;
			case 3:
				char publisher[50];
				cout << "请输入出版社:";
				cin >> publisher;
				strcpy(p->data.publisher, publisher);
				// 修改出版社
				break;
			case 4:
				float price;
				cout << "请输入价格:";
				cin >> price;
				p->data.price = price;
				// 修改价钱
				break;
			case 5:
				break;
			default:
				cout << "请重新输入数字" << endl;
				break;
			}
			if (inputOption == 5) {
				WriteStructToFile(L);
				return OK;
				break;
			}
		}
	}
	else {
		cout << "没有找到书号" << endl;
		return ERROR;
	}
}

void DeleteBookInfo(LNode* L) {
	char inputNo[50];
	int intOption = 0;
	int i = 1;
	LNode* p;
	LNode* pre = new LNode;
	while (1) {
		cout << "请输入需要删除的信息 1.书号 2.书名 3.退出" << endl;
		cin >> intOption;
		if (intOption == 3) {
			break;
		}
		switch (intOption) {
		case 1:
			// 按书号删除
			cout << "请输入书号:";
			cin >> inputNo;
			p = L->next;
			i = 1;
			while (p) {
				if (strcmp(p->data.no, inputNo) == 0) {
					break;
				}
				p = p->next;
				i++;
			}
			if (p) {
				ListDelete(L, i);
				WriteStructToFile(L);
				cout << "删除成功" << endl;
			}
			else {
				cout << "删除失败,没有找到书籍信息";
			}
			break;
		case 2: {
			// 按书名删除
			char bookName[50];
			int flag = 0;
			cout << "请输入书名:";
			cin >> bookName;
			p = L->next;
			pre = L;
			while (p) {
				if (strcmp(p->data.bookName, bookName) == 0) {
					pre->next = p->next;
					free(p);
					p = pre;
					flag = 1;
				}
				pre = p;
				p = p->next;
			}
			if (flag == 1) {
				WriteStructToFile(L);
				cout << "删除成功" << endl;
			}
			else {
				cout << "没有找到需要找到的书籍" << endl;
			}
			break;
		}
		case 3:
			break;
		default:
			cout << "请重新输入数字" << endl;
			break;
		}
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
	//InitData();
	Console();
}
