### From United Kingdom and Ireland Programming Contest 2019

# Problem I

## Integral Pyramid

Pascal's triangle is a marvel of the combinatorical world, and what's more you can easily build one for yourself at home.

The lowest row has $n$ numbers. The next row is staggered and has $n−1$ numbers, where the $i$-th is the sum of the $i$-th and the $i+1$-th on the previous row.

You can choose any positive integers for the lowest row, but the single cell on the top row needs to be equal to a given $x$. Is this possible?

### Input

The input consists of:
- The only line contains the number of rows, $n$ ($1 \leq n \leq 20$), and the value needed at the top, $x$ ($1 \leq x \leq 10^9$).

### Output

If a pyramid can be constructed, output all of the numbers on each row, starting from the top. Every number must be greater than or equal to 1.

Otherwise, output `impossible`.

## Editorial Answer

<details>
    <summary>Click for Simplifed Overview</summary>
    <ul>
        <li>A pyramid is made by adding numbers on lower rows together.</li>
        <li>We want to make a given number at the top. What should the numbers at the bottom be?</li>
    </ul>
</details>

<details>
    <summary>Click for Answer</summary>
    <b>Techniques</b>
    <ul>
        <li>Dynamic programming</li>
        <li>Cheekiness</li>
    </ul>
    <b>Algorithm</b>
    <ul>
        <li>
            Start by just putting all 1s in the bottom row.
            <ul>
                <li>This gives a sum of 2^(n-1) at the pinnacle.</li>
            </ul>
        </li>
        <li>
            Now, because there’s only one way for the first and last items to "contribute" to the final score, we can make up the difference in column 0 by adding to it.
            <ul>
                <li>As long as we make sure this addition is non-negative. If not, the test case is impossible.</li>
            </ul>
        </li>
        <li>Nicer ways are possible too, but why bother?</li>
    </ul>
</details>