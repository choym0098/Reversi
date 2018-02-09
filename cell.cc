#include <iostream>
#include "cell.h"
#include <string>
#include <vector>

using namespace std;

Cell::Cell(size_t r, size_t c): r{r}, c{c} {
}

void Cell::setPiece(Colour colour) {
	this->colour=colour;
	State s{StateType::NewPiece, colour, Direction::NE};
	this->setState(s);
}

void Cell::toggle() {
	if (colour == Colour::Black) {
		colour = Colour::White;
	} else if (colour == Colour::White) {
		colour = Colour::Black;
	}
}



void Cell::notify(Subject<Info, State> &whoFrom) {
	//First Notification
	Info mom = whoFrom.getInfo();
	int rM = mom.row;
	int cM = mom.col;
	Colour colM = mom.colour;
 	Info child = this->getInfo();
 	int rC = child.row;
 	int cC = child.col;
 	Colour colC = child.colour;
 	int rDiff = rC - rM;
 	int cDiff = cC - cM;
 	State s = whoFrom.getState();

 	//First 8 neighbor
 	if (s.type == StateType::NewPiece) {
 		if (rDiff == -1 && cDiff == -1) { //NW

 			if (colC == Colour::None) {

 			} else if (!(colM == colC)) {
 				State newState{StateType::Relay, colC, Direction::NW};
 				this->setState(newState);
 				this->notifyObservers();
 			}
 		} else if (rDiff == -1 && cDiff == 0) { //N

 			if (colC == Colour::None) {

 			} else if (!(colM == colC)) {
 				State newState{StateType::Relay, colC, Direction::N};
 				this->setState(newState);
 				this->notifyObservers();
 			}
	 	} else if (rDiff == -1 && cDiff == 1) { //NE
	 	
			if (colC == Colour::None) {

 			} else if (!(colM == colC)) {
 				State newState{StateType::Relay, colC, Direction::NE};
 				this->setState(newState);
 				this->notifyObservers();
 			}
 		} else if (rDiff == 0 && cDiff == -1) { //W

 			if (colC == Colour::None) {

 			} else if (!(colM == colC)) {
 				State newState{StateType::Relay, colC, Direction::W};
 				this->setState(newState);
 				this->notifyObservers();
 			}
 		} else if (rDiff == 0 && cDiff == 1) { //E

 			if (colC == Colour::None) {

 			} else if (!(colM == colC)) {
 				State newState{StateType::Relay, colC, Direction::E};
 				this->setState(newState);
 				this->notifyObservers();
 			}
 		} else if (rDiff == 1 && cDiff == -1) { //SW

 			if (colC == Colour::None) {

 			} else if (!(colM == colC)) {
 				State newState{StateType::Relay, colC, Direction::SW};
 				this->setState(newState);
 				this->notifyObservers();
 			}
 		} else if (rDiff == 1 && cDiff == 0) { //S

 			if (colC == Colour::None) {

 			} else if (!(colM == colC)) {
 				State newState{StateType::Relay, colC, Direction::S};
 				this->setState(newState);
 				this->notifyObservers();
 			}
	 	} else if (rDiff == 1 && cDiff == 1) { //SE

	 		if (colC == Colour::None) {

 			} else if (!(colM == colC)) {
 				State newState{StateType::Relay, colC, Direction::SE};
 				this->setState(newState);
 				this->notifyObservers();
 			}
 		}


 	} else if (s.type == StateType::Relay) {


 		if (s.direction == Direction::NW) {
			if(rDiff == -1 && cDiff == -1) {
				if (colC == Colour::None) {

 				} else if(!(colM == colC)) {
 					State newState{StateType::Reply, colC, Direction::SE}; //Now going backwards
 					this->setState(newState);
 					this->notifyObservers();
 				} else {
					State newState{StateType::Relay, colC, Direction::NW};
					this->setState(newState);
 					this->notifyObservers();
 				}
 			}
 		} else if (s.direction == Direction::N) {
			if(rDiff == -1 && cDiff == 0) {
 				if (colC == Colour::None) {

                                } else if(!(colM == colC)) {
 					State newState{StateType::Reply, colC, Direction::S}; //Now going backwards
 					this->setState(newState);
 					this->notifyObservers();
 				} else {
                                        State newState{StateType::Relay, colC, Direction::N};
                                        this->setState(newState);
 					this->notifyObservers();
 				}
 			}
 		} else if (s.direction == Direction::NE) {
			if(rDiff == -1 && cDiff == 1) {
				if (colC == Colour::None) {

                                } else if(!(colM == colC)) {
 					State newState{StateType::Reply, colC, Direction::SW}; //Now going backwards
 					this->setState(newState);
 					this->notifyObservers();
 				} else {
                                        State newState{StateType::Relay, colC, Direction::NE};
                                        this->setState(newState);
 					this->notifyObservers();
 				}
 			}
 		} else if (s.direction == Direction::W) {
			if(rDiff == 0 && cDiff == -1) {
				if (colC == Colour::None) {

                                } else if(!(colM == colC)) {
 					State newState{StateType::Reply, colC, Direction::E}; //Now going backwards
 					this->setState(newState);
 					this->notifyObservers();
 				} else {
                                        State newState{StateType::Relay, colC, Direction::W};
                                        this->setState(newState);
 					this->notifyObservers();
 				}
 			}
 		} else if (s.direction == Direction::E) {
			if(rDiff == 0 && cDiff == 1) {
				if (colC == Colour::None) {

                                } else if(!(colM == colC)) {
 					State newState{StateType::Reply, colC, Direction::W}; //Now going backwards
 					this->setState(newState);
 					this->notifyObservers();
 				} else {
                                        State newState{StateType::Relay, colC, Direction::E};
                                        this->setState(newState);
 					this->notifyObservers();
 				}
 			}
 		} else if (s.direction == Direction::SW) {
			if(rDiff == 1 && cDiff == -1) {
				if (colC == Colour::None) {

                                } else if(!(colM == colC)) {
 					State newState{StateType::Reply, colC, Direction::NE}; //Now going backwards
 					this->setState(newState);
 					this->notifyObservers();
 				} else {
                                        State newState{StateType::Relay, colC, Direction::SW};
                                        this->setState(newState);
 					this->notifyObservers();
 				}
 			}
 		} else if (s.direction == Direction::S) {
			if(rDiff == 1 && cDiff == 0) {
				if (colC == Colour::None) {

                                } else if(!(colM == colC)) {
 					State newState{StateType::Reply, colC, Direction::N}; //Now going backwards
 					this->setState(newState);
 					this->notifyObservers();
 				} else {
                                        State newState{StateType::Relay, colC, Direction::S};
                                        this->setState(newState);
 					this->notifyObservers();
 				}
 			}
 		} else if (s.direction == Direction::SE) {
			if(rDiff == 1 && cDiff == 1) {
				if (colC == Colour::None) {

                                } else if(!(colM == colC)) {
 					State newState{StateType::Reply, colC, Direction::NW}; //Now going backwards
 					this->setState(newState);
 					this->notifyObservers();
 				} else {
                                        State newState{StateType::Relay, colC, Direction::SE};
                                        this->setState(newState);
 					this->notifyObservers();
 				}
 			}
 		}


 	} else if (s.type == StateType::Reply) {

 		if (s.direction == Direction::NW) {
			if(rDiff == -1 && cDiff == -1) {
				if(colC == Colour::None) {
				
 				} else if(colM != colC) {
 					State newState{StateType::Reply, colC, Direction::NW}; 
 					this->setState(newState);
 					this->toggle();
 					this->notifyObservers();
 				}
 			}
 		} else if (s.direction == Direction::N) {
 			if(rDiff == -1 && cDiff == 0) {
				if(colC == Colour::None) {

                                } else if(colM != colC) {
 					State newState{StateType::Reply, colC, Direction::N}; 
 					this->setState(newState);
 					this->toggle();
 					this->notifyObservers();
 				}
 			}
 		} else if (s.direction == Direction::NE) {
			if(rDiff == -1 && cDiff == 1) {
				if(colC == Colour::None) {

                                } else if(colM != colC) {
 					State newState{StateType::Reply, colC, Direction::NE}; 
 					this->setState(newState);
 					this->toggle();
 					this->notifyObservers();
 				}
 			}
 		} else if (s.direction == Direction::W) {
			if(rDiff == 0 && cDiff == -1) {
				if(colC == Colour::None) {

                                } else if(colM != colC) {
 					State newState{StateType::Reply, colC, Direction::W}; 
 					this->setState(newState);
 					this->toggle();
 					this->notifyObservers();
 				}
 			}
 		} else if (s.direction == Direction::E) {
			if(rDiff == 0 && cDiff == 1) {
				if(colC == Colour::None) {

                                } else if(colM != colC) {
 					State newState{StateType::Reply, colC, Direction::E}; 
 					this->setState(newState);
 					this->toggle();
 					this->notifyObservers();
 				}
 			}
 		} else if (s.direction == Direction::SW) {
			if(rDiff == 1 && cDiff == -1) {
				if(colC == Colour::None) {

                                } else if(colM != colC) {
 					State newState{StateType::Reply, colC, Direction::SW}; 
 					this->setState(newState);
 					this->toggle();
 					this->notifyObservers();
 				}
 			}
 		} else if (s.direction == Direction::S) {
			if(rDiff == 1 && cDiff == 0) {
 				if(colC == Colour::None) {

                                } else if(colM != colC) {
 					State newState{StateType::Reply, colC, Direction::S}; 
 					this->setState(newState);
 					this->toggle();
 					this->notifyObservers();
 				}
 			}
 		} else if (s.direction == Direction::SE) {
			if(rDiff == 1 && cDiff == 1) {
 				if(colC == Colour::None) {

                                } else if(colM != colC) {
 					State newState{StateType::Reply, colC, Direction::SE}; 
 					this->setState(newState);
 					this->toggle();
 					this->notifyObservers();
 				}
 			}
 		}



 	}

}



Info Cell::getInfo() const {
	Info info{r, c, colour};
	return info;
}

