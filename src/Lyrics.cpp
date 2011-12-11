/*
 *  Lyrics.cpp
 *  choir
 *
 *  Created by William Hooke on 11/12/2011.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */


#include "ofMain.h"
#include "testApp.h"
#include "Lyrics.h"

//#include "OscHandler.h"

void Lyrics::setupLyrics() {
	
	ofTrueTypeFont::setGlobalDpi(72);
	adobeCaslonSemiBoldItalic.loadFont("fonts/ACaslonPro-SemiboldItalic.otf", 30, true, true);
	adobeCaslonSemiBoldItalic.setLineHeight(18.0f);
	adobeCaslonSemiBoldItalic.setLetterSpacing(1.0);
	
	// Verse 1
	lyricLines[0] = "\"We wish you a Merry Christmas\"";
	lyricLines[1] = "\"We wish you a Merry Christmas\"";
	lyricLines[2] = "We wish you a Merry Christmas";
	lyricLines[3] = "And a Happy New Year";
	
	lyricLines[4] = "Good tidings we bring";
	lyricLines[5] = "To you and your kin";
	lyricLines[6] = "We wish you a Merry Christmas";
	lyricLines[7] = "And a Happy New Year";
	
	// Verse 2
	lyricLines[8] = "Now bring us some figgy pudding";
	lyricLines[9] = "Now bring us some figgy pudding";
	lyricLines[10] = "Now bring us some figgy pudding";
	lyricLines[11] = "And bring some out here!";
	
	lyricLines[12] = "Good tidings we bring";
	lyricLines[13] = "To you and your kin";
	lyricLines[14] = "We wish you a Merry Christmas";
	lyricLines[15] = "And a Happy New Year";
	
	// Verse 3
	lyricLines[16] = "For we all like figgy pudding";
	lyricLines[17] = "We all like figgy pudding";
	lyricLines[18] = "For we all like figgy pudding";
	lyricLines[19] = "So bring some out here!";

	lyricLines[20] = "Good tidings we bring";
	lyricLines[21] = "To you and your kin";
	lyricLines[22] = "We wish you a Merry Christmas";
	lyricLines[23] = "And a Happy New Year";
	
	// Verse 4
	lyricLines[23] = "And we won't go until we've got some";
	lyricLines[23] = "We won't go until we've got some";
	lyricLines[23] = "And we won't go until we've got some";
	lyricLines[23] = "So bring some out here!";
	
	lyricLines[23] = "Good tidings we bring";
	lyricLines[23] = "To you and your kin";
	lyricLines[23] = "Good tidings for Christmas";
	lyricLines[23] = "And a Happy New Year";
}

void Lyrics::updateLyrics() {

}

void Lyrics::drawLyrics(int oscLyricLine) {
	ofPushMatrix();
		ofTranslate(0, 0);
		
		int lyricWidth = adobeCaslonSemiBoldItalic.stringWidth(lyricLines[oscLyricLine]);
		int lyricPosX = (1024 / 2) - (lyricWidth/2);
		int lyricPosY = 590;
		
		// Draw a shadow	
		ofSetColor(0, 0, 0, 200);
		adobeCaslonSemiBoldItalic.drawString(lyricLines[oscLyricLine], lyricPosX - 2, lyricPosY + 2);
		
		// Draw the lyric
		ofSetColor(240,235,233);
		adobeCaslonSemiBoldItalic.drawString(lyricLines[oscLyricLine], lyricPosX, lyricPosY);
		ofSetColor(255);
	
	ofPopMatrix();
}