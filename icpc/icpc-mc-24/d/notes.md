# Problem D - Cascade Centrality

### ICPC Mid-Central Regional Contest

[Link to Problem](https://mcpc24.kattis.com/contests/mcpc24/problems/cascadecentrality)

This program calculates the mean cascade centrality of nodes in a tree. The tree is represented by an undirected graph G=(V,E) with N nodes. The cascade centrality for a node i is defined by summing over all other nodes j in the tree, using the product of node degrees along the unique path from i to j. For each node, we start with a base centrality of 1.0 and add terms based on paths to other nodes.

After reading the number of nodes N, we handle the special case where N=1, outputting a mean centrality of 1.0 since a single node has no other connections. For larger trees, we build an adjacency list from the input edges, representing the tree structure, and calculate the degree of each node. Using BFS from each node i, we find paths to every other node j in the tree. For each path, we compute the product of degrees along the path and add the inverse of this product to the centrality of i.Summing the cascade centralities for all nodes gives the total centrality, which we then divide by N to compute the mean.

Pseudocode:

```python
n = input_num()

if n == 1:
    return 1

tree = list(n + 1, [])
for i in [0..n]:
    u, v = input_nums()
    tree[u].append(v)
    tree[v].append(u)

degrees = list(n + 1, 0)
for node in [1..n + 1]:
    degrees[node] = len(tree[node])

totalCentrality = 0

for i in [1..n + 1]:
    cascadeCentrality = 1
    visited = list(n + 1, false)
    
    queue = [(i, 1)]
    visited[i] = true

    while queue:
        current, productOfDegrees = queue.pop(0)

        for neighbor in tree[current]:
            if not visited[neighbor]:
                visited[neighbor] = true
                newProduct = productOfDegrees * degrees[neighbor]
                cascadeCentrality += 1 / newProduct
                queue.append((neighbor, newProduct))

    totalCentrality += cascadeCentrality

output(totalCentrality / n)
```