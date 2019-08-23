#include<iostream>
using namespace std;

class coder
{
	int length;
	int ind;
	string code[50];
	float mess[50];
	public:
	coder()
	{
		cout<<"ENTER No of messages\n";
		cin>>length;
		length=length-1;
		cout<<"\nEnter probablities\n";
		for(int i=0;i<=length;i++){cin>>mess[i];}
		//cout<<"\nEnter message number to find code";
		//cin>>ind;
		ind=0;
		for(int i=0;i<length;i++){code[i]="";}
	}
	void gen_code()
	{
		int start=0;
		int end=length;
		while(end>start)
		{
			float half=0;
			for(int i=start;i<end;i++){half=half+mess[i];}
			half=half/2;
			float temp=0;
			for(int i=start;i<end;i++)
			{
				temp=temp+mess[i];
				if(temp>=half)
				{
					//cout<<"\ni: "<<i<<" start "<<start<<" end "<<end;
					if(ind<=i){//cout<<"\n ind<=i";
						code[ind]=code[ind]+'0';end=i;break;}
					else{//cout<<"\n ind>i";
						code[ind]=code[ind]+'1';start=i+1;break;}
				}
			}
		}
	}
	void gen_code_all()
	{
		for(int i=0;i<=length;i++)
		{
			ind=i;
			gen_code();
		}
	}
	void print_code()
	{
		cout<<"\n Codes Are";
		for(int i=0;i<=length;i++){cout<<"\n"<<code[i];}
	}
};

int main()
{
	coder obj;
	obj.gen_code_all();
	obj.print_code();
}
