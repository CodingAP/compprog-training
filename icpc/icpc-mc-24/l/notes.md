# Problem L - Sauna

### ICPC Mid-Central Regional Contest

[Link to Problem](https://mcpc24.kattis.com/contests/mcpc24/problems/sauna)

Kaisa and her friends are going to the sauna, and each has a preferred temperature range represented as an inclusive interval [ai,bi] in millidegrees Celsius. You need to determine the set of temperatures that satisfy all individuals' preferences, if any. Specifically, you should:

- Output the number of temperatures that fall within everyone’s preferred range.
- Output the lowest acceptable temperature if there is a valid range.

If no temperature can satisfy everyone, output "bad news".

Initialize:
- Read the integer n for the number of people.
- Read the first person's preferred range and set minNum and maxNum to establish the initial common range.

Process Each Range:
- For each additional person:
  - Read their range
  - Check if this range overlaps with the current common range.
    - If there’s overlap, update the global minimum to be the higher of the minimums, and the global maximum to be the lower of the maximums.
    - If there’s no overlap, output "bad news" and terminate, as no common temperature exists for everyone.

If a common range exists after processing all inputs, output the number of valid temperatures in the range, (maxNum - minNum + 1), and the lowest temperature in the range, minNum.

Pseudocode:

```python
n = input()

minNum, maxNum = input_nums()

for i in [0..n-1]:
    a, b = input_nums()

    if maxNum >= a and b >= minNum:
        minNum = max(a, minNum)
        maxNum = min(b, maxNum)
    else:
        output("bad news")
        exit()

output((maxNum - minNum + 1), minNum)
```