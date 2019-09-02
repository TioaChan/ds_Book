#pragma once
void asc(LNode* L) {
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

void desc(LNode* L) {
	Book t;
	for (LNode* temp = L->next; temp->next != NULL; temp = temp->next) {
		for (LNode* p = L->next; p->next != NULL; p = p->next) {
			if (p->data.price < p->next->data.price) {
				t = p->data;
				p->data = p->next->data;
				p->next->data = t;
			}
		}
	}
}
