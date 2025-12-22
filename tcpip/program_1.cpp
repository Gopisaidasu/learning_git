#include<iostream>
#include<fstream>
using namespace std;
int main(int argc,char*argv[])

{

fstream fin;
fin.open(argv[1],ios::in);

	if(fin.is_open() == 0)
	{
		cout << "the src_file doesn't exist" << endl;
		return 0;
	}
	char ch;
	fstream fout;
	fout.open(argv[2],ios::out);

	while( (ch = fin.get()) != EOF)
	fout.put(ch);

	fin.close();
	fout.close();

}
