#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>

#include "graph_and_edge.h"
#include "disjoint_set.h"


// Ʈ���� �׷����� ǥ���� �� �����Ƿ� �ּ� ���� Ʈ���� Graph ��ü�� ��ȯ
// ��, ����Ŭ�� �����ϸ� �ȵ�
template <typename T>
Graph<T> minimum_spanning_tree(const Graph<T>& G) {
	// ���� ����ġ�� �̿��� �ּ� �� ����
	priority_queue<Edge<T>, vector<Edge<T>>, greater<Edge<T>>> edge_min_heap;

	// ��� ������ �ּ� ���� �߰�
	for (const Edge<T>& e : G.edges())
		edge_min_heap.push(e);

	// ���� ������ �ش��ϴ� ũ���� ������Ʈ-�� �ڷᱸ�� ���� �� �ʱ�ȭ
	unsigned N = G.vertices();
	SimpleDisjointSet dset(N);
	for (unsigned i = 0; i < N; i++)
		dset.make_set(i);

	// ������Ʈ-�� �ڷᱸ���� �̿��Ͽ� �ּ� ���� Ʈ�� ���ϱ�
	Graph<T> MST(N);
	
	while (!edge_min_heap.empty()) {
		// �ּ� ������ �ּ� ����ġ�� ���� ���� ����
		Edge<T> e = edge_min_heap.top();
		edge_min_heap.pop();

		// ������ ������ ����Ŭ�� �������� ������ �ش� ������ MST�� �߰�
		if (dset.find(e.src) != dset.find(e.dst)) {
			MST.add_edge(Edge<T>{e.src, e.dst, e.weight});
			dset.union_sets(e.src, e.dst);
		}
	}

	return MST;
}

// �׽�Ʈ �Լ�
void mst_test() {
	using T = unsigned;

	// �׷��� ��ü ����
	Graph<T> G(9);

	map<unsigned, vector<pair<unsigned, T>>> edge_map;
	edge_map[1] = { {2, 2}, {5, 3} };
	edge_map[2] = { {1, 2}, {5, 5}, {4, 1} };
	edge_map[3] = { {4, 2}, {7, 3} };
	edge_map[4] = { {2, 1}, {3, 2}, {5, 2}, {6, 4}, {8, 5} };
	edge_map[5] = { {1, 3}, {2, 5}, {4, 2}, {8, 3} };
	edge_map[6] = { {4, 4}, {7, 4}, {8, 1} };
	edge_map[7] = { {3, 3}, {6, 4} };
	edge_map[8] = { {4, 5}, {5, 3}, {6, 1} };

	for (auto& i : edge_map)
		for (auto& j : i.second)
			G.add_edge(Edge<T>{i.first, j.first, j.second});

	cout << "[�Է� �׷���]" << endl;
	cout << G << endl;

	Graph<T> MST = minimum_spanning_tree(G);
	cout << "\n\n[�ּ� ���� Ʈ��]" << endl;
	cout << MST << endl;
}