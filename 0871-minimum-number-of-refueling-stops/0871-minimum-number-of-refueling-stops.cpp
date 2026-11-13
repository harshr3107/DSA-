class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations)
    {
        priority_queue<int> fuel;
        long long reach = startFuel;
        int i = 0;
        int stops = 0;
        int n = stations.size();

        while (reach < target)
        {
            while (i < n && stations[i][0] <= reach)
            {
                fuel.push(stations[i][1]);
                i++;
            }

            if (fuel.empty())
            {
                return -1;
            }

            reach += fuel.top();
            fuel.pop();
            stops++;
        }

        return stops;
    }
};