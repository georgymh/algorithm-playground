#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct LinkNode {
    int val;
    LinkNode* next;
    LinkNode(int x) : val(x), next(NULL) {}
};

void helper(LinkNode* coins, int total, vector<int>& currComb, vector<vector<int>>& result) {
    if (total == 0)
        result.push_back(currComb);
    else if (coins == NULL)
        return;
    else if (coins->val > total)
        helper(coins->next, total, currComb, result);
    else {
        currComb.push_back(coins->val);
        helper(coins, total - coins->val, currComb, result);
        currComb.pop_back();
        helper(coins->next, total, currComb, result);
    }
}

vector<vector<int>> listCoinChange(LinkNode* coins, int total) {
    vector<vector<int>> result;
    vector<int> combination;
    helper(coins, total, combination, result);
    return result;
}

void printResults(const vector<vector<int>>& result) {
    int outerLen = static_cast<int>(result.size());
    for (int i = 0; i < outerLen; i++) {
        int innerLen = static_cast<int>(result[i].size());
        for (int j = 0; j < innerLen; j++)
            cout << result[i][j] << " ";
        cout << endl;    
    }
    cout << endl;
}

int main()
{
    // Test #1 - Making change of 10 cents with US Currency
    LinkNode * a = new LinkNode(25);
    LinkNode * b = new LinkNode(10);
    LinkNode * c = new LinkNode(5);
    LinkNode * d = new LinkNode(1);
    a->next = b;
    b->next = c;
    c->next = d;
  
    printResults(listCoinChange(a, 10));
    
    
    // Test #2 - Making change of 5 cents with cents {1, 2, 3, 4}
    LinkNode * x = new LinkNode(4);
    LinkNode * y = new LinkNode(3);
    LinkNode * z = new LinkNode(2);
    LinkNode * w = new LinkNode(1);
    x->next = y;
    y->next = z;
    z->next = w;
    
    printResults(listCoinChange(x, 5));
}
