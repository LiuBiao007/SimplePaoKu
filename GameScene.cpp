#include "GameScene.h"

USING_NS_CC;
GameScene::GameScene()
{
	_jumped = false;
};

GameScene::~GameScene(){};

void GameScene::toString(std::string &s, const int &t)
{
	std::ostringstream os;
	os << t;
	s = os.str();
}

bool GameScene::init()
{
	
	if(! cocos2d::Layer::init())
	{
		CCLOG("layer init false");
		return false;
	}

	win = Director::getInstance()->getWinSize();
	visibleSize = Director::getInstance()->getVisibleSize();
	origilSize = Director::getInstance()->getVisibleOrigin();

	_wuguiSprite = Sprite::create("tortoise0.png");
	_wuguiSprite->setPosition(win.width/2,win.height/2);
	this->addChild(_wuguiSprite,0);
	
	//this->gameScene_JumpTo();
	gameScene_RunAction();
	setTouchEnabled(true);
	setTouchMode(cocos2d::Touch::DispatchMode::ONE_BY_ONE);
	return true;
}

void GameScene::gameScene_RunAction()
{
	auto _animation = Animation::create();
	std::string head = "tortoise";
	std::string tail = ".png";
	std::string numStr;

	for(int i=0;i<8;i++)
	{
		this->toString(numStr,i);

		_animation->addSpriteFrameWithFile(head+numStr+tail);
	}

	_animation->setDelayPerUnit(0.1f);
	_animation->setRestoreOriginalFrame(true);

	auto _animate = Animate::create(_animation);
	//_wuguiSprite->runAction(CCRepeatForever::create(_animate));	
}

void GameScene::jumpEndCallBack(Node* n)
{
	_wuguiSprite->stopAllActions();
	this->gameScene_RunAction();
}

void GameScene::gameScene_JumpTo()
{
	if(! _jumped)
	{
		_jumped = true;
		//_wuguiSprite->stopAllActions();
		//auto x = _wuguiSprite->getPositionX();
		//auto y = _wuguiSprite->getPositionY();
		//auto _jumpBy = JumpTo::create(1.0f,Vec2(x,y+100),0,1);	
		//auto jumpEnd = CCCallFuncN::create(this, CC_CALLFUNCN_SELECTOR(GameScene::jumpEndCallBack));
		//_wuguiSprite->runAction(CCSequence::create(_jumpBy, jumpEnd, NULL));
		//_wuguiSprite->setPosition(x,y);			
		_jumped = false;
	}
}

bool GameScene::onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *unused_event)
{
	auto x = touch->getLocation().x;
	auto y = touch->getLocation().y;

	if(x >= origilSize.x + visibleSize.width/2 && y >= origilSize.y + visibleSize.height/2)
	{
		gameScene_JumpTo();
		return true;
	}
	return false;
}

cocos2d::Scene* GameScene::createScene()
{
	//CCASSERT(0,"game scene createScene");
	auto scene = Scene::create();

	auto layer = GameScene::create();
	scene->addChild(layer);

	return scene;
}



