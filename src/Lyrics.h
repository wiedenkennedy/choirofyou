/*
 *  Lyrics.h
 *  choir
 *
 *  Created by William Hooke on 11/12/2011.
 *  Copyright 2011 Wieden + Kennedy. All rights reserved.
 *
 */

#ifndef _LYRICS
#define _LYRICS

#pragma once

#include "ofMain.h"
#include "testApp.h"
#include "OscHandler.h"

class Lyrics {
	
public:
	ofTrueTypeFont	adobeCaslonSemiBoldItalic;
	
	void setupLyrics();
	void updateLyrics();
	void drawLyrics(int oscLyricLine);
	
	string lyricLines[32];
	int lyricWidth;
	int lyricPosX;
	int lyricPosY;
	
private:
	
	//private vars
};

#endif