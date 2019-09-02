#pragma once
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
