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
enum Color{White,Black};

enum PieceType{
  Pawn, Knight,Rook,Bishop,Queen,King, NoPiece
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

ChessSquare* get_square(ChessBoard board, int rank, int file);
bool is_square_occupied(ChessBoard board, int rank, int file);
bool add_piece(ChessBoard board, int rank, int file, struct ChessPiece piece);
ChessPiece get_piece(ChessBoard board, int rank, int file);
void setup_chess_board(ChessBoard board);
