#include <iostream>
#include <openssl/md5.h>

#define AES_BLOCK_SIZE 16

using namespace std;

// unsigned char *MD5(const unsigned char *d, 
//                    unsigned long n,
//                    unsigned char *md);

int main()
{

	const unsigned char * d =  const unsigned char 100;
	size_t n=16;
	unsigned char md="";
	MD5(d,n,md)
	cout <<md  << endl;
	return 0;
}