# 🐬 So Long

## 📖 About

"So Long" is a simple 2D game project designed to explore the use of textures, sprites, and basic gameplay elements. Inspired by "The Hitchhiker's Guide to the Galaxy", this game features a dolphin trying to escape Earth after eating fish.

## 🎮 Features

- 🗺️ Map generation from `.ber` files
- 🏃‍♂️ Smooth character movement (W, A, S, D)
- 🍣 Item collection
- 🚪 Exit search
- 🧱 Wall collision detection
- 🖼️ Graphical display with MiniLibX

## 🛠️ Prerequisites

- Linux operating system
- GCC
- Make
- MiniLibX

## 🚀 Installation and Usage

1. Clone the repository:
   ```
   git clone https://github.com/your-username/so_long.git
   ```
2. Navigate to the project folder:
   ```
   cd so_long
   ```
3. Compile and run the project:
   ```
   make
   ./so_long path/to/your/map.ber
   ```

For the bonus version:
```
make bonus
./so_long_bonus path/to/your/map.ber
```

Maps are already available in the project, but you can also create your own!

## 🗺️ Map Format

Maps use the following characters:
- `0`: Empty space
- `1`: Wall
- `C`: Collectible item
- `E`: Exit
- `P`: Player's starting position

Example of a valid map:

```
1111111111111
10010000000C1
1000011111001
1P0011E000001
1111111111111
```

---

Made with ❤️ as part of the 42 School curriculum.