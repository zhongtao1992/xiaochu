#include "GameLogic/ClearLogic.h"
USING_NS_CC;

ClearLogic::ClearLogic()
{
// 	for(int i=0;i<MAX_LINE;i++)
// 	{
// 		for (int j=0;j<MAX_RANK;j++)
// 		{
// 			Block[i][i]=NULL;
// 		}
// 	}
}
//消除判断，应该是传入一个位置，再根据这个位置做四个方向的判断
void ClearLogic::clearBlocks(/*int Block[i][j]*/)
{
	//向上移动。即列位置不变，行数减一。如I[2][0]位置的元素向上移动后为I[1][0]
// 	if (Block[i][j])
// 	{
// 	}
}

// bool ClearLogic::sameInUp(int Block[i][j])
// {
// 	if (Block[i][j])
// 	{
// 	}
// }