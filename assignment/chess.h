/*----------------------------------------------------------
 *				HTBLA-Leonding / Klasse: 2AHDV
 * ---------------------------------------------------------
 * Exercise Number: 0
 * Title:			chess.h
 * Author:			P. Bauer
 * Due Date:		October 15, 2014
 * ----------------------------------------------------------
 * Description:
 * Basic chess functions.
 * ----------------------------------------------------------
 */

 #include <stdbool.h>
  #ifndef ___CHESS_H
 #define ___CHESS_H


enum Color{White,Black};

enum PieceType{
  Pawn, Knight,Rook,Bishop,Queen,King, NoPiece
};
enum Move{
    NormalMove,CaptureMove
};
struct ChessPiece{
  enum Color color;
  enum  PieceType type;
};

struct ChessSquare{
  bool is_occupied;
  struct ChessPiece piece;
};

typedef ChessSquare ChessBoard[8][8];
typedef int File;
typedef int Rank;

bool is_piece(struct ChessPiece piece, enum Color color,enum PieceType type);

void init_chess_board(ChessBoard chess_board);

ChessSquare* get_square(ChessBoard board, int file, int rank);
bool is_square_occupied(ChessBoard board, int file, int rank);
bool add_piece(ChessBoard board, int file, int rank, struct ChessPiece piece);
ChessPiece get_piece(ChessBoard board, int file, int rank);
void setup_chess_board(ChessBoard board);

bool remove_piece(ChessBoard board, int file,int rank);

bool squares_share_file(int file, int rank, int file2, int rank2);

bool squares_share_rank(int file, int rank, int file2, int rank2);

bool squares_share_diagonal(int file, int rank, int file2, int rank2);

bool squares_share_knights_move(int file, int rank, int file2, int rank2);

bool squares_share_pawns_move(Color color,Move move,int file, int rank, int file2, int rank2);

bool squares_share_queens_move(int file, int rank, int file2, int rank2);

bool squares_share_kings_move(int file, int rank, int file2, int rank2);

#endif
