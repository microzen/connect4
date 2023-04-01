# Connect-Four Plan First Draft

Created: October 24, 2022 12:09 PM
Created By: Yezhi Wu
Last Edited By: Microzenas
Last Edited Time: October 26, 2022 11:04 PM
Stakeholders: Regina, Yezhi Wu, Microzenas
Status: In Progress
Type: Project Kickoff 🚀

# What is Connect Four

There are some details about the game.

[Connect Four - Wikipedia](https://en.wikipedia.org/wiki/Connect_Four)

# Resource

Git open-source project of the Connect 4

[https://github.com/kenrick95/c4](https://github.com/kenrick95/c4)

Game example:

[c4](https://kenrick95.github.io/c4/)

Win List

[connect-four/app.js at master · kubowania/connect-four](https://github.com/kubowania/connect-four/blob/master/app.js)

# Coding

Write a program that **Connect Four.** User can choose and take turn dropping pieces into a seven-column, six-row vertically suspended grid. The pieces fall straight down, occupying the lowest available space within the column. 

The objective of the game is to be the first to form a horizontal, vertical, or diagonal line of four of one's own tokens.

# Interface

## Input

- User enter the number for the column that player want to drop the pieces. (only 1 -7)
- Enter players’ name (1 or 2 players).
- Choose the models
    - play with other player
    - **play with computer**
    - Check the score list
    - Check the recordings list
- Asking for a new turn after game ends.
- Game undo
    - ask another player to agree
- Game restore
- Losing
- Sum

## Output

- Display a 6*7 table and display the number of column on the top.
    - Separate each columns with the delimiter `|`.
    - **Different colors (or other .**
    - To refresh the table of the interface for every turn.
- Show the information which player win.
- Display the score list
    - Name
    - Score
- Display the recordings list
    - List number
    - Players’ name
- Show the information of the turn of player

            Game tips

- Name
- Total of time that used
- **Colors (or other..**
- Display Score (sorted)
    - Player

# Logics

- Winning algorithm.
- Dropping pieces to the lowest available space.
- **Computer steps.**
- Save player info as a file
    - Scores
    - Names
- Save record as a file (array elements) with a ID (timestamp)
- A timer to record the spending time during
    - total
    - play1
    - play2
    - start time
- Undo
    - record 10 step
-