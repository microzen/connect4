# C4 - Class Diagram

Created: November 7, 2022 5:17 PM
Created By: Microzenas
Last Edited By: Microzenas
Last Edited Time: March 31, 2023 11:40 PM
Stakeholders: Microzenas, Yezhi Wu
Status: In Progress

# Core

`IJudgeProxy`: Design for Proxy Patterns. Proxy IC4Game Class

Advantage: Use IOC (Inversion of Control) design to proxy `DropPiece` function.  

CODE: [https://github.com/microzen/connect4/blob/dev/core/c4/c4_judge.cpp](https://github.com/microzen/connect4/blob/dev/core/c4/c4_judge.cpp)

```mermaid
classDiagram
class IPlayer{
	IPlayer(name,IC4)
	#name: string
	#color:PieceColor 
	#IC4
	+dropPiece(int line) int
	+getName() string
	+getScore() int
}
class IJudgeProxy{
	+IJudge(IPlayer, IC4Game)
	+dropPiece(line) int
}
class IC4{
	$C4_ROW:int
	$C4_COLUMN:int
	#table:int[R][C]
	+getBoard(newTable[][]) void
	+dropPiece(int line, PieceColor) int
	
	+init()* void
}
class C4_Recording{
	+toArray() int
	+addStep() void
	+removeStep() void
	+getSize();
}

class IC4BaseRule{
	+isWin()* bool
}
class IC4Game{
	#status:int
	-players[]:IPlayer 
	-c4:IC4
	+start(IC4 *, IPlayer *, IPlayer *) void
	+currentPlayer() IPlayer
	+saveRecording() void
	+setPlayer(IPlayer) void
	+nextTurn() void
	+getTurnNumber() int
}

IC4BaseRule<..IJudgeProxy
IPlayer *-- IC4
%%IPlayer <|-- Player%%
%%IC4 <|-- C4%%
IJudgeProxy <-- C4_Recording
%%IC4Game <|-- IJudgeProxy:Proxy%%
IC4 <|-- IJudgeProxy:Proxy
```

# File Storage

`CacheStorage`: Because `UserLogin`, `RecordingList`, and `ScoreList` will spend IO, `CacheStorage` will save time for IO reading and writing.

`ISerialize`: `IC4Game` and `Player` information will be stored after the game.  `CacheStrorage` should not care who it is. Save Function just wants to know what info should be stored.

Advantage: **Low Coupling**, Design an Interface `ISerialize` for information that needs to store. 

For example, this game needs to store login information every day. Now `Login` class inherits `ISerialize` and implements `serializeInfo()` function. Finally, login info can be stored by `Save(ISerialize)`.

```mermaid
classDiagram
class ISerialize{
	+serializeInfo()* string
}
class CacheStorage{
	#path:string
	#expired() void 
	+save(ISerialize)* void
	+save()* void
	+getSize() int
	+getContentAsArray() string[]
}
class recordingStorage{
	
}
class socreStorage{
	+findByName(string) string[]
}
ISerialize <|-- IC4Game
ISerialize <|-- IPlayer
CacheStorage <|-- recordingStorage
CacheStorage <|-- socreStorage
```

# Extra Function (2.0)

```mermaid
classDiagram
class IPlayerExtra{
	+undo() int
	+restore() int
	+surrender() int
}
class IC4Extra{
	+takePieceOur(int line, PieceColor) int
}
class IC4GameExtra{
	+lastTurn() void
}
IC4<|--IC4Extra
IPlayer<|--IPlayerExtra
IC4Game<|--IC4GameExtra
```

# Base

```mermaid
classDiagram
class PieceColor{
<<enumeration>>
NONE = 0
RED
YELLOW
}
class C4Status{
<<enumeration>>
    UNSTART = -1
    PLAYING = 1
    WON = 2
    END = 0
}
```

# Interface (Input/Output)

```mermaid
classDiagram
class C4_Application{
	-game:IC4Game
	-interface:C4_Interface
	+C4_Application(IC4Game,C4_Interface)
	+gameInterface() void
	+startGame() void
}
class C4_Interface{
	+askName() string
	+askLine() int
	+displayMeun() void
	+chooseMenu() int
	+displayBoard(int[R][C] array) void
	+displayPlayerInfoWithColor(name,turn,time,PieceColor) void
	+displayWinningInfo(name,score,time,PieceColor) void
}
```