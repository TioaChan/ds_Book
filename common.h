#pragma once

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

int ListLength(LinkList L) {// 返回L中元素个数
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
