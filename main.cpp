#include <iostream>
#include <openssl/md5.h>
#include <openssl/evp.h>
#define AES_BLOCK_SIZE 16

using namespace std;

// unsigned char *MD5(const unsigned char *d, 
//                    unsigned long n,
//                    unsigned char *md);
void print_hex(int value)
{
if (value == 0)
return;

int rem = value % 16;
value /= 16;
print_hex(value); //first execute recurency and print next value

//after return print the less significant digit
if (rem > 9)
cout << (char)(rem - 10 + 'A');
else
cout << rem;
}

int main()
{
	// MD5_CTX kl;
	// MD5_CTX * k=kl;

	// MD5_Init(k);
	unsigned char text[] = "Error";
	const unsigned char * d =  text  ;
	size_t n=5;
	unsigned char md[n];
	unsigned char *m=md;

	unsigned char md1[n];
	unsigned char *m1=md1;

	m1=MD5(d,n,m);
	for(int i=0;i<n;i++)
	{
		print_hex((int)m1[i]);
		//cout <<(int)md[i] << endl;
	}
	cout<<endl;
	for(int i=0;i<n;i++)
	{
		
		print_hex((int)md[i]);
		//cout <<(int)md[i] << endl;
	}
	return 0;
}