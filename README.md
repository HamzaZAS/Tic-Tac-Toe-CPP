# Tic-Tac-Toe Game (C++)

A terminal-based, interactive Tic-Tac-Toe game implemented in C++. This project was built during my summer vacation following the completion of my second semester of BS Computer Science at PUCIT. It serves as a practical application of the concepts learned under the guidance of my Programming Fundamentals (PF) professor, Abdul Mateen.

The game allows a human player to compete against a computer opponent that makes randomized moves. The board dynamically updates after each turn, validating player inputs and tracking win or draw conditions.

## Features
* **Interactive Command Line Interface:** Displays a clean 3x3 grid layout that updates in real-time.
* **Input Validation:** Prevents players from choosing occupied spaces or entering invalid inputs outside the 1-9 range.
* **Automated Opponent:** Features a computer opponent powered by randomized moves utilizing `srand` and `rand()`.
* **Win/Draw Detection:** Checks all rows, columns, and diagonals after every turn starting from the 3rd round to determine a winner or declare a draw.

## Technical Concepts Used
* 2D Arrays for board state representation.
* Multi-layered `for` loops and nested conditional logic.
* Pass-by-reference for efficient memory management and state tracking.
* Modular functions to separate game mechanics (`humanPlay`, `CompPlay`, `checkwin`, and `show`).
