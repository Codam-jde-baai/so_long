# So Long: A Simple 2D Game

This **So Long** project is my sixth project at Codam. It is the first graphics project, featuring a simple 2D game where the game state updates after a player action. The objective is straightforward: collect all items to open the exit. The game also tracks the number of steps taken, allowing players to challenge themselves to complete the map in the fewest steps possible.

## Project Highlights

- **Graphics Introduction**: This project introduces basic graphics programming, focusing on efficient pixel manipulation.
- **Map Parsing**: Ensures the map is valid and all collectibles and the exit are reachable using the floodfill algorithm.
- **Efficient Rendering**: Instead of replacing the entire character instance when moving, the project updates the pixels of the `mlx_image_t` for faster rendering.

## The Project

The **So Long** project is structured to provide a simple yet engaging gaming experience:

- **Core Functionality**: Players navigate a 2D map, collecting items to unlock the exit.
- **Graphics library**: for the graphics we used MLX42, a graphics library provided by CODAM. Understanding the functioning of the library was key to writing the project.
- **Floodfill Algorithm**: Used to validate the map, ensuring all necessary elements are accessible.
- **Pixel Management**: Efficiently update the character image and gamestate for a smooth experience

### Challenges

Developing **So Long** presented several challenges:

- Implementing the floodfill algorithm for map validation.
- Managing pixel updates for character movement efficiently.
- Planning the data structure to support game mechanics and rendering.

### How to Run

To run the **So Long** game, use the following command:
*note: This project was developed for macOS.*

1. Ensure you have a valid map file, such as `valid.ber`.

bash
```
make
./so_long /maps/valid.ber
```


## Conclusion

The **So Long** project was a fun and educational experience, enhancing my understanding of graphics programming and game development. It involved careful planning of data structures and efficient rendering techniques. 

Feel free to explore the code and use it as a reference or inspiration for your own projects.