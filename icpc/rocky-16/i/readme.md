### From 2016 Rocky Mountain Regional Programming Contest 2016

# Problem I

## Stacking Cups

You are programming a cup stacking module for your robot. This robot is equiped with several sensors that can accurately determine the radius and color of a cup. The problem is that there is a glitch in the robot's core routine that processess sensor inputs so the radius is doubled, if the result of the color sensor arrives to the routine after the radius.

For instance, for a red cup with a radius of 5 units, your module will receive either "red 5" or "10 red" message.

Given a list of messages from the core routine, each describing a different cup, can you put the cups in order of the smallest to the largest?

### Input

The first line of the input file contains an integer $N$, the number of cups ($1 \leq N \leq 20$). Next $N$ lines will contain two tokens each, either as "color radius" or "diameter color". The radius of a cup $R$ will be a positive integer less than 1000. The color of a cup $C$ will be a non-empty string of lower case English letters of length at most 20. All cups will be different in both size and color.

### Output

Output colors of cups, one color per line, in order of increasing radius.

## Editorial Answer

<details>
    <summary>Click for Simplifed Overview</summary>
    We are sorting different colored cups by the size of it's radius with varying types of inputs
</details>

<details>
    <summary>Click for Answer</summary>
    <ul>
        <li>Sorting problem.</li>
        <li>Trickiest part - reading input correctly.</li>
    </ul>
</details>