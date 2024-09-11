# Connect4

Full doc --> [Flowchart.md](doc/Flowchart.md)

Design --> [C4 - Class Diagram.md](doc/C4%20-%20Class%20Diagram.md)

Plans --> [Connect4 Robot.md](doc/Connect4%20Robot.md)

``` text
.
├── LICENSE
├── Makefile
├── README.md
├── cleanup.sh
├── core
│   ├── c4                      // folder, about connect 4
│   │   ├── c4_judge.cpp        // judge and proxy (intercept steps and save to recording list
│   │   ├── c4_winning.cpp      // about winning
│   │   ├── connect4.cpp        // about connect borad
│   │   ├── connect4_core.cpp   // about game
│   │   ├── recording_core.cpp  // recording steps, (stack structure
│   │   ├── serialize.cpp       // serialize players and game info
│   │   ├── storage.cpp         // storage, save players and games info to file
│   │   └── user_core.cpp       // about player
│   ├── com                     // common function folder
│   │   ├── convert.cpp         // convert type between string and array
│   │   ├── file_operator.cpp   // file reader and writer
│   │   └── log.cpp             // for test, and debug
│   ├── interface               // business, display and input hand file
│   │   ├── c4_application.cpp  // for business logic
│   │   ├── c4_interface.cpp    // display and input
│   │   └── c4_interface_color.cpp //color printer 
|   |   
│   ├── common.hpp              // common hand file
│   ├── connect4.hpp            // connect 4 and game hand file
│   ├── c4_interface.hpp        // handfile about output and input
│   └── storage.hpp             // storage hand file
├── main.cpp                    //main function
├── recording_list.txt
└── score_list.txt
```
