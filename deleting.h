#pragma once
/*
	5. 可以删除某些图书信息（分别按书号和书名进行删除）。
*/
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
