#pragma once
#include "s3e.h"
#include "IwGx.h"
#include "Iw2D.h"
#include "Sprite.h";

class IntroPanel
{


public:
	IntroPanel(void);
	~IntroPanel(void);
	void initialize( char *filePath, int16 dir );
	void terminate();
	void render();
	void setPosition( int16 x, int16 y );
	
	CIwSVec2 position;
	Sprite sprite;
	CIw2DImage *image;
	
	enum {UP, DOWN, LEFT, RIGHT, START}; // these are the directions in which the panels are sliding towards
	int16 direction;
	int16 id;
};

