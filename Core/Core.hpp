#include"Account.hpp"
#include"Interface.hpp"
class Core
{
	protected:
		Account account;
		void copy();
		void loadPresets(std::string str,Presets &presets);
		void saveFolder(std::ofstream &fout, Folder &folder,Presets &presetsWork);
		void CScopy(char *a,std::string &b);
		std::string savePassword(Presets presets,Password password,Key key);
		std::string savePresets(const Presets &presets);
		Password loadPassword(std::ifstream &fin, Presets &presets,Key &key);
		Folder loadFolder(std::ifstream &fin,Presets &presetsWork);
		Key requestKey(const auto & callable,std::string name);
		Interface *interface;
	public:
		std::string logo();
		Core(Interface *inInterface);
		Account read();
		void write(Account in);
		void load(std::string name);
		void save(std::string name);
};

Core::Core(Interface *inInterface)
{
	interface=inInterface;
}

void Core::CScopy(char *a,std::string &b)
{
	for(int i=0;i<16;i++)
	{
		if(a[i]==0)
		{
			break;
		}
		b+=a[i];
	}
}

Account Core::read()
{
	return account;
}

Key requestKey(const auto & callable,std::string name)
{
	return callable(name);
}

void Core::copy()
{

}

void Core::write(Account in)
{
	account=in;
}

void Core::loadPresets(std::string str,Presets &presets)
{
	if(str[0]!='0'&&str[0]!='1'||str[1]!='0'&&str[1]!='1'||str[2]!='0'&&str[2]!='1'||str[3]!='0'&&str[3]!='1'||str[4]!='0'&&str[4]!='1'||str.size()>21||str.size()<6)
	{
		std::cerr<<"error 101"<<std::endl;
	}
	else
	{
		if(str[0]=='0')
		{
			presets.presetsOn=0;
		}
		else
		{
			presets.presetsOn=1;
		}

		if(str[1]=='0')
		{
			presets.siteName=0;
		}
		else
		{
			presets.siteName=1;
		}

		if(str[2]=='0')
		{
			presets.accountName=0;
		}
		else
		{
			presets.accountName=1;
		}

		if(str[3]=='0')
		{
			presets.password=0;
		}
		else
		{
			presets.password=1;
		}

		if(str[4]=='0')
		{
			presets.serviceName=0;
		}
		else
		{
			presets.serviceName=1;
		}
		for(int i=5;i<str.size();i++)
		{
			presets.typeCrypto[i-5]=str[i];
		}
	}
}

std::string Core::savePresets(const Presets &presets)
{
	std::string buffString="Presets: ";
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

std::string Core::savePassword(Presets presets,Password password,Key key)
{
	std::string buff;
	std::string savingString="PassType: ";
	if(presets.siteName)
	{

	}
	else
	{
		savingString+=password.site;
	}
	savingString+=" ";
	if(presets.accountName)
	{

	}
	else
	{
		savingString+=password.nameAccount;
	}
	savingString+=" ";
	if(presets.password)
	{

	}
	else
	{
		savingString+=password.password;
	}
	savingString+=" ";
	if(presets.serviceName)
	{

	}
	else
	{
		savingString+=password  .serviceName;
	}
	return savingString;
}

Password Core::loadPassword(std::ifstream &fin, Presets &presets,Key &key)
{
	std::string strAccountNameCrypt,strSiteCrypt, strPasswordCrypt, strServiseNameCrypt;
	fin>>strSiteCrypt>>strAccountNameCrypt>>strPasswordCrypt>>strServiseNameCrypt;
	Password password;
	char strAccountName[16]={};
	char strSite[16]={};
	char strPassword[16]={};
	char strServiseName[16]={};
	int counter=0,count=0;

	if(strAccountNameCrypt.size()>16||strSiteCrypt.size()>16||strPasswordCrypt.size()>16||strServiseNameCrypt.size()>16)
	{
		std::cerr<<"error 102";
	}
	else
	{
		std::copy(strAccountNameCrypt.begin(),strAccountNameCrypt.end(),strAccountName);
		std::copy(strSiteCrypt.begin(),strSiteCrypt.end(),strSite);
		std::copy(strPasswordCrypt.begin(),strPasswordCrypt.end(),strPassword);
		std::copy(strServiseNameCrypt.begin(),strServiseNameCrypt.end(),strServiseName);
		if(presets.siteName)
		{

		}
		else
		{
			strcpy(password.site,strSite);
		}

		if(presets.accountName)
		{

		}
		else
		{
			strcpy(password.nameAccount,strAccountName);
		}

		if(presets.password)
		{

		}
		else
		{
			strcpy(password.password,strPassword);
		}

		if(presets.serviceName)
		{

		}
		else
		{
			strcpy(password.serviceName,strServiseName);
		}
	}
	return password;
}

void Core::saveFolder(std::ofstream &fout, Folder &folder,Presets &presetsWork)
{
	Key key;
	fout<<"Folder: "<<folder.name<<std::endl;
	fout<<savePresets(folder.presets)<<std::endl;
	fout<<"{"<<std::endl;
	if(folder.presets.presetsOn){
		folder.presets.key=interface->callback(folder.name);
		for(int i=0;i<folder.passwords.size();i++)
		{
			fout<<savePassword(folder.presets,folder.passwords[i],key)<<std::endl;
		}
		for(int i=0;i<folder.folders.size();i++)
		{
			saveFolder(fout,folder.folders[i],folder.presets);
		}
	}
	else
	{
		for(int i=0;i<folder.passwords.size();i++)
		{
			fout<<savePassword(presetsWork,folder.passwords[i],key)<<std::endl;
		}
		for(int i=0;i<folder.folders.size();i++)
		{
			saveFolder(fout,folder.folders[i],presetsWork);
		}
	}
	fout<<"}"<<std::endl;
}

void Core::save(std::string name)
{
	account.presets.key=interface->callback("Account password");
	std::ofstream fout(name);
	fout<<account.name<<std::endl;
	fout<<savePresets(account.presets)<<std::endl;
	fout<<"{"<<std::endl;	
	for(int i=0;i<account.folders.size();i++)
	{
		saveFolder(fout,account.folders[i],account.presets);
	}
	fout<<"}"<<std::endl;
	fout.close();
}

Folder Core::loadFolder(std::ifstream &fin,Presets &presetsWork)
{
	Key key;
	Folder folder;
	std::string buff;
	fin>>buff;
	if(buff.size()>16)
	{
		std::cerr<<"error 105 ";
	}
	std::copy(buff.begin(),buff.end(),folder.name);
	fin>>buff;
	if(buff!="Presets:")
	{
		std::cerr<<"error 106 "<<buff;
	}
	fin>>buff;
	loadPresets(buff,folder.presets);
	if(folder.presets.presetsOn)
	{
		folder.presets.key=interface->callback(folder.name);
	}
	fin>>buff;
	while(fin >> buff)
	{
		if(buff=="}")
		{
			break;
		}
		else if(buff=="Folder:")
		{
			if(folder.presets.presetsOn)
			{
				folder.folders.push_back(loadFolder(fin,folder.presets));
			}
			else
			{
				folder.folders.push_back(loadFolder(fin,presetsWork));
			}
		}
		else if(buff=="PassType:")
		{
			if(folder.presets.presetsOn)
			{
				folder.passwords.push_back(loadPassword(fin,folder.presets,key));
			}
			else
			{
				folder.passwords.push_back(loadPassword(fin,presetsWork,key));
			}
		}
		else
		{
			std::cerr<<"error 108 ";
		}
	}
	return folder;
}

void Core::load(std::string name)
{
	Account buffAccount;
	std::ifstream fin(name);
	std::string buff;
	fin>>buff;
	if(buff.size()>16)
	{
		std::cerr<<"error 103 ";
	}
	else
	{
		std::copy(buff.begin(),buff.end(),buffAccount.name);
	}
	fin>>buff;
	if(buff!="Presets:")
	{
		std::cerr<<"error 104 ";
	}
	fin>>buff;
	loadPresets(buff,buffAccount.presets);
	buffAccount.presets.key=interface->callback("Account");
	fin>>buff;
	//buffAccount.presets.key=requestKey(callableF,"account");
	while(fin >> buff)
	{
		if(buff=="}")
		{
			break;
		}
		else if(buff=="Folder:")
		{
			buffAccount.addFolder(loadFolder(fin,buffAccount.presets));
		}
		else
		{
			std::cerr<<"error 107 "<<buff;
		}
	}
	account=buffAccount;
}