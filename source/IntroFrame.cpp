#include "IntroFrame.h"


IntroFrame::IntroFrame(void)
{
}


IntroFrame::~IntroFrame(void)
{
}

void IntroFrame::initialize()
{
	numOfPanels = 5;
	nextPanelIndex = 1;
	ended = false;
	deltaDistance = 4; // this is how fast each panel moves by

	// Create the panels
	// Must have at least TWO panels for current and next
	for( int i = 0; i < numOfPanels; i++ )
	{
		IntroPanel tempPanel;
		switch( i )
		{
		case 0:
			tempPanel.initialize( "yellow.png", IntroPanel::START );
			tempPanel.id = 0;
			break;
		case 1:
			tempPanel.initialize( "white.png", IntroPanel::UP );
			tempPanel.id = 1;
			break;
		case 2:
			tempPanel.initialize( "yellow.png", IntroPanel::DOWN );
			tempPanel.id = 2;
			break;
		case 3:
			tempPanel.initialize( "white.png", IntroPanel::LEFT );
			tempPanel.id = 3;
			break;
		case 4:
			tempPanel.initialize( "yellow.png", IntroPanel::RIGHT );
			tempPanel.id = 4;
			break;

		}
		
		panels[i] = tempPanel;
	}

	currentPanel = panels[nextPanelIndex-1]; // 0
	nextPanel = panels[nextPanelIndex]; // 1
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
	
	if( state == PLAY )
	{
		int16 limit = 0;

		// Check the next panel's direction. Movement will be decided by that direction
		switch( nextPanel.direction )
		{
		case IntroPanel::UP:
			// move the current panel and next panel
			currentPanel.position.y -= deltaDistance;
			nextPanel.position.y -= deltaDistance;

			// set the bounds for when picture is in center of screen
			// corresponds to either x, or y value
			limit = IwGxGetScreenHeight()/2;

			// check the next panel's end position to see if it is center
			if( nextPanel.position.y <= limit )
			{
				nextPanel.position.y = limit;

				// check to see if it's the last panel
				if( nextPanelIndex == numOfPanels )
				{
					// if last panel, set ended = true
					ended = true;
					this->pause();
				}
				else
				{
					// if it is not last panel, increment nextPanelIndex					
					currentPanel = nextPanel;
					nextPanelIndex++;
					nextPanel = panels[nextPanelIndex];
				}
			}
			break;
		case IntroPanel::DOWN:
			// move the current panel and next panel
			currentPanel.position.y += deltaDistance;
			nextPanel.position.y += deltaDistance;

			// set the bounds for when picture is in center of screen
			// corresponds to either x, or y value
			limit = IwGxGetScreenHeight()/2;

			// check the next panel's end position to see if it is center
			if( nextPanel.position.y >= limit )
			{
				nextPanel.position.y = limit;

				// check to see if it's the last panel
				if( nextPanelIndex == numOfPanels )
				{
					// if last panel, set ended = true
					ended = true;
					this->pause();
				}
				else
				{
					// if it is not last panel, increment nextPanelIndex					
					currentPanel = nextPanel;
					nextPanelIndex++;
					nextPanel = panels[nextPanelIndex];
				}
			}
			break;
		case IntroPanel::LEFT:
			// move the current panel and next panel
			currentPanel.position.x -= deltaDistance;
			nextPanel.position.x -= deltaDistance;

			// set the bounds for when picture is in center of screen
			// corresponds to either x, or y value
			limit = IwGxGetScreenWidth()/2;

			// check the next panel's end position to see if it is center
			if( nextPanel.position.x <= limit )
			{
				nextPanel.position.x = limit;

				// check to see if it's the last panel
				if( nextPanelIndex == numOfPanels )
				{
					// if last panel, set ended = true
					ended = true;
					this->pause();
				}
				else
				{
					// if it is not last panel, increment nextPanelIndex					
					currentPanel = nextPanel;
					nextPanelIndex++;
					nextPanel = panels[nextPanelIndex];
				}
			}
			break;
		case IntroPanel::RIGHT:
			// move the current panel and next panel
			currentPanel.position.x += deltaDistance;
			nextPanel.position.x += deltaDistance;

			// set the bounds for when picture is in center of screen
			// corresponds to either x, or y value
			limit = IwGxGetScreenWidth()/2;

			// check the next panel's end position to see if it is center
			if( nextPanel.position.x >= limit )
			{
				nextPanel.position.x = limit;

				// check to see if it's the last panel
				if( nextPanelIndex == numOfPanels )
				{
					// if last panel, set ended = true
					ended = true;
					this->pause();
				}
				else
				{
					// if it is not last panel, increment nextPanelIndex					
					currentPanel = nextPanel;
					nextPanelIndex++;
					nextPanel = panels[nextPanelIndex];
				}
			}
			break;
		}
	}
}

void IntroFrame::render()
{
	// render the panels
	//printf("Current panel's y position is %d \n", currentPanel.position.y );
	//printf("Current panel's id is %d \n", currentPanel.id );
	currentPanel.render();
	nextPanel.render();
	/*
	for( int i = 0; i < numOfPanels; i++ )
	{
		panels[i].render();
	}*/
}

void IntroFrame::pause()
{
	state = PAUSE;
}

void IntroFrame::play()
{
	state = PLAY;
}