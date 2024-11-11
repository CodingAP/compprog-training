### From 2016 Rocky Mountain Regional Programming Contest 2016

# Problem A

## FizzBuzz

According to Wikipedia, FizzBuzz is a group word game for children to teach them about division. This may or may not be true, but this question is generally used to ~~torture~~ screen young computer science graduates during programming interviews.

Basically, this is how it works: you print the integers from 1 to $N$, replacing any of them divisible by $X$ with `Fizz` or, if they are divisible by $Y$, with `Buzz`. If the number is divisible by both $X$ and $Y$, you print `FizzBuzz` instead.v

Check the samples for further clarification.

### Input

Input file will contain a single test case. Each test case will contain three integers on a single line, $X$, $Y$ and $N$ ($1 \leq X < Y \leq N \leq 100$).

### Output

Print integers from 1 to $N$ in order, each on its own line, replacing the ones divisible by $X$ with `Fizz`, the ones divisible by $Y$ with `Buzz` and ones divisible by both $X$ and $Y$ with `FizzBuzz`.

## Editorial Answer

<details>
    <summary>Click for Simplifed Overview</summary>
    It's FizzBuzz with different divisors
</details>

<details>
    <summary>Click for Answer</summary>
    Straightforward - do exactly what you are asked.
    (that is all the editorial provided cause... you know)
</details>