
              // file is included in more than one place
#define WIN32_LEAN_AND_MEAN
#ifndef _ENEMY_H                 // Prevent multiple definitions if this 
#define _ENEMY_H   
class Enemy;

#include "entity.h"
#include "constants.h"

namespace enemyNS
{
    const int WIDTH = 128;                   // image width
    const int HEIGHT = 64;                  // image height
    const int X = GAME_WIDTH/2 - WIDTH/2;   // location on screen
    const int Y = GAME_HEIGHT/2 - HEIGHT/2;
    const float SPEED = 75;    
	const int frameCompensation = 40;
	
   
}

// inherits from Entity class
class Enemy : public Entity
{
protected:
  
    bool collision;                 
    bool target;           

	//gamestate checkers
	bool walkingLeft;
	bool walkingRight;
	bool facingLeft;
	bool facingRight;
	bool jumpLeft;
	bool jumpRight;
	bool jumpStatLeft;
	bool jumpStatRight;
	bool landing;
	float secondsPassed;
	int health;
	bool isHit;
	float hitTimer;
	int dmgCounter;
public:
    // constructor
	 Enemy();

    // inherited member functions
	virtual void update(float frameTime);

    // Set collision Boolean
    void setCollision(bool c)
    {collision = c;}

    // Set collision type (NONE, CIRCLE, BOX, ROTATED_BOX)
    virtual void setCollisionType(entityNS::COLLISION_TYPE ctype)
    {collisionType = ctype;}

    // Set RECT structure used for BOX and ROTATED_BOX collision detection.
    void setEdge(RECT e) {edge = e;}

	virtual void setIsHit(bool h){}
	virtual bool getIsHit(){return isHit;}
	void setHitTimer(float t){hitTimer = t;}
	float getHitTimer(){return hitTimer;}
	void Enemy::incDmgCounter();
	int Enemy::getDmgCounter();


	/*********HOMEGROWN FUNCTIONS*********/

	//less typing
	virtual int getScaledWidth(){return (int)(getWidth()*getScale());}
	virtual int getRightEdge(){return (int)(getX()+getScaledWidth());}
	virtual int getScaledHeight(){return (int)(getHeight()*getScale());}

	//Character State Checks
	virtual bool isWalkingLeft(){ return walkingLeft;}
	virtual bool isWalkingRight(){ return walkingRight;}
	virtual bool isFacingLeft(){return facingLeft;}
	virtual bool isFacingRight(){return facingRight;}
	virtual bool isJumpingLeft(){return jumpLeft;}
	virtual bool isJumpingRight(){return jumpRight;}
	virtual bool isLanding(){return landing;}
	virtual void face(int direction);
	virtual void walk(int direction);
	virtual void jump(int direction);
	virtual void fall();
	virtual void land();
	virtual void updateJump(float frameTime);
	virtual void updateFall(float frameTime);
	virtual void updateHit(float frameTime){}
	virtual void ai(float frameTime, Entity &ent);
    // Get collision
    bool getCollision() {return collision;}
	int getHealth() {return health;}

    // Get collision type
    entityNS::COLLISION_TYPE getCollisionType() {return collisionType;}


    void right()
    {
        velocity.x = enemyNS::SPEED;
    }
    void left()
    {
        velocity.x = -enemyNS::SPEED;
    }
	void stop()
	{
		velocity.x = 0;
	}
	void hit(int damage, float frameTime);
};
#endif

