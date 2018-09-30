#include "Sound.h"
#include <comdef.h>
#include <mutex>


Sound::Sound()
{
}


Sound::~Sound()
{
}

void Sound::initialise()
{
	createAudioSystem();
	createBackgroundMusic();
	playSoundEffect(backgroundMusic);
}

bool Sound::createAudioSystem()
{
	FMOD_RESULT result;
	result = FMOD::System_Create(&audioSystem);
	if (result != FMOD_OK)
	{
		return false;
	}

	result = audioSystem->init(100, FMOD_INIT_NORMAL | FMOD_INIT_3D_RIGHTHANDED, 0);
	if (result != FMOD_OK)
	{
		return false;
	}

	return true;
}

void Sound::update()
{
	audioSystem->update();
}

void Sound::setStringPath(std::string fileRoute, int soundID)
{
	if (soundID == 0)
	{
		audioPathBackground = fileRoute;
	}
	if (soundID == 1)
	{
		audioPathsoundEffect = fileRoute;
	}
	if (soundID == 2)
	{
		audioPathsoundEffect2 = fileRoute;
	}
	if (soundID == 3)
	{
		audioPathsoundEffect3 = fileRoute;
	}
	
}

bool Sound::createBackgroundMusic()
{
	FMOD_RESULT result;

	//Conversion from string too wide string
	std::wstring widestr = std::wstring(audioPathBackground.begin(), audioPathBackground.end());
	//Conversion from wise string too wide char pointer
	const wchar_t * wideChar = widestr.c_str();
	//Conversion from char pointer too _bstr_t
	_bstr_t convertedStr(wideChar);
	const char* newString = convertedStr;
	//Conversion from _bstr_t too const char pointer
	result = audioSystem->createSound(newString, FMOD_LOOP_NORMAL, 0, &backgroundMusic);
	if (result != FMOD_OK)
	{
		return false;
	}
	return true;
}

bool Sound::createSoundEffect(int soundID)
{
	FMOD_RESULT result;

	
	if (soundID == 1)
	{
		//Conversion from string too wide string
		std::wstring widestr = std::wstring(audioPathsoundEffect.begin(), audioPathsoundEffect.end());
		//Conversion from wise string too wide char pointer
		const wchar_t * wideChar = widestr.c_str();
		//Conversion from char pointer too _bstr_t
		_bstr_t convertedStr(wideChar);
		const char* newString = convertedStr;
		//Conversion from _bstr_t too const char pointer
		result = audioSystem->createSound(newString, FMOD_DEFAULT, 0, &soundEffect);
	}
	if (soundID == 2)
	{
		//Conversion from string too wide string
		std::wstring widestr = std::wstring(audioPathsoundEffect2.begin(), audioPathsoundEffect2.end());
		//Conversion from wise string too wide char pointer
		const wchar_t * wideChar = widestr.c_str();
		//Conversion from char pointer too _bstr_t
		_bstr_t convertedStr(wideChar);
		const char* newString = convertedStr;
		//Conversion from _bstr_t too const char pointer
		result = audioSystem->createSound(newString, FMOD_DEFAULT, 0, &soundEffect2);
	}
	if (soundID == 3)
	{
		//Conversion from string too wide string
		std::wstring widestr = std::wstring(audioPathsoundEffect3.begin(), audioPathsoundEffect3.end());
		//Conversion from wise string too wide char pointer
		const wchar_t * wideChar = widestr.c_str();
		//Conversion from char pointer too _bstr_t
		_bstr_t convertedStr(wideChar);
		const char* newString = convertedStr;
		//Conversion from _bstr_t too const char pointer
		result = audioSystem->createSound(newString, FMOD_DEFAULT, 0, &soundEffect3);
	}
	
	if (result != FMOD_OK)
	{
		return false;
	}
	return true;
}

bool Sound::playSoundEffect(FMOD::Sound* sound)
{
	FMOD_RESULT  result;
	result = audioSystem->playSound(sound, 0, false, 0);
	if (result != FMOD_OK)
	{
		return false;
	}
	return true;
}

bool Sound::playSound(int soundID)
{
	if (soundID == 1)
	{
		playSoundEffect(soundEffect);
	}
	if (soundID == 2)
	{
		playSoundEffect(soundEffect2);
	}
	if (soundID == 3)
	{
		playSoundEffect(soundEffect3);
	}

	return true;
}
