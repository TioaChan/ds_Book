#pragma once
void searchbyauthor(LNode* L) {
	printf("输入作者以进行查找：");
	char keywords[10];
	scanf("%s", keywords);
	LinkList searchresult = new LNode;
	searchresult->next = NULL;//初始化搜索结果链表
	LNode* p1 = L->next;//指向数据源的指针
	LNode* p2 = searchresult->next;//指向结果集的指针
	while (p1)//遍历数据源
	{
		if (strcmp(p1->data.author, keywords) == 0) {//如果作者相同
			p2->data = p1->data; //数据源数据赋给结果集
			p2 = p2->next;//
		}
		p1 = p1->next;
	}
}
