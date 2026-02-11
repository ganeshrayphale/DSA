

#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <limits>   
#include <string>
#include <iomanip>  

using namespace std;


struct Packet {
    int id;
    int src;
    int dst;
    int ttl;
    int startTime; 
    string payload;

    Packet(int _id, int _src, int _dst, int _ttl, int _start, string _p = "")
        : id(_id), src(_src), dst(_dst), ttl(_ttl), startTime(_start), payload(_p) {}
};

struct Edge {
    int to;
    int weight; 
    Edge(int _to, int _w) : to(_to), weight(_w) {}
};

struct Graph {
    int N;
    vector<vector<Edge>> adj;
    Graph(int n = 0) : N(n), adj(n) {}

    void add_edge(int u, int v, int w = 1) {
        adj[u].push_back(Edge(v, w));
        adj[v].push_back(Edge(u, w)); 
    }

    
    void remove_edge(int u, int v) {
        
        for (auto it = adj[u].begin(); it != adj[u].end(); ++it) {
            if (it->to == v) {
                adj[u].erase(it);
                break;
            }
        }
        
        for (auto it = adj[v].begin(); it != adj[v].end(); ++it) {
            if (it->to == u) {
                adj[v].erase(it);
                break;
            }
        }
    }
};


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


struct Simulator {
    Graph g;
    int bandwidthPerNode;
    int maxBufferSize; 
    vector<deque<Packet>> buffers;
    vector<vector<int>> routingTable;
    int nextPacketId;
    int current_step; 

    
    int stat_delivered;
    int stat_dropped_ttl;
    int stat_dropped_congestion;
    double stat_total_latency;

    Simulator(int n, int bw = 1, int _maxBuff = 10) 
        : g(n), bandwidthPerNode(bw), maxBufferSize(_maxBuff), nextPacketId(1), current_step(0),
          stat_delivered(0), stat_dropped_ttl(0), stat_dropped_congestion(0), stat_total_latency(0.0) {
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

    
    void break_link(int u, int v) {
        if (u >= g.N || v >= g.N || u < 0 || v < 0) {
            cout << "Invalid link: nodes " << u << " or " << v << " do not exist.\n";
            return;
        }
        cout << "\n*** DYNAMIC EVENT: LINK FAILURE " << u << " <-> " << v << " at Step " << current_step << " ***\n";
        g.remove_edge(u, v);
        cout << "All routers rebuilding routing tables...\n";
        build_routing_tables();
        cout << "Routing tables updated.\n";
    }

    
    void inject_packet(int src, int dst, int ttl = 16, string payload = "") {
        if (src >= g.N || dst >= g.N || src < 0 || dst < 0) {
            cout << "Invalid packet: nodes " << src << " or " << dst << " do not exist.\n";
            return;
        }
        Packet p(nextPacketId++, src, dst, ttl, current_step, payload);
        buffers[src].push_back(p);
        cout << "Packet " << p.id << " injected at Node " << src << " (to " << dst << ") at step " << current_step << "\n";
    }

    
    void print_statistics() {
        cout << "\n--- SIMULATION STATISTICS (at Step " << current_step << ") ---\n";
        cout << "Total Packets Delivered: " << stat_delivered << "\n";
        cout << "Total Packets Dropped (TTL): " << stat_dropped_ttl << "\n";
        cout << "Total Packets Dropped (Congestion): " << stat_dropped_congestion << "\n";
        cout << "Total Packets Processed: " << (stat_delivered + stat_dropped_ttl + stat_dropped_congestion) << "\n";
        
        cout << fixed << setprecision(2);
        if (stat_delivered > 0) {
            cout << "Average Packet Latency: "
                 << (stat_total_latency / stat_delivered) << " steps\n";
        } else {
            cout << "Average Packet Latency: N/A (0 delivered)\n";
        }
        cout << "------------------------------------------\n" << endl;
    }


    void run(int steps_to_run, bool verbose = true) {
        if (verbose)
            cout << "\nRunning simulation for " << steps_to_run << " steps...\n";

        for (int i = 0; i < steps_to_run; ++i) {
            int step = current_step;
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
                        if (verbose) cout << "Packet " << p.id << " DELIVERED at Node " << u
                                          << " [Payload: " << p.payload << ", Latency: " << (step - p.startTime) << "]\n";
                        stat_delivered++;
                        stat_total_latency += (step - p.startTime);
                        forwarded++;
                        continue;
                    }

                    // 2. Check TTL
                    p.ttl--;
                    if (p.ttl <= 0) {
                        if (verbose) cout << "Packet " << p.id << " DROPPED (TTL expired) at Node " << u << "\n";
                        stat_dropped_ttl++;
                        forwarded++;
                        continue;
                    }

                    // 3. Find Next Hop
                    int nh = routingTable[u][p.dst];
                    if (nh == -1) {
                        if (verbose) cout << "Packet " << p.id << " DROPPED (No route) from Node " << u << " to " << p.dst << "\n";
                        // This counts as a TTL drop for simplicity, or add a new stat
                        stat_dropped_ttl++; 
                        forwarded++;
                        continue;
                    }

                    // 4. Check Congestion at Next Hop
                    if (nextBuffers[nh].size() >= maxBufferSize) {
                        if (verbose) cout << "Packet " << p.id << " DROPPED (Congestion) at next hop Node " << nh << "\n";
                        stat_dropped_congestion++;
                    } else {
                        // 5. Forward Packet
                        if (verbose) cout << "Node " << u << " forwards Packet " << p.id << " -> Node " << nh << " (for " << p.dst << ")\n";
                        nextBuffers[nh].push_back(p);
                    }
                    forwarded++;
                }

                // Keep remaining packets in the 'u' buffer waiting
                while (!buffers[u].empty()) {
                    nextBuffers[u].push_back(buffers[u].front());
                    buffers[u].pop_front();
                }
            }

            buffers.swap(nextBuffers); // Atomic update of all buffers for the next step
            current_step++; // Advance global time

            if (!anyPackets && verbose) {
                cout << "All queues empty. No packets to process.\n";
            }
        }
        cout << "\nSimulation advanced to Step " << current_step << ".\n";
    }
};

//------------------------------------------
// MAIN (Interactive Menu)
//------------------------------------------

void show_menu() {
    cout << "\n========= Network Simulator Menu =========\n";
    cout << "1. Inject Packet\n";
    cout << "2. Break Link\n";
    cout << "3. Run Simulation (N steps)\n";
    cout << "4. Show Statistics\n";
    cout << "5. Quit\n";
    cout << "==========================================\n";
    cout << "Enter choice: ";
}

int main() {
    // Create simulator: 6 routers, 2 packets/node/step bandwidth, 5-packet buffer size
    Simulator sim(6, 2, 5); 

    // Define network topology
    cout << "Building network topology...\n";
    sim.add_link(0, 1, 1);
    sim.add_link(1, 2, 1);
    sim.add_link(2, 3, 1);
    sim.add_link(3, 4, 1);
    sim.add_link(4, 5, 1);
    sim.add_link(0, 5, 10); // This is a "slow" link
    sim.add_link(1, 4, 3);
    sim.add_link(0, 2, 4);

    sim.build_routing_tables();
    cout << "Network ready.\n";

    // Inject some initial packets
    sim.inject_packet(0, 3, 20, "A->D");
    sim.inject_packet(5, 2, 20, "F->C");
    sim.inject_packet(1, 5, 20, "B->F"); // This one will take the "slow" 1-4-5 path first
    
    int choice = 0;
    while (true) {
        show_menu();
        if (!(cin >> choice)) {
            cout << "Invalid input. Please enter a number.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        switch (choice) {
            case 1: { // Inject Packet
                int src, dst, ttl;
                string payload;
                cout << "Enter Src Node (0-5): "; cin >> src;
                cout << "Enter Dst Node (0-5): "; cin >> dst;
                cout << "Enter Payload (string): "; cin >> payload;
                cout << "Enter TTL (e.g., 16): "; cin >> ttl;
                sim.inject_packet(src, dst, ttl, payload);
                break;
            }
            case 2: { // Break Link
                int u, v;
                cout << "Enter first node (0-5): "; cin >> u;
                cout << "Enter second node (0-5): "; cin >> v;
                sim.break_link(u, v);
                break;
            }
            case 3: { // Run Simulation
                int steps;
                cout << "Enter number of steps to run: "; cin >> steps;
                sim.run(steps, true); // Run with verbose output
                break;
            }
            case 4: { // Show Statistics
                sim.print_statistics();
                break;
            }
            case 5: { // Quit
                cout << "Exiting simulator. Final Statistics:\n";
                sim.print_statistics();
                return 0;
            }
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}