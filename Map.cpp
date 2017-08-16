#include "Map.h"

Map::Map(int a_col, int a_row)
{
  this->m_total_col = a_col;
  this->m_total_row = a_row;

  m_play_col = m_total_col * 3 / 4;
  m_side_col = m_total_col * 1 / 4;
  
  mp_play_map = new Mapinfo* [m_play_col];
  mp_side_map = new Mapinfo* [m_side_col];
  for(int i = 0; i < m_total_row; i++){
	*(mp_play_map + i) = new Mapinfo[m_play_col];
	memset(*(mp_play_map + i), 0, sizeof(Mapinfo) * m_play_col);
	*(mp_side_map + i) = new Mapinfo[m_side_col];
	memset(*(mp_side_map + i), 0, sizeof(Mapinfo) * m_side_col);
  }

  for(int i = 0; i < m_play_col; i++){
	  mp_play_map[0]->isBlock = 1;
  }

  for(int i = 0; i < m_side_col; i++){
	  mp_side_map[0]->isBlock = 1;
  }

}

Map::~Map()
{
 	for(int i = 0; i < m_total_row; i++){
		delete[] *(mp_play_map + i);
		delete[] *(mp_side_map + i);
  	}
	delete[] mp_play_map;
	delete[] mp_side_map;
}


int Map::checkLines()
{
  //iterate and if complete line found, then call deleteLine
	return 1;
}

void Map::deleteLine()
{
  
}

