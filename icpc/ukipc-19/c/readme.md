### From United Kingdom and Ireland Programming Contest 2019

# Problem C

## Crooked Dealing

This week you started a flashy new job in Leeds as a poker dealer. Your task will be to hand out the cards for games. The base pay is not particularly good, but you found out that you can earn a lot from tips if you deal the cards well.

The most generous customers prefer that their opponents at the table don’t receive any pairs of cards with the same number; so to keep them happy you will make sure this never happens.

You already know the numbers on every card in the pile , and the number of cards any player must have in their hand. Find how many hands you can make at once without introducing a pair.

### Input

The input consists of:
- A line with two integers $n$ and $h$ ($1 \leq h \leq n \leq 10^6$), the number of cards in the pile, and the number of cards in a hand.
- A line with $n$ integers $v_1$, . . . , $v_n$ ($1 \leq v_i \leq 10^6$ for all $i$), the numbers on the cards in noparticular order.

### Output

If it is not possible to make any hands at all without introducing a pair, output `impossible`.

Otherwise, output $k$ lines (where $k$ is the maximum possible number of players) each containing $h$ numbers from the input. You may not use any number any more times than it appears in $v$.

If there are multiple answers with a maximum value of $k$, you may output any one of them.

## Editorial Answer

<details>
    <summary>Click for Simplifed Overview</summary>
    <ul>
        <li>Partition some numbers into as many groups of K as possible,</li>
        <li><b>But</b> make sure the name number never shows up in the same partition twice</li>
    </ul>
</details>

<details>
    <summary>Click for Answer</summary>
    <b>Techniques</b>
    <ul>
        <li>Greedy algorithms</li>
        <li>Priority queues</li>
    </ul>
    <b>Algorithm</b>
    <ul>
        <li>Use a hashmap (or Python’s Counter class) to get the frequency of all the cards. It’s always best to try and get rid of the most frequent card as fast as possible.</li>
        <li>Put the cards into a priority queue ordered by frequency.</li>
        <li>
            While the queue has enough elements to make a hand:
            <ul>
                <li>Pop the largest K items from the queue</li>
                <li>Add the values to the answer</li>
                <li>Reduce the frequencies by one</li>
                <li>
                    Reinsert the items and new frequencies into the queue
                    <ul>
                        <li>They may not have the same ordering in the queue afterwards.</li>
                    </ul>
                </li>
            </ul>
        </li>
        <li>Or, binary search on the answer X, lay the numbers out into a grid with X columns, and the answer is the columns of the grid.</li>
    </ul>
</details>