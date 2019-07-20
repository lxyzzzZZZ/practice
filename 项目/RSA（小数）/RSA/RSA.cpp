#include "RSA.h"

//�ļ�����
void RSA::ecrept(const char* plain_file_in, const char* ecrept_file_out,
	long ekey, long pkey)
{
	std::ifstream fin(plain_file_in,std::ifstream::binary);
	std::ofstream fout(ecrept_file_out,std::ofstream::binary);
	if (!fin.is_open())
	{
		std::cout << "open file failed" << std::endl;
		return;
	}
	const int Num = 256;
	char Buffer[Num];
	long Buffer_out[Num];
	int Curnum;
	while (!fin.eof())
	{
		fin.read(Buffer, Num);
		Curnum = fin.gcount();
		for (int i = 0; i < Curnum; i++)
			Buffer_out[i] = ecrept((long)Buffer[i], ekey, pkey);
		fout.write((char*)Buffer_out, Curnum * sizeof(long));
	}
	fin.close();
	fout.close();
}

//�ļ�����
void RSA::decrept(const char* ecrept_file_in, const char* plain_file_out,
	long dkey, long pkey)
{
	std::ifstream fin(ecrept_file_in,std::ifstream::binary);
	std::ofstream fout(plain_file_out, std::ofstream::binary);
	if (!fin.is_open())
	{
		std::cout << "open file failed" << std::endl;
		return;
	}
	const int Num = 256;
	long Buffer[Num];
	char Buffer_out[Num];
	int Curnum;
	while (!fin.eof())
	{
		fin.read((char*)Buffer, Num * sizeof(long));
		Curnum = fin.gcount();
		Curnum /= sizeof(long);
		for (int i = 0; i < Curnum; i++)
			Buffer_out[i] = (char)ecrept(Buffer[i], dkey, pkey);
		fout.write(Buffer_out, Curnum);
	}
	fin.close();
	fout.close();
}

//�ַ�������
std::vector<long> RSA::ecrept(std::string& str_in, long ekey, long pkey)
{
	std::vector<long> Ciphertext;
	for (const auto& e : str_in)
	{
		Ciphertext.push_back(ecrept(e, ekey, pkey));
	}
	return Ciphertext;
}

//�ַ�������
std::string RSA::decrept(std::vector<long>& ecrept_str, long dkey, long pkey)
{
	std::string Plaintext;
	for (const auto& e : ecrept_str)
	{
		Plaintext.push_back((char)ecrept(e, dkey, pkey));
	}
	return Plaintext;
}

//��ӡ
void RSA::printInfo(std::vector<long>& ecrept_str)
{
	for (const auto& e : ecrept_str)
	{
		std::cout << e << " ";
	}
	std::cout << std::endl;
}



//1. ���ѡ����������ȵ�����p��q(ʵ��Ӧ���У�����������Խ�󣬾�Խ���ƽ�)��
//2. ����p��q�ĳ˻�n��n = pq��
//3. ����n��ŷ��������(n)��
//4. ���ѡ��һ������e��������1 < e < ��(n)����e���(n) ���ʡ�
//5. ����e���ڦ�(n)��ģ��Ԫ��d��ʹ��de��1 mod ��(n)������
//6.		(de) mod ��(n) = 1
//7. ������Կ(e, n)��˽Կ(d, n)��



RSA::RSA()
{
	produce_keys();
}

//���ܵ�����Ϣ	return pow(msg, key) % pkey
//An = (An-1 * An-1) % pkey;
long RSA::ecrept(long msg, long key, long pkey)
{
	//��ʼ��
	long msg_des = 1;
	//a, ��Ҫ���ܵ���Ϣ�� a^b % c
	long a = msg;
	//key: b
	//pkey : c
	long b = key;
	while (b)
	{
		//���������Ϊ1������
		if (b & 1)
			msg_des = (msg_des * a) % pkey;
		b >>= 1;
		//Ai = (A(i-1) * A(i-1)) % c
		a = (a * a) % pkey;
	}
	return msg_des;
}

//�������һ������
long RSA::produce_prime()
{
	//boost::random::mt19937 gen(time(nullptr));
	//ָ��������ķ�Χ 0 ~ (1<<128)
	//boost::random::uniform_int_distribution<long> dist(0, long(1) << 128);
	srand(time(nullptr));
	long prime = 0;
	while (1)
	{
		prime = rand() % 50 +1;
		if (is_prime(prime))
			return prime;
	}
}

//�����ж�
bool RSA::is_prime(long prime)
{
	if (prime < 2)
		return false;
	for (long i = 2; i <= sqrt(prime); i++)
	{
		if (prime % i == 0)
		{
			return false;
		}
	}
	return true;
}

//bool RSA::is_prime_bigInt(long digit)
//{
//	boost::random::mt11213b gen(time(nullptr));
//	if (miller_rabin_test(digit, 25, gen));
//	{
//		if (miller_rabin_test((digit -1) / 2, 25, gen));
//			return true;
//	}
//	return false;
//}

//�������е���Կ
void RSA::produce_keys()
{
	long prime1 = produce_prime();
	long prime2 = 0;
	while (1)
	{
		prime2 = produce_prime();
		if (prime2 != prime1)
			break;
	}
	_key.pkey = produce_pkey(prime1, prime2);
	long orla = produce_orla(prime1, prime2);
	_key.ekey = produce_ekey(orla);
	_key.dkey = produce_dkey(_key.ekey, orla);
	std::cout << _key.dkey << std::endl;
	std::cout << _key.ekey << std::endl;
	std::cout << _key.pkey << std::endl;
}

long RSA::produce_pkey(long prime1, long prime2)
{
	return prime1 * prime2;
}

//����ŷ������
long RSA::produce_orla(long prime1, long prime2)
{
	return (prime1 - 1) * (prime2 - 1);
}

//���ɹ�Կ
long RSA::produce_ekey(long orla)
{
	//boost::random::mt19937 gen(time(nullptr));
	//ָ��������ķ�Χ 0 ~ (1<<128)
	//boost::random::uniform_int_distribution<long> dist(0, long(1) << 128);
	srand(time(nullptr));
	long ekey = 0;
	//if (is_prime(orla))
	//{
	//	ekey = rand() % (orla - 1) + 1;
	//	return ekey;
	//}
	while (1)
	{
		ekey = rand() % orla;
		//std::cout << ekey << std::endl;
		if (ekey > 1 && produce_gcd(ekey, orla) == 1)
			break;
	}
	return ekey;

}

//շת����������Լ��
long RSA::produce_gcd(long ekey, long orla)
{
	long a;
	while (a = ekey % orla)
	{
		ekey = orla;
		orla = a;
	}
	return orla;
}

//����˽Կ
long RSA::produce_dkey(long ekey, long orla)
{
	long dkey = orla / ekey;
	while (1)
	{
		if ((dkey * ekey) % orla == 1)
			break;
		++dkey;
	}
	return dkey;
	//long x, y;
	//exgcd(ekey, orla, x, y);
	//return (x % orla + orla) % orla;
}
//long RSA::exgcd(long ekey, long orla, long& x, long& y)
//{
//	if (orla == 0)
//	{
//		x = 1;
//		y = 0;
//		return ekey;
//	}
//	long ret = exgcd(orla, ekey % orla, x, y);
//	long x1 = x, y1 = y;
//	x = y1;
//	y = x1 - (ekey / orla) * y1;
//	return ret;
//}