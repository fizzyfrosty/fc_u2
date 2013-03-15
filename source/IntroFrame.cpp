#include "IntroFrame.h"


IntroFrame::IntroFrame(void)
{
}


IntroFrame::~IntroFrame(void)
{
}

void IntroFrame::initialize()
{
	numOfPanels = 1;
	currentPanelIndex = 0;
	ended = false;

	// Create the panels
	for( int i = 0; i < numOfPanels; i++ )
	{
		IntroPanel tempPanel;
		switch( i )
		{
		case 0:
			tempPanel.initialize( "yellow.png", IntroPanel::UP );
			break;
		case 1:
			tempPanel.initialize( "panel1.png", IntroPanel::UP );
			break;
		case 2:
			tempPanel.initialize( "panel2.png", IntroPanel::UP );
			break;
		case 3:
			tempPanel.initialize( "panel3.png", IntroPanel::UP );
			break;
		case 4:
			tempPanel.initialize( "panel4.png", IntroPanel::UP );
			break;

		}
		
		panels[i] = tempPanel;
	}
}

void IntroFrame::terminate()
{
	for( int i = 0; i < numOfPanels; i++ )
	{
		panels[i].terminate();
	}
}

void IntroFrame::update()
{
	// set the position of the panels
	panels[0].position.y -= 5;
	int16 value = IwGxGetScreenHeight()/2 * -2;
	if( panels[0].position.y <= value )
	{
		ended = true;
	}
}

void IntroFrame::render()
{
	// render the panels
	for( int i = 0; i < numOfPanels; i++ )
	{
		panels[i].render();
	}
}

void IntroFrame::pause()
{
	state = PAUSE;
}

void IntroFrame::play()
{
	state = PLAY;
}