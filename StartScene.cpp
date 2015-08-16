#include "StartScene.h"
#include "GameScene.h"

StartScene::StartScene()
{
	visibleSize = Director::getInstance()->getVisibleSize();
	origilSize = Director::getInstance()->getVisibleOrigin();
	winSize = Director::getInstance()->getWinSize();
};

StartScene::~StartScene(){};

bool StartScene::init()
{
	if(! Layer::init())
	{
		return false;
	}
															   
	_StartSprite = Sprite::create("stbg.png");
	CCASSERT(_StartSprite != nullptr, "stbg.png error");

	_StartSprite->setAnchorPoint(Vec2(0,0));
	_StartSprite->setPosition(0,0);

	this->addChild(_StartSprite, 0);

	auto menuItem = MenuItemImage::create("stBut0.png", "stBut1.png", CC_CALLBACK_1(StartScene::startRunGame, this));
	auto menu = Menu::create(menuItem, NULL); 
	menuItem->setAnchorPoint(Vec2(0,0));
	menuItem->setPosition(Vec2(origilSize.x +  visibleSize.width/2, origilSize.y + visibleSize.height/4));
	menu->setAnchorPoint(Vec2(0,0));
	menu->setPosition(Vec2(0,0));
	addChild(menu, 1);

	
	auto closeMenuItem = MenuItemImage::create("CloseNormal.png", "CloseSelected.png", CC_CALLBACK_1(StartScene::closeGame, this));
	auto closeMenu = Menu::create(closeMenuItem, NULL);
	closeMenuItem->setAnchorPoint(Vec2(0,0));
	closeMenuItem->setPosition(Vec2(origilSize.x + 6 * visibleSize.width/7, origilSize.y + 6 * visibleSize.height/7));
	closeMenu->setAnchorPoint(Vec2(0,0));
	closeMenu->setPosition(Vec2(0,0));
	addChild(closeMenu, 1);

	return true;
}

void StartScene::closeGame(Ref* sender)
{
	Director::getInstance()->end();
}

void StartScene::startRunGame(Ref* sender)
{
	auto gameScene = GameScene::createScene();
	//flipx Director::getInstance()->replaceScene(TransitionFlipY::create(1.6f, gameScene));
	Director::getInstance()->replaceScene(TransitionCrossFade::create(1.2f,gameScene));
	//Director::getInstance()->replaceScene(TransitionTurnOffTiles::create(1.2f,gameScene));
}

Scene* StartScene::createScene()
{
	auto scene = Scene::create();
	auto layer = StartScene::create();
	scene->addChild(layer);
	return scene;
}
