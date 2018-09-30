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

	void setStringPath(std::string fileRoute, int soundID);

	bool createBackgroundMusic();

	bool createSoundEffect(int soundID);

	bool playSoundEffect(FMOD::Sound* sound);

	bool playSound(int soundID);

private:

	FMOD::System* audioSystem;
	FMOD::Sound* soundEffect;
	FMOD::Sound* soundEffect2;
	FMOD::Sound* soundEffect3;
	FMOD::Sound* backgroundMusic;
	std::string audioPathBackground;
	std::string audioPathsoundEffect;
	std::string audioPathsoundEffect2;
	std::string audioPathsoundEffect3;
};

