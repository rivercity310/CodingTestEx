#include <iostream>
#include <unordered_map>
#include <unordered_set>
using namespace std;

namespace stl_h {
	void prt_all_container(unordered_set<int>& container) {
		for (const auto& elem : container) cout << elem << " ";
		cout << endl;
	}

	void prt_all_container(unordered_map<int, int>& container) {
		for (const auto& elem : container) cout << elem.first << ": " << elem.second << ", ";
		cout << endl;
	}

	void find(const unordered_set<int>& container, const int elem) {
		if (container.find(elem) == container.end()) cout << "�˻� ����!" << endl;
		else cout << elem << " �˻� ����!" << endl;
	}

	void find(const unordered_map<int, int>& container, const int elem) {
		auto it = container.find(elem);
		if (it == container.end()) cout << "�˻� ����!" << endl;
		else cout << "�˻� ����: " << it->second << endl;
	}
}

void stl_hash() {
	cout << "*** std::unordered_set ���� ***" << endl;
	unordered_set<int> set1 = { 1, 2, 3, 4, 5 };

	cout << "set1 �ʱⰪ" << endl;
	stl_h::prt_all_container(set1);

	set1.insert(10);
	set1.insert(300);

	cout << "10, 300 ����" << endl;
	stl_h::prt_all_container(set1);

	stl_h::find(set1, 4);
	stl_h::find(set1, 100);

	set1.erase(1);
	cout << "1 ����" << endl;
	stl_h::prt_all_container(set1);
	cout << "��Ŷ�� ����: " << set1.bucket_count() << endl;

	cout << "\n" << endl;

	cout << "*** std::unordered_map ���� ***" << endl;
	unordered_map<int, int> sqr_map;

	sqr_map.insert({ 2, 4 });
	sqr_map[3] = 9;
	cout << "2, 3�� ���� ����" << endl;
	stl_h::prt_all_container(sqr_map);

	stl_h::find(sqr_map, 3);
	stl_h::find(sqr_map, 4);

	cout << "sqr_map[3] = " << sqr_map[3] << endl;
	cout << "��Ŷ�� ����: " << sqr_map.bucket_count() << endl;
}