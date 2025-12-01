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

