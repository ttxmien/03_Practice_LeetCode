class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size();
        int n = classroom[0].size();
        pair<int, int> start;
        vector<pair<int, int>> litter;

        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                if (classroom[r][c] == 'S') start = {r, c};
                else if (classroom[r][c] == 'L') litter.push_back({r, c});
            }
        }

        int k = litter.size();
        if (k == 0) return 0;
        int target = (1 << k) - 1;

        // -> TLE 798/799 TC passed
        // static int dist[20][20][1024][51];
        // memset(dist, -1, sizeof(dist));

        int maxEnergy[20][20][1024];
        memset(maxEnergy, -1, sizeof(maxEnergy));

        queue<tuple<int, int, int, int, int>> q;                // {r, c, mask, energy, step}
        q.push({start.first, start.second, 0, energy, 0});      
        maxEnergy[start.first][start.second][0] = energy;

        int dr[] = {-1, 1, 0, 0}, dc[] = {0, 0, -1, 1};

        // BFS
        while (!q.empty()) {
            auto [r, c, mask, e, step] = q.front();
            q.pop();

            if (mask == target) return step;

            for (int i = 0; i < 4; ++i) {
                int nr = r + dr[i], nc = c + dc[i];

                if (nr >= 0 && nr < m && nc >= 0 && nc < n && classroom[nr][nc] != 'X' && e > 0) {
                    int ne = e - 1;
                    int nmask = mask;

                    if (classroom[nr][nc] == 'L') {
                        for (int j = 0; j < k; ++j) {
                            if (litter[j] == pair(nr, nc)) {
                                nmask |= (1 << j);
                            } 
                        }
                    }

                    if (classroom[nr][nc] == 'R') ne = energy;

                    // -> TLE 798/799 TC passed
                    // if (dist[nr][nc][nmask][ne] == -1) {
                    //     dist[nr][nc][nmask][ne] = dist[r][c][mask][e] + 1;
                    //     q.push({nr, nc, nmask, ne});
                    // }

                    if (ne > maxEnergy[nr][nc][nmask]) {
                        maxEnergy[nr][nc][nmask] = ne;
                        q.push({nr, nc, nmask, ne, step + 1});
                    }
                }
            }
        }

        return -1;
    }
};