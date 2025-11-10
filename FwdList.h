#pragma once
#include <iostream>
using std::cout;
using std::endl;
using std::cin;

template <typename T>
struct Node
{
	T data;
	Node* next;
	Node(const T& data = T(), Node* next = nullptr)
		:data{ data }, next{ next }
	{}
};

template <typename T>
class FwdList
{
private:
	Node<T>* head = nullptr;
	Node<T>* tail= nullptr;
	size_t size = 0;
public:
	FwdList() = default;
	void addHead(const T& data);
	void print() const;
	bool isEmpty() const;
	void removeHead();
	void removeTail();
	void AddToTail(const T& data);
	void DeleteAll();
};

template<typename T>
inline void FwdList<T>::addHead(const T& data)
{
	Node<T>* tmp = new Node<T>(data, head);
	if (isEmpty())
		tail = tmp;
	head = tmp;
	size++;
}

template<typename T>
inline void FwdList<T>::print() const
{
	if (isEmpty()) {
		cout << "List is Empty" << endl;
		return;
	}
	auto tmp = head;
	cout << "List :: \t";
	while (tmp != nullptr)
	{
		cout << tmp->data << "\t";
		tmp = tmp->next;
	}
	cout << endl;
}

template<typename T>
inline bool FwdList<T>::isEmpty() const
{
	return head == nullptr;
}

template<typename T>
inline void FwdList<T>::removeHead()
{
	if (isEmpty()) {
		cout << "List id Empty" << endl;
		return;
	}
	auto tmp = head;
	head = head->next;
	if (isEmpty())
		tail = nullptr;
	--size;
	delete tmp;
}

template<typename T>
inline void FwdList<T>::removeTail()
{
	if (isEmpty()) {
		cout << "List is Empty" << endl;
		return;
	}
	auto tmp = head;
	while (tmp->next != tail)
	{
		tmp = tmp->next;
	}
	delete tail;
	tail = tmp;
	tail->next = nullptr;
	--size;
}

template<typename T>
inline void FwdList<T>::AddToTail(const T& data)
{
	Node<T>* tmp = new Node<T>(data, nullptr);
	tail->next = tmp;
	if (isEmpty())
		head = tmp;
	tail = tmp;
	size++;

}

template<typename T>
inline void FwdList<T>::DeleteAll()
{
	auto tmp = head;
	while (tmp != nullptr)
	{
		head = head->next;
		--size;
		auto tmp1 = tmp;
		tmp = tmp->next;
		delete tmp1;
	}
}
