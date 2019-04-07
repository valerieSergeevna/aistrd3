#include "List.h"
//#include <iostream>
#include <stdexcept>


using namespace std;

template<typename T>
List<T>::List()
{
	head = nullptr;
	tail = nullptr;
	size = 0;
}

template<typename T>
List<T>::~List()
{

	clear();
}

template<typename T>
size_t List<T>::get_size() const
{
	return size;
}
template<typename T>
void List<T>::push_back(T newElem, size_t freq)
{
	if (size == 0) {
		head = new Node(newElem, freq);
		tail = head;
	}
	else {

		tail->next = new Node(newElem, freq);
		tail->next->prev = tail;
		//tail = tail->next;
	}
	size++;

}
template<typename T>
void List<T>::push_front(T newElem, size_t freq)
{
	if (size == 0)
		add_first(newElem, freq);
	else
	{
		/*auto cur = new Node(newElem, head);
		head = cur;*/
		head->prev = new Node(newElem, freq, head);
		head = head->prev;
		
	}

	size++;
}
template<typename T>
void List<T>::pop_back()
{

	if (size == 0) return;

	if (size == 1) {
		head = nullptr;
		tail = nullptr;
		delete head;
		delete tail;

	}
	else {
		Node * cur = head;
		do
		{
			cur = cur->next;
		} while (cur->next != tail);
		cur->next = nullptr;
		cur->next->prev = nullptr;
		delete tail;
		tail = cur;

	}
	size--;

}
template<typename T>
void List<T>::pop_front()
{
	if (size == 0) return;
	if (size == 1)
	{
		head = nullptr;
		tail = nullptr;
		size = 0;
		return;
	}
	else
	{
		Node *cur = head->next;
		head->next = nullptr;
		cur->prev = nullptr;
		delete head;
		head = cur;
	}
	size--;
}
template<typename T>
T List<T>::at(size_t index) const
{
	if (index >= size) {
		throw out_of_range("Index is greater than list size");
	}
	else {
		size_t count = 0;
		Node * cur = head;
		while (count != index) {
			cur = cur->next;
			count++;
		}
		cout << cur->data;
		return cur->data;
	}
}
template<typename T>
bool List<T>::isEmpty()
{
	if (size == 0)
		return true;
	return false;
}

template<typename T>
void List<T>::set(size_t index, T newElem)
{

	if (index >= size) {
		return;
	}
	else {
		size_t count = 0;
		Node * cur = head;
		while (count != index) {
			cur = cur->next;
			count++;
		}
		cur->data = newElem;

	}
}

template<typename T>
void List<T>::clear()
{
	Node * cur = head;
	while (cur != nullptr)
	{
		Node * next = cur->next;
		delete cur;
		cur = next;
	}
	head = tail = nullptr;
	size = 0;

}



template<typename T>
void List<T>::Delete(size_t index)
{
	if (size == 0 || index > size) throw out_of_range("List is empty");

	Node * cur = head;
	if (index == 0)
	{
		pop_front();
		return;
	}
	size_t i = index;
	while (i != index - 1)
	{
		cur = cur->next;
		i--;
	}
	if (cur->prev != nullptr)
		cur->prev->next = cur->next;
	if (cur->next->next != nullptr)
	{
		cur->next = cur->next->next;
		delete cur;
	}
	else
	{
		cur->next = nullptr;
		delete cur->next;
	}

	if (size == 1)
		head = tail = nullptr;

	size--;
}

template<typename T>
void List<T>::insert(T newElem,size_t freq, size_t index)
{
	if (index >= size) {
		throw out_of_range("Index is greater than list size");
	}
	else {

		size_t count = 0;
		Node * cur = head;
		if (index == 0)
		{
			push_front(newElem, freq);
		}
		else
		{
			while (count != index - 1) {
				cur = cur->next;
				count++;
			}

			Node *El = new Node(newElem, freq, cur->next);
			cur->next->prev = El;
			cur->next = El;

		}
		size++;
	}
}



//template<typename T>
//List<T>::Node* List<T>::get_back()
//{
//	return tail;
//}
//
//template<typename T>
//List<T>::Node* List<T>::get_front()
//{
//	return head;
//}

template<typename T>
void List<T>::add_first(T newElem, size_t freq)
{
	head = new Node(newElem, freq);
	tail = head;
}

template<typename T>
void List<T>::sorting(Node* left, Node* right)
{
	if (left == right ) return;
	Node *start = left;
	Node *cur = left->next;
	size_t frequancy;
	T inf;
	while (1)
	{
		if (start->freq < cur->freq)
		{
			frequancy = cur->freq;
			inf = cur->data;
			cur->data = start->data;
			cur->freq = start->freq;
			start->freq = frequancy;
			start->data = inf;
		}
		if (cur == right) break;
		cur = cur->next;
	}
	frequancy = left->freq;
	inf = left->data;
	left->data = cur->data;
	left->freq = cur->freq;
	cur->data = inf;
	cur->freq = frequancy;
	Node *old_cur = cur;
	//рекурсия
	cur = cur->prev;
	if (cur != nullptr)
	{
		if ((left->prev != cur) && (cur->next != left))
			sorting(left, cur);
	}
	cur = old_cur;
	cur = cur->next;
	if (cur != nullptr)
	{
		if ((cur->prev != right) && (right->next != cur))
			sorting(cur, right);

	}
}
