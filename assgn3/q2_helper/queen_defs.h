struct Vars {
	int count;
    int full_one;
	/** DO NOT CHANGE ANYTHING ABOVE THIS LINE **/
	
	/** Add any global variables you may want below this line **/


	/** Define this function which takes in the N to solve for. This is called
	 * before calling countQueens from main **/
	void setup(int N) {
		count = 0;	
        full_one = (N==32? 0xffffffff : (1<<N);
	}

};

extern Vars glob_vars;

inline bool solved(int col, int ld, int rd) {
	// Must return true iff queens have been placed on each row.
    if(col==glob_vars.full_one)
        return true;
	return false;
}

inline int getValidPositions(int col, int ld, int rd) {
	// Must return a bit vector with 1s in positions where it is
	// safe to place a queen
	return 0;
}

inline bool positionsAvailable(int valid_positions) {
	// Must return true iff there are safe positions to place
	// queens
	return false;
}

inline int chooseOnePosition(int valid_positions) {
	// Must return an int with exactly one bit set as 1.
	// This bit must be chosen from the positions where
	// validPositions is also 1.
	return 0;
}

inline int removeChosenPosition(int valid_positions, int cur_posn) {
	// Must return a bit pattern with one less 1, and this one is
	// removed from the position where cur_posn is 1.
	return 0;
}

inline int calcNewColDanger(int col, int cur_posn) {
	// Must return a bit pattern with the updated
	// column dangers due to placing a queen on cur_posn
	return 0;
}

inline int calcNewLdDanger(int ld, int cur_posn) {
	// Must return a bit pattern with the updated
	// bottom left diagonal dangers due to placing a queen 
	// on cur_posn
	return 0;
}

inline int calcNewRdDanger(int rd, int cur_posn) {
	// Must return a bit pattern with the updated
	// bottom right diagonal dangers due to placing a queen
	// on cur_posn
	return 0;
}
