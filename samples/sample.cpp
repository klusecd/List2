#include "utlist.h"

template<class T>
void SearchMiddleElem(List<T>& list) {
	int n = 0;
	for (auto i = list.begin(); i != list.end(); ++i)
		n++;
	auto iter = list.begin();
	if (n % 2 == 0) {
		for (int i = 1; i < (n - 2) / 2; i++)
			++iter;
		list.Return(iter);
		list.Return(iter);
	}
	if (n % 2 == 1) {
		for (int i = 1; i < (n - 1) / 2; i++)
			++iter;
		list.Return(iter);
	}
}

int main() {
	List<int> list;;
	std::cout << "Example for an even number of nodes:\n";
	list.push_front(4);
	list.push_front(3);
	list.push_front(2);
	list.push_front(1);
	list.PrintList();
	std::cout << "\nMiddle list:\n";
	SearchMiddleElem(list);
	list.Clear();
	std::cout << "\nExample for an odd number of nodes:\n";
	list.push_front(3);
	list.push_front(2);
	list.push_front(1);
	list.PrintList();
	std::cout << "\nMiddle list:\n";
	SearchMiddleElem(list);
	return 0;
}