# Problem G - Enchanted Maze

### ICPC Mid-Central Regional Contest

[Link to Problem](https://mcpc24.kattis.com/contests/mcpc24/problems/enchantedmaze)

Mila and Liam need to escape a maze with various obstacles, switches, and constraints on their movement. Each twin starts at a designated position, and they must reach either of two exit positions at the same time. The twins must move in the same direction at each step, though either may be blocked by boundaries, obstacles, or pits. The maze includes switches that control specific obstacles, raising or lowering them as needed. Each switch is toggled when a twin steps onto it, affecting the corresponding obstacles (e.g., 'A'/'a' for switch '1'). Mila and Liam cannot occupy the same cell, and they cannot be on a switch and a corresponding obstacle at the same time.

To find the shortest path to escape, we use Breadth-First Search (BFS), treating each state as a unique configuration defined by the positions of Mila and Liam, the current state of toggleable obstacles, and the time elapsed. The toggle state of obstacles is tracked through a bitmask that updates whenever a switch is activated. For each BFS step, we attempt to move Mila and Liam in all four directions, checking that their new positions don’t conflict with obstacles or each other. The BFS terminates when both twins reach any valid combination of exit positions simultaneously, at which point we return the shortest time taken for them to escape.

Pseudocode:

```python
not yet
```