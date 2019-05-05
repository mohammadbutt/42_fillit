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

---
# How to read the code.
Reading big programs can get a bit challenging. I have summed up some point below that can assisst in reading the code.

1. First, the very first function that appears in the program `` void ft_exit (void) ``. The program can run fine even without this because this function only has two lines. But having created this function prints an Error on the screen and exits out of the program.

2. Second function, ``char **ft_tetrominoes(int fd)``, reads the file and stores the tetrominoes. Tetrominoes are stored in a double pointer array. First pointer was malloced with size of 26, since the most alphabetical characters we can have are 26. Then the second pointer was malloced with a size of 20 characters because each tetromino has 20 characters(12 dots + 4 hashtags+ 4 newlines). While tetrominoes are being stored, flags are also placed to evaluate if the 4th, 9th, 14th, and 19th characters of each tetromino are a new line, '\n', or not. If one of these characters are not a new_line then the program will exit out using the ``ft_exit()``.

3. Third function, ``int dots_and_hash(char ** characters)``, takes the stored the tetrominoes and checks if there are 12 dots and 4 hashtags or not. If there are not 12 dots or 4 hashtags then the program will exit out via ``ft_exit()``. If there are 12 dots and 4 hashtags then the program will return 1, which means now the stored pieces can be further assessed to determine if it a valid tetromino or not. Because there are could be 4 hashtags in all four corners and 12 dots in the middle, and the program will still return 1.

4. Function, `int is_it_valid(char **characters, int i, int j, int hash)`, is the last stage in validating if a tetromino is actually valid or not. Suppose if x at the 0th position is a #, then we simply check if x+1, x+5, x-1, x-5 is a hastag. If any or all of these position are a hashtag then we add them all up. If total of this function generates 6 or 8 we can be assured that is an actual tetromino.

<table>
  <tr>
    <td>#</td>
    <td>#</td>
    <td>#</td>
    <td>#</td>
    <td>\n</td>
  </tr>
</table>
<table>
  <tr>
    <td>o</td>
    <td>o</td>
    <td>o</td>
    <td>o</td>
    <td>\n</td>
  </tr>
</table>
<table>
  <tr>
    <td>o</td>
    <td>o</td>
    <td>o</td>
    <td>o</td>
    <td>\n</td>
  </tr>
</table>
<table>
  <tr>
    <td>o</td>
    <td>o</td>
    <td>o</td>
    <td>o</td>
    <td>\n</td>
  </tr>
</table>

5. Function, `int **x_y_coordinates(char **characters)` converts the stored tetrominoes in x and y coordinates. Memory is allocated using malloc for the double pointer for a size of 26. Unlike the string where we allocate the memory of 21, in this case we only allocate memory for a size of 9, because we are only getting coordinates for x and y. To get the x coordinate, we take the position of a tetromino and do modulous 5. To get the y coordinate, we take the position of a tetromino and divide that by 5.

Taking the above figure, below is what the tranformation will look like once we convert the hastags into coordinates:

<table>
  <tr>
    <td>0%5(x = 0), 0/5(y = 0)</td>
    <td>1%1(x = 1), 0/5(y = 0)</td>
    <td>2%5(x = 2), 0/5(y = 0)</td>
    <td>3%5(x = 3), 0/5(y = 0)</td>
    <td>\n</td>
  </tr>
</table>

# Resources:
1. [19 Valid Tetrominoes - Wolfram](http://mathworld.wolfram.com/Tetromino.html)
2. [Empty Tetromines grid](https://gfredericks.com/things/polyominoes)
3. [Tetris Collision Detection](https://gamedevelopment.tutsplus.com/tutorials/implementing-tetris-collision-detection--gamedev-852)
4. [Bitwise calculator](https://www.binaryconvert.com/convert_unsigned_short.html)
5. [Another Bitwise calculator](http://bitwisecmd.com/)
6. [Data Types - Oracle](https://docs.oracle.com/javase/tutorial/java/nutsandbolts/datatypes.html)


