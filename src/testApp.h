#pragma once

#include "ofMain.h"
#include "ofxCv.h"
#include "ofFileUtils.h"
#include "FaceTracker2.h"
#include "FaceTracker.h"
#include "ofxMask.h"
#include "LiveFace.h"
#include "ChoirFace.h"
#include "OscHandler.h"
#include "ofxMovieExporter.h"

using namespace ofxCv;

#define _LIVE

class testApp : public ofBaseApp
{
public:
	void setup();
	void update();
	void draw();
	void keyPressed(int key);
	
private:
	float faceWStretch;
	float faceHStretch;
	
	float faceSizeLerp;
	float facePosLerp;
	
	FaceTracker2 faceTracker;
	
	ofDirectory choirFaceDir;
	vector<ofFile> faceDataFiles;
	
	map<unsigned, LiveFace> faces;
	vector<ChoirFace> choirFaces;
	//ChoirFace choirFace;
	
	float scaleFactor;
	
	ofBaseVideoDraws* videoPtr;
	
	Apex::ofxMovieExporter movieExporter;
	
#ifdef _LIVE
	ofVideoGrabber cam;
#else
	ofVideoPlayer player;
#endif	
	
	ofVideoPlayer choirVideos[3];
	string choirVideoFileNames[3];
	int currentMovieLevel;
	float fadeToAlpha;
	
	int yShift;
	
	ofVideoPlayer* fadeFrom;
	ofVideoPlayer* fadeTo;
	
	
	ofFbo facesFbo;
	
	int width;
	int height;
	int interactionLevel;
	bool drawTriangles; 
	
	ofImage maskImage;
	//vector<Apex::ofxMask> masker;
	Apex::ofxMask masker;
	
	OscHandler messageHandler;
};
