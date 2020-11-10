#include <iostream>

#include <thread> //std::thread
#include <mutex> //std::mutex
#include <atomic> //std::atomic

std::atomic<int> increments = 0;

void incrementValue()
{
	for (int i = 0; i < 100000; ++i)
	{
		increments.fetch_add(1, std::memory_order_seq_cst);
	}
}

int main()
{
	std::thread funThreads[100];

	for (size_t i = 0; i < 100; ++i)
	{
		funThreads[i] = std::thread(incrementValue);
	}

	for (size_t i = 0; i < 100; ++i)
	{
		funThreads[i].join();
	}

	std::cout << increments << std::endl;

	return 0;
}