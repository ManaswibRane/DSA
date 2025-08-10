/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/
class Solution {
public:
    bool isAllSame(vector<vector<int>>& grid, int st, int end, int size) {
        int val = grid[st][end];
        for (int i = st; i < st + size; i++) {
            for (int j = end; j < end + size; j++) {
                if (grid[i][j] != val) {
                    return false;
                }
            }
        }
        return true;
    }

    Node* solve(vector<vector<int>>& grid, int st, int end, int size) {
        if (isAllSame(grid, st, end, size)) {
            return new Node(grid[st][end], true);
        }
        Node* newNode = new Node(1, false);

        newNode->topLeft     = solve(grid, st, end, size/2);
        newNode->topRight    = solve(grid, st, end + size/2, size/2);
        newNode->bottomLeft  = solve(grid, st + size/2, end, size/2);
        newNode->bottomRight = solve(grid, st + size/2, end + size/2, size/2);

        return newNode;
    }

    Node* construct(vector<vector<int>>& grid) {
        int n = grid.size();
        return solve(grid, 0, 0, n);
    }
};
