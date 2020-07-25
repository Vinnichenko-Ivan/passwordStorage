class ConsoleUI:public Interface
{
	public:
		virtual Key callback(std::string name)override
		{
			Key key;
			std::cout<<name<<std::endl;
			std::cin>>key.key;
			return key;
		}
};