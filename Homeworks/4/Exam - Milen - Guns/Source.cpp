#include <cmath>
#include <string>
#include <vector>
#include <iterator>
#include <sstream>
#include <list>
#include <iostream>
#include <algorithm>
using namespace std;

class Node {
public:
	Node(int data) : data(data){}

	int data;

	Node* next;
	Node* prev;
};

class List {
public:
	List() : head(nullptr), tail(nullptr), mid(nullptr), size(0) {}

	Node* head;
	Node* mid;
	Node* tail;

	int size;

	void add(int data) {
		Node* node = new Node(data);

		if (!this->size)
		{
			this->head = this->tail = node;
			this->mid = nullptr;
			this->size++;
		}
		else
		{
			this->size++;
			this->tail->next = node;
			node->prev = this->tail;
			this->tail = node;
			if (this->mid == nullptr ) {
				this->mid = this->head;
			}
			else if (size % 2 == 0)
			{
				this->mid = this->mid->next;
			}
		}
	}

	void hide() {
		Node* to_be_removed;

		if (tail == nullptr)
		{
			return;
		}
		if (head == tail)
		{
			to_be_removed = head;
			head->next = head->prev = nullptr;
			this->mid = nullptr;

			free(to_be_removed);
		}
		else
		{
			to_be_removed = tail;
			tail = tail->prev;
			tail->next = nullptr;

			if (size % 2 == 0)
			{
				this->mid = this->mid->prev;
			}

			free(to_be_removed);
		}
		this->size--;
	}

	void shuffle() {

		Node* prev_tail = tail;


		if (this->mid == nullptr)
		{
			return;
		}		
		
		this->head->prev = this->tail;
		this->tail->next = this->head;

		this->head = this->mid->next;


		this->head->prev = nullptr;
		this->tail = mid;
		this->tail->next = nullptr;

		if (this->size %2 == 0)
		{
			this->mid = prev_tail;
		}
		else
		{
			this->mid = prev_tail->prev;
		}
	}
	

	void print(Node* node) {
		Node* curr = node;
		while (curr != nullptr) {
			if (this->size == 0)
			{
				return;
			}
			else
			{
			printf("%d ", curr->data);
			curr = curr->next;
			}
		}
	}
};

int main() {
	long long N;
	cin >> N;
	cin.ignore();

	List guns;

	string command;

	for (int i = 0; i < N; i++)
	{
		getline(cin, command);

		if (command == "milen")
		{
			guns.shuffle();
		}
		else if (command == "gun") {
			guns.hide();
		}
		else
		{
			istringstream it(command);
			vector<string> splitted{ istream_iterator<string>{it}, istream_iterator<string>{} };

			if (splitted[0] == "add" && splitted.size() == 2)
			{
				guns.add(stoi(splitted[1]));
			}
		}
	}	 
	printf("%d\n", guns.size);

	guns.print(guns.head);

	return 0;
}

