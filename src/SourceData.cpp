#include "SourceData.h"

SourceData::SourceData(string _sharingName, ofRectangle _rect) :
	sharingName(_sharingName),
	rect(_rect)
{
	receiver.setup();

}

void SourceData::draw()
{
	receiver.updateTexture();
	receiver.getTexture().draw(rect.x*ofGetWidth(), rect.y*ofGetHeight(), rect.width*ofGetWidth(), rect.height*ofGetHeight());
}
