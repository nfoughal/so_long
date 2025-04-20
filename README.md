# So_Long

**So_Long** is a 2D game developed as part of the 42 curriculum. The objective is to navigate through a maze, collect all collectibles, and reach the exit. The project emphasizes handling user inputs and graphical rendering using the MiniLibX library.

## Features

- Navigate using **W**, **A**, **S**, **D** or arrow keys.
- Collect all items to unlock the exit.
- Real-time rendering with MiniLibX.
- Error handling for invalid maps.

## Installation & Execution

### Prerequisites

- GCC compiler
- Make
- MiniLibX library

### Steps

1. **Clone the repository:**

   ```bash
   git clone https://github.com/nfoughal/so_long.git
   cd so_long
   ```

2. **Build the project:**

   ```bash
   make
   ```

3. **Run the game with a map:**

   ```bash
   ./so_long maps/map.ber
   ```

   > Ensure that your map file has the `.ber` extension and follows the required format.

## Controls

| Key      | Action     |
|----------|------------|
| W / ↑    | Move Up    |
| A / ←    | Move Left  |
| S / ↓    | Move Down  |
| D / →    | Move Right |
| ESC      | Exit Game  |

## Map Requirements

- Rectangular shape.
- Enclosed by walls (`1`).
- Contains:
  - One player (`P`)
  - One exit (`E`)
  - At least one collectible (`C`)
- Valid path from player to all collectibles and exit.

## Project Structure

- `src/` – Source code files.
- `maps/` – Sample map files.
- `includes/` – Header files.
- `Makefile` – Build automation.

## License

This project is part of the 42 School curriculum and is intended for educational purposes.
