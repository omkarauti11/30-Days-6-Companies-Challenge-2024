#include <bits/stdc++.h>
using namespace std;

// solution

class Solution
{
public:
    int minPrice;

    int directlyBuy(const vector<int> &price, const vector<int> &needs)
    {
        int total = 0;
        int n = price.size();
        for (int i = 0; i < n; i++)
        {
            total += price[i] * needs[i];
        }
        return total;
    }

    bool canUse(const vector<int> &offer, const vector<int> &needs)
    {
        int n = needs.size();
        for (int i = 0; i < n; i++)
        {
            if (offer[i] > needs[i])
            {
                return false;
            }
        }
        return true;
    }

    void helper(const vector<int> &price, const vector<vector<int>> &special, int index, vector<int> needs, int used)
    {
        if (used >= minPrice)
        {
            return;
        }

        if (index == special.size())
        {
            used += directlyBuy(price, needs);

            if (used < minPrice)
            {
                minPrice = used;
            }

            return;
        }

        vector<int> offer = special[index];
        int n = needs.size();

        if (canUse(offer, needs))
        {
            for (int i = 0; i < n; i++)
            {
                needs[i] -= offer[i];
            }

            helper(price, special, index, needs, used + offer[n]);

            for (int i = 0; i < n; i++)
            {
                needs[i] += offer[i];
            }
        }

        helper(price, special, index + 1, needs, used);
    }

    int shoppingOffers(vector<int> &price, vector<vector<int>> &special, vector<int> &needs)
    {
        minPrice = directlyBuy(price, needs);
        helper(price, special, 0, needs, 0);
        return minPrice;
    }
};