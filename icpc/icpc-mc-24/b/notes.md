# Problem B - Always Know Where Your Towel Is

### ICPC Mid-Central Regional Contest

[Link to Problem](https://mcpc24.kattis.com/contests/mcpc24/problems/alwaysknowwhereyourtowelis)

Arthur needs to find a locker number S that can be opened by more than one combination of button presses on an app. Each button displays a distinct positive integer, and pressing any subset of these buttons unlocks a locker numbered by the sum of those integers. Not every locker number can be accessed, but at least one locker is guaranteed to be unlockable by multiple distinct combinations.

The solution uses a meet-in-the-middle strategy to efficiently find a locker number with duplicate combinations. We divide the list of button values into two halves. For each half, we generate all possible subset sums, creating two lists of sums. Using a hash map, we track each subset sum generated from the first half and check if any subset sum from the second half produces a repeated locker number when combined with the sums from the first half. This approach reduces the problem’s search space and leverages hash maps to efficiently detect duplicate sums, ensuring we identify a locker with multiple combinations quickly.

Pseudocode:

```python
```