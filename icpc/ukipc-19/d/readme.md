### From United Kingdom and Ireland Programming Contest 2019

# Problem D

## Dome Construction

The world’s largest indoor water park is built inside a hemispherical dome that was once used as an aircraft hangar. The park attracts more than 10,000 visitors per day and is big enough that it even has its own tropical micro-climate with clouds forming inside.

Management would like to expand business operations by opening another branch in the dome of your local cathedral. The micro-climate is a key selling point, so to really capitalise on the cathedral they asked you to expand the dome’s radius so that it contains at least a given number of clouds. A cloud is contained if its centre is on or inside the boundary of the dome.

You are a cloud engineer by trade, and hence a competent meteorologist. You already identified several potential clouds close by and plotted them in three dimensions relative to the centre of the current structure. In order to capture enough of them, how large do you need to make the radius of the dome?

### Input

The input consists of:
- The first line contains the number of clouds you found, $n$, and the number that must be contained, $k$, respectively ($1 \leq k \leq n \leq 10^5$).
- The next n lines each contain three real numbers $x_i$, $y_i$, $z_i$, the coordinates of the $i$th cloud relative to the centre of the dome ($0 ≤ |x_i|, |y_i|, |z_i| ≤ 10^6$). Every cloud has a non-negative $y$-coordinate.

### Output

Output the minimum radius of the dome required to enclose at least k points. Your answer must be accurate to an absolute or relative error of $10^{−6}$.

## Editorial Answer

<details>
    <summary>Click for Simplifed Overview</summary>
    <ul>
        <li>There are some points in 3D space</li>
        <li>We have a dome sited at the origin</li>
        <li>How big do we have to make the dome to capture K or more of the points?</li>
    </ul>
</details>

<details>
    <summary>Click for Answer</summary>
    <b>Techniques</b>
    <ul>
        <li>Sorting</li>
        <li>Geometry</li>
    </ul>
    <b>Algorithm</b>
    <ul>
        <li>The actual positions of the points don’t matter, just how far they are from the origin. Map the points to hypot(x,y,z) or hypot(hypot(x,y),z) if your programming language doesn’t take 3 arguments.</li>
        <li>
            Now sort them. This will put the closest K distances as the first K elements of the array!
            <ul>
                <li>So now you can just print the Kth element.</li>
            </ul>
        </li>
        <li>Or: binary search on the answer (a very versatile algorithm) and count how many points match to decide to go lower/higher.</li>
    </ul>
</details>