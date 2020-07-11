#include"Account.hpp"

class Core
{
	protected:
		Account account;
	public:
		std::string logo();
		std::string savePassword(Presets presets,Password password);
		std::string savePresets(Presets presets);
		Account read();
		void write(Account in);
		void load(std::string name);
		void save(std::string name);
		void printf(std::ofstream &fout,const Folder &folder);

};

Account Core::read()
{
	return account;
}

void Core::write(Account in)
{
	account=in;
}

std::string Core::savePresets(Presets presets)
{
	std::string buffString="";
	if(presets.presetsOn)
	{
		buffString+="1";
	}
	else
	{
		buffString+="0";
	}
	if(presets.siteName)
	{
		buffString+="1";
	}
	else
	{
		buffString+="0";
	}
	if(presets.accountName)
	{
		buffString+="1";
	}
	else
	{
		buffString+="0";
	}
	if(presets.password)
	{
		buffString+="1";
	}
	else
	{
		buffString+="0";
	}
	if(presets.serviceName)
	{
		buffString+="1";
	}
	else
	{
		buffString+="0";
	}
	buffString+=presets.typeCrypto;
	return buffString;
}

std::string Core::savePassword(Presets presets,Password password)
{
	std::string savingString="";
	if(presets.siteName)
	{

	}
	else
	{
		savingString+=password.site;
	}
	savingString+=":";
	if(presets.accountName)
	{

	}
	else
	{
		savingString+=password.nameAccount;
	}
	savingString+=":";
	if(presets.password)
	{

	}
	else
	{
		savingString+=password.password;
	}
	savingString+=":";
	if(presets.serviceName)
	{

	}
	else
	{
		savingString+=password.serviceName;
	}
	return savingString;
}

void Core::printf(std::ofstream &fout,const Folder &folder)
{
	fout<<folder.name<<std::endl;
	fout<<savePresets(folder.preset)<<std::endl;
	fout<<"{"<<std::endl;
	for(int i=0;i<folder.passwords.size();i++)
	{
		fout<<savePassword(folder.preset,folder.passwords[i])<<std::endl;
	}
	for(int i=0;i<folder.folders.size();i++)
	{
		printf(fout,folder.folders[i]);
	}
	fout<<"}"<<std::endl;
}

void Core::save(std::string name)
{
	std::ofstream fout(name);
	fout<<account.name<<std::endl;
	fout<<savePresets(account.presets)<<std::endl;
	fout<<"{"<<std::endl;
	for(int i=0;i<account.folders.size();i++)
	{
		printf(fout,account.folders[i]);
	}
	fout<<"}"<<std::endl;
}

