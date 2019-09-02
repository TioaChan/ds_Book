#pragma once

int BF(char* source, char* target) {
	int j = 0;
	int t_len = strlen(target);
	int s_len = strlen(source);
	for (int i = 0; i < s_len; i++) {
		if (source[i] == target[j]) {
			j++;//��¼��ͬ�ĳ���,��������target��ͬ�����ʾ����ȫƥ�� 
		}
		else if (j != 0) {//����
			i -= j;//��i������source��target�ĵ�һ��Ԫ�ص�λ�ã�����ģ�,i++ ��������һ��λ�ý��бȽ� 
			j = 0;//��j��0��Ѱ��source����һ����target��һ��Ԫ����ȵ�λ��
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
