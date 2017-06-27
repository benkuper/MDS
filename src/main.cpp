#include "ofMain.h"
#include "ofApp.h"
#include "ofxJSON.h"

vector<shared_ptr<ofApp>> outputs;

//========================================================================
int main( ){


	ofxJSONElement result;
	bool parsingSuccessful = result.open("config.json");

	int numOutputs = result["outputs"].size();
	ofLog() << numOutputs << " outputs";
	for (int i = 0; i < numOutputs; i++)
	{
		ofxJSONElement o = result["outputs"][i];
		int numSources = o["sources"].size();

		ofLog() << " >> " << numSources << " sources";

		vector<SourceData *> sources;
		for (int j = 0; j < numSources; j++)
		{
			ofxJSONElement s = result["outputs"][i]["sources"][j];
			ofLog() << "source : " << s.getRawString();
			sources.push_back(new SourceData(s["name"].asString(), ofRectangle(s["x"].asFloat(), s["y"].asFloat(), s["w"].asFloat(), s["h"].asFloat())));
		}

		outputs.push_back(make_shared<ofApp>(o["x"].asFloat(), o["y"].asFloat(), o["w"].asFloat(), o["h"].asFloat(),sources));
	}

	vector<shared_ptr<ofAppBaseWindow>> windows;
	for (auto &o : outputs)
	{
		ofGLFWWindowSettings settings;
		settings.setGLVersion(4,4); 
		settings.setPosition(ofVec2f(o->bounds.x,o->bounds.y)); 
		auto w = ofCreateWindow(settings);
		w->setWindowShape(o->bounds.width, o->bounds.height);
		windows.push_back(w);
	}
	
	int index = 0;
	for (auto &w : windows)
	{
		ofRunApp(w,outputs[index]);
		index++;
	}

	ofLog() << "Finish init windows";
	ofRunMainLoop();
}
