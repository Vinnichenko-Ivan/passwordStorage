#include"Folder.hpp"

struct Account
{
  char typeCrypto;
  std::vector<Folder> folders;
  Presets preset;
};