#include "MapChip.h"
#include "DxLib.h"

MapChip::MapChip()
{
	LoadDivGraph("image/MapBlocks.png", 23, 23, 1, 32, 32, MapBlock_Image);


	w = 32;
	h = 32;
	x = 0;
	y = 0;

}

AbstractScene* MapChip::Update()
{
	return this;
}

void MapChip::Draw() const
{

}

void InitBlock(void)
{

}
