#include<iostream>
#include<cmath>
using namespace std;

template<class T1>
int compare(T1 x,T1 y){
	if(x<y)
	   return -1;
	else if(x==y)
	   return 0;
	else
	   return 1;
}

template<class T=int>    //class template defaulted with int
class Set {                  //class set
	int number_of_elements;
	T* s;
public:
	Set() {
		number_of_elements=0;
		s=NULL;
	}                                       //default constructor
	Set(int n) {                                         //parametrized constructor
		number_of_elements = n;
		s = new T[number_of_elements];
	}
	Set(Set& S) {                                               //copy constructor
		number_of_elements = S.number_of_elements;
		s = S.s;
	}
	void inputElements(int n) {
		int i;
		number_of_elements=n;
		s = new T[number_of_elements];
		cout << "Number of Elements in the set : " << number_of_elements << endl;
		cout << "Enter the " << number_of_elements << " elements" << endl;
		for (i = 0; i < number_of_elements; i++)
			cin >> *(s+i);
		cout << "Set elements filled\n";
	}
	void displaySet(void) {
		int i;
		if(number_of_elements==0){
			cout<<"\nSet is empty = {}\n";
			return;
		}
		cout << "\nNumber of Elements in the set : " << number_of_elements << endl;
		cout << "Elements are : {";
		for (i = 0; i < number_of_elements-1; i++)
			cout << *(s+i) << ",";
		cout <<*(s+i)<< "}\n\n";
	}
	Set operator+(Set<T>& S2) {               //operator '+' finds union of two set
		int i,j,flag=0,k=0;                      //returns the union set
		Set<T> S;
		Set<T> Si;
		Si=intersection(S2);
		S.number_of_elements=number_of_elements+S2.number_of_elements-Si.number_of_elements;
		S.s=new T[S.number_of_elements];
        for(i=0;i<number_of_elements;i++){
			for(j=0;j<Si.number_of_elements;j++){
				if(compare(s[i],Si.s[j])==0){
                    flag=1;break;}
			}
			if(flag==0)
			    S.s[k++]=s[i];
			flag=0;
		}
		for(i=0;i<S2.number_of_elements;i++)
		    S.s[k++]=S2.s[i];
		return S;
	}
	Set operator-(Set<T>& S2) {                   //operator '-' to find A-B of any two set
		int i,j,k=0,flag=0;                       //returns the set 
		Set<T> S;
		Set<T> Si;
		Si=intersection(S2);
		S.number_of_elements=number_of_elements-Si.number_of_elements;
		S.s=new T[S.number_of_elements];
        for(i=0;i<number_of_elements;i++){
			for(j=0;j<Si.number_of_elements;j++){
				if(compare(s[i],Si.s[j])==0){
                    flag=1;break;}
			}
			if(flag==0)
			    S.s[k++]=s[i];
			flag=0;
		}
		return S;
	}
	Set intersection(Set<T>& S2) {                      //find intersection of two sets
        int i,j,k=0,flag=0;                                 //returns the intersecting set
		Set<T> S;
		S.s=new T[number_of_elements+S2.number_of_elements];
		for(i=0;i<number_of_elements;i++){
            for(j=0;j<S2.number_of_elements;j++){
				if(compare(s[i],S2.s[j])==0){
                    flag=1;break;}
			}
			if(flag==1)
			    S.s[k++]=s[i];
			flag=0;
		}
		S.number_of_elements=k;
		return S;
	}
	int operator==(Set<T>& S2){                        //operator '==' to check equal or not 
		int i,j,count=0;                                      //returns 1 or 0
        if(number_of_elements!=S2.number_of_elements)
		    return 0;
		else{
			for(i=0;i<number_of_elements;i++){
				for(j=0;j<S2.number_of_elements;j++){
					if(compare(s[i],S2.s[j])==0){
                        count++;break;}
				}
			}
			if(count==number_of_elements)
			    return 1;
			else
			    return 0;
		}
	}
	//Set complement();
	void displayPowerSet(void) {                    //function to display power set
	    if(number_of_elements==0){                     //void displayPowerSet(void)
			cout<<"\nSet is empty = {}\n";
			return;
		}
		unsigned int pow_set_size=pow(2,number_of_elements);
		int j,counter;
		for(counter=0;counter<pow_set_size;counter++){
			cout<<"{";
			for(j=0;j<number_of_elements;j++){
				if(counter&(1<<j))
				    cout<<s[j]<<",";
			}
			cout<<"}\n";
		}
	}
	void displayMMV(void) {                 //function to display mean,median,variance
        double mean=0,variance=0,SD;          //void displayMMM(void)
		int median;
		int i;
		if(number_of_elements==0){
			cout<<"\nSet is empty = {}\n";
			return;
		}
		for(i=0;i<number_of_elements;i++)
		    mean+=s[i];
		mean=mean/number_of_elements;
	    for(i=0;i<number_of_elements;i++)
		    variance+=(s[i]-mean)*(s[i]-mean);
		variance=variance/number_of_elements;
		SD=sqrt(variance);
        if(number_of_elements%2==1){
		    median=(number_of_elements/2);
			cout<<"\nMedian - "<<s[median]<<endl;}
		else{
		    median=number_of_elements/2;
			cout<<"\nMedian - "<<s[median]<<","<<s[median-1]<<endl;}
		cout.precision(3);
		cout.setf(ios::showpoint);
		cout<<"Mean - "<<mean<<endl;
		cout<<"Variance - "<<variance<<endl;
		cout<<"Standard Deviation - "<<SD<<endl;
	}
	void checkDistinct(void){                    //checks if the Set has distint elements or not
		int i,j,flag=0;
		if(number_of_elements==0){
			cout<<"\nSet is empty = {}\n";
			return;
		}                               
		for(i=0;i<number_of_elements;i++){
			for(j=i+1;j<number_of_elements;j++){
				if(s[i]==s[j]){
				    flag=1;break;}
			}
			if(flag==1)
			    break;
		}
		if(flag==1)
		    cout<<"\nSet is not Distinct\n";
		else 
		    cout<<"\nSet is Distinct\n";
	}
	void cartesianProduct(Set<T>& S2);              //prints the cartisian producdt of two sets 
	void complement(Set<T>);
};

template<class T>
void Set<T>::cartesianProduct(Set<T>& S2){
    int i,j;
		cout<<"\nCartesian product : ";
		for(i=0;i<number_of_elements;i++){
			for(j=0;j<S2.number_of_elements;j++){
                cout<<"("<<s[i]<<","<<S2.s[j]<<")";
		    }
	    }
	    cout<<endl;
	}

template<class T>
void Set<T>::complement(Set<T> U){
	int i,j,flag=0;
	cout<<"\nComplement of the Set : {";
	for(i=0;i<U.number_of_elements;i++){
		for(j=0;j<number_of_elements;j++){
			if(U.s[i]==s[j])
			    {flag=1;break;}
		}
		if(flag==0)
		    cout<<U.s[i]<<",";
		flag=0;
	}
	cout<<"}\n";
}



int main(){
	int choice,n,c;
	do{
		cout<<"\n1. to move to integer sets\n";
		cout<<"2. to move to float sets\n";
		cout<<"3. to move to character sets\n";
		cout<<"0. to exit\n";
		cout<<"Enter your choice : ";
		cin>>choice;
		switch(choice){
		case 1:{
			Set<int> U;
		    Set<int> S1;
			Set<int> S2;
			Set<int> Su;
			Set<int> Si;
			Set<int> Sd;
			cout<<"Enter the number of elements of the integer Univarsal Set\n";
			cin>>n;
			U.inputElements(n);
			U.displaySet();
		do{
		    cout<<"\n0. to exit\n";
		    cout<<"1. to create set A\n";
			cout<<"2. to create set B\n";
			cout<<"3. to find the union of A and B\n";
			cout<<"4. to find the intersection A and B\n";
			cout<<"5. to find the difference\n";
			cout<<"6. to test if set A and B are equal\n";
			cout<<"7. to print the cartisian product of A and B\n";
			cout<<"8. to display power set\n";
			cout<<"9. to see if the set is distinct\n";
			cout<<"10. to see the mean,median and variance\n";
			cout<<"11. to find the complement of a set\n";
            cout<<"Enter your choice : ";
			cin>>c;
			switch(c){
			case 1:
				cout<<"\nEnter the number of Elements : ";
				cin>>n;
				S1.inputElements(n);
				S1.displaySet();
				break;
			case 2:
			    cout<<"\nEnter the number of Elements : ";
				cin>>n;
				S2.inputElements(n);
				S2.displaySet();
				break;
			case 3:
				Su=S1+S2;
				cout<<"Union of A and B : ";
				Su.displaySet();
				break;
			case 4:
				Si=S1.intersection(S2);
				cout<<"Intersection of A and B : ";
				Si.displaySet();
				break;
			case 5:
			    cout<<"\nPress 1 for A-B, 2 for B-A \n";
				cin>>n;
				if(n==1)
				    Sd=S1-S2;
				else
				    Sd=S2-S1;
				Sd.displaySet();
				break;
			case 6:
			    if(S1==S2)
				    cout<<"\nSets are Equal\n";
				else
				    cout<<"\nSets are not Equal\n";
				break;
			case 7:
			    S1.cartesianProduct(S2);
				break;
			case 8:
			    cout<<"\nPress 1 to display powerset of A, 2 for B : ";
				cin>>n;
				if(n==1)
				    S1.displayPowerSet();
				else
				    S2.displayPowerSet();
				break;
			case 9:
			    cout<<"\nPress 1 to see if A is distinct, 2 for B : ";
				cin>>n;
				if(n==1)
				    S1.checkDistinct();
				else
				    S2.checkDistinct();
				break;
			case 10:
			    cout<<"\nPress to see for A, 2 for set B : ";
				cin>>n;
				if(n==1)
				    S1.displayMMV();
				else
				    S2.displayMMV();
				break;
			case 11:
			    cout<<"Press 1 to Find complement of Set-1 and 2 for Set-2 : ";
				cin>>n;
				if(n==1)
				    S1.complement(U);
				else
				    S2.complement(U);
				break;
			case 0:
			    break;
			default:
			    cout<<"\nEnter the correct choice\n";
			}
		}while(c!=0);
		cout<<"\nInterger Sets exited\n";
		break;}
		case 2:{
			Set<float> U;
		    Set<float> S1;
			Set<float> S2;
			Set<float> Su;
			Set<float> Si;
			Set<float> Sd;
			cout<<"Enter the number of elements of the float Universal set : ";
			cin>>n;
			U.inputElements(n);
			U.displaySet();
		do{
		    cout<<"\n0. to exit\n";
		    cout<<"1. to create set A\n";
			cout<<"2. to create set B\n";
			cout<<"3. to find the union of A and B\n";
			cout<<"4. to find the intersection A and B\n";
			cout<<"5. to find the difference\n";
			cout<<"6. to test if set A and B are equal\n";
			cout<<"7. to print the cartisian product of A and B\n";
			cout<<"8. to display power set\n";
			cout<<"9. to see if the set is distinct\n";
			cout<<"10. to see the mean,median and variance\n";
			cout<<"11. to see the complement of a Set\n";
            cout<<"Enter your choice : ";
			cin>>c;
			switch(c){
			case 1:
				cout<<"\nEnter the number of Elements : ";
				cin>>n;
				S1.inputElements(n);
				S1.displaySet();
				break;
			case 2:
			    cout<<"\nEnter the number of Elements : ";
				cin>>n;
				S2.inputElements(n);
				S2.displaySet();
				break;
			case 3:
				Su=S1+S2;
				cout<<"\nUnion of A and B : ";
				Su.displaySet();
				break;
			case 4:
				Si=S1.intersection(S2);
				cout<<"\nIntersection of A and B : ";
				Si.displaySet();
				break;
			case 5:
			    cout<<"\nPress 1 for A-B, 2 for B-A \n";
				cin>>n;
				if(n==1)
				    Sd=S1-S2;
				else
				    Sd=S2-S1;
				Sd.displaySet();
				break;
			case 6:
			    if(S1==S2)
				    cout<<"\nSets are Equal\n";
				else
				    cout<<"\nSets are not Equal\n";
				break;
			case 7:
			    S1.cartesianProduct(S2);
				break;
			case 8:
			    cout<<"\nPress 1 to display powerset of A, 2 for B : ";
				cin>>n;
				if(n==1)
				    S1.displayPowerSet();
				else
				    S2.displayPowerSet();
				break;
			case 9:
			    cout<<"\nPress 1 to see if A is distinct, 2 for B : ";
				cin>>n;
				if(n==1)
				    S1.checkDistinct();
				else
				    S2.checkDistinct();
				break;
			case 10:
			    cout<<"\nPress to see for A, 2 for set B : ";
				cin>>n;
				if(n==1)
				    S1.displayMMV();
				else
				    S2.displayMMV();
				break;
			case 11:
			    cout<<"Press 1 to Find complement of Set-1 and 2 for Set-2 : ";
				cin>>n;
				if(n==1)
				    S1.complement(U);
				else
				    S2.complement(U);
				break;
			case 0:
			    break;
			default:
			    cout<<"\nEnter the correct choice\n";
			}
		}while(c!=0);
		cout<<"\nFloat Sets exited\n";
		break;}
		case 3:{
			Set<char> U;
		    Set<char> S1;
			Set<char> S2;
			Set<char> Su;
			Set<char> Si;
			Set<char> Sd;
			cout<<"Enter the number of character Universal set : ";
			cin>>n;
			U.inputElements(n);
			U.displaySet(); 
		do{
		    cout<<"\n0. to exit\n";
		    cout<<"1. to create set A\n";
			cout<<"2. to create set B\n";
			cout<<"3. to find the union of A and B\n";
			cout<<"4. to find the intersection A and B\n";
			cout<<"5. to find the difference\n";
			cout<<"6. to test if set A and B are equal\n";
			cout<<"7. to print the cartisian product of A and B\n";
			cout<<"8. to display power set\n";
			cout<<"9. to see if the set is distinct\n";
			cout<<"10. to see the complement of a set\n";
            cout<<"Enter your choice : ";
			cin>>c;
			switch(c){
			case 1:
				cout<<"\nEnter the number of Elements : ";
				cin>>n;
				S1.inputElements(n);
				S1.displaySet();
				break;
			case 2:
			    cout<<"\nEnter the number of Elements : ";
				cin>>n;
				S2.inputElements(n);
				S2.displaySet();
				break;
			case 3:
				Su=S1+S2;
				cout<<"\nUnion of A and B : ";
				Su.displaySet();
				break;
			case 4:
				Si=S1.intersection(S2);
				cout<<"\nIntersection of A and B : ";
				Si.displaySet();
				break;
			case 5:
			    cout<<"\nPress 1 for A-B, 2 for B-A \n";
				cin>>n;
				if(n==1)
				    Sd=S1-S2;
				else
				    Sd=S2-S1;
				Sd.displaySet();
				break;
			case 6:
			    if(S1==S2)
				    cout<<"\nSets are Equal\n";
				else
				    cout<<"\nSets are not Equal\n";
				break;
			case 7:
			    S1.cartesianProduct(S2);
				break;
			case 8:
			    cout<<"\nPress 1 to display powerset of A, 2 for B : ";
				cin>>n;
				if(n==1)
				    S1.displayPowerSet();
				else
				    S2.displayPowerSet();
				break;
			case 9:
			    cout<<"\nPress 1 to see if A is distinct, 2 for B : ";
				cin>>n;
				if(n==1)
				    S1.checkDistinct();
				else
				    S2.checkDistinct();
				break;
			case 10:
			    cout<<"Press 1 to Find complement of Set-1 and 2 for Set-2 : ";
				cin>>n;
				if(n==1)
				    S1.complement(U);
				else
				    S2.complement(U);
				break;
			case 0:
			    break;
			default:
			    cout<<"\nEnter the correct choice\n";
			}
		}while(c!=0);
		cout<<"\nCharacter Sets exited\n";
		break;}
		case 0:
		break;
		default:
		    cout<<"\nEnter correct choice!!\n";
		}
	}while(choice!=0);
	cout<<"\nThank You\n";
}