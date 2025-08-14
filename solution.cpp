#include <iostream>
#include <string>

int parseDepth(const std::string& preorder, std::size_t& pos) {
    char label = preorder[pos++];
    if (label == 'l') {
        return 0; // folha
    }
    int leftDepth = parseDepth(preorder, pos);
    int rightDepth = parseDepth(preorder, pos);
    return 1 + (leftDepth > rightDepth ? leftDepth : rightDepth);
}

int computeDepthPre(const std::string& preorder) {
    std::size_t pos = 0;
    return parseDepth(preorder, pos);
}

int main() {
    int tests = 0;
    std::cin >> tests;
    if (!std::cin) return 0;

    for (int caseIndex = 0; caseIndex < tests; ++caseIndex) {
        std::string preorderString;
        if (!(std::cin >> preorderString)) {
            return 0;
        }
        int treeDepth = computeDepthPre(preorderString);
        std::cout << treeDepth << '\n';
    }

    return 0;
}
