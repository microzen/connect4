# Game’s Flow Details

Created: October 24, 2022 8:38 PM
Created By: Microzenas
Last Edited By: Microzenas
Last Edited Time: November 8, 2022 4:06 PM
Stakeholders: Yezhi Wu, Regina, Microzenas
Status: Archived
Type: Coding, Flowchart

# FlowChart

```mermaid
graph TB
direction TB
	dUI[/Display Current Turn Info and User Info/] --> dTB[/Display Connect 4 Board/] 

		dTB -.-> Undo -. Remove a step .->RS
		dTB -.-> Surrender -.->Save
		dTB -.-> Restore -.->Save
		dTB--> Number(Number of Rows) --> DropPiece
  DropPiece --> Win{is win}
  Win -- Yes --> Save(Save All Steps)
	Win -. Add a step .-> RS
  Win -- No --> RS[[Recording Steps]] -->dUI
File[(Flie)]
Save(Save All Steps) -.-> File[(File)]
File --> Recording
File -.-> dDetail
subgraph Recording List
	Recording[/Display Recording List/] --> dDetail[/Display Details/]
end
```