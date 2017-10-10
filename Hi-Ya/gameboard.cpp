#include "gameboard.h"
#include <stdlib.h>
#include <stdio.h>
#include <memory.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>

void hy::setup_board(hy::game_board *board)
{  
    //North
    set_piece(board, Computer, King, 4, 8);
    set_piece(board, Computer, Ninja, 1, 7);
    set_piece(board, Computer, Ninja, 2, 7);
    set_piece(board, Computer, Ninja, 3, 7);
    set_piece(board, Computer, Samurai, 5, 7);
    set_piece(board, Computer, Samurai, 6, 7);
    set_piece(board, Computer, Samurai, 7, 7);
    set_piece(board, Computer, Mini_Samurai, 1, 6);
    set_piece(board, Computer, Mini_Samurai, 2, 6);
    set_piece(board, Computer, Mini_Samurai, 3, 6);
    set_piece(board, Computer, Mini_Ninja, 5, 6);
    set_piece(board, Computer, Mini_Ninja, 6, 6);
    set_piece(board, Computer, Mini_Ninja, 7, 6);
    //South
    set_piece(board, Player, King, 4, 1);
    set_piece(board, Player, Ninja, 5, 2);
    set_piece(board, Player, Ninja, 6, 2);
    set_piece(board, Player, Ninja, 7, 2);
    set_piece(board, Player, Samurai, 1, 2);
    set_piece(board, Player, Samurai, 2, 2);
    set_piece(board, Player, Samurai, 3, 2);
    set_piece(board, Player, Mini_Samurai, 5, 3);
    set_piece(board, Player, Mini_Samurai, 6, 3);
    set_piece(board, Player, Mini_Samurai, 7, 3);
    set_piece(board, Player, Mini_Ninja, 1, 3);
    set_piece(board, Player, Mini_Ninja, 2, 3);
    set_piece(board, Player, Mini_Ninja, 3, 3);

	for (auto col = 0; col < 7; col++)
	{
		for (auto row = 0; row < 8; row++)
		{
			switch (board->board_pieces[col][row].type)
			{
			case King:
			case Ninja:
			case Samurai:
			case Mini_Samurai:
			case Mini_Ninja:
				break;
			default: {
				board->board_pieces[col][row].p_type = Invalid;
				board->board_pieces[col][row].type = Null;
			} break;
			}
		}
	}
}

void print_board(hy::game_board *board)
{
    printf("\t  ---------------------     Mabo Tofu\n");
    for (auto row = 7; row >= 0; row--)
    {
        printf("\t%d", row + 1);
        for (auto col = 0; col < 7; col++)
        {
            printf("  %c", piece_to_char(board->board_pieces[col][row].type));
        }
        printf("\n");
    }
    printf("\t  ---------------------     Human\n");
    printf("\t   A  B  C  D  E  F  G\n");
}

void hy::run_board(hy::game_board *board)
{   
    while (true)
    {
        print_board(board);
        do_player(board);
    }
}

void hy::do_player(hy::game_board *board)
{
    std::string choice;
	char x1;
	int y1;
	piece_type type;
	char x2;
	int y2;
	do
	{
		printf("Choose YOUR move: ");
		std::cin >> choice;
		std::transform(choice.begin(), choice.end(), choice.begin(), ::toupper);
		std::stringstream choice_stream(choice);
		choice_stream >> x1;
		choice_stream >> y1;
		choice_stream >> x2;
		choice_stream >> y2;
		type = get_piece(board, letter_to_int_pos(x1), y1).type;
	} while ((is_valid_choice(board, Player, letter_to_int_pos(x1), y1)) && (!is_valid_choice(board, Invalid, letter_to_int_pos(x2), y2)));

	set_piece(board, Invalid, Null, letter_to_int_pos(x1), y1);
	set_piece(board, Player, type, letter_to_int_pos(x2), y2);
}

void hy::do_computer(hy::game_board *board)
{
}

bool hy::is_valid_choice(hy::game_board *board, player_type p_type, int x, int y)
{
    return get_piece(board, x, y).p_type == p_type;
}

void hy::set_piece(hy::game_board *board, hy::player_type p_type, hy::piece_type type, int x, int y)
{
    board->board_pieces[x - 1][y - 1].p_type = p_type;
    board->board_pieces[x - 1][y - 1].type = type;
}

hy::piece hy::get_piece(hy::game_board *board, int x, int y)
{
	return board->board_pieces[x - 1][y - 1];
}

int hy::letter_to_int_pos(const char pos)
{
    switch (pos)
    {
        case 'A':
            return 1;
        case 'B':
            return 2;
        case 'C':
            return 3;
        case 'D':
            return 4;
        case 'E':
            return 5;
        case 'F':
            return 6;
        case 'G':
            return 7;
        default:
            return 8;
    }
}

char hy::int_to_letter_pos(int pos)
{
    switch (pos)
    {
        case 1:
            return 'A';
        case 2:
            return 'B';
        case 3:
            return 'C';
        case 4:
            return 'D';
        case 5:
            return 'E';
        case 6:
            return 'F';
        case 7:
            return 'G';
        default:
            return 'H';
    }
}

char hy::piece_to_char(piece_type type)
{
    switch (type)
    {
        case King:
            return 'K';
        case Samurai:
            return 'S';
        case Ninja:
            return 'J';
        case Mini_Samurai:
            return 's';
        case Mini_Ninja:
            return 'j';
        default:
            return ' ';
    }
}
