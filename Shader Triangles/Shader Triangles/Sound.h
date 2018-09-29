#pragma once
#include <fmod.hpp>
#include <string>

class Sound
{
public:
	Sound();
	~Sound();

	void initialise();

	bool createAudioSystem();

	void update();

	void setStringPath(std::string fileRoute);

	bool createBackgroundMusic();

	bool playSoundEffect(FMOD::Sound* sound);

private:

	FMOD::System* audioSystem;
	FMOD::Sound* soundEffect;
	FMOD::Sound* backgroundMusic;
	std::string audioPath;
};

