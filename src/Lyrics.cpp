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
	adobeCaslonSemiBoldItalic.loadFont("fonts/ACaslonPro-SemiboldItalic.otf", 30, true, true, true);
	adobeCaslonSemiBoldItalic.setLineHeight(18.0f);
	adobeCaslonSemiBoldItalic.setLetterSpacing(1.0);
	
	// Verse 1
	lyricLines[0] = "\"We wish you a Merry Christmas\"";
	lyricLines[1] = "\"We wish you a Merry Christmas\"";
	lyricLines[2] = "\"We wish you a Merry Christmas\"";
	lyricLines[3] = "\"And a Happy New Year\"";
	
	lyricLines[4] = "\"Good tidings we bring\"";
	lyricLines[5] = "\"To you and your kin\"";
	lyricLines[6] = "\"We wish you a Merry Christmas\"";
	lyricLines[7] = "\"And a Happy New Year\"";
	
	// Verse 2
	lyricLines[8] = "\"Now bring us some figgy pudding\"";
	lyricLines[9] = "\"Now bring us some figgy pudding\"";
	lyricLines[10] = "\"Now bring us some figgy pudding\"";
	lyricLines[11] = "\"And bring some out here!\"";
	
	lyricLines[12] = "\"Good tidings we bring\"";
	lyricLines[13] = "\"To you and your kin\"";
	lyricLines[14] = "\"We wish you a Merry Christmas\"";
	lyricLines[15] = "\"And a Happy New Year\"";
	
	// Verse 3
	lyricLines[16] = "\"For we all like figgy pudding\"";
	lyricLines[17] = "\"We all like figgy pudding\"";
	lyricLines[18] = "\"For we all like figgy pudding\"";
	lyricLines[19] = "\"So bring some out here!\"";

	lyricLines[20] = "\"Good tidings we bring\"";
	lyricLines[21] = "\"To you and your kin\"";
	lyricLines[22] = "\"We wish you a Merry Christmas\"";
	lyricLines[23] = "\"And a Happy New Year\"";
	
	// Verse 4
	lyricLines[24] = "\"And we won't go until we've got some\"";
	lyricLines[25] = "\"We won't go until we've got some\"";
	lyricLines[26] = "\"And we won't go until we've got some\"";
	lyricLines[27] = "\"So bring some out here!\"";
	
	lyricLines[28] = "\"Good tidings we bring\"";
	lyricLines[29] = "\"To you and your kin\"";
	lyricLines[30] = "\"Good tidings for Christmas";
	lyricLines[31] = "\"And a Happy New Year\"";
	
	lyricReceiver.setup(8001);
}

int Lyrics::updateLyrics() {
	
	//newLyric = 0;
	
	while( lyricReceiver.hasWaitingMessages() )
	{
		// get the next message
		ofxOscMessage lyricMsg;
		lyricReceiver.getNextMessage( &lyricMsg );
		
		// check for new lyrics message
		if ( lyricMsg.getAddress() == "/lyrics" )
		{
			// both the arguments are int32's
			newLyric = lyricMsg.getArgAsInt32( 0 );
		}
		if ( lyricMsg.getAddress() == "/singing" )
		{
			// both the arguments are int32's
			isSinging = lyricMsg.getArgAsInt32( 0 );
			printf("isSinging = %i", isSinging);
		}
	}
	return newLyric;
}

/*
bool Lyrics::singing() {
	while( lyricReceiver.hasWaitingMessages() )
	{
		// get the next message
		ofxOscMessage lyricMsg;
		lyricReceiver.getNextMessage( &lyricMsg );
		
		// check for new lyrics message
		if ( lyricMsg.getAddress() == "/singing" )
		{
			// both the arguments are int32's
			newLyric = lyricMsg.getArgAsInt32( 0 );
		}
	}
	return singing;
}
*/

void Lyrics::drawLyrics(int oscLyricLine) {
	ofPushMatrix();
		ofTranslate(0, 0);
		
		lyricWidth = adobeCaslonSemiBoldItalic.stringWidth(lyricLines[oscLyricLine]);
		lyricPosX = (1024 / 2) - (lyricWidth/2);
		lyricPosY = 570;
		
		// Draw a shadow	
		ofSetColor(0, 0, 0, 200);
		adobeCaslonSemiBoldItalic.drawString(lyricLines[oscLyricLine], lyricPosX - 2, lyricPosY + 2);
		
		// Draw the lyric
		ofSetColor(240,235,233);
		adobeCaslonSemiBoldItalic.drawString(lyricLines[oscLyricLine], lyricPosX, lyricPosY);
		ofSetColor(255);
	
	ofPopMatrix();
}