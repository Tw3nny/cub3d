*This project has been created as part of the 42 curriculum by moidoubi.*

# cub3D

## Description

cub3D is a small first-person "3D" renderer written in C with the MiniLibX, inspired by Wolfenstein 3D. The goal is to learn how raycasting turns a 2D grid map into a view of a maze, and to practise window management, event handling, texture mapping and error handling.

The program reads a scene description file (`.cub`), checks it, then draws the maze:

- one ray per screen column, advanced through the grid with the DDA algorithm;
- perpendicular wall distance, to avoid the fisheye effect;
- a different texture for the north, south, west and east faces of the walls;
- solid floor and ceiling colors taken from the scene file;
- movement and rotation with the keyboard.

## Instructions

### Requirements

- Linux with an X11 session (or XWayland).
- A C compiler and `make`.
- X11 and Xext development packages (`libx11-dev libxext-dev` on Debian/Ubuntu, `libX11-devel libXext-devel` on Fedora).
- The Linux MiniLibX, in a folder named `minilibx-linux` at the root of the repository. It is not committed:

```
git clone https://github.com/42paris/minilibx-linux.git
```

The bundled `libft` (including `get_next_line`) is built automatically.

### Compilation

```
make        # build the program
make clean  # remove object files
make fclean # remove object files and the program
make re     # rebuild from scratch
```

### Execution

```
./cub3D path/to/map.cub
```

Example:

```
./cub3D test/maps/valid/subject_example.cub
```

### Controls

| Key | Action |
|---|---|
| `W` / `S` | move forward / backward |
| `A` / `D` | move left / right |
| Left / Right arrows | look left / right |
| `ESC` or the window's close button | quit |

### Scene file format

```
NO ./test/textures/north.xpm
SO ./test/textures/south.xpm
WE ./test/textures/west.xpm
EA ./test/textures/east.xpm

F 220,100,0
C 225,30,0

111111
100101
101001
1100N1
111111
```

- `NO`, `SO`, `WE`, `EA`: path to the `.xpm` texture of each wall face.
- `F`, `C`: floor and ceiling colors as `R,G,B` (0 to 255), without spaces inside the value.
- These six elements can come in any order and be separated by empty lines.
- The map comes last and contains no empty line. Allowed characters: `0` (floor), `1` (wall), space, and exactly one of `N`, `S`, `E`, `W` for the player's start position and orientation.
- The area reachable by the player must be closed by walls.

On any invalid input, the program prints `Error` followed by a message and exits.

### Project layout

| Path | Content |
|---|---|
| `src/parsing/` | reading and validating the `.cub` file |
| `src/exec_game/` | raycasting, drawing, textures, movement, closing |
| `include/cub3d.h` | structures and prototypes |
| `test/` | sample maps and textures, valid and invalid |

## Resources

### References

- [Lode's Computer Graphics Tutorial: Raycasting](https://lodev.org/cgtutor/raycasting.html)
- [MiniLibX documentation (42 Docs)](https://harm-smits.github.io/42docs/libs/minilibx)
- [MiniLibX Linux sources](https://github.com/42paris/minilibx-linux)
- [Digital differential analyzer (Wikipedia)](https://en.wikipedia.org/wiki/Digital_differential_analyzer_(graphics_algorithm))
- `man 3 math`, and the 42 Norm.

### Use of AI

An AI assistant (Claude, through Claude Code) was used as a tutor, mainly for the rendering part (`src/exec_game/` and the related code in `src/main.c` and the `Makefile`):

- explaining the concepts and the maths (raycasting, DDA, camera plane, texture coordinates, rotation) with worked examples;
- breaking the work into small steps and suggesting how to test each one;
- reviewing the code, building it and running test maps, including with valgrind;
- giving formulas and, for some fixes and features, individual lines of code that were then typed into the project (for example texture mapping, movement and rotation);
- explaining the parsing code so that it can be understood and defended;
- writing study notes and the draft of this README.
