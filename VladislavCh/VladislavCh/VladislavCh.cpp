#include <iostream>

using namespace std;

std::pair<int, int> binSearchInner(int* ar, int first, int last, int el, int count_call)
{
	if (last - first <= 1)
	{
		if (ar[last] == el)
		{
			return std::make_pair(last, count_call);
		}

		if (ar[first] == el)
		{
			return std::make_pair(first, count_call);
		}

		else
		{
			return std::make_pair(-1, count_call);
		}
	}

	int mid_el = ar[(last + first) / 2];

	if (mid_el >= el)
	{
		return binSearchInner(ar, first, (last + first) / 2, el, count_call + 1);
	}

	else if (mid_el <= el)
	{
		return binSearchInner(ar, (last + first) / 2, last, el, count_call + 1);
	}
}

std::pair<int/*index el*/, int /*count call*/> binSearch(int* ar, int sizeAr, int el)
{
	return binSearchInner(ar, 0, sizeAr - 1, el, 1);
}


int main()
{
	int nums[15] = { 0, 1, 1, 2, 3, 4, 6, 12, 12, 16, 23, 76, 78, 132, 154 };

	pair<int, int> result(0, 0);

	result = binSearch(nums, 15, 12);

	cout<< result.first<< " " « result.second;
}