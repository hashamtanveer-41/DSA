#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
    struct TrieNode {
        int children[10];
        int word_idx;
        TrieNode() {
            fill(children, children + 10, -1);
            word_idx = -1;
        }
    };

    vector<TrieNode> trie;
    long long total_inversions = 0;

    vector<int> dfs(int u, const vector<int>& pos) {
        vector<int> active_children;
        vector<vector<int>> child_lists;

        for (int c = 0; c < 10; ++c) {
            int v = trie[u].children[c];
            if (v != -1) {
                active_children.push_back(c);
                child_lists.push_back(dfs(v, pos));
            }
        }

        int k = active_children.size();
        if (k > 0) {
            // cost[i][j]: number of inversions if child i precedes child j
            vector<vector<long long>> pair_inv(k, vector<long long>(k, 0));

            for (int i = 0; i < k; ++i) {
                // Ensure elements are sorted to count cross-inversions in O(N log N) or two-pointer
                vector<int> list_i = child_lists[i];
                sort(list_i.begin(), list_i.end());

                for (int j = 0; j < k; ++j) {
                    if (i == j) continue;
                    long long inv_count = 0;
                    // Count pairs (x in list_i, y in child_lists[j]) with x > y
                    for (int y : child_lists[j]) {
                        // Count elements in list_i that are strictly greater than y
                        auto it = upper_bound(list_i.begin(), list_i.end(), y);
                        inv_count += (list_i.end() - it);
                    }
                    pair_inv[i][j] = inv_count;
                }
            }

            // Bitmask DP to find optimal permutation of active children
            // dp[mask]: minimum inversions within elements in mask
            int num_masks = 1 << k;
            vector<long long> dp(num_masks, 1e18);
            dp[0] = 0;

            for (int mask = 0; mask < num_masks; ++mask) {
                if (dp[mask] >= 1e18) continue;
                for (int nxt = 0; nxt < k; ++nxt) {
                    if (!(mask & (1 << nxt))) {
                        // Inversions between previously chosen children in mask and nxt
                        long long add_inv = 0;
                        for (int prev = 0; prev < k; ++prev) {
                            if (mask & (1 << prev)) {
                                add_inv += pair_inv[prev][nxt];
                            }
                        }
                        int next_mask = mask | (1 << nxt);
                        dp[next_mask] = min(dp[next_mask], dp[mask] + add_inv);
                    }
                }
            }

            total_inversions += dp[num_masks - 1];
        }

        // Aggregate all elements in this subtree
        vector<int> subtree_elements;
        if (trie[u].word_idx != -1) {
            int p = pos[trie[u].word_idx];
            subtree_elements.push_back(p);
            // Ancestor-descendant inversions: word at u precedes all descendants
            for (const auto& clist : child_lists) {
                for (int desc_val : clist) {
                    if (p > desc_val) {
                        total_inversions++;
                    }
                }
            }
        }

        for (auto& clist : child_lists) {
            subtree_elements.insert(subtree_elements.end(), clist.begin(), clist.end());
        }

        return subtree_elements;
    }

public:
    long long minInversions(vector<string>& words, vector<int>& target) {
        int n = words.size();
        vector<int> pos(n);
        for (int i = 0; i < n; ++i) {
            pos[target[i]] = i;
        }

        trie.clear();
        trie.emplace_back(); // root = 0
        total_inversions = 0;

        // Build Trie
        for (int i = 0; i < n; ++i) {
            int curr = 0;
            for (char ch : words[i]) {
                int c = ch - 'a';
                if (trie[curr].children[c] == -1) {
                    trie[curr].children[c] = trie.size();
                    trie.emplace_back();
                }
                curr = trie[curr].children[c];
            }
            trie[curr].word_idx = i;
        }

        dfs(0, pos);

        return total_inversions;
    }
};