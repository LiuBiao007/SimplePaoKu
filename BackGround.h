#ifndef __CC_BACKGROUND_H
#define __CC_BACKGROUND_H

#include "cocos2d.h"

class BackGround:public cocos2d::Layer
{
public:
	
	BackGround();
	~BackGround();

	virtual bool init();

	CREATE_FUNC(BackGround);

	void moveForever();
protected:

private:
	cocos2d::Sprite* _backGroundSprite;
	cocos2d::Sprite* _backWaveSprite;
};


#endif




