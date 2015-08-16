#ifndef __CC_GAMESCENE_H
#define __CC_GAMESCENE_H

#include "cocos2d.h"
#include <sstream>

class GameScene:public cocos2d::Layer
{
public:
	GameScene();

	~GameScene();

	virtual bool init();

	static cocos2d::Scene* createScene();


	void gameScene_RunAction();
	void gameScene_JumpTo();

#define FRAME_DEFAULT_W 800
#define FRAME_DEFAULT_H 480

	CREATE_FUNC(GameScene);
protected:

private:
	cocos2d::Sprite* _wuguiSprite;
	cocos2d::Size win;
	cocos2d::Size visibleSize;
	cocos2d::Vec2 origilSize;
	bool _jumped;
	//template <class T>
	void toString(std::string &s, const int &t);
	void jumpEndCallBack(Node* n);
	bool onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *unused_event);
};

#endif
