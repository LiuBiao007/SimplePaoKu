#ifndef __CC_STARTSCENE_H
#define __CC_STARTSCENE_H

#include "cocos2d.h"
USING_NS_CC;
class StartScene:public Layer
{
public:
	StartScene();
	~StartScene();

	virtual bool init();
	static Scene* createScene();
	CREATE_FUNC(StartScene);
protected:

private:
	Sprite* _StartSprite;
	Size visibleSize;
	Size winSize;
	Vec2 origilSize;
	void startRunGame(Ref* sender);
	void closeGame(Ref* sender);
};


#endif




