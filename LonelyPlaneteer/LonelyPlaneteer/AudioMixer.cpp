#include "AudioMixer.h"
#include <iostream>

AudioMixer::AudioMixer() {
	init();
}

void AudioMixer::init() {

	if (Mix_OpenAudio(FREQUENCY, MIX_DEFAULT_FORMAT, 2, CHUNK_SIZE) < 0) {
		std::cout << "Error: " << Mix_GetError() << std::endl;
	}

	//Music
	//Must free resources on game exit with Mix_FreeMusic()
	music = Mix_LoadMUS("Assets/Sound/game_music.ogg");

	if (music == NULL) {
		std::cout << "Error: " << Mix_GetError() << std::endl;
	}

	//Sound FX
	//Must free resources on game exit with Mix_FreeChunk()
	laserShot = new SoundFX("Assets/Sound/laser_shot.wav");
	ricochet = new SoundFX("Assets/Sound/ricochet.wav");
	ricochet_metal = new SoundFX("Assets/Sound/ricochet_metal.wav");
	winMusic = new SoundFX("Assets/Sound/win_music.ogg");
	lossMusic = new SoundFX("Assets/Sound/loss_music.ogg");

	//Play Music
	if (!Mix_PlayingMusic()) {

		std::cout << "playing music" << std::endl;
		if (Mix_PlayMusic(music, -1) < 0) {
			std::cout << "Error: " << Mix_GetError() << std::endl;
		}
	}
	
}

void AudioMixer::stopMusic() {

	Mix_HaltMusic();

}