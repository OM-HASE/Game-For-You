# Game For You

Welcome to **Game For You**, a project featuring two engaging non-graphical C language games: **Tap Tap Match** and **Sliding Puzzle Game**. Both games offer increasing difficulty levels and varying board sizes, providing a satisfying challenge to puzzle enthusiasts.

## Features

### Tap Tap Match
A fast-paced puzzle game that tests your speed and memory. Match pairs of items as quickly as possible to achieve high scores.

### Sliding Puzzle Game
A classic brain teaser that promotes logical thinking. Arrange the tiles in the correct order to solve the puzzle.

## Installation

1. **Clone the repository:**
    ```sh
    git clone https://github.com/OM-HASE/Game-For-You.git
    ```
2. **Navigate to the project directory:**
    ```sh
    cd Game-For-You
    ```
3. **Compile the games:**
    ```sh
    gcc -o Tap_Tap_Match Tap_Tap_Match.c
    gcc -o Sliding_Puzzle Sliding_Puzzle.c
    ```

## Usage

1. **Run Tap Tap Match:**
    ```sh
    ./Tap_Tap_Match
    ```
2. **Run Sliding Puzzle Game:**
    ```sh
    ./Sliding_Puzzle
    ```

## Game Details

### Tap Tap Match
- **Objective:** Match all pairs of items.
- **Controls:** Use keyboard inputs to select and match items.
- **Levels:** Multiple levels with increasing difficulty.
- **Scoring:** Points based on speed and accuracy.

### Sliding Puzzle Game
- **Objective:** Arrange tiles in the correct order.
- **Controls:** Use keyboard inputs to move tiles.
- **Board Sizes:** Various board sizes from 3x3 to larger grids.
- **Difficulty:** Increasing levels of complexity.

## Configuration

### Tap Tap Match
- **Difficulty Settings:** Adjust the number of pairs and the time limit in the configuration file `Tap_Tap_Match_config.txt`.
- **Themes:** Change themes by modifying the theme settings in the configuration file.

### Sliding Puzzle Game
- **Board Size:** Customize the board size by editing the `Sliding_Puzzle_config.txt`.
- **Tile Numbers:** Toggle between numbered and image tiles in the configuration file.

## Development

### Code Structure
- **Tap_Tap_Match.c:** Main source file for Tap Tap Match.
- **Sliding_Puzzle.c:** Main source file for Sliding Puzzle Game.
- **utils.c / utils.h:** Utility functions shared between games.

### Building from Source
Use `make` for convenient compilation:
```sh
make
```
This will compile both games automatically.

## Testing

### Unit Tests
Run unit tests to verify the functionality of the games:
```sh
make test
./test_suite
```

### Integration Tests
Test the integration of different components by running:
```sh
./integration_test
```

## Contributions

Feel free to contribute to this project by submitting issues or pull requests. Contributions are welcome to enhance features, fix bugs, or improve documentation.

### How to Contribute
1. Fork the repository.
2. Create a new branch (`git checkout -b feature-branch`).
3. Commit your changes (`git commit -am 'Add new feature'`).
4. Push to the branch (`git push origin feature-branch`).
5. Open a pull request.

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for more information.

## Contact-Us

Have feedback, suggestions, or questions? We'd love to hear from you! You can reach out to us via email, social media, or through our website. Your feedback helps us improve Game For You and provide a better experience for all users.

- Email: omhase9955@gmail.com
- LinkedIn: www.linkedin.com/in/omhase

## Acknowledgments

Special thanks to the contributors and the open-source community for their valuable inputs and support.

---

Enjoy playing and improving your puzzle-solving skills with **Game For You**!
