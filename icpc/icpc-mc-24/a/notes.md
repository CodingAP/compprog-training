# Problem A - Airfare Grants

### ICPC Mid-Central Regional Contest

[Link to Problem](https://mcpc24.kattis.com/contests/mcpc24/problems/airfaregrants)

In this problem, we are given a list of plane ticket prices. Our goal is to find the smallest amount that we have to pay given that the sponsors will reimburse our ticket. The strategy is to find the biggest ticket price for the reimbursement and purchase the cheapest ticket. The reimbursement is calculated as `max(prices) / 2`, so all we need to do is to subtract the minimum price with this reimbursement, make sure to cap the minimum at 0 (negative dollars doesn't make sense)...

Pseudocode:

```python
prices = input_list()
reimbursement = max(prices) / 2
payment = min(prices) - reimbursement

if payment < 0
    payment = 0

output(payment)
```