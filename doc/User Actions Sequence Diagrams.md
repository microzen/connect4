# User Actions Sequence Diagrams

Created: October 26, 2022 7:21 PM
Created By: Microzenas
Last Edited By: Microzenas
Last Edited Time: November 12, 2022 6:41 PM
Stakeholders: Yezhi Wu, Microzenas
Status: In Progress

```mermaid
sequenceDiagram
	App ->>+ C4: New Game
	App ->>+ Recording: New Recording Structure
	App ->>+ Player: Start Gram
	loop Each Turn
		Player ->> Player: Drop Piece
		Player -->> Recording: Add Step
		Player -->> C4: Drop Piece Action to C4 Table
		Player -->> Interface: Refresh Table
		%%Player ->> Player: Other Player Turn%%
	end 
	Player ->>- App:Win (Save Score)
	Recording ->>-App: Save Recording Status
	C4 ->>- App: End
```