#pragma once

#include "SDL_mixer.h"
#include "SoundFX.h"

class AudioMixer
{
public:
	Mix_Music* music;
	SoundFX* winMusic;
	SoundFX* lossMusic;
	SoundFX* laserShot;
	SoundFX* ricochet;
	SoundFX* ricochet_metal;

	AudioMixer();
	~AudioMixer();

	void init();

	void stopMusic();

private:
	int const FREQUENCY = 44100;
	int const CHUNK_SIZE = 2048;
	

};
