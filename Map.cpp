#include "Map.h"

Map::Map(int a_col, int a_row)
{
  this->m_col = a_col;
  this->m_row = a_row;
  
  mp_play_map = new Mapinfo* [m_col];
  for(int i = 0; i < this->m_col; i++){
  //  *(pMap + i) = new Mapinfo[m_col];
  }
}

Map::~Map()
{
  /* for(int i = 0; i < this->nRow; i++){
    delete[] *(pMap + i);
  }
  delete[] pMap;*/
}



int Map::checkLines()
{
  //iterate and if complete line found, then call deleteLine
	return 1;
}

void Map::deleteLine()
{
  
}

