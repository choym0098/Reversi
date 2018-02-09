#include "cell.h"
#include "textdisplay.h"

using namespace std;

TextDisplay::TextDisplay(int n): gridSize{n} {
	char c = '-';
	for(int i = 0; i < n; ++i) {
		vector<char> row;
		for(int j = 0; j < n; ++j) {
			row.emplace_back(c);
		}
		theDisplay.emplace_back(row);
	}
}

void TextDisplay::notify(Subject<Info, State> &whoNotified) {
	Info info = whoNotified.getInfo();
	if(info.colour == Colour::Black) {
		theDisplay[info.row][info.col] = 'B';
	} else if(info.colour == Colour::White) {
		theDisplay[info.row][info.col] = 'W';
	} else {
		theDisplay[info.row][info.col] = '-';
	}
}

ostream &operator<<(ostream &out, const TextDisplay &td) {
	unsigned int n = td.theDisplay.size();
  	for(unsigned int i = 0; i < n; ++i) {
    	for(unsigned int j = 0; j < n; ++j) {
      		out << td.theDisplay[i][j];
    	}
    	out << endl;
  	}
	return out;
}
