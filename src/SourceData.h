#pragma once

#include "ofMain.h"
#include "ofxSpout2Receiver.h"

class SourceData
{
public:
	SourceData(string _sharingName, ofRectangle _rect);

	string sharingName;
	ofRectangle rect;

	ofxSpout2::Receiver receiver;

	void draw();
};