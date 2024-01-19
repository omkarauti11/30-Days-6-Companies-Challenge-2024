

#include <bits/stdc++.h>
using namespace std;

// solution

class Solution
{
public:
    int maxNumberOfFamilies(int n, vector<vector<int>> &reservedSeats)
    {

        int count = 0;
        unordered_map<int, array<bool, 3>> seatMap;

        for (const auto &reservedSeat : reservedSeats)
        {
            int row = reservedSeat[0];
            int seat = reservedSeat[1];

            if (seat == 1 || seat == 10)
            {
                continue;
            }

            if (seatMap.find(row) == seatMap.end())
            {
                seatMap[row] = {true, true, true};
            }

            array<bool, 3> &seatsAvailable = seatMap[row];

            if (seat == 2 || seat == 3)
            {
                seatsAvailable[0] = false;
            }
            else if (seat == 8 || seat == 9)
            {
                seatsAvailable[2] = false;
            }
            else if (seat == 4 || seat == 5)
            {
                seatsAvailable[0] = false;
                seatsAvailable[1] = false;
            }
            else if (seat == 6 || seat == 7)
            {
                seatsAvailable[1] = false;
                seatsAvailable[2] = false;
            }
        }

        for (const auto &entry : seatMap)
        {
            const array<bool, 3> &seatsAvailable = entry.second;

            if ((seatsAvailable[0] && seatsAvailable[1] && seatsAvailable[2]) || (seatsAvailable[0] && seatsAvailable[2]))
            {
                count += 2;
            }
            else if ((seatsAvailable[0] && seatsAvailable[2]) || seatsAvailable[0] || seatsAvailable[1])
            {
                count++;
            }
            else if ((seatsAvailable[1] && seatsAvailable[2]) || seatsAvailable[1] || seatsAvailable[2])
            {
                count++;
            }
        }

        count = count + (n - seatMap.size()) * 2;

        return count;
    }
};