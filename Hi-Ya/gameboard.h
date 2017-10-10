#ifndef __HY_GAMEBOARD_H__
#define __HY_GAMEBOARD_H__

namespace hy
{
    enum player_type
    {
        Invalid, Computer, Player
    };
    
    enum piece_type
    {
        Null, King, Ninja, Samurai, Mini_Ninja, Mini_Samurai
    };
    
    struct piece
    {
        piece_type type = Null;
        player_type p_type = Invalid;
    };
    
    struct game_board
    {
        piece board_pieces[7][8];
    };

    void setup_board(game_board *);
    void run_board(game_board *);

    void do_player(game_board *);
    void do_computer(game_board *);
    
    void set_piece(game_board *, player_type, piece_type, int, int);
	piece get_piece(game_board *, int, int);

    bool is_valid_choice(game_board *, player_type, int x, int y);
    
    int letter_to_int_pos(const char);
    char int_to_letter_pos(int);

    char piece_to_char(piece_type);
}
#endif /* __HY_GAMEBOARD_H__ */
