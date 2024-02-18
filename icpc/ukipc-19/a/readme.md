### From United Kingdom and Ireland Programming Contest 2019

# Problem A

## Automatic Accountant

The bank you work in has purchased an advanced technological solution to the problems it has with counting money deposited by clients. The machine works by running each individual coin along a sloped track. At every integer multiple of centimetres along, starting from 1$cm$, there is a slot in the track with a bucket underneath.

The slot will allow a coin to fall in, if the thickness of the coin (in millimetres) is **less than or equal to** the width of the slot (also in millimetres), and the mass of the coin (in grams) is **greater than or equal to** the trigger mass of the slot (also in grams).

Since the slots are spaced 1$cm$ apart centre-to-centre, and since there can be a large number of coins (or other metal shapes) inserted, the amount of wear on the track will depend on total distance travelled by all coins.

Given a list of the coins that will be deposited, what total distance will they travel, in centimetres?

### Input

The input consists of:

- one line containing the number of slots, $s$ ($1 \leq s \leq 10^5$).
- $s$ further lines, the $i$th line containing the width of a slot in millimetres and trigger mass in grams of the $i$th slot, $a_i$ and $b_i$ respectively ($1 \leq a, b \leq 10^5$).
- one line containing the integer $c$ ($1 \leq c \leq 10^5$), the number of coins.
- $c$ further lines, the $j$th line containing the thickness in millimetres and mass in grams of the $j$th coin, $u_i$ and $v_i$ respectively ($1 \leq u, v \leq 10^5$).

It is guaranteed that every coin will be able to fall into at least one slot.

### Output

Output the total distance in centimetres travelled by coins.

## Editorial Answer

<details>
    <summary>Click for Simplifed Overview</summary>
    <ul>
        <li>We represent a coin with coords (X,Y) pair. A coin falls into a slot (U,V) if X≤U and Y≥V.</li>
        <li>For each coin, find the first slot in the list that matches and add its index to the answer.</li>
    </ul>
</details>

<details>
    <summary>Click for Answer</summary>
    <b>Techniques</b>
    <ul>
        <li>Segment trees</li>
        <li>KD trees</li>
    </ul>
    <b>Algorithm</b>
    <ul>
        <li>
            Keep a segment tree mapping for one axis:
            <ul>
                <li>For all slots with thickness ≥ T,</li>
                <li>Which one has the lowest index? (min-segment-tree)</li>
                <li>Initially this tree is empty</li>
            </ul>
        </li>
        <li>
            Sort the coins and slots along the other axis
            <ul>
                <li>Iterate through both in parallel, inserting slots as their trigger masses become eligible for the current coin.</li>
                <li>Use the tree to find the slot with the smallest index, out of those with the right mass range.</li>
            </ul>
        </li>
        <li>Alternatively, use a KD / quad tree</li>
    </ul>
</details>