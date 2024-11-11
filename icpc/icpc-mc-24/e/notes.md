# Problem E - Connectedness

### ICPC Mid-Central Regional Contest

[Link to Problem](https://mcpc24.kattis.com/contests/mcpc24/problems/connectedness)

You're given an undirected graph with N vertices and M edges. You want to know the number of edges added to the graph when it first becomes connected. A graph is considered connected if there is a path between every pair of vertices. If the graph does not become connected after adding all edges, you should output -1.

The problem can be solved by simulating the process of adding edges to the graph and using a Union-Find (Disjoint Set Union) data structure to keep track of connected components. As we add each edge:

- We connect the edges, making sure the size is updated correctly
- If the size of one of the nodes reaches the size of the graph, we know that the graph is fully connect, and we output
- If all edges are added and there is more than one component remaining, output -1.

*NOTE: We are using 1-based indexing, so we must allocate one more than the node count. We must also handle the edge case where there is one node and no edges as the graph is already connected.*

Pseudocode:

```python
nodeCount, edgeCount = input_line()
parent = list(nodeCount + 1)
sizes = list(nodeCount + 1)

if nodeCount == 1:
    output(0)
    exit()

for i in [1..nodeCounts + 1]:
    parent[i] = i
    sizes[i] = 1

for i in [0..edgeCount]:
    node1, node2 = input_line()

    if union(node1, node2):
        output(i + 1)
        exit()

function find(x):
    current = x
    while current != parent[current]:
        current = parent[current]
    return current

function union(a, b):
    rootA = find(a)
    rootB = find(b)

    if rootA == rootB:
        return false

    // make sure the smallest set points to the largest to be efficient
    if sizes[a] < sizes[b]:
        swap(a, b)

    sizes[a] += sizes[b];
    parent[b] = a;

    return (sizes[a] == nodeCount);


```