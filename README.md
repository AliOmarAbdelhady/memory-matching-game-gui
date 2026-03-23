# Memory Matching Game GUI

## Overview
The Memory Matching Game is a classic card matching game implemented with a graphical user interface (GUI) using C++. The objective of the game is to find all matching pairs of cards by flipping them over two at a time. The game keeps track of the player's score, attempts, and pairs found.

## Features
- Intuitive GUI for easy interaction
- Dynamic card grid based on user input
- Score tracking and game statistics
- Stylish design using Qt Stylesheets

## Project Structure
```
memory-matching-game-gui
├── src
│   ├── main.cpp               # Entry point of the application
│   ├── game
│   │   ├── MemoryGame.h       # Header file for game logic
│   │   └── MemoryGame.cpp     # Implementation of game logic
│   └── ui
│       ├── MainWindow.h       # Header file for main window UI
│       ├── MainWindow.cpp     # Implementation of main window UI
│       ├── CardWidget.h       # Header file for individual card UI
│       ├── CardWidget.cpp     # Implementation of individual card UI
│       ├── GameBoard.h        # Header file for game board management
│       └── GameBoard.cpp      # Implementation of game board management
├── include
│   └── config.h               # Configuration constants and settings
├── resources
│   └── styles.qss             # Stylesheet for the GUI
├── CMakeLists.txt             # Build configuration file
└── README.md                  # Project documentation
```

## Building the Project
To build the Memory Matching Game GUI, follow these steps:

1. Ensure you have CMake and a compatible C++ compiler installed.
2. Clone the repository or download the project files.
3. Open a terminal and navigate to the project directory.
4. Create a build directory:
   ```
   mkdir build
   cd build
   ```
5. Run CMake to configure the project:
   ```
   cmake ..
   ```
6. Build the project:
   ```
   make
   ```

## Running the Application
After building the project, you can run the application by executing the generated binary in the `build` directory.

## Dependencies
This project uses the Qt framework for GUI development. Ensure you have the appropriate version of Qt installed and configured in your environment.

## License
This project is licensed under the MIT License. See the LICENSE file for more details.