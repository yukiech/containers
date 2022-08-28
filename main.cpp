#include <iostream>
#include <string>
#include <deque>
#include <map>
#include <vector>
#include "map.hpp"
#include "vector.hpp"
#include <stdlib.h>
#include "colors.hpp"
#include <chrono>
using namespace std::chrono;

void	ft_banner();
void	ft_vector();
void	ft_map();

int main(int argc, char** argv)
{
	ft_banner();
	ft_vector();
	ft_map();
}

void	ft_vector()
{
	ft::vector<std::string>		ft_vector_string;
	std::vector<std::string>	std_vector_string;
	ft::vector<int>		ft_vector_int;
	std::vector<int>	std_vector_int;

	// Tests Vector

	std::cout << UNDL(BOLD(FBLU("\n\nVector"))) << std::endl << std::endl;

	// Test push_back

	auto ft_push_back = high_resolution_clock::now();
	for (int i = 0; i < 1000; i++)
	{
		ft_vector_int.push_back(i);
	}
	auto ft_push_back2 = high_resolution_clock::now();
	auto ft_push_back_diff = duration_cast<microseconds>(ft_push_back2 - ft_push_back);

	auto std_push_back = high_resolution_clock::now();
	for (int i = 0; i < 1000; i++)
	{
		std_vector_int.push_back(i);
	}
	auto std_push_back2 = high_resolution_clock::now();
	auto  std_push_back_diff = duration_cast<microseconds>(std_push_back2 - std_push_back);
	
	int i = 0;
	int result = 0;
	while (i < 1000)
	{
		if (ft_vector_int[i] != std_vector_int[i])
			result = 1;
		i++;
	}
	
	std::cout << "push_back = ";
	if (result == 1)
		std::cout << FRED("KO");
	else
		std::cout << FGRN("OK");
	std::cout << " | Duration : FT = " << ft_push_back_diff.count() << " | STD = " << std_push_back_diff.count() << " | Diff = " << float(ft_push_back_diff.count()) / float(std_push_back_diff.count()) << " | ";
	if (ft_push_back_diff.count() / std_push_back_diff.count() <= 20)
		std::cout << FGRN("OK\n");
	else
		std::cout << FRED("KO\n");
	
	// Test operators
	
	int operator_result = 0;
	if ((ft_vector_int[0] == ft_vector_int[1]) != (std_vector_int[0] == std_vector_int[1]))
		operator_result = 1;
	if ((ft_vector_int[0] != ft_vector_int[1]) != (std_vector_int[0] != std_vector_int[1]))
		operator_result = 1;
	if ((ft_vector_int[0] < ft_vector_int[1]) != (std_vector_int[0] < std_vector_int[1]))
		operator_result = 1;
	if ((ft_vector_int[0] <= ft_vector_int[1]) != (std_vector_int[0] <= std_vector_int[1]))
		operator_result = 1;
	if ((ft_vector_int[0] > ft_vector_int[1]) != (std_vector_int[0] > std_vector_int[1]))
		operator_result = 1;
	if ((ft_vector_int[0] >= ft_vector_int[1]) != (std_vector_int[0] >= std_vector_int[1]))
		operator_result = 1;

	std::cout << "operators = ";
	if (operator_result == 0)
		std::cout << FGRN("OK");
	else
		std::cout << FRED("KO");
	std::cout << " | == : ";
	if ((ft_vector_int[0] == ft_vector_int[1]) != (std_vector_int[0] == std_vector_int[1]))
		std::cout << FRED("KO");
	else
		std::cout << FGRN("OK");
	std::cout << " | != : ";
	if ((ft_vector_int[0] != ft_vector_int[1]) != (std_vector_int[0] != std_vector_int[1]))
		std::cout << FRED("KO");
	else
		std::cout << FGRN("OK");
	std::cout << " | < : ";
	if ((ft_vector_int[0] < ft_vector_int[1]) != (std_vector_int[0] < std_vector_int[1]))
		std::cout << FRED("KO");
	else
		std::cout << FGRN("OK");
	std::cout << " | <= : ";
	if ((ft_vector_int[0] <= ft_vector_int[1]) != (std_vector_int[0] <= std_vector_int[1]))
		std::cout << FRED("KO");
	else
		std::cout << FGRN("OK");
	std::cout << " | > : ";
	if ((ft_vector_int[0] > ft_vector_int[1]) != (std_vector_int[0] > std_vector_int[1]))
		std::cout << FRED("KO");
	else
		std::cout << FGRN("OK");
	std::cout << " | >= : ";
	if ((ft_vector_int[0] >= ft_vector_int[1]) != (std_vector_int[0] >= std_vector_int[1]))
		std::cout << FRED("KO\n");
	else
		std::cout << FGRN("OK\n");

	// Test erase()
	auto ft_erase = high_resolution_clock::now();
	for (int i = 0; i != 100; i++)
	{
		ft_vector_int.erase(ft_vector_int.begin());
	}
	auto ft_erase2 = high_resolution_clock::now();
	auto ft_erase_diff = duration_cast<microseconds>(ft_erase2 - ft_erase);
	
	auto std_erase = high_resolution_clock::now();
	for (int i = 0; i != 100; i++)
	{
		std_vector_int.erase(std_vector_int.begin());
	}
	auto std_erase2 = high_resolution_clock::now();
	auto std_erase_diff = duration_cast<microseconds>(std_erase2 - std_erase);
	
	std::cout << "erase     = ";
	int	erase_result = 0;
	int	erase_i = 0;
	while (erase_i < 1000)
	{
		if (ft_vector_int[erase_i] != std_vector_int[erase_i])
			erase_result = 1;
		erase_i++;
	}
	if (ft_vector_int.size() != std_vector_int.size() || erase_result != 0)
		std::cout << FRED("KO");
	else
		std::cout << FGRN("OK");
	std::cout << " | Duration : FT = " << ft_erase_diff.count() << " | STD = " << std_erase_diff.count() << " | Diff = " << float(ft_erase_diff.count()) / float(std_erase_diff.count()) << " | ";
	
	if (std_erase_diff.count() == 0 && ft_erase_diff.count() <= 20)
                std::cout << FGRN("OK\n");
	else if (ft_erase_diff.count() / std_erase_diff.count() <= 20)
                std::cout << FGRN("OK\n");
        else
                std::cout << FRED("KO\n");
	
	// Test insert()
	auto ft_insert = high_resolution_clock::now();
	for (int i = 0; i != 500; i++)
	{
		ft_vector_int.insert(ft_vector_int.begin(), 42);
	}
	auto ft_insert2 = high_resolution_clock::now();
	auto ft_insert_diff = duration_cast<microseconds>(ft_insert2 - ft_insert);
	
	auto std_insert = high_resolution_clock::now();
	for (int i = 0; i != 500; i++)
	{
		std_vector_int.insert(std_vector_int.begin(), 42);
	}
	auto std_insert2 = high_resolution_clock::now();
	auto std_insert_diff = duration_cast<microseconds>(std_insert2 - std_insert);
	
	std::cout << "insert    = ";
	int	insert_result = 0;
	int	insert_i = 0;
	while (insert_i < 1500)
	{
		if (ft_vector_int[insert_i] != std_vector_int[insert_i])
			insert_result = 1;
		insert_i++;
	}
	if (ft_vector_int.size() != std_vector_int.size())
		std::cout << FRED("KO");
	else
		std::cout << FGRN("OK");
	std::cout << " | Duration : FT = " << ft_insert_diff.count() << " | STD = " << std_insert_diff.count() << " | Diff = " << float(ft_insert_diff.count()) / float(std_insert_diff.count()) << " | ";
	
	if (std_insert_diff.count() == 0 && ft_insert_diff.count() <= 20)
                std::cout << FGRN("OK\n");
	else if (ft_insert_diff.count() / std_insert_diff.count() <= 20)
                std::cout << FGRN("OK\n");
        else
                std::cout << FRED("KO\n");
	

	// Test resize()
	auto ft_resize = high_resolution_clock::now();
	ft_vector_int.resize(2000);
	auto ft_resize2 = high_resolution_clock::now();
	auto ft_resize_diff = duration_cast<microseconds>(ft_resize2 - ft_resize);
	
	auto std_resize = high_resolution_clock::now();
	std_vector_int.resize(2000);
	auto std_resize2 = high_resolution_clock::now();
	auto std_resize_diff = duration_cast<microseconds>(std_resize2 - std_resize);
	
	std::cout << "resize    = ";
	if (ft_vector_int.size() != std_vector_int.size())
		std::cout << FRED("KO");
	else
		std::cout << FGRN("OK");
	std::cout << " | Duration : FT = " << ft_resize_diff.count() << " | STD = " << std_resize_diff.count() << " | Diff = " << float(ft_resize_diff.count()) / float(std_resize_diff.count()) << " | ";
	
	if (std_resize_diff.count() == 0 && ft_resize_diff.count() <= 20)
                std::cout << FGRN("OK\n");
	else if (ft_resize_diff.count() / std_resize_diff.count() <= 20)
                std::cout << FGRN("OK\n");
        else
                std::cout << FRED("KO\n");
	
	
	
	// Test pop_back()
	auto ft_pop_back = high_resolution_clock::now();
	int pop_back = 0;
	while (pop_back < 1000)
	{
		ft_vector_int.pop_back();
		pop_back++;
	}
	auto ft_pop_back2 = high_resolution_clock::now();
	auto ft_pop_back_diff = duration_cast<microseconds>(ft_pop_back2 - ft_pop_back);
	
	auto std_pop_back = high_resolution_clock::now();
	pop_back = 0;
	while (pop_back < 1000)
	{
		std_vector_int.pop_back();
		pop_back++;
	}
	auto std_pop_back2 = high_resolution_clock::now();
	auto std_pop_back_diff = duration_cast<microseconds>(std_pop_back2 - std_pop_back);
	
	std::cout << "pop_back  = ";
	if (ft_vector_int.size() != std_vector_int.size())
		std::cout << FRED("KO");
	else
		std::cout << FGRN("OK");
	std::cout << " | Duration : FT = " << ft_pop_back_diff.count() << " | STD = " << std_pop_back_diff.count() << " | Diff = " << float(ft_pop_back_diff.count()) / float(std_pop_back_diff.count()) << " | ";
	
	if (std_pop_back_diff.count() == 0 && ft_pop_back_diff.count() <= 20)
                std::cout << FGRN("OK\n");
	else if (ft_pop_back_diff.count() / std_pop_back_diff.count() <= 20)
                std::cout << FGRN("OK\n");
        else
                std::cout << FRED("KO\n");
	
	// Test swap()
	ft::vector<int>		ft_vector_swap(ft_vector_int);
	std::vector<int>	std_vector_swap(std_vector_int);

	ft_vector_swap.resize(500);
	std_vector_swap.resize(500);	
	ft_vector_swap.insert(ft_vector_swap.begin(), 666);
	std_vector_swap.insert(std_vector_swap.begin(), 666);
	
	auto ft_swap = high_resolution_clock::now();
	ft_vector_int.swap(ft_vector_swap);
	auto ft_swap2 = high_resolution_clock::now();
	auto ft_swap_diff = duration_cast<microseconds>(ft_swap2 - ft_swap);
	
	auto std_swap = high_resolution_clock::now();
	std_vector_int.swap(std_vector_swap);
	auto std_swap2 = high_resolution_clock::now();
	auto std_swap_diff = duration_cast<microseconds>(std_swap2 - std_swap);
	
	int swap_i = 0;
	int swap_result = 0;
	while (swap_i < 666)
	{
		if (ft_vector_int[swap_i] != std_vector_int[swap_i])
			swap_result = 1;
		swap_i++;
	}
	std::cout << "swap      = ";
	if (swap_result != 0)
                std::cout << FRED("KO");
        else
		std::cout << FGRN("OK");
	std::cout << " | Duration : FT = " << ft_swap_diff.count() << " | STD = " << std_swap_diff.count() << " | Diff = " << float(ft_swap_diff.count()) / float(std_swap_diff.count()) << " | ";
	if (std_swap_diff.count() == 0 && ft_swap_diff.count() <= 20)
                std::cout << FGRN("OK\n");
	else if (ft_swap_diff.count() / std_swap_diff.count() <= 20)
                std::cout << FGRN("OK\n");
        else
                std::cout << FRED("KO\n");
		
	ft_vector_int.swap(ft_vector_swap);
	std_vector_int.swap(std_vector_swap);

	// Test capacity
	int capacity_result = 0;
	if (ft_vector_int.empty() != std_vector_int.empty())
		capacity_result = 1;
	if (ft_vector_int.size() != std_vector_int.size())
		capacity_result = 1;
	if (ft_vector_int.max_size() != std_vector_int.max_size())
		capacity_result = 1;
	if (ft_vector_int.capacity() != std_vector_int.capacity())
		capacity_result = 1;

	std::cout << "capacity  = ";
	if (capacity_result == 0)
		std::cout << FGRN("OK");
	else
		std::cout << FRED("KO");
	std::cout << " | empty = ";
	if (ft_vector_int.empty() == std_vector_int.empty())
		std::cout << FGRN("OK");
	else
		std::cout << FRED("KO");
	std::cout << " | size = ";
	if (ft_vector_int.size() == std_vector_int.size())
		std::cout << FGRN("OK");
	else
		std::cout << FRED("KO");
	std::cout << " | max_size = ";
	if (ft_vector_int.max_size() == std_vector_int.max_size())
		std::cout << FGRN("OK");
	else
		std::cout << FRED("KO");
	std::cout << " | capacity = ";
	if (ft_vector_int.capacity() == std_vector_int.capacity())
		std::cout << FGRN("OK");
	else
		std::cout << FRED("KO");
	std::cout << " | reserve = ";
	ft_vector_int.reserve(ft_vector_int.capacity() + 1);
	std_vector_int.reserve(std_vector_int.capacity() + 1);
	if (ft_vector_int.size() == std_vector_int.size())
		std::cout << FGRN("OK\n");
	else
		std::cout << FRED("KO\n");

	// Test clear()
	auto ft_clear = high_resolution_clock::now();
	ft_vector_int.clear();
	auto ft_clear2 = high_resolution_clock::now();
	auto ft_clear_diff = duration_cast<microseconds>(ft_clear2 - ft_clear);
	
	auto std_clear = high_resolution_clock::now();
	std_vector_int.clear();
	auto std_clear2 = high_resolution_clock::now();
	auto  std_clear_diff = duration_cast<microseconds>(std_clear2 - std_clear);

	std::cout << "clear     = ";
	if (ft_vector_int.size() != std_vector_int.size())
		std::cout << FRED("KO");
	else
		std::cout << FGRN("OK");
	std::cout << " | Duration : FT = " << ft_clear_diff.count() << " | STD = " << std_clear_diff.count() << " | Diff = " << float(ft_clear_diff.count()) / float(std_clear_diff.count()) << " | ";
	
	if (std_clear_diff.count() == 0 && ft_clear_diff.count() <= 20)
                std::cout << FGRN("OK\n");
	else if (ft_clear_diff.count() / std_clear_diff.count() <= 20)
                std::cout << FGRN("OK\n");
        else
                std::cout << FRED("KO\n");
}

void	ft_map()
{
	ft::map<int, std::string>	ft_map;
	std::map<int, std::string>	std_map;
	
	// Tests Map

	std::cout << UNDL(BOLD(FBLU("\nMap"))) << std::endl << std::endl;

	// Test  insert
	auto ft_insert_map = high_resolution_clock::now();
    	ft_map.insert({1, "one"});
    	ft_map.insert({2, "two"});
    	ft_map.insert({3, "three"});
    	ft_map.insert({4, "four"});
    	ft_map.insert({5, "five"});
	auto ft_insert_map2 = high_resolution_clock::now();
	auto ft_insert_map_diff = duration_cast<microseconds>(ft_insert_map2 - ft_insert_map);
    	
	auto std_insert_map = high_resolution_clock::now();
	std_map.insert({1, "one"});
    	std_map.insert({2, "two"});
    	std_map.insert({3, "three"});
    	std_map.insert({4, "four"});
    	std_map.insert({5, "five"});
	auto std_insert_map2 = high_resolution_clock::now();
	auto std_insert_map_diff = duration_cast<microseconds>(std_insert_map2 - std_insert_map);
	
	ft::map<int, std::string>::const_iterator ft_it = ft_map.begin();
	
	int insert_result_map = 0;
	for (std::map<int, std::string>::const_iterator std_it = std_map.begin(); std_it != std_map.end(); std_it++)
	{
		if (std_it->first != ft_it->first || std_it->second != ft_it->second)
			insert_result_map = 1;
		ft_it++;
	}
	std::cout << "insert    = ";
	if (insert_result_map != 0)
                std::cout << FRED("KO");
	else
                std::cout << FGRN("OK");
	
	std::cout << " | Duration : FT = " << ft_insert_map_diff.count() << " | STD = " << std_insert_map_diff.count() << " | Diff = " << float(ft_insert_map_diff.count()) / float(std_insert_map_diff.count()) << " | ";
	
	if (std_insert_map_diff.count() == 0 && ft_insert_map_diff.count() <= 20)
                std::cout << FGRN("OK\n");
	else if (ft_insert_map_diff.count() / std_insert_map_diff.count() <= 20)
                std::cout << FGRN("OK\n");
        else
                std::cout << FRED("KO\n");

	// Test erase()
	auto ft_erase_map = high_resolution_clock::now();
	for (int i = 0; i != 2; i++)
	{
		ft_map.erase(ft_map.begin());
	}
	auto ft_erase_map2 = high_resolution_clock::now();
	auto ft_erase_map_diff = duration_cast<microseconds>(ft_erase_map2 - ft_erase_map);
	
	auto std_erase_map = high_resolution_clock::now();
	for (int i = 0; i != 2; i++)
	{
		std_map.erase(std_map.begin());
	}
	auto std_erase_map2 = high_resolution_clock::now();
	auto std_erase_map_diff = duration_cast<microseconds>(std_erase_map2 - std_erase_map);
	
	std::cout << "erase     = ";
	int	erase_map_result = 0;
	int	erase_map_i = 0;
	while (erase_map_i < 1000)
	{
		if (ft_map[erase_map_i] != std_map[erase_map_i])
			erase_map_result = 1;
		erase_map_i++;
	}
	if (ft_map.size() != std_map.size() || erase_map_result != 0)
		std::cout << FRED("KO");
	else
		std::cout << FGRN("OK");
	std::cout << " | Duration : FT = " << ft_erase_map_diff.count() << " | STD = " << std_erase_map_diff.count() << " | Diff = " << float(ft_erase_map_diff.count()) / float(std_erase_map_diff.count()) << " | ";
	
	if (std_erase_map_diff.count() == 0 && ft_erase_map_diff.count() <= 20)
                std::cout << FGRN("OK\n");
	else if (ft_erase_map_diff.count() / std_erase_map_diff.count() <= 20)
                std::cout << FGRN("OK\n");
        else
                std::cout << FRED("KO\n");

	// Test swap()
	ft::map<int, std::string>	ft_map_swap;
	std::map<int, std::string>	std_map_swap;

    	ft_map_swap.insert({42, "forthy-two"});
    	ft_map_swap.insert({21, "twenty-one"});
    	std_map_swap.insert({42, "forthy-two"});
    	std_map_swap.insert({21, "twenty-one"});
	
	auto ft_swap_map = high_resolution_clock::now();
	ft_map.swap(ft_map_swap);
	auto ft_swap_map2 = high_resolution_clock::now();
	auto ft_swap_map_diff = duration_cast<microseconds>(ft_swap_map2 - ft_swap_map);
	
	auto std_swap_map = high_resolution_clock::now();
	std_map.swap(std_map_swap);
	auto std_swap_map2 = high_resolution_clock::now();
	auto std_swap_map_diff = duration_cast<microseconds>(std_swap_map2 - std_swap_map);
	
	int swap_map_i = 0;
	int swap_map_result = 0;
	while (swap_map_i < 666)
	{
		if (ft_map[swap_map_i] != std_map[swap_map_i])
			swap_map_result = 1;
		swap_map_i++;
	}
	std::cout << "swap      = ";
	if (swap_map_result != 0)
                std::cout << FRED("KO");
        else
		std::cout << FGRN("OK");
	std::cout << " | Duration : FT = " << ft_swap_map_diff.count() << " | STD = " << std_swap_map_diff.count() << " | Diff = " << float(ft_swap_map_diff.count()) / float(std_swap_map_diff.count()) << " | ";
	if (std_swap_map_diff.count() == 0 && ft_swap_map_diff.count() <= 20)
                std::cout << FGRN("OK\n");
	else if (ft_swap_map_diff.count() / std_swap_map_diff.count() <= 20)
                std::cout << FGRN("OK\n");
        else
                std::cout << FRED("KO\n");
		
	ft_map.swap(ft_map_swap);
	std_map.swap(std_map_swap);

	// Test count()
	auto ft_count_map	= high_resolution_clock::now();
	int	ft_count_return = ft_map.count(1);
	auto ft_count_map2 = high_resolution_clock::now();
	auto ft_count_map_diff = duration_cast<microseconds>(ft_count_map2 - ft_count_map);
	
	auto std_count_map = high_resolution_clock::now();
	int	std_count_return = std_map.count(1);
	auto std_count_map2 = high_resolution_clock::now();
	auto  std_count_map_diff = duration_cast<microseconds>(std_count_map2 - std_count_map);

	std::cout << "count     = ";
	if (ft_count_return != std_count_return)
		std::cout << FRED("KO");
	else
		std::cout << FGRN("OK");
	std::cout << " | Duration : FT = " << ft_count_map_diff.count() << " | STD = " << std_count_map_diff.count() << " | Diff = " << float(ft_count_map_diff.count()) / float(std_count_map_diff.count()) << " | ";
	
	if (std_count_map_diff.count() == 0 && ft_count_map_diff.count() <= 20)
                std::cout << FGRN("OK\n");
	else if (ft_count_map_diff.count() / std_count_map_diff.count() <= 20)
                std::cout << FGRN("OK\n");
        else
                std::cout << FRED("KO\n");
	

	// Test find()
	auto ft_find_map	= high_resolution_clock::now();
	ft::map<int, std::string>::iterator	ft_find_iterator = ft_map.find(1);
	auto ft_find_map2 = high_resolution_clock::now();
	auto ft_find_map_diff = duration_cast<microseconds>(ft_find_map2 - ft_find_map);
	
	auto std_find_map = high_resolution_clock::now();
	std::map<int, std::string>::iterator	std_find_iterator = std_map.find(1);
	auto std_find_map2 = high_resolution_clock::now();
	auto  std_find_map_diff = duration_cast<microseconds>(std_find_map2 - std_find_map);

	std::cout << "find      = ";
	if (ft_find_iterator->second != std_find_iterator->second)
		std::cout << FRED("KO");
	else
		std::cout << FGRN("OK");
	std::cout << " | Duration : FT = " << ft_find_map_diff.count() << " | STD = " << std_find_map_diff.count() << " | Diff = " << float(ft_find_map_diff.count()) / float(std_find_map_diff.count()) << " | ";
	
	if (std_find_map_diff.count() == 0 && ft_find_map_diff.count() <= 20)
                std::cout << FGRN("OK\n");
	else if (ft_find_map_diff.count() / std_find_map_diff.count() <= 20)
                std::cout << FGRN("OK\n");
        else
                std::cout << FRED("KO\n");
	
	// Test operators
	
	int operator_result = 0;
	ft::map<int, std::string>::iterator	ft_operator_i = ft_map.begin();
	ft::map<int, std::string>::iterator	ft_operator_i2 = ft_map.begin();
	ft_operator_i2++;
	std::map<int, std::string>::iterator	std_operator_i = std_map.begin();
	std::map<int, std::string>::iterator	std_operator_i2 = std_map.begin();
	std_operator_i2++;
	if ((ft_operator_i->second == ft_operator_i2->second) != (std_operator_i->second == std_operator_i2->second))
		operator_result = 1;
	if ((ft_operator_i->second != ft_operator_i2->second) != (std_operator_i->second != std_operator_i2->second))
		operator_result = 1;
	if ((ft_operator_i->second < ft_operator_i2->second) != (std_operator_i->second < std_operator_i2->second))
		operator_result = 1;
	if ((ft_operator_i->second <= ft_operator_i2->second) != (std_operator_i->second <= std_operator_i2->second))
		operator_result = 1;
	if ((ft_operator_i->second > ft_operator_i2->second) != (std_operator_i->second > std_operator_i2->second))
		operator_result = 1;
	if ((ft_operator_i->second >= ft_operator_i2->second) != (std_operator_i->second >= std_operator_i2->second))
		operator_result = 1;

	std::cout << "operators = ";
	if (operator_result == 0)
		std::cout << FGRN("OK");
	else
		std::cout << FRED("KO");
	std::cout << " | == : ";
	if ((ft_operator_i->second == ft_operator_i2->second) != (std_operator_i->second == std_operator_i2->second))
		std::cout << FRED("KO");
	else
		std::cout << FGRN("OK");
	std::cout << " | != : ";
	if ((ft_operator_i->second != ft_operator_i2->second) != (std_operator_i->second != std_operator_i2->second))
		std::cout << FRED("KO");
	else
		std::cout << FGRN("OK");
	std::cout << " | < : ";
	if ((ft_operator_i->second < ft_operator_i2->second) != (std_operator_i->second < std_operator_i2->second))
		std::cout << FRED("KO");
	else
		std::cout << FGRN("OK");
	std::cout << " | <= : ";
	if ((ft_operator_i->second <= ft_operator_i2->second) != (std_operator_i->second <= std_operator_i2->second))
		std::cout << FRED("KO");
	else
		std::cout << FGRN("OK");
	std::cout << " | > : ";
	if ((ft_operator_i->second > ft_operator_i2->second) != (std_operator_i->second > std_operator_i2->second))
		std::cout << FRED("KO");
	else
		std::cout << FGRN("OK");
	std::cout << " | >= : ";
	if ((ft_operator_i->second >= ft_operator_i2->second) != (std_operator_i->second >= std_operator_i2->second))
		std::cout << FRED("KO\n");
	else
		std::cout << FGRN("OK\n");
	std::cout << std::endl << std::endl;
}

void	ft_banner()
{
	std::cout << BOLD(FBLU("##################################################################################################\n"));
	std::cout << BOLD(FBLU("#  ____ ___     ____ ____ _  _ ___ ____ _ _  _ ____ ____ ____     ___ ____ ____ ___ ____ ____    #\n"));
        std::cout << BOLD(FBLU("#  |___  |      |    |  | |\\ |  |  |__| | |\\ | |___ |__/ [__       |  |___ [__   |  |___ |__/    #\n"));
        std::cout << BOLD(FBLU("#  |     |  ___ |___ |__| | \\|  |  |  | | | \\| |___ |  \\ ___] ___  |  |___ ___]  |  |___ |  \\    #\n"));
        std::cout << BOLD(FBLU("#                                                                                                #\n"));
        std::cout << BOLD(FBLU("#  ___  _   _    ____ _  _ _  _ ___  ____ ____                                                   #\n")); 
        std::cout << BOLD(FBLU("#  |__]  \\_/     |__| |__| |  | |__] |___ |__/                                                   #\n"));
        std::cout << BOLD(FBLU("#  |__]   |      |  | |  | |__| |__] |___ |  \\                                                   #\n"));
	std::cout << BOLD(FBLU("#                                                                                                #\n"));
	std::cout << BOLD(FBLU("##################################################################################################\n"));
}
