#include <iostream>

template<class T>

class Node
{
public:
	Node *next;
	T data;
	Node(T data = T(), Node *next = nullptr)
	{
		this->data = data;
		this->next = next;
	}
};

template<class T>
class List {
private:
	Node<T>* head;
	Node<T>* last;
public:

	class iterator {
	public:
		Node<T>* current;
		iterator() { current = head; }
		iterator(Node<T>* n) { current = n; }
		iterator(const iterator& iter) { current = iter.current; }
		Node<T>*& operator*() { return current; }
		Node<T>*& operator->() { return current; }
		iterator operator++() {
			if (current != nullptr)
				current = current->next;
			return *this;
		}
		bool operator==(const iterator& iter) {
			return iter.current == current;
		}
		bool operator!=(const iterator& iter) {
			return iter.current != current;
		}
	};

	List() {
		head = nullptr;
		last = nullptr;
	}

	~List() { Clear(); }

	List(const List& lst) {
		head = nullptr;
		last = nullptr;
		Node<T>* current = head;
		for (iterator iter = list.begin(); iter != list.end(); ++iter)
			push_back(iter.current->data);
	}

	T GetFirst() { return head->data; }

	T GetLast() { return last->data; }

	void Clear() {
		iterator it = begin();
		while (it != end()) {
			iterator tmp(it->next);
			delete* it;
			it = tmp;
		}
		head = nullptr;
	}

	void push_front(T d) {
		Node<T>* n = new Node<T>;
		n->data = d;
		n->next = head;
		head = n;
		if (last == nullptr) last = head;
	}

	void push_back(T d) {
		if (last == nullptr) push_front(d);
		else {
			Node<T>* n = new Node<T>;
			n->data = d;
			n->next = nullptr;
			last->next = n;
			last = n;
		}
	}

	void pop_front() {
		Node<T>* tmp = head;
		head = tmp->next;
		delete tmp;
		if (head == nullptr) last = nullptr;
	}

	void pop_back() {
		if (head != last) {
			Node<T>* current = head;
			while (current->next != last)
				current = current->next;
			std::swap(current, last);
			delete current;
			last->next = nullptr;
		}
		else pop_front();
	}

	void PrintList() {
		for (iterator iter = begin(); iter != end(); ++iter) {
			std::cout << iter.current->data << ' ';
		}
	}

	bool IsEmpty() {
		return head == nullptr;
	}

	iterator begin() const {
		iterator iter(head);
		return iter;
	}
	iterator end() const {
		iterator iter(nullptr);
		return iter;
	}

	void DeleteNextElem(iterator iter) {
		if (iter != end()) {
			iterator tmp(iter);
			++tmp;
			iter.current->next = tmp->next;
			delete tmp.current;
		}
	}

	void Insert(iterator iter, T d) {
		if (iter == end()) push_back(d);
		else {
			Node<T>* n = new Node<T>;
			n->data = d;
			n->next = (*iter)->next;
			(*iter)->next = n;
			if (n->next == nullptr) last = n;
		}
	}

	void Return(iterator iter) {
		if (iter != end()) {
			iterator tmp(iter);
			++tmp;
			iter.current->next = tmp->next;
			std::cout << tmp.current->data << " ";
		}
	}
};