//
// Created by Luis on 08/09/2023.
//

#ifndef MARATONA_SOLUTION_H
#define MARATONA_SOLUTION_H
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define INF 1000000010
#define INFLL 1000000000000000010LL
#define ALL(x) x.begin(), x.end()
#define UNIQUE(c) (c).resize(unique(ALL(c)) - (c).begin())
#define REP(i, a, b) for(int i = (a); i <= (b); i++)
#define POS(n, x) (lower_bound(ALL(n), x) - (n).begin())
#define ll long long
#define ld long double
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pii>
#define os_type int
#define PB push_back
#define EB emplace_back
#define MOD 1000000007
#define PRIME 101
#define MAXN 1010101
#define MAXL 23
#define EPS 1e-9
#define endl '\n'

using namespace std;
using namespace __gnu_pbds;

#define ordered_set tree<os_type, null_type,less<os_type>, rb_tree_tag,tree_order_statistics_node_update>
struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


struct NodePairs{
    int sum;
    int left;
    int right;
    int mid;
    vector<vector<ListNode*>> pares;
    int quantPares(int val){
        if(val & 1){
            return val/2 +1;
        }
        return val/2;
    }

    void init(){
        for(auto &par : pares){
            ListNode* node1 = new ListNode();
            ListNode* node2 = new ListNode();
            par = {node1,node2};
        }
    }

    NodePairs(int left,int right)   {
        this->sum = left+right;
        this->left = left;
        this->right = right;
        this->mid = (left+right)/2;
        int quant = quantPares(right - left);
        pares = vector<vector<ListNode*>>(quant);
        init();
    }

    void insert(ListNode *node,int pos){
        int index;
        if(pos < left || pos > right) return;
        if(pos <= mid){
            index = pos -left;
            pares[index][0]->next = node;
        }else{
            index = right - pos;
            pares[index][1]->next = node;
        }
    }

    void fix(){
        for(auto &par : pares){
            swap(par[0]->next->val,par[1]->next->val);
        }
    }
};


class Solution {
public:
    ListNode *reverseBetween(ListNode *head, int left, int right) {
        ListNode* aux = head;
        NodePairs *pares = new NodePairs(left,right);
        int pos = 1;
        while (aux != nullptr) {
            pares->insert(aux,pos);
            aux = aux->next;
            pos++;
        }
        pares->fix();
        return head;
    }
};


#endif //MARATONA_SOLUTION_H
