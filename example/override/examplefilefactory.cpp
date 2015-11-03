#include "examplefilefactory.h"

#include "../../spriterengine/override/imagefile.h"
#include "../../spriterengine/override/soundfile.h"

#include "tinyxmlscmlloader.h"
#include "sfmlimagefile.h"
#include "sfmlsoundfile.h"

namespace SpriterEngine
{

	ExampleFileFactory::ExampleFileFactory(sf::RenderWindow *validRenderWindow):
		renderWindow(validRenderWindow)
	{
	}

	ImageFile * ExampleFileFactory::newImageFile(const std::string &initialFilePath, point initialDefaultPivot)
	{
		return new SfmlImageFile(initialFilePath, initialDefaultPivot, renderWindow);
	}

	SoundFile * ExampleFileFactory::newSoundFile(const std::string & initialFilePath)
	{
		return new SfmlSoundFile(initialFilePath);
	}

	SpriterFileLoader * ExampleFileFactory::newScmlLoader()
	{
		return new TinyXmlScmlLoader();
	}
}