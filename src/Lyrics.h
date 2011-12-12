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
//#include "OscHandler.h"
#include "ofxOsc.h"

class Lyrics {
	
public:
	ofTrueTypeFont	adobeCaslonSemiBoldItalic;
	
	void setupLyrics();
	int updateLyrics();
	void drawLyrics(int oscLyricLine);
	
	string lyricLines[32];
	int lyricWidth;
	int lyricPosX;
	int lyricPosY;
	
	ofxOscReceiver	lyricReceiver;
	
	int newLyric;
	bool isSinging;
	
private:
	
	//private vars
};

#endif