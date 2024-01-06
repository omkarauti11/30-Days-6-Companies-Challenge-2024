
#include <bits/stdc++.h>
using namespace std;

// solution

class Solution
{
public:
    vector<vector<int>> rects;
    vector<double> weights;
    double sum;

    default_random_engine rand_gen{random_device{}()};

    Solution(vector<vector<int>> &rects)
    {

        this->rects = rects;
        this->sum = 0;

        for (const auto &rect : rects)
        {
            int x1 = rect[0], y1 = rect[1], x2 = rect[2], y2 = rect[3];
            int num_points = (x2 - x1 + 1) * (y2 - y1 + 1);
            this->weights.push_back(num_points);
            this->sum += num_points;
        }

        for (double &weight : this->weights)
        {
            weight /= this->sum;
        }
    }

    vector<int> pick()
    {

        uniform_real_distribution<double> distribution(0.0, 1.0);
        double rand_num = distribution(rand_gen);

        double cumulative_weight = 0;
        int chosen_index = 0;

        for (int i = 0; i < this->weights.size(); ++i)
        {
            cumulative_weight += this->weights[i];
            if (rand_num <= cumulative_weight)
            {
                chosen_index = i;
                break;
            }
        }

        int x1 = this->rects[chosen_index][0];
        int y1 = this->rects[chosen_index][1];
        int x2 = this->rects[chosen_index][2];
        int y2 = this->rects[chosen_index][3];

        uniform_int_distribution<int> x_distribution(x1, x2);
        uniform_int_distribution<int> y_distribution(y1, y2);

        return {x_distribution(rand_gen), y_distribution(rand_gen)};
    }
};
