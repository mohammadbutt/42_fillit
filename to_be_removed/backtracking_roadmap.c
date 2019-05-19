//------------------------------STEP 1--------------------------------------

int				place_next_piece(t_game *tetromino, t_uint8 i)

{
	t_uint64	piece_mask;
	t_int8		row;
	t_int8		col;

	if (we are one after the last piece.)// If we have placed all the tetrominoes)
		return (SUCCESS);

	row = 0;

	while (is piece within board in row - board collision)
	{
		col = 0;
		while (is piece within board in column - board collision) //Collision
			if (piece does not collide with another piece)
			{
				place_piece at row and col// alpha_on_grid
				if (place_next_piece(tetromino, i + 1) == SUCCESS) // function calls on to itself
					return (SUCCESS);
				remove_piece at row and col// clear_tetro
			}
	}

	return (FAILURE); // If failure then increase size of the board.
}

//--------------------------------STEP 2-----------------------------------------
// If the above fails to place the tetromino on the board and exhaustas all possibilities,
// then we increase the size of the board and call on to the above function again.


