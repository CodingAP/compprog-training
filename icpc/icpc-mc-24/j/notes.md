# Problem J - Pascal Multiple

### ICPC Mid-Central Regional Contest

[Link to Problem](https://mcpc24.kattis.com/contests/mcpc24/problems/pascalmultiple)

You are given two integers N and K. The task is to count how many entries in the first N+1 rows of Pascal's triangle are divisible by K. Each entry C(i,j) in Pascal's triangle represents a binomial coefficient, which can be computed using the formula: C(i+1,j)=C(i,j)+C(i,j−1) with out-of-bounds entries treated as 0.

Pascal's triangle grows quickly in value, so to avoid handling excessively large numbers, we can use modular arithmetic by calculating each entry modulo K. This allows us to efficiently check if each entry is divisible by K (i.e., if it equals 0 modulo K) without the numbers themselves growing large.

If K is 1, then we can skip the loops as we are essentially looking for how many entries is in the generated Pascal's triangle, which is (N+1)×(N+2)/2.

Pseudocode:

```python
n, k = input_numbers()

if k == 1:
    output((n + 1) * (n + 2) / 2)
    exit()

lastRow = [1]
count = 0

for i in [1..n]:
    row = list(i + 1).fill(1)
    
    for j from 1 to i - 1:
        row[j] = (lastRow[j] + lastRow[j - 1]) % k

    for j from 0 to i:
        if row[j] % k == 0:
            count += 1

    lastRow = row

output(count)
```