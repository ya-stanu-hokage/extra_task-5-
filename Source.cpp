#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <iomanip>

int main()
{
	std::vector<int> vector_sort(1000000);
	std::vector<int> vector_nth(1000000);

	std::iota(std::begin(vector_sort), std::end(vector_sort), 1);
	std::reverse(std::begin(vector_sort), std::end(vector_sort));

	std::iota(std::begin(vector_nth), std::end(vector_nth), 1);
	std::reverse(std::begin(vector_nth), std::end(vector_nth));

	std::size_t count_sort = 0;
	std::size_t count_nth = 0;

	std::sort(std::begin(vector_sort), std::end(vector_sort), [&count_sort](auto a, auto b)
		{
			count_sort++;
			return a < b;
		});

	std::nth_element(std::begin(vector_nth), std::begin(vector_nth) + std::size(vector_nth) / 2,
		std::end(vector_nth), [&count_nth](auto a, auto b)
		{
			count_nth++;
			return a < b;
		});

	std::cout << std::left << std::setw(17) << "Count for sort: " << count_sort << ' ' << std::endl
		<< std::left << std::setw(17) << "Count for nth: " << count_nth << std::endl;

	return 0;
}