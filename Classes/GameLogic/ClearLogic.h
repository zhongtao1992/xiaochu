/*
   游戏逻辑
   1、移动判断。移动某个方块之后如果有三个或三个以上(四或五)同颜色的方块，则触发消除，并得分；否则方块移回原位
   2、消除了方块之后，要从屏幕上方增加方块

   关于消除
   消除的条件：有三个，四个或五个同色的则消除
   移动方向有四个：向上、向下、向左、向右
   向上：
           向上移动后                        触发消除，并得分，被消除过的区域上方增加方块
           **************************三个*****************************
           。。。。。左边有两个同色的。。。。。。。。。。。。。。。。。。。。。。。。
           。。。。。右边。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。
		   。。。。。上方。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。
		   **********************************************************

		   **************************四个*****************************
		   。。。。。左边一个、右边两个。。。。。。。。。。。。。。。。。。。。。。。
		   。。。。。右边一个、左边两个。。。。。。。。。。。。。。。。。。。。。。。
		   **********************************************************

		   **************************五个*****************************
		   。。。。。左边、右边有两个。。。。。。。。。。。。。。。。。。。。。。。。
		   。。。。。左边、上方有两个。。。。。。。。。。。。。。。。。。。。。。。。
		   。。。。。右边、上方有两个。。。。。。。。。。。。。。。。。。。。。。。。
		   。。。。。左边、右边、上方有两个。。。。。。。。。。。。。。。。。。。。。
		   **********************************************************
	向左：
	向右：
	向下：

	二维数组，如I[3][4]：
	                I[0][0],I[0][1],I[0][2],I[0][3]
					I[1][0],I[1][1],I[1][2],I[1][3]
					I[2][0],I[2][1],I[2][2],I[2][3]
*/

#ifndef __Clear__ClearLogic__
#define __Clear__ClearLogic__

#include "GlobalData/GameData.h"

class ClearLogic
{
public:
	ClearLogic();
	~ClearLogic();
protected:
	/*int Block[MAX_LINE][MAX_RANK];*/
	void clearBlocks(/*int Block[i][j]*/);

	//四个方向的判断
	bool sameInUp(int Block[i][j]);
	bool sameInDown(int Block[i][j]);
	bool sameInRight(int Block[i][j]);
	bool sameInLeft(int Block[i][j]);
};
#endif