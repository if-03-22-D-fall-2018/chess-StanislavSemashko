/*----------------------------------------------------------
 *				HTBLA-Leonding / Klasse: 2AHDV
 * ---------------------------------------------------------
 * Exercise Number: 0
 * Title:			chess.c
 * Author:			P. Bauer
 * Due Date:		November 03, 2010
 * ----------------------------------------------------------
 * Description:
 * Implementation of basic chess functions.
 * ----------------------------------------------------------
 */
#include "shortcut.h"
#include "test_chess.h"
#include "chess.h"

bool is_piece(struct ChessPiece piece, enum Color color,enum PieceType type)
{
    if(piece.color == color && piece.type == type)
    {
        return true;
    }
    return false;
}
void init_chess_board(ChessBoard chess_board)
{
    for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
	        chess_board[i][j].is_occupied = false;
            chess_board[i][j].piece.type = NoPiece;
		}
	}
}
ChessSquare* get_square(ChessBoard board, int file, int rank)
{
    if(rank >=1 && rank <= 8 && file >= 'a' && file <='h')
    {
        return &board[file -1][rank -97];
    }
    return 0;
}
bool is_square_occupied(ChessBoard board, int file, int rank)
{
    return board[file -1][rank -97].is_occupied;
}
bool add_piece(ChessBoard board, int file, int rank, struct ChessPiece piece)
{
    if(rank >=1 && rank <= 8 && file >= 'a' && file <='h' && board[file -1][rank -97].is_occupied)
    {
        board[file -1][rank -97].piece = piece;
        board[file -1][rank -97].is_occupied = true;
        return true;
    }
    return false;
}
ChessPiece get_piece(ChessBoard board, int file, int rank)
{
   return board[file -1][rank -97].piece;
}
void setup_chess_board(ChessBoard board)
{
 struct ChessPiece white_pawn = {White, Pawn};
 struct ChessPiece white_rook = {White, Rook};
 struct ChessPiece white_knight = {White, Knight};
 struct ChessPiece white_bishop = {White, Bishop};
 struct ChessPiece white_queen = {White, Queen};
 struct ChessPiece white_king = {White, King};

 struct ChessPiece black_pawn = {Black, Pawn};
 struct ChessPiece black_rook = {Black, Rook};
 struct ChessPiece black_knight = {Black, Knight};
 struct ChessPiece black_bishop = {Black, Bishop};
 struct ChessPiece black_queen = {Black, Queen};
 struct ChessPiece black_king = {Black, King};

 for(int file = 'a'; file <= 'h'; file++)
 {

     add_piece(board, file,2,white_pawn);
     add_piece(board, file,7,black_pawn);
 }
 add_piece(board,'a',1,white_rook);
 add_piece(board,'b',1,white_knight);
 add_piece(board,'c',1,white_bishop);
 add_piece(board,'d',1,white_queen);
 add_piece(board,'e',1,white_king);
 add_piece(board,'f',1,white_bishop);
 add_piece(board,'g',1,white_knight);
 add_piece(board,'h',1,white_rook);

 add_piece(board,'a',7,black_rook);
 add_piece(board,'b',7,black_knight);
 add_piece(board,'c',7,black_bishop);
 add_piece(board,'d',7,black_queen);
 add_piece(board,'e',7,black_king);
 add_piece(board,'f',7,black_bishop);
 add_piece(board,'g',7,black_knight);
 add_piece(board,'h',7,black_rook);
}

bool remove_piece(ChessBoard board, int file,int rank)
{
    if(is_square_occupied(board,file,rank))
    {
        board[file-1][rank-97].is_occupied = false;
        return false;
    }
    return true;
}

bool squares_share_file(int file, int rank, int file2, int rank2)
{
    if(rank >=1 && rank <= 8 && file >= 'a' && file <='h' && file == file2)
    {
        return true;
    }
    return false;
}
bool squares_share_rank(int file, int rank, int file2, int rank2)
{
    if(rank >=1 && rank <= 8 && file >= 'a' && file <='h' && rank == rank2)
    {
        return true;
    }
    return false;
}

bool squares_share_diagonal(int file, int rank, int file2, int rank2)
{
    if(rank >=1 && rank <= 8 && file >= 'a' && file <='h' && (file - file2) == (rank -rank2))
    {
        return true;
    }
    return false;

}


bool squares_share_knights_move(int file, int rank, int file2, int rank2)
{
  return false;
}

bool squares_share_pawns_move(Color color,Move move,int file, int rank, int file2, int rank2)
{
return false;
}

bool squares_share_queens_move(int file, int rank, int file2, int rank2)
{
return false;
}

bool squares_share_kings_move(int file, int rank, int file2, int rank2)
{
return false;
}
