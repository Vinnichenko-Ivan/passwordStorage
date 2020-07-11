#include"Presets.hpp"
#include"Password.hpp"

struct Folder
{ 
	char name[16];
	std::vector<Folder> folders;
	std::vector<Password> passwords;
	Presets preset;
	void addFolder(const Folder folder);
};

void Folder::addFolder(const Folder folder)
{
	folders.push_back(folder);
}
