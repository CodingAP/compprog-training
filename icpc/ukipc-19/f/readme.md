### From United Kingdom and Ireland Programming Contest 2019

# Problem F

## Feeding Seals

You are in charge of feeding the seals in the Welsh Mountain Zoo. This involves purchasing buckets of fish and allocating them to volunteers to trek into the enclosure and distribute fairly to the blubbery residents.

The buckets of fish are already set out. Each volunteer can be assigned to carry either one or two of these buckets, as long as the combined weight of the buckets is small enough.

How many volunteers will you need to distribute all of the fish in one trip?

### Input

The input consists of:
- The first line contains the number of buckets to be delivered, $n$ ($1 \leq n \leq 10^5$), and the integer carrying capacity of a volunteer, $c$ ($1 \leq c \leq 10^9$).
- The second line contains the integer weights of each of the $n$ buckets, $w_1$ . . . $w_n$ ($1 \leq w \leq c$).

### Output

Output the minimum number of volunteers required to deliver all of the buckets of fish.

## Editorial Answer

<details>
    <summary>Click for Simplifed Overview</summary>
    <ul>
        <li>
            We can give a person 2 buckets if their combined weight is less than or equal to some constant C.
            <ul>
                <li>But if we can’t do that, or don’t want to, we can give them just one bucket.</li>
            </ul>
        </li>
        <li>To carry N buckets of various weights, how many people do we need?</li>
    </ul>
</details>

<details>
    <summary>Click for Answer</summary>
    <b>Techniques</b>
    <ul>
        <li>Sorting</li>
        <li>Two pointers</li>
    </ul>
    <b>Algorithm</b>
    <ul>
        <li>
            This is a class of problem called “two pointers”. If we sort all of the weights, we can solve it with a kind of recursive argument:
            <ul>
                <li>If anything is going to be paired up, it makes sense to use the smallest item as part of a pair.</li>
                <li>
                    We should also use as big an item as possible with the smallest item.
                    <ul>
                        <li>If this can be the largest item, that’s the best option. We throw both the start and end of the array away.</li>
                        <li>Otherwise, we can never pair the largest item, so we throw it away.</li>
                    </ul>
                </li>
                <li>Use two pointers into the ends of the array (or a deque) to implement this efficiently.</li>
            </ul>
        </li>
    </ul>
</details>