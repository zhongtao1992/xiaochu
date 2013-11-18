#include "GameUI/GameScene.h"

GameScene::GameScene(){
	m_GameBoard=NULL;
}

GameScene::~GameScene(){

}

bool GameScene::init(){
	bool bRet=false;
	do 
	{
		CC_BREAK_IF(!CCScene::init());

		//add tilemap
		m_GameBoard=GameBoard::create();
		this->addChild(m_GameBoard);

		bRet=true;
	} while (0);
	return bRet;
}