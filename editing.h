#pragma once
Status ChangeBookInfo(LNode* L) {
	LNode* p = L->next;
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
