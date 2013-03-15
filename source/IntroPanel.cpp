#include "IntroPanel.h"


IntroPanel::IntroPanel(void)
{
}

IntroPanel::~IntroPanel(void)
{
}

void IntroPanel::initialize( char *filePath, int16 dir )
{
	position = CIwSVec2( 0, 0 );

	image = Iw2DCreateImage( filePath );
	sprite.setImage( image );
	sprite.setUWidth( image->GetWidth() );
	sprite.setUHeight( image->GetHeight() );
	sprite.setSize( IwGxGetScreenWidth(), IwGxGetScreenHeight() );

	direction = dir; // directions can only be UP, DOWN, LEFT, RIGHT

	// If the panel is moving upward, spawn it at the center bottom of screen
	if( direction == UP )
	{
		position = CIwSVec2( IwGxGetScreenWidth()/2, IwGxGetScreenHeight()/2 * 3 );
	}
	// If the panel is moving downward, spawn it at the center top of screen
	else if( direction == DOWN )
	{
		position = CIwSVec2( IwGxGetScreenWidth()/2, IwGxGetScreenHeight()/2 * -1 );
	}
	// If the panel is moving left, spawn it at the right center of screen
	else if( direction == LEFT )
	{
		position = CIwSVec2( IwGxGetScreenWidth()/2 * 3, IwGxGetScreenHeight()/2 );
	}
	// If the panel is moving right, spawn it at the left center of screen
	else if( direction == RIGHT )
	{
		position = CIwSVec2( IwGxGetScreenWidth()/2 * -1, IwGxGetScreenHeight()/2 );
	}
}

void IntroPanel::terminate()
{
	if( this->image != NULL )
	{
		delete this->image;
	}
}

void IntroPanel::render()
{
	// (image, CIwSVec2 topLeft, CIwSVec2 size)

	sprite.position = this->position;
	sprite.Render();
}

void IntroPanel::setPosition( int16 x, int16 y )
{
	position.x = x;
	position.y = y;
}