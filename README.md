## Chess Game Engine

A powerful and lightweight chess engine implemented in C, supporting full game logic including FEN parsing, move validation, en passant, castling, promotion, and check detection , checkmate detection , 50 move rule detection  , without using any graphics library.

---

### Features

- [x] **FEN Support**: Export board positions using Forsyth–Edwards Notation (Saved in FEN.txt).
- [x] **Move Validation**: Ensures all moves follow standard chess rules.
- [x] **En Passant**: Correct handling of special pawn captures.
- [x] **Castling**: Supports both kingside and queenside castling with all legality checks.
- [x] **Promotion**: Pawn promotion to queen, rook, bishop, or knight.
- [x] **Check Detection**: Identifies when  king is in check and restricts illegal moves.
- [x] **Checkmate Detection**: Identifies when  king is checkmated and ends the game.
- [x] **50 Move Rule Detection**: Identifies when 50 move have passed without any captures or pawn moves and ends the game.
---
### Usage

- Upon first opening the program use **CTRL +** and **CTRL -** and **SCROLL UP** untill you can see all the text  then enter anything .
- The Game uses pointer to select and move the piece . 
- Use **w a s d** to move the pointer in the respective direction and **y** to select the piece you want to move and move the pointer again to move it to final position and select that position using **y**.
- While Promoting use **Q R N B** for white and **q r n b** for black.


---
#### To Compile 

` gcc game.c renderer.h logic.h move.h  -o Game-2.exe `

---
## Compiling Chess

To compile follow these steps:

1. **Install a C compiler**: Ensure you have a C compiler installed on your system. Common options include GCC (GNU Compiler Collection) and Clang.

2. **Navigate to the game directory**: Open a terminal or command prompt and change the directory to where the game files are located.

   ```
   cd path/to/game-directory
3. Compile the game: Use the following command to compile Chess Engine .
   ```
   gcc game.c logic.h move.h renderer.h -o game_name
4. Run the game: After compilation, you can run the game using the following command:

   ```
   ./game_name

