### From United Kingdom and Ireland Programming Contest 2019

# Problem B

## Ballpark Estimate

Giving the right level of detail is an important skill for efficient communication. Sometimes, only the high-level message matters.

For example, whenever a person asks for a number, often they just want an estimate. If the value is in the millions, they do not need to know the precise number of hundreds and tens. Likewise, if the value is in the billions, they do not necessarily care about little things like millions.

Given a (possibly very large) number, print its numerically closest representation that has only one digit other than trailing zeroes.

The closeness of the representation $r$ of a number $n$ is defined by abs$(r − n)$.

### Input

The input consists of:
- one line with the positive integer $n$ ($1 \leq n \leq 10^{18}$).

### Output

Output the closest number to n with exactly one significant (non-zero) figure. If there are two equally-close answers, print the larger one.

## Editorial Answer

<details>
    <summary>Click for Simplifed Overview</summary>
    <ul>
        <li>Estimate a number to one significant figure (exactly one nonzero digit).</li>
        <li>
            The number fits inside a 64-bit integer
            <ul>
                <li>(c++: int64_t)</li>
                <li>(java: long)</li>
                <li>(python: number)</li>
            </ul>
        </li>
    </ul>
</details>

<details>
    <summary>Click for Answer</summary>
    <b>Techniques</b>
    <ul>
        <li>Logarithms</li>
        <li>Rounding</li>
    </ul>
    <b>Algorithm</b>
    <ul>
        <li>
            If we reduce the number to {x}.{abcdefg} where x is a single-digit number, we can just round it and add zeroes back on later. We just need to make sure to keep the extra information after the decimal point.
<pre>while (number >= 10) { tens++, number /= 10.0; }
number = int(round(number))
while (tens > 0) {tens--, number *= 10; }</pre>
        </li>
        <li>
            Or (since only the first two digits matter):
            <pre>int(round(int(s[0:2]) / 10.0)) * (10**(len(s)-3))</pre>
        </li>
    </ul>
</details>