#include <vector>
#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <openssl/conf.h>
#include <openssl/err.h>
#include <openssl/md5.h>
#include <openssl/evp.h>
#include <openssl/rsa.h> 
#include <openssl/pem.h>
#include <openssl/aes.h>
#include "Core/Core.hpp"
#include "UI/UI.hpp"


Interface * interface = new ConsoleUI;
Core core(interface);


int main()
{
	// Account account;
	// Folder buffFolder;
	// std::strcpy(account.name,"Ivan");
	// Password buffPass{"Ivan1","Ivan2","Ivan3","Ivan4"};
	// buffFolder.passwords.push_back(buffPass);
	// std::strcpy(buffFolder.name,"folder1");
	// account.addFolder(buffFolder);
	// buffFolder.addFolder(buffFolder);
	// std::strcpy(buffFolder.name,"folder2");
	// account.addFolder(buffFolder);
	// core.write(account);
	// core.save("passw.txt");
	core.load("passw.txt");
	core.save("passw.txt");
}
