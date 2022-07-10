#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <stack>

#include "graph_and_edge.h"

using namespace std;


// ���� �켱 Ž���� ������ �Լ�
template <typename T>
vector<unsigned> depth_first_search(const Graph<T>& G, unsigned start) {
	stack<unsigned> stack;
	set<unsigned> visited;
	vector<unsigned> visit_order;

	stack.push(start);

	while (!stack.empty()) {
		unsigned current_vertex = stack.top();
		stack.pop();

		// ���� ������ ������ �湮���� �ʾҴٸ�
		if (visited.find(current_vertex) == visited.end()) {
			visited.insert(current_vertex);
			visit_order.push_back(current_vertex);

			for (Edge<T>& e : G.edges(current_vertex))
				// ������ ���� �߿��� �湮���� ���� ������ �ִٸ� ���ÿ� �߰�
				if (visited.find(e.dst) == visited.end())
					stack.push(e.dst);
		}
	}

	return visit_order;
}

void dfs_test() {
	using T = unsigned;

	// �׷��� ��ü ����
	Graph<T> G = create_reference_graph<T>();

	cout << "[�Է� �׷���]" << endl;
	cout << G << endl;

	// 1�� �������� DFS ���� & �湮 ���� ���
	cout << "\n\n[DFS �湮 ����]" << endl;
	vector<unsigned> dfs_visit_order = depth_first_search(G, 1);
	for (unsigned v : dfs_visit_order)
		cout << v << endl;
}