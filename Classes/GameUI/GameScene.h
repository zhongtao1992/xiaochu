#ifndef __Clear__GameScene__
#define __Clear__GameScene__

#include "cocos2d.h"
#include "GameUI/GameBoard.h"
USING_NS_CC;

class GameScene:public CCScene{
public:
	GameScene();
	~GameScene();
	CREATE_FUNC(GameScene);
	bool init();

private:
	GameBoard* m_GameBoard;
};
#endif