class Solution {
public:
    vector<long long> minTimeMaxPower(int n, vector<vector<int>>& edges, int power,
                                      vector<int>& cost, int source, int target) {

        vector<vector<pair<int,int>>> adj(n);
        for (auto &e : edges) {
            adj[e[0]].push_back({e[1], e[2]});
        }

        const long long INF = 1e18;
        vector<vector<long long>> minTime(n, vector<long long>(power + 1, INF));

        using State = tuple<long long,int,int>; // time, power, node
        priority_queue<State, vector<State>, greater<State>> pq;

        pq.push({0LL, power, source});
        minTime[source][power] = 0;

        while (!pq.empty()) {
            auto [t, p, u] = pq.top();
            pq.pop();

            if (t > minTime[u][p]) continue;

            if (p < cost[u]) continue;
            int nextPower = p - cost[u];

            for (auto &nb : adj[u]) {
                int v = nb.first;
                long long w = nb.second;

                long long nt = t + w;

                if (nt < minTime[v][nextPower]) {
                    minTime[v][nextPower] = nt;
                    pq.push({nt, nextPower, v});
                }
            }
        }

        long long bestTime = INF;
        int maxRemPower = -1;

        for (int p = 0; p <= power; p++) {
            if (minTime[target][p] < bestTime) {
                bestTime = minTime[target][p];
                maxRemPower = p;
            } else if (minTime[target][p] == bestTime) {
                maxRemPower = max(maxRemPower, p);
            }
        }

        if (bestTime == INF) return {-1, -1};

        return {bestTime, maxRemPower};
    }
};