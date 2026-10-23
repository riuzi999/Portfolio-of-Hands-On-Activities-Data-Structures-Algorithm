#include <string>
#include <vector>
#include <iostream>
#include <set>
#include <map>
#include <queue>

template <typename T>
class Graph;

template <typename T>
struct Edge
{
size_t src;
size_t dest;
T weight;

inline bool operator<(const Edge<T> &e) const
{
return this->weight < e.weight;
}

inline bool operator>(const Edge<T> &e) const
{
return this->weight > e.weight;
}
};

template <typename T>
std::ostream &operator<<(std::ostream &os, const Graph<T> &G);

template <typename T>
class Graph
{
public:
Graph(size_t N) : V(N) {}

auto vertices() const
{
return V;
}

auto &edges() const
{
return edge_list;
}

void add_edge(Edge<T> &&e)
{
if (e.src >= 1 && e.src <= V &&
e.dest >= 1 && e.dest <= V)
edge_list.emplace_back(e);
else
std::cerr << "Vertex out of bounds" << std::endl;
}

auto outgoing_edges(size_t v) const
{
std::vector<Edge<T>> edges_from_v;
for (auto &e : edge_list)
{
if (e.src == v)
{
edges_from_v.emplace_back(e);
}
}
return edges_from_v;
}

template <typename U>
friend std::ostream &operator<<(std::ostream &os, const Graph<U> &G);

private:
size_t V;
std::vector<Edge<T>> edge_list;
};

// FIX 1: Forward declaration - moved here and completed after Graph class
template <typename T>
std::ostream &operator<<(std::ostream &os, const Graph<T> &G)
{
// FIX 2: Changed i < G.vertices() to i <= G.vertices() to include all vertices
for (auto i = 1; i <= G.vertices(); i++)
{
os << i << ":\t";
auto edges = G.outgoing_edges(i);
for (auto &e : edges)
os << "{" << e.dest << ": " << e.weight << "}, ";
os << std::endl;
}
// FIX 3: Added missing return statement
return os;
}

template <typename T>
auto create_reference_graph()
{
Graph<T> G(9);
std::map<unsigned, std::vector<std::pair<size_t, T>>> edges;
edges[1] = {{2, 2}, {5, 3}};
edges[2] = {{1, 2}, {5, 5}, {4, 1}};
edges[3] = {{4, 2}, {7, 3}};
edges[4] = {{2, 1}, {3, 2}, {5, 2}, {6, 4}, {8, 5}};
edges[5] = {{1, 3}, {2, 5}, {4, 2}, {8, 3}};
edges[6] = {{4, 4}, {7, 4}, {8, 1}};
edges[7] = {{3, 3}, {6, 4}};
edges[8] = {{4, 5}, {5, 3}, {6, 1}};

for (auto &i : edges)
for (auto &j : i.second)
G.add_edge(Edge<T>{i.first, j.first, j.second});

return G;
}

template <typename T>
auto breadth_first_search(const Graph<T> &G, size_t start)
{
std::queue<size_t> queue;
std::vector<size_t> visit_order;
std::set<size_t> visited;

// FIX 4: Changed hardcoded 1 to use the start parameter
queue.push(start);
visited.insert(start);

while (!queue.empty())
{
auto current_vertex = queue.front();
queue.pop();

visit_order.push_back(current_vertex);

for (auto e : G.outgoing_edges(current_vertex))
{
// FIX 5: Check if vertex has been visited BEFORE pushing to queue
// This prevents duplicate entries in the queue
if (visited.find(e.dest) == visited.end())
{
visited.insert(e.dest);
queue.push(e.dest);
}
}
}

return visit_order;
}

template <typename T>
void test_BFS()
{
// Create an instance of and print the graph
auto G = create_reference_graph<unsigned>();
std::cout << G << std::endl;

// Run BFS starting from vertex ID 1 and print the order
// in which vertices are visited.
std::cout << "BFS Order of vertices: " << std::endl;
auto bfs_visit_order = breadth_first_search(G, 1);
for (auto v : bfs_visit_order)
std::cout << v << std::endl;
}

int main()
{
using T = unsigned;
test_BFS<T>();
return 0;
}