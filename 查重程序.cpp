#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;

#define MAX 655

int same=0;
int dif=0;
float samerate=0;

int Judge(char str1[],char str2[],int strlen1,int strlen2){
	int i=0;
	for(i=0;i<strlen1;i++){
		if(str1[i]==str2[i]);
		else return 0;
	}
	return 1;
}

void Check(char str1[],char str2[],int slen1,int slen2) {
	cout<<str1<<endl;
	cout<<str2<<endl<<endl;
	int i=0,j=0;
	char s1[6];
	char s2[6];
	int flag=0;
	for(i=0;i<slen1-6;){
		int n=0;
		while(n++<6) s1[n]=str1[i+n]; 
		for(j=0;j<slen2-4&&flag==0;){
			int m=0;
			while(m++<6) s2[m]=str2[j+m];
			if(Judge(s1,s2,strlen(s1),strlen(s2))) {
				same++;
				flag=1;
			}
			else flag=0;
			j+=2;
		}
		if(flag==0) dif++;
		i+=6;
	}
	cout<<same<<endl;
	cout<<dif<<endl; 
	samerate=same*100/(same+dif);
	cout<<same<<endl;
	cout<<slen1<<endl;
	cout<<"两篇论文重复率为"<<samerate<<"%"<<endl;
	return ;
}



int main() {

	ifstream in1;
	ifstream in2;
	char in_file_name1[26],in_file_name2[26];

	char ch1[MAX],ch2[MAX];


	//读入进行比较的文件内容
	cout<<"请输入文件1名及完整路径：\n";
	cin>>in_file_name1;
	in1.open(in_file_name1);
	if(in1.fail()) {
		cout<<"Inputput file opening failed.\n";
		exit(1);
	}
	in1.getline(ch1,MAX);
	
	//输入用于查重的文件路径
	cout<<"请输入文件2名及完整路径：\n";
	cin>>in_file_name2;
	in2.open(in_file_name2);
	if(in2.fail()) {
		cout<<"Inputput file opening failed.\n";
		exit(1);
	}
	in2.getline(ch2,MAX);
	cout<<in_file_name1 <<":\n";
	cout<<ch1<<endl;
	cout<<in_file_name2 <<":\n";
	cout<<ch2<<endl;

	//对文件进行查重处理
	Check(ch1,ch2,strlen(ch1),strlen(ch2));
	
	in1.close();
	in2.close();
	

	return 0;
}
