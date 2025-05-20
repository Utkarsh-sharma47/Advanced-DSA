 #include <bits/stdc++.h>
using namespace std;

// Custom comparator for max heap (priority_queue)
typedef pair<int, int> FuelStation;

int minRefuelStops() {
    int n;
    cout << "Enter number of fuel stations: ";
    cin >> n;

    vector<FuelStation> stations(n); // {distance from town, fuel}

    cout << "Enter distance from town and fuel for each station:\n";
    for (int i = 0; i < n; i++) {
        cin >> stations[i].first >> stations[i].second;
    }

    int L, P;
    cout << "Enter distance to town (L) and initial fuel (P): ";
    cin >> L >> P;

    // Convert all station distances from town-based to start-based
    for (int i = 0; i < n; i++) {
        stations[i].first = L - stations[i].first;
    }

    // Sort stations based on their distance from the starting point
    sort(stations.begin(), stations.end());

    int stops = 0;         // Number of refueling stops
    int currFuel = P;      // Current fuel in tank
    int i = 0;             // Index for station traversal

    priority_queue<int> maxHeap; // Stores fuel amounts of reachable stations

    while (currFuel < L) {
        // Push all reachable stations (within current fuel range) to maxHeap
        while (i < n && stations[i].first <= currFuel) {
            maxHeap.push(stations[i].second);
            i++;
        }

        // If no fuel station is reachable and we haven't reached the town
        if (maxHeap.empty()) {
            cout << "-1 (Cannot reach the town)\n";
            return -1;
        }

        // Refuel at the best station (with max fuel)
        currFuel += maxHeap.top();
        maxHeap.pop();
        stops++; // Count the stop
    }

    cout << "Minimum stops: " << stops << endl;
    return stops;
}

int main() {
    int t;
    cout << "Enter number of test cases: ";
    cin >> t;

    while (t--) {
        minRefuelStops();
    }

    return 0;
}
