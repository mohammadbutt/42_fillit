# Project Status - In Progress
# Fillit - An Algorithm to put tetrominoes in a smallest square possible

# Brainstorming
- [X] 1. Open the file
- [X] 2. Read the file
- [X] 3. Print the file
- [X] 4. Save 19 valid pieces in a .c file. Put the pieces at the top left position. Using `ft_strcpy()`, instead of `malloc()`, so there is no need to free allocated memory.
- [X] 5. Migrating to valid pieces over to macros because it is a better option then having to store valid pieces in two seperate functions. What valid pieces look like http://mathworld.wolfram.com/Tetromino.html
- [X] 6. `ft_strcmp` can be used to compare pieces of the user with the valid pieces. It works
- [X] 7. Created an empty grid function, so when we enter 4 into that function it creates a grid of 4 by 4. Linear grid works. But created a grid of double pointer, 2 dimensional array, so we can enter x and y coordinates, or we can go to 
```
A table of 4 by 4. 
....
....
....
....
````
- [ ] 8. How to store user pieces properly? Cannot use Buff_size of 20 because what if the user has a valid piece, but at the end there is extra space? Not true. Tested and it works. Pieces can be stored with a buff size of 20 and ft_strcmp will still be able to compare the pieces properly. `ft_strcmp` will know the difference between the following:

```
###.$
.#..$
....$
....$

Above is a valid piece. Below is an invalid piece because the last line has a space at the end.

###.$
.#..$
....$
.... $
```

- [ ] 9. Move the pieces of a given file to our desired location which is to the top left. Use x, y coordinates to move the pieces. Use this link https://gfredericks.com/things/polyominoes to put pieces at random places to understand how the pieces can be moved and shifted. We can move the whole row if it is not a #. We can move the whole column if it is not a #.

# Resources:
1. [19 Valid Tetrominoes] (http://mathworld.wolfram.com/Tetromino.html)
2. 
3. [Tetris Collision Detection](https://gamedevelopment.tutsplus.com/tutorials/implementing-tetris-collision-detection--gamedev-852)


