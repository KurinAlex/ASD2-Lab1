#include <ctime>

#include "Meme.h"
#include "DynamicArray.h"
#include "LinkedList.h"

const int push_back_iterations_number = 50000;
const int push_front_iterations_number = 10000;
const int get_iterations_number = 20000;
const int pop_front_iterations_number = 5000;
const int pop_back_iterations_number = 5000;

double GetTime(clock_t start, clock_t end)
{
	return (double)(end - start) / CLOCKS_PER_SEC;
}

int main()
{
	srand(time(0));

	DynamicArray<Meme> dynamic_array;
	LinkedList<Meme> linked_list;
	clock_t start;
	clock_t end;
	clock_t function_start;
	clock_t function_end;
	size_t size;

	std::cout << "DynamicArray:\n";
	start = clock();

	function_start = clock();
	for (int i = 0; i < push_back_iterations_number; i++)
	{
		dynamic_array.push_back(generate_meme());
	}
	function_end = clock();
	std::cout << "- push_back: " << GetTime(function_start, function_end) << " sec\n";

	function_start = clock();
	for (int i = 0; i < push_front_iterations_number; i++)
	{
		dynamic_array.push_front(generate_meme());
	}
	function_end = clock();
	std::cout << "- push_front: " << GetTime(function_start, function_end) << " sec\n";

	function_start = clock();
	size = dynamic_array.size();
	for (int i = 0; i < get_iterations_number; i++)
	{
		dynamic_array.get(rand() % size);
	}
	function_end = clock();
	std::cout << "- get: " << GetTime(function_start, function_end) << " sec\n";

	function_start = clock();
	for (int i = 0; i < pop_front_iterations_number; i++)
	{
		dynamic_array.pop_front();
	}
	function_end = clock();
	std::cout << "- pop_front: " << GetTime(function_start, function_end) << " sec\n";

	function_start = clock();
	for (int i = 0; i < pop_back_iterations_number; i++)
	{
		dynamic_array.pop_back();
	}
	function_end = clock();
	std::cout << "- pop_back: " << GetTime(function_start, function_end) << " sec\n";

	end = clock();
	std::cout << "All operations: " << GetTime(start, end) << " sec\n\n";

	std::cout << "LinkedList:\n";
	start = clock();

	function_start = clock();
	for (int i = 0; i < push_back_iterations_number; i++)
	{
		linked_list.push_back(generate_meme());
	}
	function_end = clock();
	std::cout << "- push_back: " << GetTime(function_start, function_end) << " sec\n";

	function_start = clock();
	for (int i = 0; i < push_front_iterations_number; i++)
	{
		linked_list.push_front(generate_meme());
	}
	function_end = clock();
	std::cout << "- push_front: " << GetTime(function_start, function_end) << " sec\n";

	function_start = clock();
	size = linked_list.size();
	for (int i = 0; i < get_iterations_number; i++)
	{
		linked_list.get(rand() % size);
	}
	function_end = clock();
	std::cout << "- get: " << GetTime(function_start, function_end) << " sec\n";

	function_start = clock();
	for (int i = 0; i < pop_front_iterations_number; i++)
	{
		linked_list.pop_front();
	}
	function_end = clock();
	std::cout << "- pop_front: " << GetTime(function_start, function_end) << " sec\n";

	function_start = clock();
	for (int i = 0; i < pop_back_iterations_number; i++)
	{
		linked_list.pop_back();
	}
	function_end = clock();
	std::cout << "- pop_back: " << GetTime(function_start, function_end) << " sec\n";

	end = clock();
	std::cout << "All operations: " << GetTime(start, end) << " sec\n\n";
}