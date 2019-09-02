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
	strcpy(BaseBookifm.no, "���");
	strcpy(BaseBookifm.bookName, "����");
	strcpy(BaseBookifm.author, "����");
	strcpy(BaseBookifm.publisher, "������");
	BaseBookifm.price = 0;
	L->data = BaseBookifm;
	// L->data=BaseBookifm
	// ������ֱ�Ӹ�ֵ
	return OK;
}

/*
	�������ʼ��ͷ�ڵ�
*/
Status InitList(LNode** L) {
	*L = (LNode*)malloc(sizeof(LNode));
	if (*L == NULL) {
		printf("����ռ�ʧ��");
	}
	if (InitHeadNode(*L) == OK) {
		cout << "�ɹ���ʼ��ͷ���" << endl << endl;
	}
	(*L)->next = NULL;
	return OK;
}

/*
	�������س���
*/
int ListLength(LinkList L) {
	// ����L��Ԫ�ظ���
	LinkList p;
	p = L->next; // pָ���һ�����
	int i = 0;
	while (p) { // ����������ͳ�ƽ����
		i++;
		p = p->next;
	}
	return i;
}

Status ClearList(LinkList L) {
	// ��L����Ϊ�ձ�
	LinkList p, q;
	p = L->next; // pָ���һ�����
	while (p) {
		q = p->next;
		free(p);
		p = q;
	}
	L->next = NULL;
	return OK;
}

void JudgeResponseCode(Status ResponseCode) {
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

