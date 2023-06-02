CXX = g++
CXXFLAGS = -std=c++11 -Wall

SRCS = game.cpp Chessboard.cpp Rook.cpp Knight.cpp Bishop.cpp Queen.cpp King.cpp Pawn.cpp Piece.cpp
OBJS = $(SRCS:.cpp=.o)
DEPS = $(SRCS:.cpp=.h)
TARGET = anarchyChess

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

.cpp.o:
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)
