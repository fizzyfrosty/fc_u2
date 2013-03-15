#pragma once
#include "s3e.h"
#include "IwGx.h"
#include "IntroPanel.h"

class IntroFrame
{
public:
	IntroFrame(void); // the intro frame is actually a scrolling frame, but named intro to stay consistent with IntroPanel naming
	~IntroFrame(void);

	void initialize(); // creates the panels with image and direction of panel
	void terminate(); // calls terminate on all the panels
	void update(); // updates the position of only the current and next panels. Other panels rest.
	void render(); // calls render on the panels

	void play(); // set state to play
	void pause(); // set state to pause

	IntroPanel *currentPanel; // this is pointer to current panel of the panels array
	IntroPanel *nextPanel; // this is pointer to next panel of the panels array
	int currentPanelIndex; // This is the index used to increment the current panel and next panel pointers

	IntroPanel panels[5]; // all the panels that are stored
	int16 numOfPanels; // the total number of panels

	enum {PLAY, PAUSE}; // the two possible states of the scrolling frame
	int16 state; // the state variable to check
	bool ended; // this helps main game determine if it's not playing. Could have just used if state == paused
};

