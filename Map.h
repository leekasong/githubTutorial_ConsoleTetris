#include "common.h"
struct Mapinfo
{
	char isBlock; // 0 - empty, 1 - wall, 2 - block
	int color;
	//... add needed variable.
};

class Map
{
 private:
    int m_col, m_row;
    Mapinfo **mp_play_map;
	Mapinfo **mp_side_map;
 public:
 	Map(int a_col, int a_row);
	Mapinfo **getPlayMap() { return 0; }
	Mapinfo **getSideMap() { return 0; }

	//void setMap(Block *pBlock);
	//check if map include complete lines.
	//fail -> -1, succeed -> number of lines
	int checkLines();
	void deleteLine();
	~Map();
};
