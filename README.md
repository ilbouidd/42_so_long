*This project has been created as part of the 42 curriculum by ilbouidd*

# So_long – 42 Project

## 📚 Description

**So_long** is a project from School 42 that consists of creating a small 2D game using the MiniLibX graphics library. The goal is to implement a game where the player must collect all the items on a map and reach the exit using as few moves as possible.

The player controls a character that moves on a map made up of walls, empty spaces, collectible items, and an exit.

## 🛠️ Features

- Graphical display of a 2D map using MiniLibX
- Player movement using WASD keys or arrow keys
- Mandatory item collection before being able to exit
- Movement counter displayed in the terminal
- Collision handling with walls
- Clean program exit (ESC key or window close button)

## 🚀 Usage

### 1. Compilation

```bash
make
```

### 2. Launching the game

```bash
./so_long <file.ber>
```

Example:
```bash
./so_long maps/map1.ber
```

### 3. Game controls

- **W** or **↑** : Move up
- **A** or **←** : Move left
- **S** or **↓** : Move down
- **D** or **→** : Move right
- **ESC** : Quit the game

## 🗺️ Map format

Maps must be `.ber` files containing:
- **0** : Empty space
- **1** : Wall
- **C** : Collectible item
- **E** : Exit
- **P** : Player starting position
- **M** : Monster

Example of a valid map:
```
1111111111111
10010000000C1
1000011111001
1P0011E000001
1111111111111
```

## 📝 Constraints

- The map must be rectangular and surrounded by walls
- There must be exactly one player (P) and one exit (E)
- At least one collectible item (C) must be present
- All collectibles must be reachable from the starting position
- Exclusive use of MiniLibX for graphical display
