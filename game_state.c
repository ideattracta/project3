/*
*	Game State ADT Implementation
*	Author: <<YOUR STUDENT IDs AND NAMES HERE>>
*	Version: xxx
*
*	This file holds the game_state ADT.  It comprises
*	the coordinate of the knight's current position
*	(as "row" and "column"), and the board (as a
*	two-dimensional array called "board").
*
*	YOU NEED TO MAKE CHANGES TO THIS FILE!
*/


#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "game_state.h"
#include "assig_three123.h"


// types
struct game_state_int {
	int row;
	int column;
	int moves;
	square_state board[DIMENSION][DIMENSION];
};


/*
	*	init_game_state
	*	initialiser function.
	*	Pre-condition: none
	*	Post-condition: a game_state variable is created and pointed
	*					to by the first parameter.  Its row field
	*					is set to -1 its column field is set to -1,
	*					and each element in the board table is set
	*					to 'empty'
	*	Informally: creates an initial game_state
*/
void init_game_state(game_state* gp)
{
	int x, y;  // row and column indices

	trace("init_game_state: init_game_state starts");

	*gp = (game_state)malloc(sizeof(struct game_state_int));
	(*gp)->row = -1;
	(*gp)->column = -1;
	for (x = 1; x <= DIMENSION; x++)
	{
		for (y = 1; y <= DIMENSION; y++)
		{
			init_square_state(&((*gp)->board[x - 1][y - 1]), x, y);
		}
	}
	(*gp)->moves = 0;

	trace("init_game_state: init_game_state ends");
}


/*
* 	get_row
*	Get function for row field.
*	Pre-condition: none
*	Post-condition: the value of the game_state variable's row
*					field is returned
*	Informally: return the game_state variable's row
*
*	return int the current row number of the knight
*/
int get_row(game_state s)
{
	trace("get_row: get_row starts and finishes");

	// return the current row of the knight
	return s->row;
}


/*
* 	get_column
*	Get function for column field.
*	Pre-condition: none
*	Post-condition: the value of the game_state variable's column
*					field is returned
*	Informally: return the game_state variable's column
*
*	return int the current column number of the knight
*/
int get_column(game_state s)
{
	trace("get_column: get_column starts and finishes");

	// Return the current  colomn of the knight
	return s->column;
}


/*
* 	set_row
*	Set function for row field.
*	Pre-condition: the given game_state is defined and the given row
*					is within the bounds of that game_state variable's
*					board
*	Post-condition: the value of the game_state variable's row
*					field is updated to the given int value
*	Informally: update the game_state variable's row
*
* Param r int value to be placed into the game_state's row field
*/
void set_row(game_state s, int r)
{
	trace("set_row: set_row starts");

	// set the row of the knight to given value
	s->row = r;

		trace("set_row: set_row ends");
}


/*
* 	set_column
*	Set function for column field.
*	Pre-condition: the given game_state is defined and the given column
*					is within the bounds of that game_state variable's
*					board
*	Post-condition: the value of the game_state variable's column
*					field is updated to the given int value
*	Informally: update the game_state variable's column
*
*	Param c int value to be placed into the game_state's column field
*/
void set_column(game_state s, int c)
{
	trace("set_column: set_column starts");

	// set the colomn of the knight to the given value
	s->column = c;

		trace("set_column: set_column ends");
}


/*
	*	get_moves
	*	Get count of number of moves on the board.
	*	Pre-condition: the given game_state has at least one knight on it.
	*	Post-condition: the number of knights on the board is returned.
	*	Informally: determine the number of moves which have been made
	*
	*	return int the number of moves made on the board
*/
int get_moves(game_state g)
{
	trace("get_moves: get_moves starts and finishes");

	// return the number of moves  made on the board
	return g->moves;

}


/*
	*	set_moves
	*	Set count of number of moves on the board.
	*	Pre-Condition: the given game_state has been defined.
	*	Post-Condition: the moves field of the given game_state has been
	*					updated.
	*	Informally: remember how many moves have been made
*/
void set_moves(game_state g, int m)
{
	trace("set_moves: set_moves starts");

	// set the number of moves made on the board
	g->moves = m;

		trace("set_moves: set_moves ends");
}
/*
	* 	get_square
	*	Get function for a square_state.
	*	Pre-condition: the given coordinate is within the bounds of the board
	*	Post-condition: the value of the indicated square_state variable
	*					is returned
	*	Informally: return the square_state in the game_state variable's board
	*
	*	Param int r the row component of the desired square's coordinate
	*	Param int c the column component of the desired square's coordinate
	*
	*	return square_state the nominated square_state
*/
square_state get_square(game_state g, int r, int c)
{
	trace("get_square: get_square starts and finishes");

	// return the square state at the specific row and coloumn
	return g->board[r - 1][c - 1];
}


/*
	* 	set_square
	*	Set function for a square_state.
	*	Pre-condition: the given square_state value is defined and is within the
	*				   dimension of the board array
	*	Post-condition: the square of the board at the given coordinate is updated
	*					to the given square_state value
	*	Informally: update the game_state board variable's element to the given value
	*
	*	Param set_square s value to be placed into the game_state's board field
*/
void set_square(game_state g, square_state s)
{
	int r, c;	// row and column of given square_state

	trace("set_square: set_square starts");

	// get the row and coloumn from the square_state
	r = get_row_square(s);
	c = get_column_square(s);

	//set the value of the board at the specific row and column
	g->board[r - 1][c - 1]= s;


		trace("set_square: set_square ends");
}


/*
	* 	valid
	*	Check whether a square is on the board
	*	Pre-condition: the given game_state is defined
	*	Post-condition: true is returned if (r,c) is within the bounds
	*					of the given game_state variable's board field,
	*					and false is returned otherwise
	*	Informally: Return whether or not a square is on the board
	*
	*	Param r int row value to check
	*	Param c int column value to check
	*
	*	return bool whether the coordinate is on the board
	*/
bool valid(game_state g, int r, int c)
{
	trace("valid: valid starts and finishes");

	// check row and column value are within the board dimension
	return (r >= 1) && (r <= DIMENSION) && (c >= 1) && (c <= DIMENSION);

}


/*
	* 	taken
	*	Check whether a square on the board has already been visited
	*	Pre-condition: the given game_state is defined and (r,c) is
	*					within the bounds of the given game_state
	*					variable's board field
	*	Post-condition: true is returned if (r,c) has been visited (i.e.
	*					is non-zero, and false is returned otherwise
	*	Informally: Return whether or not a square has been taken
	*
	*	Param r int row value to check
	*	Param c int column value to check
	*
	*	return bool whether the nominated square contains a queen
	*/
bool taken(game_state g, int r, int c)
{
	trace("taken: taken starts and finishes");

	// check if the square at the specified row and column has been  visitied 
	return get_visited(get_square(g, r, c));
}


/*
* 	land
*	Visit a square on the board
*	Pre-condition: the given game_state is defined and (r,c) is
*					within the bounds of the given game_state
*					variable's board field
*	Post-condition: the square at (r,c) has been visited and it
*					has been recorded that this is the current
*					location of the knight in the given board
*	Informally: Visit a square
*
*	Param r int row value to use
*	Param c int column value to use
*/
void land(game_state g, int r, int c)
{
	trace("land: land starts");

	//COMPLETE ME!
	// visit  the square  at the specified  row and column
	set_visited(get_square(g, r, c)), true;

	// update the knight position
	set_row(g, r);
	set_column(g, c);

	//increment the number of moves 
	set_moves(g, get_moves(g) + 1);


		trace("land: land ends");
}


/*
* 	clone_game_state
*	Deeply clone a game_state
*	Pre-condition: the given game_state is defined
*	Post-condition: a deep clone of the given game_sate is returned
*	Informally: Copy a game
*
*	return game_state the independent copy of the game_state
*/
game_state clone_game_state(game_state g)
{
	game_state p;
	int r, c;

	trace("clone_game_state: clone_game_state starts");

	//COMPLETE ME!
	// create new game state
	init_game_state(&p);

	// copy the value  from the given  game_sate
	for (r = 1; r <= DIMENSION; r++)
	{
		for (c = 1; c <= DIMENSION; c++)
		{
			set_square(p, clone_square_state(get_square(g, r, c)));
		}
	}

	//set the knight position and number moves 
	set_row(p, get_row(g));
	set_column(p, get_column(g));
	set_moves(p, get_moves(g));


		trace("clone_game_state: clone_game_state finishes");

	// return the deep clone of the game state.
	return p;
}


/*
	* 	show_game_state
	*	Display a game state
	*	Pre-condition: the given game_state is defined
	*	Post-condition: the given game_state has been displayed on
	*					the standard output stream
	*	Informally: Print the board
*/
void show_game_state(game_state g)
{
	int x, y;

	trace("show_game_state: show_game_state starts");

	// for all rows
	for (x = 1; x <= DIMENSION; x++)
	{
		// print row separator
		printf("+");
		for (y = 1; y <= DIMENSION * 4 - 1; y++)
		{
			printf("-");
		}
		printf("+\n");

		// print all columns
		printf("|");
		for (y = 1; y <= DIMENSION; y++)
		{
			show_square_state(get_square(g, x, y));
			printf("|");
		}
		printf("\n");
	}

	// print row separator
	printf("+");
	for (y = 1; y <= DIMENSION * 4 - 1; y++)
	{
		printf("-");
	}
	printf("+\n");

	trace("show_game_state: show_game_state ends");
}