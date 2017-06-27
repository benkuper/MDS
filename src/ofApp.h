#pragma once

#include "ofMain.h"
#include "SourceData.h"

class ofApp : public ofBaseApp{

	public:
		ofApp(int tx, int ty, int tw, int th, vector<SourceData *> _sources);
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
		ofRectangle bounds;
		vector<SourceData *> sources;

};
