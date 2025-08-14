#include <iostream>
#include <vector>


struct Node {
    int left;
    int right;
};


void SwapNodes(std::vector<Node>& tree, int index, int depth, int k, std::vector<int>& out) {
    if (index == -1) return;

    if (k > 0 && depth % k == 0) {
        int temp = tree[index].left;
        tree[index].left = tree[index].right;
        tree[index].right = temp;
    }

    SwapNodes(tree, tree[index].left, depth + 1, k, out);
    out.push_back(index);
    SwapNodes(tree, tree[index].right, depth + 1, k, out);
}

std::vector<std::vector<int>> swapNodes(std::vector<Node>& tree, const std::vector<int>& queries) {
    std::vector<std::vector<int>> result;
    result.reserve(queries.size());

    for (int k : queries) {
        std::vector<int> traversal;
        traversal.reserve(tree.size() > 0 ? tree.size() - 1 : 0);
        SwapNodes(tree, 1, 1, k, traversal);  
        result.push_back(std::move(traversal));
    }

    return result;
}

int main() {
    int n;
    std::cin >> n;

    std::vector<Node> tree(n + 1);  

    for (int i = 1; i <= n; ++i) {
        int left, right;
        std::cin >> left >> right;
        tree[i] = {left, right};
    }

    int t;
    std::cin >> t;
    std::vector<int> queries(t);

    for (int i = 0; i < t; ++i) {
        std::cin >> queries[i];
    }

    std::vector<std::vector<int>> results = swapNodes(tree, queries);

    for (const auto& traversal : results) {
        for (int val : traversal) {
            std::cout << val << ' ';
        }
        std::cout << '\n';
    }

    return 0;
}
