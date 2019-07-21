#include<iostream>
#include<vector>
#include<string>
#include<stack>

using namespace std;

int count(string s,char ch){
	int l=s.length(),count=0;
	for(int i=0;i<l;i++){
		if(s.at(i)==ch)
			count++;
	}
	return count;
}

bool isPresent(string bs,string s){
	int Size=bs.length(),l=s.length();
	for(int i=0;i<Size;i++){
		if (s==bs.substr(i,l))
			return true;
	}
	return false;
}

string interpret(string s,vector<string> code){
	stack<string> stk;
	string attr=s.substr(s.find_last_of('~')+1,s.length()-s.find_last_of('~'));
	int l=s.length(),Size=code.size(),idx;
	string tag;
	for(int i=0;i<l;i++){
		if(s[i]=='.'){
			if(stk.empty()==true){
				int flag=0;
				for(int j=0;j<Size;j++){
					cout<<code[j]<<" "<<tag<<endl;
					if(isPresent(code[j],tag)==true && stk.empty()==true){
						idx=j;
						stk.push(tag);
						flag=1;
						break;
					}
					else if(isPresent(code[j],"/")==true)
						stk.pop();
					else{
						string s=code[j].substr(1,code[j].find_first_of(' '));
						stk.push(s);
					}
				}
				if (flag==0)
					return "Not Found!B";
			}
			else if(stk.empty()==false){
				idx++;
				if(isPresent(code[idx],tag)==true)
					stk.push(tag);
				else
					return "Not Found!C";
			}
			tag.clear();
		}
		else if(s[i]=='~'){
			if(count(s,'.')>0)
				idx++;
			else{
				int flag=0;
				for(int j=0;j<Size;j++){
					if(isPresent(code[j],tag)==true && stk.empty()==true){
						idx=j;
						flag=1;
						break;
					}
					else if(isPresent(code[j],"/")==true)
						stk.pop();
					else{
						string s=code[j].substr(1,code[j].find_first_of(' '));
						stk.push(s);
					}
				}
				if (flag==0)
					return "Not Found!B";
			}
			while(isPresent(code[idx],tag)==false && idx<Size){	
				idx++;
			}
			int p=idx;
			if(isPresent(code[idx],tag)==true && isPresent(code[idx],attr)==true){
				stk.push(tag);
				int flag=0;
				idx++;
				while(stk.empty()!=true && idx<Size){
					if (isPresent(code[idx],stk.top())==true)
						stk.pop();
					idx++;
				}
				if(stk.empty()==true)
					return code[p].substr(code[p].find_first_of('"')+1,code[p].find_last_of('"')-code[p].find_first_of('"')-1);
				else
					return "Not Found!";
			}
			else
				return "Not Found!E";
		}
		else
			tag.push_back(s[i]);
	}
	return "Not Found!A";
}

int main(){
	int n;
	cout<<"Enter the lines of the code - ";
	cin>>n;
	cin.get();
	vector<string> code;
	cout<<"Enter the code-\n";
	for(int i=0;i<n;i++){
		string str;
		getline(cin,str);
		code.push_back(str);
	}
	int m;
	cout<<"Enter the number of lines - ";
	cin>>m;
	for(int i=0;i<m;i++){
		string s;
		cout<<"Enter - ";
		cin>>s;
		cout<<interpret(s,code);
	}
}