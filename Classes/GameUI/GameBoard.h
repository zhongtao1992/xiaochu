#ifndef __Clear__GameBoard__
#define __Clear__GameBoard__

#include "cocos2d.h"
USING_NS_CC;

class GameBoard:public CCLayer{
public:
	GameBoard();
	~GameBoard();
	CREATE_FUNC(GameBoard);
	bool init();
	void onEnter();
	void onExit();

public:
	void ccTouchesBegan(CCSet *pTouches, CCEvent *pEvent);
	void ccTouchesMoved(CCSet *pTouches, CCEvent *pEvent);
	void ccTouchesEnded(CCSet *pTouches, CCEvent *pEvent);

private:
	CCTMXTiledMap* pTileMap;
	CCLabelBMFont* label;
	float scale;
	float distance;
};
#endif