/*
 *  FaceTracker.cpp
 *
 *  Copyright (c) 2011, Neil Mendoza, http://www.neilmendoza.com
 *  All rights reserved. 
 *  
 *  Redistribution and use in source and binary forms, with or without 
 *  modification, are permitted provided that the following conditions are met: 
 *  
 *  * Redistributions of source code must retain the above copyright notice, 
 *    this list of conditions and the following disclaimer. 
 *  * Redistributions in binary form must reproduce the above copyright 
 *    notice, this list of conditions and the following disclaimer in the 
 *    documentation and/or other materials provided with the distribution. 
 *  * Neither the name of 16b.it nor the names of its contributors may be used 
 *    to endorse or promote products derived from this software without 
 *    specific prior written permission. 
 *  
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" 
 *  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE 
 *  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE 
 *  ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE 
 *  LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR 
 *  CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF 
 *  SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS 
 *  INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN 
 *  CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) 
 *  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE 
 *  POSSIBILITY OF SUCH DAMAGE. 
 *
 */
#include "FaceTracker.h"

#include "ofxSimpleGuiToo.h"

void FaceTracker::setup(float scaleFactor, int w, int h)
{
	this->w = w;
	this->h = h;
	/*classifier.load(ofToDataPath("haarcascade_frontalface_alt2.xml"));
	
	// shouldn't need to allocate, resize should do this for us
	// graySmall.allocate(w * scaleFactor, h * scaleFactor, OF_IMAGE_GRAYSCALE);*/
	graySmallMat = Mat(h * scaleFactor, w * scaleFactor, CV_8UC1);
	this->scaleFactor = scaleFactor;
	tracker.setMaximumAge(10);
	tracker.setMaximumDistance(100);

}

void FaceTracker::update(ofBaseVideoDraws& video)
{
	if (!isThreadRunning())
	{
		//videoMat = Mat(h, w, CV_8UC3);
		videoMat = toCv(video).clone();
		convertColor(videoMat, grayMat, CV_RGB2GRAY);
		resize(grayMat, graySmallMat, graySmallMat.size());
		
		startThread(true, false);
	}
}

/*
void FaceTracker::drawThresholded(int x, int y, int w, int h)
{
	Mat dbg = graySmall & thresholded;
	drawMat(dbg, x, y, w, h);
}

void FaceTracker::resetBackground()
{
	background.reset();
}
 */

void FaceTracker::threadedFunction()
{
	// detect faces
	classifier.detectMultiScale(graySmallMat, objects, 1.06, 2,
								CascadeClassifier::DO_CANNY_PRUNING |
								//CascadeClassifier::FIND_BIGGEST_OBJECT |
								//CascadeClassifier::DO_ROUGH_SEARCH |
								0);
	
	// track the objects
	tracker.track(objects);
}