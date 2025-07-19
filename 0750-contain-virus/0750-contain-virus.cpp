using pi = pair<int, int>;
struct Region {
    int threat; 
    int perimeter; 
    vector<pi> cells; 
    set<pi> potential_infections; 
};

class Solution {
public:
    int containVirus(vector<vector<int>>& isInfected) {
        int m = isInfected.size(), n = isInfected[0].size();
        int total_walls = 0;

        vector<int> dr = {-1, 1, 0, 0};
        vector<int> dc = {0, 0, -1, 1};

        while (true) {  // Stops when there are no more active infected regions left to process.
            vector<vector<bool>> visited(m, vector<bool>(n, false));
            vector<Region> active_regions;

            for (int r = 0; r < m; ++r) {   // for finding active regions, using bfs
                for (int c = 0; c < n; ++c) {
                    if (isInfected[r][c] == 1 && !visited[r][c]) {
                        Region current_region;
                        current_region.perimeter = 0;

                        queue<pi> q;
                        q.push({r, c});
                        visited[r][c] = true;
                        current_region.cells.push_back({r, c});

                        while (!q.empty()) {
                            auto [curr_r, curr_c] = q.front(); q.pop();
                            
                            for (int i = 0; i < 4; ++i) {   // adding neighbors to potential_infections or queue
                                int nr = curr_r + dr[i], nc = curr_c + dc[i];
                                
                                if( nr < 0 || nr >= m || nc < 0 || nc >= n )    continue;
                                if (isInfected[nr][nc] == 0) {
                                    current_region.perimeter++;
                                    current_region.potential_infections.insert({nr, nc});
                                } 
                                else if (isInfected[nr][nc] == 1 && !visited[nr][nc]) {
                                    visited[nr][nc] = true;
                                    q.push({nr, nc});
                                    current_region.cells.push_back({nr, nc});
                                }
                            }
                        }

                        if (!current_region.potential_infections.empty()) {
                            current_region.threat = current_region.potential_infections.size();
                            active_regions.push_back(current_region);
                        }
                    }
                }
            }

            if (active_regions.empty())
                break;

            sort(active_regions.begin(), active_regions.end(), [](const Region& a, const Region& b) {
                return a.threat > b.threat; 
            });

            Region best_region = active_regions[0]; 
            total_walls += best_region.perimeter;   // most active region is now quarantined

            for (const auto& [cell_r, cell_c] : best_region.cells)
                isInfected[cell_r][cell_c] = 2;    // quarantined

            // spread virus for the remaining active regions
            for (size_t i = 1; i < active_regions.size(); ++i) {
                const Region& region_to_spread = active_regions[i];
                // make the potientially infective regions infective
                for (const auto& cell_to_infect : region_to_spread.potential_infections) {
                    if (isInfected[cell_to_infect.first][cell_to_infect.second] == 0)
                        isInfected[cell_to_infect.first][cell_to_infect.second] = 1;
                }
            }
            
            //Early Exit Optimization
            // If the entire grid is either:
                // Already infected, or
                // Quarantined (marked 2), then exit early.

            bool all_infected_or_quarantined = true;
            for(int r = 0; r < m; ++r) {
                for(int c = 0; c < n; ++c) {
                    if (isInfected[r][c] == 0) {
                        all_infected_or_quarantined = false;
                        break;
                    }
                }
                if (!all_infected_or_quarantined) break;
            }
            if (all_infected_or_quarantined)
                break;
        }

        return total_walls;
    }
};