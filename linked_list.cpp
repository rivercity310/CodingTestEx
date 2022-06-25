#include <iostream>
using namespace std;

class linked_list {
private:
	struct node {
		int data;
		node* next;
	};

	node* head = nullptr;
	node* tail = nullptr;

public:
	linked_list(int val) {
		if (head == NULL) {
			head = new node{ val, NULL };
			tail = head;
		}
	}

	~linked_list() {
		while (head != NULL) {
			cout << head->data << " ����" << endl;
			node* tmp = head->next;
			delete head;
			head = tmp;
		}

		tail = head;
	}

	void add_data(int val) {
		if (tail != NULL) {
			tail->next = new node{ val, NULL };
			tail = tail->next;
			tail->data = val;
		}
	}

	void del_data(int val) {
		node* p = head;
		
		// ù��° �����
		if (p->data == val) {
			node* tmp = head->next;
			delete head;
			
			head = tmp;
		}		
		else {
			// ���� ��� ã��
			node* prv = head;
			while (prv->next->data != val)
				prv = prv->next;
			
			node* tmp = prv->next->next;
			if (!tmp) cout << "NULL" << endl;
			else cout << tmp->data << " ����" << endl;

			if (!tmp) {
				delete prv->next;
				prv->next = tmp;

				tail = tmp;
			}
			// ������ ��带 �����ϴ� ���
			else {
				cout << "Last Node Del" << endl;
				delete tail;
				tail = prv;
			}
		}
	}

	node* find_data(int val) {
		node* p = head;
		while (p != NULL) {
			if (p->data == val) return p;
			p = p->next;
		}

		return NULL;
	}

	void prt_data() {
		node* p = head;
		while (p != NULL) {
			cout << p->data << " ";
			p = p->next;
		}
		cout << endl;
	}
};

void ll_ex() {
	int n;
	cout << "�ʱ갪: ";
	cin >> n;
	
	auto p = new linked_list(n);

	while (true) {
		int sel;
		cout << "(1)Input   (2)del    (3)���� >> ";
		cin >> sel;

		int n;
		if (sel == 1) {
			cout << "Input: ";
			cin >> n;

			p->add_data(n);
		}
		else if (sel == 2) {
			cout << "Delete: ";
			cin >> n;
			if (p->find_data(n)) {
				p->del_data(n);
				cout << n << " ����!" << endl;
			}
			else cout << n << " ã�� �� ����!" << endl;
		}
		else if (sel == 3) break;
		else cout << "\a��ȿ���� ���� �Է°�!" << endl;
		
		cout << "\n\n���� ����Ʈ ���" << endl;
		p->prt_data();
		cout << "\n\n" << endl;
	}
}