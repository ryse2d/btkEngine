#include "SoundManager.h"
#include <iostream>

Mix_Chunk* SoundManager::GetSound(const string& k, const string& p) {
	auto it = cache.find(k); if (it != cache.end()) return it->second;
	Mix_Chunk* c = Mix_LoadWAV(p.empty() ? k.c_str() : p.c_str());
	if (!c) { std::cerr << "Mix_LoadWAV:" << Mix_GetError() << endl; return nullptr; }
	cache[k] = c; return c;
}

void SoundManager::Shutdown() {
	for (auto& kv : cache) Mix_FreeChunk(kv.second);
	Mix_CloseAudio(); cache.clear();
}