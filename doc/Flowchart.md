# Flowchart

Created: October 24, 2022 12:09 PM
Created By: Yezhi Wu
Last Edited By: Regina
Last Edited Time: November 19, 2022 8:04 PM
Stakeholders: Regina, Yezhi Wu, Microzenas
Status: In Progress
Type: Project Kickoff 🚀

# LOG

- Drop Play with Computer - resultantly dropped to simplify project development - November 1, 2022

# Interface

## Play with Another Player and Computer

```mermaid
graph TD
Menu --> P[Play with Player]
	P --> dR(Display Rule) -->
    iUI(Input User 1 and 2 Info) --> dUI(Display Current Turn Info and User Info) --> dTB(Display Connect 4 Board) 

		dTB -.-> Undo
		dTB -.-> Surrender
		dTB -.-> Restore
		dTB--> Number(Number of Rows) --> DropPiece

    DropPiece --> Win{is win}

    Win -- Yes --> dWI(Winning Info) --> PA{Play Again}
    Win -- No --> RS[(Recording Steps)] --> dUI

    PA -- Yes --> dUI
    PA -- No --> Menu

	Menu -.-> S[Scores List]
	Menu -.-> R[Recording List]
	%%Menu -.-> C[Play with Computer] --> dR%%

```

## Scores List

```mermaid
graph TD
	%%Menu -.-> P[Play with Another Player]
	Menu --> S[Scores List]
	S --> Display[Display: Name, Scores. ->Descending by Scores] --> |Type q or Q to Quit|S
	Type[Type q or Q to Quit] --> END
	%%Menu -.-> R[Recording List]
	Display -.Read.-> DB[(File)]
	%%Menu -.-> C[Play with Computer]%%
```

## Recording List

```mermaid
graph TD
	Menu -.-> P[Play with Another Player]
	Menu -.-> S[Scores List]
	Menu -.-> R[Recording List]
	R --> Display[/Display: Number, Player Name, Date. Descending/] --> 
	Number[/Type the Number to See More Details/] -->
	Detail 
	Number -.-> |Type q or Q to Quit|R
	Detail -.-> |Type q or Q to Quit|Display
	Detail
	%%Menu -.-> C[Play with Computer]%%

```
