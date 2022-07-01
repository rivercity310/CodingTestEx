#include <iostream>
#include <vector>
#include <iomanip>
#include <random>
using namespace std;

template <typename T>
auto partition(typename vector<T>::iterator begin, typename vector<T>::iterator end) {
	// �� ���� �ݺ��� ����
	// �ϳ��� �ǹ�, ������ ���� ������ ó���� ��
	T pivot_val = *begin;
	auto left_iter = begin + 1;
	auto right_iter = end;

	while (true) {
		// ������ ù��° ���Һ��� �����Ͽ� �ǹ����� ū ���� ã��
		while (*left_iter <= pivot_val && distance(left_iter, right_iter) > 0)
			left_iter++;

		// ������ ������ ���Һ��� �������� �ǹ����� ���� ���� ã��
		while (*right_iter > pivot_val && distance(left_iter, right_iter) > 0)
			right_iter--;

		cout << "[ iter_swap ���� ]" << "\n";
		cout << "left_iterator_value: " << *left_iter << "\n";
		cout << "right_iterator_value: " << *right_iter << endl;

		if (left_iter == right_iter) break;
		else iter_swap(left_iter, right_iter);
	
		cout << "[ iter_swap ���� ]" << "\n";
		cout << "left_iterator_value: " << *left_iter << "\n";
		cout << "right_iterator_value: " << *right_iter << "\n";
		cout << "\n\n\n" << endl;
	}

	if (pivot_val > *right_iter) {
		cout << "[ pivot�� right_iter�� Swap ]" << "\n";
		cout << "���� �� >> pivot: " << *begin << ", right_iter: " << *right_iter << "\n";
		iter_swap(begin, right_iter);
		cout << "���� �� >> pivot: " << *begin << ", right_iter: " << *right_iter << endl;
	}

	return right_iter;
}

// ���� ���� (partition �Լ�)�� ��������� �����Ͽ� �� ������ ����
template <typename T>
void quick_sort(typename vector<T>::iterator begin, typename vector<T>::iterator last) {
	if (distance(begin, last) >= 1) {
		// ���� �۾� ����
		auto partition_iter = partition<T>(begin, last);

		// ���� �۾��� ���� ������ ���͸� ��������� ����
		quick_sort<T>(begin, partition_iter - 1);
		quick_sort<T>(partition_iter, last);
	}
}

template <typename T>
void prt_vt3(vector<T> arr) {
	for (auto i : arr)
		cout << setw(10) << right << i;
	cout << endl;
}

void q_sort_test() {
	random_device rd;
	mt19937 rand(rd());

	uniform_int_distribution<mt19937::result_type> uniform_dist(1, 1000);
	
	vector<int> v1;
	vector<double> v2;
	for (int i = 0; i < 3; i++) {
		v1.push_back(uniform_dist(rand));
		v2.push_back(uniform_dist(rand) / (double)(i+ 1));
	}

	cout << "[ ���� �� ���� ]" << endl;
	prt_vt3(v1);
	prt_vt3(v2);

	// end()�� ������ ���� ������ ����Ű�Ƿ� 1�� ���ش�.
	quick_sort<int>(v1.begin(), v1.end() - 1);
	quick_sort<double>(v2.begin(), v2.end() - 1);
	
	cout << "[ ���� �� ���� ]" << endl;
	prt_vt3<int>(v1);
	prt_vt3<double>(v2);


}
