#pragma once
/*
排序方法
*/

int BF(char* source, char* target) {//
	int j = 0;
	int t_len = strlen(target);
	int s_len = strlen(source);
	for (int i = 0; i < s_len; i++) {
		if (source[i] == target[j]) {
			j++;//记录相同的长度,若长度与target相同，则表示已完全匹配 
		}
		else if (j != 0) {//回溯
			i -= j;//将i回溯至source中target的第一个元素的位置（最近的）,i++ 后将移向下一个位置进行比较 
			j = 0;//将j归0，寻找source中下一个与target第一个元素相等的位置
		}
		if (j == t_len) {
			return 1;
		}
	}
	return 0;
}


void asc_price(LNode* L) {
	Book t;
	for (LNode* temp = L->next; temp->next != NULL; temp = temp->next) {
		for (LNode* p = L->next; p->next != NULL; p = p->next) {
			if (p->data.price > p->next->data.price) {
				t = p->data;
				p->data = p->next->data;
				p->next->data = t;
			}
		}
	}
}

void asc_PublisherAndAuthor(LNode* L) {
	Book t;
	for (LNode* temp = L->next; temp->next != NULL; temp = temp->next) {
		for (LNode* p = L->next; p->next != NULL; p = p->next) {
			if (strcmp(p->data.publisher, p->next->data.publisher)==1) {
				t = p->data;
				p->data = p->next->data;
				p->next->data = t;
			}
			else if(strcmp(p->data.publisher, p->next->data.publisher) == 0) {
				if (strcmp(p->data.author, p->next->data.author) == 1){
					t = p->data;
					p->data = p->next->data;
					p->next->data = t;
				}
			}
		}
	}
}

void asc_AuthorAndPrice(LNode* L) {
	Book t;
	for (LNode* temp = L->next; temp->next != NULL; temp = temp->next) {
		for (LNode* p = L->next; p->next != NULL; p = p->next) {
			if (strcmp(p->data.author, p->next->data.author) == 1) {
				t = p->data;
				p->data = p->next->data;
				p->next->data = t;
			}
			else if (strcmp(p->data.author, p->next->data.author) == 0) {
				if (p->data.price > p->next->data.price) {
					t = p->data;
					p->data = p->next->data;
					p->next->data = t;
				}
			}
		}
	}
}
