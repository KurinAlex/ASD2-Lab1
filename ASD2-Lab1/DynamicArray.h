#pragma once

#include <iostream>

template<class T>
class DynamicArray
{
public:
	DynamicArray()
	{
		m_size = 0;
		m_capasity = 4;
		m_array = new T[m_capasity];
	}

	~DynamicArray()
	{
		delete[] m_array;
	}

	void push_back(T el)
	{
		if (m_size == m_capasity)
		{
			reserve(0);
		}
		m_array[m_size++] = el;
	}

	void push_front(T el)
	{
		if (m_size == m_capasity)
		{
			reserve(1);
		}
		m_array[0] = el;
		m_size++;
	}

	T pop_back()
	{
		if (m_size == 0)
		{
			throw std::exception("Warning: array is empty - can't pop an element");
		}
		return m_array[--m_size];
	}

	T pop_front()
	{
		if (m_size == 0)
		{
			throw std::exception("Warning: array is empty - can't pop an element");
		}
		T to_remove = m_array[0];
		m_size--;
		for (size_t i = 0; i < m_size; i++)
		{
			m_array[i] = m_array[i + 1];
		}
		return to_remove;
	}

	T get(int pos)
	{
		if (pos < 0 || pos >= m_size)
		{
			throw std::exception("Warning: pos is outside of array boundaries");
		}
		return m_array[pos];
	}

	size_t size()
	{
		return m_size;
	}

	void print(void (*print_element)(T el))
	{
		if (m_size == 0)
		{
			std::cout << "Array is empty\n";
			return;
		}

		std::cout << "Array of size " << m_size << ":\n\n";
		for (size_t i = 0; i < m_size; i++)
		{
			print_element(m_array[i]);
			std::cout << '\n';
		}
	}

private:
	size_t m_size;
	size_t m_capasity;
	T* m_array;

	void reserve(size_t start_pos)
	{
		m_capasity *= 2;
		T* tmp_array = new T[m_capasity];
		for (size_t i = 0; i < m_size; i++)
		{
			tmp_array[i + start_pos] = m_array[i];
		}
		m_array = tmp_array;
	}
};