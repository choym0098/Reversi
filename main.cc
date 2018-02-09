#include <iostream>
#include <string>
#include "grid.h"
#include "state.h"
#include "graphicsdisplay.h"


using namespace std;

int main(int argc, char *argv[]) {
  cin.exceptions(ios::eofbit|ios::failbit);
  string cmd;
  Grid g;

  int check = 1; // 1 = Black, 2 = White

  try {
  while (true) {
    cin >> cmd;
    if (cmd == "new") {
      int n;
      cin >> n;
      if (n % 2 == 0 && n >= 4) {
	g.init(n);
        cout << g;
	
      }
    }
    else if (cmd == "play") {
      int r = 0, c = 0;
      cin >> r >> c;
      if (check == 1) { //Black
          g.setPiece(r, c, Colour::Black);
          check = 2;
	
      } else { //White
          g.setPiece(r, c, Colour::White);
          check = 1;
	
      }
      cout << g;
      if(g.isFull()) break;
    }
  }
  if (g.whoWon() == Colour::Black) {
    cout << "Black Wins!" << endl;
  } else if (g.whoWon() == Colour::White) {
    cout << "White Wins!" << endl;
  } else {
    cout << "Tie!" << endl;
  }
  }
  catch (ios::failure &) {}  // Any I/O failure quits

}


