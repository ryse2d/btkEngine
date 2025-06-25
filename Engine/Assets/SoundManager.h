#pragma once
#include <SDL2/SDL_mixer.h>
#include <unordered_map>
#include <string>

using namespace std;

class SoundManager {
public: 
	void Init() { Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048); }
	void Shutdown();
	Mix_Chunk* GetSound(const string& key, const string& path = "");
	void Play(const string& key, int loops = 0) { Mix_PlayChannel(-1, GetSound(key), loops); };

private:
	unordered_map <string, Mix_Chunk*> cache;
};