#include  <iostream>
#include <iomanip>
#include  <string>
#include  <cstring>
#include  <ctime>
#include  <cstdlib>
#include  <sstream>


#define KEY_LEN 20//�������������ַ�������

using namespace std;

//����ַ��� 
char *rand_str(char *str,const int len){
	int i;
	for(i=0;i<len;++i)
		str[i]='A'+rand()%26;
	str[++i]='\0';
	return str;
}

char key[KEY_LEN+5];


//�����ֹ���ɼ��ַ���� 
string string_to_hex(const string& str) //transfer string to hex-string
{
    string result="0x";
    string tmp;
    stringstream ss;
    for(int i=0;i<str.size();i++){
        ss<<setw(2)<<setfill('0')<<hex<<int(str[i])<<endl;
        ss>>tmp;
        result+=tmp;
    }
    return result;
}

void encrypt(char * plain ,char *key){
	char cipher [KEY_LEN+5];
	for (int i = 0;i < KEY_LEN;i++){
		cipher[i] = plain[i]^key[i];
	}
	cout<<string_to_hex(cipher)<<endl;
}

int main(){
	srand(time(NULL));
	rand_str(key,KEY_LEN);
	for(int i = 0;i < 30; i++){
		encrypt(plain[i],key);
	}
}

/**```output
0x193e2d30626b2532212178302f206924242b3c2c
0x78382d336e3f38372d6f393f25643d2120297439
0x3236223b6e0d23333e20343e3437693c243e3134
0x30243875076b393f293d3c71352c2c68282f3c37
0x79772d272126712e202a78272028252d343f7439
0x3b336b21262e71322d2e2a25610b392d236c2037
0x752323306e273e342d232171322b3c246d233278
0x263e283e222e7132293d2e34323020262a6c1b28
0x30396b21216b25322d6f343e2f2125316d3f3b2d
0x397724336e38383923233d7129253b3e283f2031
0x3b306b1c6e293436212a2e34610d6929206c1637
0x27396b343d6b25322d6f3a232823213c6d3f2135
0x3832397528273e2d2d3d2b71052b69262238742f
0x3c2323303c2e357a3d213c342721283c2828743e
0x3c32392c6e2f34372721782334282c680529352a
0x217739343a2e713b262b78333321283c25253a3f
0x752324752c2e3028683b303461282629296c3b3e
0x752323306e2824372a2a2a222e292c680f23263d
0x31770275262e30282c6f2c392464243d3e253774
0x7531393a236b25322d6f353e2e2a69292328743b
0x342528343d38711b3d37313d28253b316d292c2c
0x273226306e2a34293c273d252827203b206c3639
0x3c236b21216b323b383b2d23246424213e382d78
0x133e27392725367a3c273d71282a3d2d233f3178
0x393e2d30626b332f3c6f393d322b692e24203831
0x3b306b21262e712a3d3d3d71152c2c3a286c352a
0x30772a39392a282968223d3c2e36202d3e6c2030
0x27383e322624242e683b30346121283a39247411
0x75352e39272e273f680678302c647b7b7e7f6778
0x0d0d02010d1f1721053b280e2f743d3b2c2a3125
```
