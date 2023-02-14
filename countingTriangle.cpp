#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int countTriangles(vector<pair<int, int>> &inputs) {
    unordered_map<int, int> umap_x;
    unordered_map<int, int> umap_y;

    for (auto &p: inputs) {
        umap_x[p.first]++;
        umap_y[p.second]++;
    }

    int count = 0;
    for (auto &p: inputs) {
        count += (umap_x[p.first] - 1) * (umap_y[p.second] - 1);
    }
    return count;
}

int main(void) {
    vector<pair<int,int>> inputs;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        inputs.push_back({x, y});
    }
    cout << countTriangles(inputs) << endl;

    return 0;
}