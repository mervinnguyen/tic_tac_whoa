# Tic-Tac-Whoa

A console-based two-player Tic-Tac-Toe game written in C, demonstrating foundational systems programming concepts including 2D array manipulation, modular function design, input validation, and control flow state management.

---

## Features

- **Interactive Menu System** — Navigate between starting a game, reading rules, or quitting via a numbered prompt with input validation and graceful error handling
- **Two-Player Gameplay** — Alternating turns between Player 1 (X) and Player 2 (O) with move validation to prevent overwriting occupied cells
- **Win Detection** — Checks all rows, columns, and both diagonals after every move for a three-in-a-row condition
- **Draw Detection** — Tracks remaining free spaces via a counter; declares a draw when the board is full with no winner
- **Live Board Rendering** — Renders the 3×3 grid to stdout after each move with labeled rows and columns for readability
- **Post-Game Flow** — Prompts players to return to menu, start a new game, or quit after each match

---

## Build & Run

**Requirements:** GCC or any C99-compliant compiler

```bash
# Compile
gcc -o tic_tac_whoa main.c

# Run
./tic_tac_whoa
```

---

## Gameplay

```
------------------------
Welcome to Tic-Tac-Whoa!
------------------------

Game Menu

(1) Start a New Game
(2) Rules and Instructions
(3) Quit

Enter an option(1-3):
```

During a game, players enter a row (1–3) and column (1–3) to place their mark:

```
1  X  |     |   
  ————  —————  ————
2     |  O  |   
  ————  —————  ————
3     |     |   
    1     2     3
```

---

## Project Structure

```
├── main.c       # Full game source — menu, game loop, board logic, win detection
└── README.md
```

---

## Implementation Notes

- Board state is maintained in a `char board[3][3]` global array, reset via nested loops at the start of each game
- `checkSpaces()` traverses the board to count empty cells, used to detect draw conditions
- `gameWinner()` checks all 8 win conditions (3 rows, 3 columns, 2 diagonals) and returns the winning player's character or `' '` if no winner yet
- Input is read with `scanf()` and offset by `-1` to translate 1-indexed user input to 0-indexed array coordinates
- Menu navigation uses recursive calls to re-enter states (menu → rules → game → menu), keeping control flow simple for a single-file project

---

## Known Limitations / Potential Improvements

- Recursive calls to `main()` for menu navigation are non-standard C; a proper game loop with a state machine would be more robust for production code
- No input sanitization for non-integer input. entering a character instead of a number causes `scanf` to loop indefinitely
- Diagonal win checks use unnecessary `for` loops; a direct conditional would suffice
- Could be extended with an AI opponent using minimax for single-player mode
