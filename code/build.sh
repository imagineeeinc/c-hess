if which program_name &> /dev/null; then
  cosmocc bishop.c chess.c movePieces.c printBoard.c tower.c calculateMoves.c methods.c king.c queen.c checkmate.c knight.c pawn.c printMenu.c moveCounters.c -o chess
else
  if [ -d "/usr/cosmocc" ]; then
    cosmocc bishop.c chess.c movePieces.c printBoard.c tower.c calculateMoves.c methods.c king.c queen.c checkmate.c knight.c pawn.c printMenu.c moveCounters.c -o chess
  else
    gcc bishop.c chess.c movePieces.c printBoard.c tower.c calculateMoves.c methods.c king.c queen.c checkmate.c knight.c pawn.c printMenu.c moveCounters.c -o chess
  fi
fi