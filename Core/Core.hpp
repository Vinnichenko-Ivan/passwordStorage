#include"Account.hpp"

class Core
{
	protected:
		Account account;
	public:
		Account read();
		void write();
		void load();
		void save();
};