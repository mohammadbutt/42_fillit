# Fillit - An Algorithm to put tetrominoes in a smallest square possible

#### Project file: [fillit](https://github.com/mohammadbutt/42_fillit/blob/master/doc.fillit.en.pdf)

Allowed C functions(2) - close(2), open(2), read(2), write(2).

Allowed C functions(3) - exit(3), free(3), malloc(3).

---
# Table of Contents
* [Cloning Repository](#coloning-repository)
* [Installing Fillit](#installing-fillit)
* [Program Demo](#program-demo)
* [Project Summary](#project-summary)
  *[Validation](#validation)
* [Resources And References](#resources-and-references)

# Cloning Repository
```git clone https://github.com/mohammadbutt/42_fillit.git fillit```

# Installing Fillit
```
make all
./fillit tests/corrects/valid_19
```

# Program Demo

![](https://github.com/mohammadbutt/42_fillit/blob/master/media/fillit_1080p_30fps.gif)

# Project Summary

### Validation - [Source Code](https://github.com/mohammadbutt/42_fillit/blob/513846b6841171d2d37894244bbde4f594c7f0b5/valid.c)
Program starts by reading the file and each time it reads 20 characters because a tetromino placed on a 4 by 4 grid + 1 for the new line will take 20 characters of space. Program checks to determine if the 4th, 9th, 14th, and 19th element of a tetromino are new lines or not. If they are not then the program exits. If there are new lines then the program stores the string.

After the program has read and stored the file, strings are further evaluated to ensure that there are 12 dots and 4 hashes. If there are 12 dots and 4 hashes then the program moves to the last stage of validation. If a tetromino is valid and all of the hashes touch each other 6 or 8 times, it means thats a valid tetromino.

### Turning hashes into x and y coordinates - [Source Code](https://github.com/mohammadbutt/42_fillit/blob/513846b6841171d2d37894244bbde4f594c7f0b5/coordinate.c)
Once the tetrominoes are stored in a 2d char arrary, the hashes are converted into x and y coordinates in a 2D int array. In order to get the x and y, nth place is modulo by 5 which gives x, and the same nth place is divided by 5 which gives the y.

Below on the left is how the tetrominoes are stored in a 2D char array. On the right, tetrominoes are converted into x and y coordinates: is what the tranformation will look like once we convert the hastags into coordinates:
```
Tetrominoes | {x, y} coordinates
....        |
.##.        | {1, 1} {2, 1}
.##.        | {1, 2} {2, 2}
....        |

....        | 
....        |
....        |
####        | {0, 3} {1, 3} {2, 3} {3, 3}

....        |
.#..        | {1, 1}
.#..        | {1, 2}
.##.        | {1, 3} {2, 3}
```
x_min and y_min are caluclated for each tetromino because x_min and y_min are used to shift the tetrominoes to the top left corner. So if a tetromino looked like following:
```
....
...#
..##
...#
```
Then after subtracting x_min and y_min from each tetromino, it will tranform the tetromino to the top left and it will look like below:

```
.#..
##..
.#..
....
```

### Backtracking
Backtracking works recursively to place the tetrominoes onto the board. There are some conditions that backtracker looks at. One, a piece cannot go over the board. What that means is that if a board is of size 2 by 2 and the tetromino is a vertical line, then the board size will have to be increased. Below is an exmaple of the board represented by dots and tetromino represented by hashes and how it will increase each time.
```
..#
..#
  #
  #
```

```
...#
...#
...#
   #
```
```
...#
...#
...#
...#
```
One more condition that the backtracker has to look at is that both pieces cannot land on top of each other. If they do then the tetrominoes will be shifted by 1 to the right until the tetrominos cannot be placed any more on that line and then the tetromino will shift 1 down and will start off at the left most position. Tetromino will keep on shifting as long as it collides with the other piece. If there is no more space left on the board to place the existing tetrominoes, then all pieces will be removed and a new board will created, the size will be increased by 1, and the backtracker will start off again by placing the first tetromino until it can place all pieces onto the map.

---
<video src="https://github.com/mohammadbutt/42_fillit/blob/master/media/fillit_1080p.mov" width="320" height="200" controls preload></video>

# Resources and References:
1. [C Tutorials on Linked List](http://www.zentut.com/c-tutorial/c-linked-list/)
2. [19 Valid Tetrominoes - Wolfram](http://mathworld.wolfram.com/Tetromino.html)
3. [Empty Tetromines grid](https://gfredericks.com/things/polyominoes)
4. [Tetris Collision Detection](https://gamedevelopment.tutsplus.com/tutorials/implementing-tetris-collision-detection--gamedev-852)
5. [Data Types - Oracle](https://docs.oracle.com/javase/tutorial/java/nutsandbolts/datatypes.html)
6. [Bitwise Calculator](http://bitwisecmd.com/)
