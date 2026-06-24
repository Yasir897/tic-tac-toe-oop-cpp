# ⭕ Tic-Tac-Toe (C++ OOP)

A feature-rich, two-player **Tic-Tac-Toe** game built in **C++** using **Object-Oriented Programming** — my **Object-Oriented Programming (OOP) project**.

> 🔗 **Note:** This is the **complete single-file** version. The same game organized into **separate class files (modular)** lives here: **[tic-tac-toe-ai-cpp](https://github.com/Yasir897/tic-tac-toe-ai-cpp)**.

## 🎮 Gameplay
Two players enter their names, pick **X** or **O**, and take turns marking a **3×3 grid** by choosing a number from **1–9**. First to line up three in a row — horizontal, vertical, or diagonal — wins; a full board with no line is a draw.

## ✨ Special Features
At any turn you can type a command instead of a number:

- **`exit`** — quit the game immediately at any point
- **`edit`** — open an in-game edit menu with options to:
  1. **Edit a player's name** — rename Player 1 or Player 2 mid-game
  2. **Undo the last move** — revert the previous move and free that cell again
  3. **Cancel** — change nothing and continue

Plus ASCII-art title screens, input validation, and automatic win/draw detection.

## 🧱 OOP Design
Built around multiple cooperating classes:
- **`TicTacToe`** — base class holding the core game data
- **`display`** *(inherits TicTacToe)* — board & screen rendering
- **`Player`** / **`AI`** — player handling
- **`editing`** *(inherits Player)* — the edit-name / undo-move logic
- **`checkwin`** — win & draw detection
- **`play`** *(inherits TicTacToe)* — main play loop
- Uses **inheritance** and **`friend` classes** (`editing` & `play` are friends of `TicTacToe`)

## 🛠️ Tech
- **Language:** C++
- **Concepts:** Classes & objects, **inheritance**, **friend classes**, encapsulation, 2D arrays

## ▶️ Build & Run
```bash
g++ tic_tac_toe.cpp -o tictactoe
./tictactoe
```

---
🎓 University project — Object-Oriented Programming (OOP) · Developed by **Yasir Naeem**.
