#pragma once

#include <iostream>
#include "Node.h"

template<class T>
class LinkedList
{
public:
	LinkedList()
	{
		m_size = 0;
		m_head = NULL;
		m_tail = NULL;
	}

	~LinkedList()
	{
		while (m_head)
		{
			Node<T>* current = m_head;
			m_head = m_head->next;
			delete current;
		}
	}

	void push_front(T el)
	{
		Node<T>* tmp = new Node<T>;
		tmp->val = el;
		tmp->next = NULL;

		if (m_size++ == 0)
		{
			m_head = tmp;
			m_tail = tmp;
			return;
		}
		tmp->next = m_head;
		m_head = tmp;
	}

	void push_back(T el)
	{
		Node<T>* tmp = new Node<T>;
		tmp->val = el;
		tmp->next = NULL;

		if (m_size++ == 0)
		{
			m_head = tmp;
			m_tail = tmp;
			return;
		}
		m_tail->next = tmp;
		m_tail = m_tail->next;
	}

	T get(size_t pos)
	{
		if (pos < 0 || pos >= m_size)
		{
			throw std::exception("Warning: pos is outside of list boundaries");
		}
		Node<T>* tmp = m_head;
		for (size_t i = 0; i < pos; i++)
		{
			tmp = tmp->next;
		}
		return tmp->val;
	}

	T pop_front()
	{
		if (m_size == 0)
		{
			throw std::exception("Warning: list is empty - can't pop an element");
		}
		T to_remove = m_head->val;
		if (m_size-- == 1)
		{
			m_head = NULL;
			m_tail = NULL;
		}
		else
		{
			m_head = m_head->next;
		}
		return to_remove;
	}

	T pop_back()
	{
		if (m_size == 0)
		{
			throw std::exception("Warning: list is empty - can't pop an element");
		}
		T to_remove = m_tail->val;
		if (m_size-- == 1)
		{
			m_head = NULL;
			m_tail = NULL;
		}
		else
		{
			Node<T>* tmp = m_head;
			while (tmp->next != m_tail)
			{
				tmp = tmp->next;
			}
			tmp->next = NULL;
			m_tail = tmp;
		}
		return to_remove;
	}

	size_t size()
	{
		return m_size;
	}

	void print(void (*print_element)(T el))
	{
		if (m_size == 0)
		{
			std::cout << "List is empty\n";
			return;
		}

		std::cout << "List of size " << m_size << ":\n\n";
		Node<T>* tmp = m_head;
		while (tmp)
		{
			print_element(tmp->val);
			std::cout << '\n';
			tmp = tmp->next;
		}
	}

private:
	size_t m_size;
	Node<T>* m_head;
	Node<T>* m_tail;
};