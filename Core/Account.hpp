#include"Folder.hpp"

struct Account
{
	char name[16];
    char typeCrypto;
    std::vector<Folder> folders;
    Presets presets;
    void addFolder(const Folder folder);
};

void Account::addFolder(const Folder folder)
{
	folders.push_back(folder);
}

