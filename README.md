# Project Status - Done
# Working on readme
# Fillit - An Algorithm to put tetrominoes in a smallest square possible

# Compiling the program
``` gcc validation.c -I. ./libft/libft.a ```
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
- [X] 8. Store pieces correctly. How to store user pieces properly? Cannot use Buff_size of 20 because what if the user has a valid piece, but at the end there is extra space? Not true. Tested and it works. Pieces can be stored with a buff size of 20 and ft_strcmp will still be able to compare the pieces properly. `ft_strcmp` will know the difference between the following:

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

- [X] 9. Validate pieces through various stages. Phase 1, is 4th, 9th, 14, and 19th character a new line. Phase 2, count if there are 12 dots and 4 hashtags. Phase 3, if the current piece is a hastag then is +1, +5, -1, and -5 a hashtag, if it is then count ++.
- [X] 10. Turn actual tetrominoes into x and y coordinates.
- [X] 11. Shift x and y coordinates to the top left. Find x_min and y_min then subtract them from the actual coordinates to move them to the top left.
- [X] 12. Create a grid/ board.
- [ ] 13. Determine the minimum size of the board.
- [X] 14. Turn coordinates into alphabets. 0th element would be A, 1st element would be B. Alphabets are stored in a double array, 9th element of each array is an alphabet. A tetromino will look like this, {1, 1, 1, 1, 0, 0, 0, 0, 'A'}.
- [X] 15. Create a collision function that will check against the board and pieces. Tetrominoes cannot collide/be on top of each other. And tetrominoes cannot be placed outside the board. Functions will return 0 or 1 if they collided or not.
- [X] 16. Create a clean tetromino function, if a tetromino collides then the tetromino will be cleared and then shifted to be placed at a different coordinate.
- [X] 17. Backtracking / recursive backtracking/ dancing links(Knuth's X Algorithm). This is when the size of the board will be increased.
- [ ] 18. Need to check for memory leaks
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

5. Function, `int **x_y_coordinates(char **characters)` converts the stored tetrominoes in x and y coordinates. Memory is allocated using malloc for the double pointer for a size of 26. Unlike the string where we allocate the memory of 21, in this case we only allocate memory for a size of 9, because we are only getting coordinates for x and y.

To get the x coordinate, we take nth position of a tetromino and do modulo 5. To get the y coordinate, we take nth position of a tetromino and divide that by 5.

Below on the right is what the tranformation will look like once we convert the hastags into coordinates:

<img src= "https://github.com/mohammadbutt/42_fillit/blob/master/media/hashes_to_corords_1.png">
<table>
  <tr>
    <td>x = 0, y = 0</td>
    <td>x = 1, y = 0</td>
    <td>x = 2, y = 0</td>
    <td>x = 3, y = 0</td>
    <td>\n</td>
  </tr>
</table>

<video src="https://github.com/mohammadbutt/42_fillit/blob/master/media/fillit_1080p.mov" width="320" height="200" controls preload></video>
![](https://github.com/mohammadbutt/42_fillit/blob/master/fillit_1080p_10fps.gif)
![](https://github.com/mohammadbutt/42_fillit/blob/master/media/fillit_1080p_30fps.gif)
![](https://github.com/mohammadbutt/42_fillit/blob/master/media/fillit.gif)
![ ](https://github.com/mohammadbutt/42_fillit/blob/master/media/fillit_1080p.gif)

# Resources:
1. [C Tutorials on Linked List](http://www.zentut.com/c-tutorial/c-linked-list/)
2. [19 Valid Tetrominoes - Wolfram](http://mathworld.wolfram.com/Tetromino.html)
3. [Empty Tetromines grid](https://gfredericks.com/things/polyominoes)
4. [Tetris Collision Detection](https://gamedevelopment.tutsplus.com/tutorials/implementing-tetris-collision-detection--gamedev-852)
5. [Bitwise calculator](https://www.binaryconvert.com/convert_unsigned_short.html)
6. [Another Bitwise calculator](http://bitwisecmd.com/)
7. [Data Types - Oracle](https://docs.oracle.com/javase/tutorial/java/nutsandbolts/datatypes.html)


