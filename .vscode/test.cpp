// network_sim.cpp
// Simple Network Routing Simulator (C++11 Compatible, ASCII Output)
// Demonstrates how packets travel through routers using Dijkstra + Queues.

#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <limits>
#include <string>
using namespace std;

//------------------------------------------
// Structures: Packet, Edge, Graph
//------------------------------------------
struct Packet {
    int id;
    int src;
    int dst;
    int ttl;
    string payload;
    Packet(int _id, int _src, int _dst, int _ttl, string _p = "")
        : id(_id), src(_src), dst(_dst), ttl(_ttl), payload(_p) {}
};

struct Edge {
    int to;
    int weight; // cost/latency
    Edge(int _to, int _w) : to(_to), weight(_w) {}
};

struct Graph {
    int N; // number of routers
    vector<vector<Edge>> adj;
    Graph(int n = 0) : N(n), adj(n) {}

    void add_edge(int u, int v, int w = 1) {
        adj[u].push_back(Edge(v, w));
        adj[v].push_back(Edge(u, w)); // undirected network
    }
};

//------------------------------------------
// Dijkstra Algorithm for Routing Table
//------------------------------------------
pair<vector<int>, vector<int>> dijkstra_with_nexthop(const Graph &g, int s) {
    const int INF = 1e9;
    int n = g.N;
    vector<int> dist(n, INF), parent(n, -1);
    dist[s] = 0;

    typedef pair<int, int> P; // (distance, node)
    priority_queue<P, vector<P>, greater<P>> pq;
    pq.push(make_pair(0, s));

    while (!pq.empty()) {
        P top = pq.top();
        pq.pop();
        int d = top.first;
        int u = top.second;
        if (d != dist[u])
            continue;

        for (size_t i = 0; i < g.adj[u].size(); ++i) {
            int v = g.adj[u][i].to;
            int w = g.adj[u][i].weight;
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                parent[v] = u;
                pq.push(make_pair(dist[v], v));
            }
        }
    }

    // Build next-hop table
    vector<int> nextHop(n, -1);
    for (int t = 0; t < n; ++t) {
        if (t == s || parent[t] == -1)
            continue;
        int cur = t;
        int prev = parent[cur];
        while (prev != -1 && prev != s) {
            cur = prev;
            prev = parent[cur];
        }
        if (prev == s)
            nextHop[t] = cur;
    }

    return make_pair(dist, nextHop);
}

//------------------------------------------
// Simulator
//------------------------------------------
struct Simulator {
    Graph g;
    int maxSteps;
    int bandwidthPerNode;
    vector<deque<Packet>> buffers;    // queue per router
    vector<vector<int>> routingTable; // next-hop table
    int nextPacketId;

    Simulator(int n, int bw = 1, int steps = 50)
        : g(n), maxSteps(steps), bandwidthPerNode(bw), nextPacketId(1) {
        buffers.resize(n);
        routingTable.assign(n, vector<int>(n, -1));
    }

    void add_link(int u, int v, int w = 1) { g.add_edge(u, v, w); }

    void build_routing_tables() {
        for (int u = 0; u < g.N; ++u) {
            pair<vector<int>, vector<int>> result = dijkstra_with_nexthop(g, u);
            routingTable[u] = result.second;
        }
    }

    void inject_packet(int src, int dst, int ttl = 16, string payload = "") {
        Packet p(nextPacketId++, src, dst, ttl, payload);
        buffers[src].push_back(p);
    }

    void run(bool verbose = true) {
        if (verbose)
            cout << "\nStarting simulation...\n";

        int delivered = 0;

        for (int step = 0; step < maxSteps; ++step) {
            bool anyPackets = false;
            if (verbose)
                cout << "\n--- Step " << step << " ---\n";

            vector<deque<Packet>> nextBuffers(g.N);

            for (int u = 0; u < g.N; ++u) {
                int forwarded = 0;

                while (forwarded < bandwidthPerNode && !buffers[u].empty()) {
                    anyPackets = true;
                    Packet p = buffers[u].front();
                    buffers[u].pop_front();

                    if (p.dst == u) {
                        cout << "Packet " << p.id << " delivered at Node " << u
                             << " [Payload: " << p.payload << "]\n";
                        delivered++;
                        forwarded++;
                        continue;
                    }

                    p.ttl--;
                    if (p.ttl <= 0) {
                        cout << "Packet " << p.id
                             << " dropped (TTL expired) at Node " << u << "\n";
                        forwarded++;
                        continue;
                    }

                    int nh = routingTable[u][p.dst];
                    if (nh == -1) {
                        cout << "No route from Node " << u << " to "
                             << p.dst << "\n";
                        forwarded++;
                        continue;
                    }

                    cout << "Node " << u << " forwards Packet " << p.id
                         << " -> Node " << nh << " (Destination: "
                         << p.dst << ")\n";

                    nextBuffers[nh].push_back(p);
                    forwarded++;
                }

                // Keep remaining packets waiting
                while (!buffers[u].empty()) {
                    nextBuffers[u].push_back(buffers[u].front());
                    buffers[u].pop_front();
                }
            }

            buffers.swap(nextBuffers);

            if (!anyPackets) {
                cout << "\nAll packets delivered or dropped.\n";
                break;
            }
        }

        cout << "\nSimulation complete. Total packets delivered: "
             << delivered << "\n";
    }
};

//------------------------------------------
// MAIN
//------------------------------------------
int main() {
    // Create simulator with 6 routers
    Simulator sim(6, 2, 20); // 6 nodes, 2 packets/node/step, max 20 steps

    // Define network topology
    sim.add_link(0, 1, 1);
    sim.add_link(1, 2, 1);
    sim.add_link(2, 3, 1);
    sim.add_link(3, 4, 1);
    sim.add_link(4, 5, 1);
    sim.add_link(0, 5, 5);
    sim.add_link(1, 4, 2);
    sim.add_link(0, 2, 4);

    sim.build_routing_tables();

    // Inject sample packets
    sim.inject_packet(0, 3, 20, "A->C");
    sim.inject_packet(5, 2, 20, "F->C");
    sim.inject_packet(1, 5, 20, "B->F");
    sim.inject_packet(2, 0, 20, "C->A");
    sim.inject_packet(0, 4, 20, "A->E");

    // Run simulation
    sim.run(true);

    return 0;
}
