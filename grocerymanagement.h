#ifndef GROCERYMANAGEMENT_H
#define GROCERYMANAGEMENT_H

template <class T>
class grocerymanagement{
	
public:

	typedef struct Node{
		T data;
		struct Node* next;
	} node;

	node* head;

	void add(T info);
	void remove(T info);
	void print();
	void print(node* q);
	grocerymanagement();

};

	template <class T>
	void grocerymanagement<T> :: add(T info)
	{
		node* temp = new node;
		temp->data = info;
		temp->next = NULL;

		if(head == NULL)
		{
			head = temp;
		}

		else{
			node* p = head;
			while(p->next != NULL)
				p = p->next;
			p->next = temp;
		}
	}
	
	
	template <class T>
	void grocerymanagement<T> :: remove(T info)
	{
		if(head->data == info)
		{
			node* q = head;
			head = q->next;
			delete q;
		}
		
		else{
			node* p = head;
			node* q = NULL;
			while(p->next->data != info)
			{
				p = p->next;
			}
			q = p->next;
			p->next = q->next;
			q->next = NULL;
			delete q;
		}
	}

	template <class T>
	void grocerymanagement<T> :: print()
	{
		node* p = head;
		while(p!=NULL)
		{
			p->data->print();
			p = p->next;
			printf("\n");
		}
	}

	template <class T>
	void grocerymanagement<T> :: print(node* q)
	{
		node* p = q;
		while(p!=NULL)
		{
			p->data->print();
			p = p->next;
			printf("\n");
		}
	}

	template <class T>
	grocerymanagement<T> :: grocerymanagement()
	{
		head = NULL;
	}

#endif
