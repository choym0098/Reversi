#include "grid.h"
#include "textdisplay.h"


using namespace std;

Grid::~Grid() {
  delete td,
  delete ob;
}

void Grid::setPiece(size_t r, size_t c, Colour colour) {
  if(theGrid[r][c].getInfo().colour == Colour::None) {
    theGrid[r][c].setPiece(colour);
    ++count;
    theGrid[r][c].notifyObservers();
  }
}
void Grid::toggle(size_t r, size_t c) {
  theGrid[r][c].toggle();
}

Colour Grid::whoWon() const {
  int white = 0;
  int black = 0;
  unsigned int n = theGrid.size();
  for(unsigned int i = 0; i < n; ++i) {
    for(unsigned int j = 0; j < n; ++j) {
      if (theGrid[i][j].getInfo().colour == Colour::Black) {
        ++black;
      } else if (theGrid[i][j].getInfo().colour == Colour::White) {
        ++white;
      }
    }
  }
  if (black == white) {
    return Colour::None;
  } else if (black > white) {
    return Colour::Black;
  } else {
    return Colour::White;
  }
}


void Grid::init(size_t n) {
  td = new TextDisplay{int(n)};
  //Make sure you clear the old grid. if necessary
 
  for(size_t i = 0; i < n; ++i) {
    vector<Cell> row;
    for(size_t j = 0; j < n; ++j) {
	      
      row.emplace_back(i, j);
      row[j].attach(td);
    }
    theGrid.emplace_back(row);
  }
  //link adjacent observers to the current observer
  int count = 0;
  int nInt = n;
  for(int i = 0; i < nInt; ++i) {
    for(int j = 0; j < nInt; ++j) {
      if ((i - 1) >= 0 && (j - 1) >= 0) {
        theGrid[i][j].attach(&theGrid[i-1][j-1]); //NW
        theGrid[i][j].attach(&theGrid[i-1][j]); //N
        theGrid[i][j].attach(&theGrid[i][j-1]); //W
      } else if ((i - 1) >= 0) {
        theGrid[i][j].attach(&theGrid[i-1][j]); //N
      } else if ((j - 1) >= 0) {
        theGrid[i][j].attach(&theGrid[i][j-1]); //W
      }
      if((i+1) <= (nInt-1) && (j-1) >= 0) {
       theGrid[i][j].attach(&theGrid[i+1][j-1]); //SW
        theGrid[i][j].attach(&theGrid[i+1][j]); //S
      } else if((i+1) < nInt) {
        theGrid[i][j].attach(&theGrid[i+1][j]); //S
      }
      if((i+1) <= (nInt-1) && (j+1) <= (nInt-1)) {
        theGrid[i][j].attach(&theGrid[i+1][j+1]); //SE
        theGrid[i][j].attach(&theGrid[i][j+1]); //E
      } else if (j + 1 < nInt) {
        theGrid[i][j].attach(&theGrid[i][j+1]); //E
      }
      if ((i-1) >= 0 && (j+1) <= (nInt-1)) {
        theGrid[i][j].attach(&theGrid[i-1][j+1]); // NE
      }
     ++count;
    
 
    }
  }

  theGrid[n / 2 - 1][n / 2 - 1].setPiece(Colour::Black);
  td->notify(theGrid[n / 2 - 1][n / 2 - 1]);

  theGrid[n / 2 - 1][n / 2].setPiece(Colour::White);

  td->notify(theGrid[n / 2 - 1][n / 2]);

  theGrid[n / 2][n / 2 - 1].setPiece(Colour::White);

  td->notify(theGrid[n / 2][n / 2 - 1]);

  theGrid[n / 2][n / 2].setPiece(Colour::Black);

  td->notify(theGrid[n / 2][n / 2]);
}


void Grid::setObserver(Observer<Info, State> *ob) {
  this->ob = ob;
}

ostream &operator<<(ostream &out, const Grid &g) {
  cout << *(g.td);
  return out;
}

bool Grid::isFull() const {
  unsigned int n = theGrid.size();
  if(count >= n*n-4) {
    return true;
  } else {
    return false;
  }
}







