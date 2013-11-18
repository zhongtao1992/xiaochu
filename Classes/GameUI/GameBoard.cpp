#include "GameUI/GameBoard.h"

GameBoard::GameBoard(){
	pTileMap=NULL;
	scale=0.0;
	distance=0.0;
}
GameBoard::~GameBoard(){

}

bool GameBoard::init(){
	bool bRet=false;
	do 
	{
		CC_BREAK_IF(!CCLayer::init());

		this->setTouchEnabled(true);
		//tileMap test
		//text begin
		pTileMap=CCTMXTiledMap::create("tile.tmx");
		pTileMap->setAnchorPoint(ccp(0.5,0.5));
		CC_BREAK_IF(!pTileMap);
		/*pTileMap->setPosition(ccp(0,0));*/
		this->addChild(pTileMap);
		
		CCTMXObjectGroup* group=pTileMap->objectGroupNamed("objects");
		CCDictionary* dic=group->objectNamed("player");
		float x=((CCString*)dic->objectForKey("x"))->floatValue();
		float y=((CCString*)dic->objectForKey("y"))->floatValue();
		CCLog("x=%f   y=%f",x,y);
		CCSprite* player=CCSprite::create("Player.png");
		player->setPosition(ccp(x,y));
		pTileMap->addChild(player);
		

		CCSprite* sprite=CCSprite::create("CloseNormal.png");
		sprite->setPosition(ccp(100,100));
		this->addChild(sprite);
		//test end

		bRet=true;
	} while (0);
	return bRet;
}

void GameBoard::onEnter(){
	CCLayer::onEnter();
}

void GameBoard::onExit(){
	CCLayer::onExit();
}
void GameBoard::ccTouchesBegan(CCSet *pTouches, CCEvent *pEvent){
	
}

void GameBoard::ccTouchesMoved(CCSet *pTouches, CCEvent *pEvent){
	float lastDistance=0;
	scale=pTileMap->getScale();
	if (pTouches->count()==1)
	{
		CCSetIterator ite=pTouches->begin();
		CCTouch* pTouch=(CCTouch*)(*ite);
		CCPoint lastPoint=pTouch->getDelta();
		CCPoint currentPoint=pTouch->getLocation();
		CCPoint mapPoint=pTileMap->getPosition();
		pTileMap->setPosition(ccpAdd(lastPoint,mapPoint));
	}
	else if(pTouches->count()==2)
	{
		CCTouch* touch[2];
		int i=0;
		//获得两个触摸点
		for (CCSetIterator ite=pTouches->begin();ite!=pTouches->end();++ite)
		{
			touch[i]=(CCTouch*)(*ite);
			++i;
		}
		distance=ccpDistance(touch[0]->getPreviousLocation(),touch[1]->getPreviousLocation());
		lastDistance=ccpDistance(touch[0]->getLocation(),touch[1]->getLocation());//两个触摸点的距离
		//float dis=ccpDistance(lastPoint,currentPoint);
		pTileMap->setScale(scale*lastDistance/distance);
		
	}	
}

void GameBoard::ccTouchesEnded(CCSet *pTouches, CCEvent *pEvent){
	scale=pTileMap->getScale();
	if (scale<1)
	{
		CCFiniteTimeAction* scaleAction=CCScaleTo::create(0.2f,1);
		pTileMap->runAction(scaleAction);
	}
	else if (scale>2)
	{
		CCFiniteTimeAction* scaleAction=CCScaleTo::create(0.2f,2);
		pTileMap->runAction(scaleAction);
	}
}