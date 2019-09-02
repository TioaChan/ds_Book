#pragma once
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
