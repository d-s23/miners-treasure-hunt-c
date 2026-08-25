# Miners' Treasure Hunt - C Based Text Game

A text-based mining adventure game developed in **C**, featuring exploration, resource collection, inventory management and pickaxe progression.

The objective is to explore a 2D underground environment, collect resources, upgrade the pickaxe and ultimately find and sell a diamond to complete the game.

## Features

* **2D mining environment** with directional movement and boundary checking
* **Randomised resource generation** for Stone, Silver, Gold and Diamond
* **Pickaxe progression** with upgrades unlocking more valuable resources
* **Inventory management** with resource storage limits
* **Shop system** for exchanging resources for coins and purchasing upgrades
* **Three difficulty levels** affecting diamond availability
* **Coordinate tracking** to prevent previously mined locations from being mined again
* **Input validation** and handling of invalid actions

## Technologies & Concepts

* **C**
* Modular programming using `.c` and `.h` files
* Functions and pointers
* Arrays and state management
* Random number generation
* Conditional logic and loops
* Input validation and boundary checking

## Project Structure

```text
miners-treasure-hunt-c/
├── CMakeLists.txt
├── main.c
├── gamefunctions1.c
├── gamefunctions1.h
└── README.md
```

## How to Play

Select a difficulty level, then use the main menu to:

1. **Mine** using `W`, `A`, `S` and `D`
2. **Visit the shop** to exchange resources for coins and upgrade the pickaxe
3. **Check your inventory** to monitor resources, coins and pickaxe health

### Controls

| Input | Action          |
| ----- | --------------- |
| `1`   | Mine            |
| `2`   | Shop            |
| `3`   | Check Inventory |

| Input | Direction |
| ----- | --------- |
| `W`   | Up        |
| `S`   | Down      |
| `A`   | Left      |
| `D`   | Right     |

### Difficulty

The player selects a difficulty at the beginning of the game. The selected difficulty affects the probability of finding diamonds.

| Difficulty | Multiplier |
| ---------- | ---------: |
| Easy       |          2 |
| Medium     |          1 |
| Hard       |        0.5 |

Invalid difficulty selections default to Medium.

### Resources & Progression

Resources are generated when the player successfully mines a new coordinate. The available resources depend on the player's pickaxe level.

* **Stone** — Available from the beginning
* **Silver** — Available from the beginning
* **Gold** — Requires a higher-level pickaxe
* **Diamond** — Requires the required upgraded pickaxe

Collected resources can be exchanged for coins at the shop, which can then be used to purchase stronger pickaxes.

The game is completed when the player mines a diamond and returns to the shop to exchange it.

## Development & Testing

The project was developed iteratively, with testing covering mining movement, coordinate tracking, pickaxe health, shop transactions, inventory updates, difficulty selection and game completion.


<img width="276" height="594" alt="image" src="https://github.com/user-attachments/assets/63018dd0-38d0-4cb0-b19f-69e14462714d" />


---

**Author:** Dev Sakaria
