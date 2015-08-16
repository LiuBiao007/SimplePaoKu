#include "BackGround.h"


BackGround::BackGround(){};

BackGround::~BackGround(){};


bool BackGround::init()
{
	if(! cocos2d::Layer::init())
	{
		return false;
	}



	_backGroundSprite = cocos2d::Sprite::createWithSpriteFrameName("bg0.png");
	_backWaveSprite = cocos2d::Sprite::createWithSpriteFrameName("w0.png");

	_backGroundSprite->setPosition(0,0);
	_backWaveSprite->setPosition(0,0);



	return true;
}



