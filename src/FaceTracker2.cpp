/*
 *  FaceTracker2.cpp
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
#include "FaceTracker2.h"

void FaceTracker2::setup(float scale, int w, int h)
{
	this->w = w;
	this->h = h;
	color.setUseTexture(false);
	color.allocate(w, h);
	gray.setUseTexture(false);
	gray.allocate(w, h);
	graySmall.setUseTexture(false);
	graySmall.allocate(w * scale, h * scale);
	
	finder.setup("haarcascade_frontalface_alt2.xml");
	finder.setScaleHaar(1.06);
}

void FaceTracker2::update(ofVideoGrabber& video)
{
	if (!isThreadRunning())
	{
		color.setFromPixels(video.getPixels(), w, h);
		gray = color;
		graySmall.scaleIntoMe(gray);
		
		startThread(true, false);
	}
}

void FaceTracker2::threadedFunction()
{
	finder.findHaarObjects(graySmall);
	vector<cv::Rect> objects;
	for (int i = 0; i < finder.blobs.size(); ++i)
	{
		objects.push_back(cv::Rect(finder.blobs[i].boundingRect.x, 
								   finder.blobs[i].boundingRect.y, 
								   finder.blobs[i].boundingRect.width, 
								   finder.blobs[i].boundingRect.height));
	}
	tracker.track(objects);
	stopThread();
	// track the objects
	
	
}
