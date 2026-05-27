# Rush Driving

A simple 2D driving game developed in C++ using OpenGL (GLUT).

## Description

"Rush Driving" is a basic arcade-style game where the player controls a car and tries to avoid obstacles (other cars) while the environment scrolls past. The game features dynamically moving background elements like grass, trees, homes, and road lines, creating a sense of motion. Collision with other cars results in a "Game Over" state.

## Features

-   **Player Car Control:** Use 'w', 's', 'a', 'd' keys to move the player's car.
-   **Obstacle Avoidance:** Navigate to avoid oncoming traffic.
-   **Scrolling Environment:** The game world (grass, trees, houses, road lines) continuously scrolls to simulate driving.
-   **Collision Detection:** Detects when the player's car collides with other vehicles.
-   **Game Over Screen:** Displays a "Game Over!" message upon collision.
-   **Visual Elements:** Includes sky, sun, clouds, and traffic lights for environmental detail.

## How to Build and Run

This project appears to be set up as a Code::Blocks project.

### Prerequisites

*   **Code::Blocks IDE:** (Recommended)
*   **OpenGL (GLUT) Library:** Ensure GLUT is installed and configured with your C++ compiler. If you are using Code::Blocks, you might need to link the GLUT library manually.

### Steps

1.  **Open in Code::Blocks:** Open the `Graphics Final Project.cbp` file with Code::Blocks.
2.  **Configure GLUT (if necessary):** If you encounter errors related to GLUT, you may need to configure the compiler and linker settings in Code::Blocks to include the GLUT library and its headers.
    *   **Settings -> Compiler -> Global compiler settings -> Search directories -> Compiler:** Add the path to your GLUT `include` directory.
    *   **Settings -> Compiler -> Global compiler settings -> Search directories -> Linker:** Add the path to your GLUT `lib` directory.
    *   **Settings -> Compiler -> Global compiler settings -> Linker settings:** Add `-lfreeglut`, `-lglu32`, `-lopengl32` (or similar depending on your GLUT distribution) to the "Other linker options".
3.  **Build Project:** Go to `Build -> Build` or press `F9`.
4.  **Run Project:** Go to `Build -> Run` or press `Ctrl+F10`.

### Alternative (Command Line - Advanced)

If you prefer to compile via the command line, you will need a C++ compiler (like g++) and proper GLUT installation.

Example compile command (may vary based on your system and GLUT setup):
```bash
g++ main.cpp -o "Graphics Final Project" -lfreeglut -lglu32 -lopengl32 -Wall
```
Then run the executable:
```bash
./"Graphics Final Project"
```

## Controls

*   **W:** Move car up
*   **S:** Move car down
*   **A:** Move car left
*   **D:** Move car right

## Development Notes

The game uses simple 2D drawing primitives provided by GLUT to render all graphics. The background elements move by continuously translating their drawing coordinates, and their positions are reset once they move off-screen to create an infinite scrolling effect. Collision detection is based on basic bounding box checks.
