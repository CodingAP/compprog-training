# Problem O - Which Number Kind Is It?

### ICPC Mid-Central Regional Contest

[Link to Problem](https://mcpc24.kattis.com/contests/mcpc24/problems/whichnumberkindisit2)

To solve this problem, we first read the number of test cases, T, and prepare to handle each case individually. For each test case, we read an integer N and determine whether it is an odd number, a perfect square, both, or neither. To check if N is odd, we use the condition N % 2 != 0. For determining if N is a perfect square, we calculate its integer square root, and verify if squaring this value returns N. Based on these properties, we classify each number: if N is both odd and a perfect square, we record "OS" for the test case; if it’s only odd, we record "O"; if it’s only a perfect square, we record "S"; and if it’s neither, we record "EMPTY".

Pseudocode:

```python
T = input()

for i in [0..T]:
    n = input()

    isOdd = (n % 2 != 0)

    sqrtN = int(sqrt(N))
    isSquare = (sqrtN * sqrtN == N)

    result = ''

    if isOdd:
        result += 'O'
    if isSquare:
        result += 'S'
    
    if result == '':
        result = 'EMPTY'

    output(result)
```