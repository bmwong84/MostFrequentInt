//given an array of ints, find the most frequent int in the array
#include <iostream>
#include <unordered_map>
#include <stdlib.h>
#include <time.h>
#include <vector>


 std::vector<int> createArray(int size)
{
	std::vector <int> temparr;
	int min, max;
	std::cout << "enter minimum of range: " << std::endl;
	std::cin >> min;
	std::cout << "enter maximum of range: " << std::endl;
	std::cin >> max;
	for (int i = 0; i < size; i++)
	{
		temparr.push_back(rand() % max + min);
	}
	return temparr;
}

int main()
{
	srand(time(NULL));
	std::unordered_map<int, int> counter;
	std::vector <int> arr;
	char cont = 'y';
	do {
		std::cout << "given a random array of ints in a user defined range, find the most frequent int in the array" << std::endl;
		std::cout << "enter array size" << std::endl;
		int temp;
		std::cin >> temp;
		counter.clear();
		arr = createArray(temp);
		//for each element in the array, try to find its index in the map
		//if index not present, add it, if index present, increment the count
		for (int i = 0; i < arr.size(); i++)
		{
			std::unordered_map<int, int>::iterator it = counter.find(arr[i]);
			if (it == counter.end())
			{
				counter.emplace(arr[i], 1);
			}
			else
			{
				it->second++;
			}
		}
		std::cout << "the array is as follows: " << std::endl;
		for (int i = 0; i < arr.size(); i++)
		{
			std::cout << arr[i] << "  ";
		}
		std::cout << std::endl;
		//iterates the map, finds the most frequent
		int maxVal = 0;
		std::vector<int> maxIndices;
		for (auto it = counter.cbegin(); it != counter.cend(); it++)
		{
			if (it->second == maxVal)
			{
				maxIndices.push_back(it->first);
			}
			else if (it->second > maxVal)
			{
				maxIndices.clear();
				maxVal = it->second;
				maxIndices.push_back(it->first);
			}
		}
		std::cout << "the most frequent ints in the array was/were: " << std::endl;
		for (int i = 0; i < maxIndices.size(); i++)
		{
			std::cout << maxIndices[i] << "  ";
		}
		std::cout << "with a frequency of " << maxVal << std::endl;
		std::cout << "run another?" << std::endl;
		std::cin >> cont;
	} while (cont == 'y' || cont == 'Y');

}
//alternatively, can not use map, just use second vector/array keeping track of how many times each number in the range of the array appears, second array will be of size of range.

