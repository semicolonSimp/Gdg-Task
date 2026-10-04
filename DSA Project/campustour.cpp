#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
#include <string>
#include <climits>
#include <algorithm>

using namespace std;

class CampusNavigation {
private:

    // location -> {neighbour, cost}
    unordered_map<string, vector<pair<string, int>>> graph;

public:

    // Add a connection between two locations
    void addEdge(string u, string v, int cost) {

        graph[u].push_back(make_pair(v, cost));
        graph[v].push_back(make_pair(u, cost));
    }

    void findShortestPath(string start, string destination) {
        unordered_map<string, int> dist;
        unordered_map<string, string> parent;
        for (auto &node : graph) {
            dist[node.first] = INT_MAX;
        }
        dist[start] = 0;
        priority_queue<
            pair<int, string>,
            vector<pair<int, string> >,
            greater<pair<int, string> >
        > pq;
        pq.push(make_pair(0, start));

        while (!pq.empty()) {

            // Get the location having minimum distance
            pair<int, string> current = pq.top();
            pq.pop();

            int currentDist = current.first;
            string currentNode = current.second;

            // Ignore outdated entry
            if (currentDist > dist[currentNode]) {
                continue;
            }

            // Explore all neighbours
            for (auto &edge : graph[currentNode]) {

                string neighbour = edge.first;
                int cost = edge.second;

                // Calculate new possible distance
                int newDist = currentDist + cost;

                // If this route is shorter
                if (newDist < dist[neighbour]) {

                    dist[neighbour] = newDist;

                    // Store previous node
                    parent[neighbour] = currentNode;

                    // Add updated distance to priority queue
                    pq.push(make_pair(newDist, neighbour));
                }
            }
        }

        // Destination cannot be reached
        if (dist.find(destination) == dist.end() ||
            dist[destination] == INT_MAX) {

            cout << "\nNo route exists.\n";
            return;
        }

        // Reconstruct shortest path
        vector<string> path;

        string current = destination;

        while (current != start) {

            path.push_back(current);

            current = parent[current];
        }

        // Add starting location
        path.push_back(start);

        // Reverse to get start -> destination
        reverse(path.begin(), path.end());

        // Display route
        cout << "\nShortest Route:\n";

        for (int i = 0; i < (int)path.size(); i++) {

            cout << path[i];

            if (i != (int)path.size() - 1) {
                cout << " -> ";
            }
        }

        // Display total cost
        cout << "\nTotal Cost: "
             << dist[destination]
             << "\n";
    }
};


int main() {
    CampusNavigation campus;
    campus.addEdge("Gate", "Library", 4);
    campus.addEdge("Gate", "Canteen", 6);
    campus.addEdge("Library", "Canteen", 2);
    campus.addEdge("Library", "Lab", 3);
    campus.addEdge("Canteen", "Admin", 1);
    campus.addEdge("Lab", "Admin", 5);

    string start;
    string destination;

    cout << "===== Campus Navigation System =====\n";
    cout << "Available Locations:\n";
    cout << "Gate\n";
    cout << "Library\n";
    cout << "Canteen\n";
    cout << "Lab\n";
    cout << "Admin\n";

    cout << "\nEnter starting location: ";
    cin >> start;

    cout << "Enter destination: ";
    cin >> destination;

    campus.findShortestPath(start, destination);

    return 0;
}