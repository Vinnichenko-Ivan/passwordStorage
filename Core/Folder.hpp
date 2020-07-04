#include"Presets.hpp"
#include"Password.hpp"

struct Folder
{ 
	char name;
	std::vector<Folder> folders;
	std::vector<Password> passwords;
	Presets preset;
};