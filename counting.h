#pragma once
/*
	11. 统计。
    * 统计每个出版社出版的图书总数，按图书总数升序输出。
    * 统计每个作者出版的图书总数，按图书总数降序输出。
*/
void countBookByPublisher_ASC(LNode* L);
void countBookByAuthor_DESC(LNode* L);

void Statistics(LNode* L) {// 统计
	int op;
	while (1) {
		cout << "1.统计出版社图书出版总数，按升序输出\n2.统计作者出版图书总数，按降序输出\n3.退出" << endl;
		cin >> op;
		if (op == 3) {
			break;
		}
		switch (op) {
		case 1: 
			countBookByPublisher_ASC(L);
			break;
		case 2: 
			countBookByAuthor_DESC(L);
			break;
		case 3:Console();
			break;
		default:
			cout << "请重新输入数字" << endl;
			break;
		}
	}
}


void countBookByPublisher_ASC(LNode* L) {//统计每个出版社出版的图书总数，按图书总数升序输出。
	PNode* waitSort = new PNode;
	LNode* p = L->next;
	PNode* pw = waitSort;
	PNode* pre = waitSort;
	strcpy(pw->data.pName, "###");
	pw->next = NULL;
	pw->data.count = 0;
	while (p) {
		int flag = 1;
		while (pw) {
			if (strcmp(pw->data.pName, p->data.publisher) == 0) {
				flag = 0;
			}
			pre = pw;
			pw = pw->next;
		}

		if (flag == 1) {
			PNode* q = new PNode;
			strcpy(q->data.pName, p->data.publisher);
			q->next = NULL;
			q->data.count = 0;
			pre->next = q;
		}
		pw = waitSort->next;
		p = p->next;
	}
	pw = waitSort->next;
	p = L->next;
	while (pw) {
		p = L->next;
		while (p) {
			if (strcmp(pw->data.pName, p->data.publisher) == 0) {
				pw->data.count++;
			}
			p = p->next;
		}
		pw = pw->next;
	}
	pw = waitSort->next;
	Publisher t;
	for (PNode* temp = waitSort->next; temp->next != NULL; temp = temp->next) {
		for (PNode* pn = waitSort->next; pn->next != NULL; pn = pn->next) {
			if (pn->data.count > pn->next->data.count) {
				t = pn->data;
				pn->data = pn->next->data;
				pn->next->data = t;
			}
		}
	}
	while (pw) {
		cout << pw->data.pName << ":" << pw->data.count << endl;;
		pw = pw->next;
	}
}

void countBookByAuthor_DESC(LNode* L) {//统计每个出版社出版的图书总数，按图书总数升序输出。
	ANode* waitSort = new ANode;
	LNode* p = L->next;
	ANode* pw = waitSort;
	ANode* pre = waitSort;
	strcpy(pw->data.aName, "###");
	pw->next = NULL;
	pw->data.count = 0;
	while (p) {
		int flag = 1;
		while (pw) {
			if (strcmp(pw->data.aName, p->data.author) == 0) {
				flag = 0;
			}
			pre = pw;
			pw = pw->next;
		}

		if (flag == 1) {
			ANode* q = new ANode;
			strcpy(q->data.aName, p->data.author);
			q->next = NULL;
			q->data.count = 0;
			pre->next = q;
		}
		pw = waitSort->next;
		p = p->next;
	}
	pw = waitSort->next;
	p = L->next;

	while (pw) {
		p = L->next;
		while (p) {

			if (strcmp(pw->data.aName, p->data.author) == 0) {
				pw->data.count++;
			}
			p = p->next;
		}
		pw = pw->next;
	}
	pw = waitSort->next;
	Author t;
	for (ANode* temp = waitSort->next; temp->next != NULL; temp = temp->next) {
		for (ANode* pn = waitSort->next; pn->next != NULL; pn = pn->next) {
			if (pn->data.count < pn->next->data.count) {
				t = pn->data;
				pn->data = pn->next->data;
				pn->next->data = t;
			}
		}
	}
	while (pw) {
		cout << pw->data.aName << ":" << pw->data.count << endl;;
		pw = pw->next;
	}
}
