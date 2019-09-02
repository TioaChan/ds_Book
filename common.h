#pragma once

#include<Windows.h>

/*
	封装Book和字段
*/
Book BookFactory(const char* no, const char* bookName, const char* author, const char* publisher, float price) {
	Book book;
	strcpy(book.no, no);
	strcpy(book.bookName, bookName);
	strcpy(book.author, author);
	strcpy(book.publisher, publisher);
	book.price = price;
	return book;
}

Status InitHeadNode(LNode* L) {
	Book BaseBookifm;
	strcpy(BaseBookifm.no, "书号");
	strcpy(BaseBookifm.bookName, "书名");
	strcpy(BaseBookifm.author, "作者");
	strcpy(BaseBookifm.publisher, "出版社");
	BaseBookifm.price = 0;
	L->data = BaseBookifm;
	// L->data=BaseBookifm
	// 这里是直接赋值
	return OK;
}

/*
	单链表初始化头节点
*/
Status InitList(LNode** L) {
	*L = (LNode*)malloc(sizeof(LNode));
	if (*L == NULL) {
		printf("申请空间失败");
	}
	if (InitHeadNode(*L) == OK) {
		cout << "成功初始化头结点" << endl << endl;
	}
	(*L)->next = NULL;
	return OK;
}

/*
	返回L中元素个数
*/
int ListLength(LinkList L) {
	LinkList p;
	p = L->next; // p指向第一个结点
	int i = 0;
	while (p) { // 遍历单链表，统计结点数
		i++;
		p = p->next;
	}
	return i;
}

Status ClearList(LinkList L) {// 将L重置为空表
	LinkList p, q;
	p = L->next; // p指向第一个结点
	while (p) {
		q = p->next;
		free(p);
		p = q;
	}
	L->next = NULL;
	return OK;
}

void JudgeResponseCode(Status ResponseCode) {//用于判断返回值
	switch (ResponseCode) {
	case OK:
		printf("Success\n");
		break;
	case ERROR:
		printf("ERROR check your code!\n");
		break;
	case OVERFLOW:
		printf("memory has OVERFLOW now\n");
		break;
	default:
		printf("No Response Code\n");
		break;
	}
}

void AccessNodesData(LNode* L) {//遍历节点并打印
	LNode* p = L;
	printf("节点信息为：\n");
	printf("%-15s|%-15s|%-15s|%-15s|%-2.0f |\n", p->data.no, p->data.bookName, p->data.author, p->data.publisher, p->data.price);
	p = p->next; // 跑出头节点
	do {
		printf("%-15s|%-15s|%-15s|%-15s|%-2.0f|\n", p->data.no, p->data.bookName, p->data.author, p->data.publisher, p->data.price);
		p = p->next;
	} while (p != NULL); // !! 注意是p!=NULL 而不是p->next!=NULL
}

Status WriteStructToFile(LNode* L) {//写入L到文件中
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

Status ReadStructFromFile(LNode* L) {//读取文件数据到L中
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

void copyright() {
	cout << "\n\n\n            Copyright\n" << endl;
	Sleep(2000);
	system("cls");
}

