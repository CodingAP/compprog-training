# Problem H - Guard Evaders

### ICPC Mid-Central Regional Contest

[Link to Problem](https://mcpc24.kattis.com/contests/mcpc24/problems/guardevaders)

This program determines whether all players can successfully pass through a row of guards without getting caught, based on specific orientation rules for each guard. Each guard faces left (L), forward (F), or right (R). A player can attempt to pass through a gap between guards i and i+1, but is caught if guard i is facing right or guard i+1 is facing left. After a player successfully passes through a gap, guard i turns to face right and guard i+1 turns to face left, preventing any subsequent successful passage through the same gap.

The solution uses Breadth-First Search (BFS) to explore all possible sequences of moves, treating each configuration of guard orientations and the number of players who have passed as a unique state. Starting with the initial guard configuration and zero players passed, the program checks if a player can safely pass through any of the gaps. For each safe gap, it updates the guard orientations, creates a new state, and adds this state to the queue if it hasn’t been visited before. If BFS reaches a state where all players have successfully passed, it outputs 1 and terminates. If the BFS completes without finding such a state, it outputs 0, indicating that not all players can pass without getting caught.

Pseudocode:

```python
g, p = input_nums()
initial_guards = input_line()

queue = [(initial_guards, 0)]
visited = set()
visited.add((initial_guards, 0))

while queue is not empty:
    guards, players_passed = queue.pop(0)
    
    if players_passed == p:
        output(1)
        exit

    for i in [0..g - 2]:
        if guards[i] != 'R' and guards[i+1] != 'L':
            new_guards = guards.copy()
            new_guards[i] = 'R'
            new_guards[i + 1] = 'L'
            new_state = (new_guards, players_passed + 1)
            
            if new_state not in visited:
                queue.append(new_state)
                visited.add(new_state)

output(0)
```