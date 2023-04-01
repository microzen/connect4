# Connect4 Winning

Created: October 24, 2022 10:30 PM
Created By: Microzenas
Last Edited By: Microzenas
Last Edited Time: October 26, 2022 11:32 PM
Status: In Review
Type: Coding

- [ ]  Write a program to find out the Winning List (How can win, what steps that win.

- [ ]  Double Check the Winning List: [https://replit.com/@zenaswu/connect4#connect4/winning.cpp](https://replit.com/@zenaswu/connect4#connect4/winning.cpp)

---

# Terminology

Winning List: A list that includes all the ways to win.

**Example:**

0   1   2   3   4   5   6
7   8   9  10  11  12  13
14  15  16  17  18  19  20
21  22  23  24  25  26  27
28  29  30  31  32  33  34
35  36  37  38  39  40  41

0 1 2 3 —> (in the winning list)

0 7 14 21 —> (in the winning list)

0 8 16 24 —> (in the winning list)

# Winning List:

1. A program to find out all the ways that can win. (Program should have comments and clear logic because this program will use to analyze the winning steps for Play Win Computer  [Connect4 Robot](Connect4%20Robot%20f8cbc207df9c4225a5fd553baebc61d0.md) ) 

# Drop Piece

1. Make sure how many ways can win in the current step
2. Compare user winning steps and Winning List
3. Sort each element of the winning list in descending because the big number at the bottom, and checking the big number can increase the probability