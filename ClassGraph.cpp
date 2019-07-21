#include<iostream>
#include<cmath>
#define size 20
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

struct vertex{                  //node structure
	int data;
    char e;
	vertex* next;
};

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
	//part of class Set modified for class Graph
	T showEdge(int i){
		return s[i];
	}
	int getNumber_of_elements(void){
		return number_of_elements;
	}
	T getMaxElement(void){
        int i;
		T max;
		max=s[0];
		for(i=1;i<number_of_elements;i++){
			if(s[i]>max)
			   max=s[i];
		}
		return max;
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
	//end of part of class Set required for graph
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

class Graph{                //CLASS GRAPH
	Set<int> V;
	Set<char> E;
	int n_vertex;
	vertex *g[size];
	int ev[100];
public:
    Graph(): E(),V(){
		int i;
		n_vertex=0;
		for(i=0;i<size;i++)
		   g[i]=NULL;
	}
	Graph(int nV,int nE): V(nV),E(nE){
		cout<<"Enter elements of Vertex Set(in numbers) -\n";
		V.inputElements(nV);
		cout<<"Enter elements of Edge Set(in characters) - \n";
		E.inputElements(nE);
		int i,a,b,k=0;
		n_vertex=nV;
	    for(i=0;i<size;i++)
		   g[i]=NULL;
		for(i=0;i<nE;i++){
			cout<<"Enter the end vertices of edge directing from 1->2 "<<E.showEdge(i)<<"\n";
            cin>>a>>b;
			addEdge(a,b,E.showEdge(i));
            ev[k++]=a;
			ev[k++]=b;
		}
		displayGraph();
	}
	Graph(Graph & G): V(G.V),E(G.E){
		int i;
		n_vertex=G.n_vertex;
        for(i=0;i<n_vertex;i++)
		    g[i]=G.g[i];
	}
    void displayGraph(void);
	void addEdge(int,int,char);
	Graph operator+(Graph&);
	Graph intersection(Graph&);
	bool checkDisjoint(int);
	int findDegree(int);
	Graph createSubGraph(int,int); 
};

void Graph::addEdge(int i,int j,char ch){          //adding new edges in the graph objects
	vertex *neew,*tmp,*ptmp;
	neew=new vertex;
	neew->data=j;
    neew->e=ch;
	if(g[i]==NULL){
		neew->next=NULL;
		g[i]=neew;
	}
	else if(g[i]->data>neew->data){
		neew->next=g[i];
        g[i]=neew;   
	}
	else{
		tmp=ptmp=g[i];
		while(tmp!=NULL){
			if(tmp->data>neew->data){
				neew->next=tmp;
				ptmp->next=neew;
				break;
			}
			ptmp=tmp;
			tmp=tmp->next;
		}
		if(tmp==NULL){
			neew->next=NULL;
			ptmp->next=neew;
		}
	}
}

void Graph::displayGraph(){                   //member function to display the graph
	int i;
	vertex *tmp;
	cout<<"Vertex Set - ";
	V.displaySet();
	cout<<"Edge Set - ";
	E.displaySet();
	int max=V.getMaxElement();
	cout<<endl;
	for(i=1;i<=max;i++){
        tmp=g[i];
		cout<<i<<" -> ";
		while(tmp!=NULL){
			cout<<(tmp->data)<<"|"<<(tmp->e)<<" , ";
			tmp=tmp->next;
		}
		cout<<endl;
	}
}

Graph Graph::operator+(Graph & G2){          //this member function does union of two graph 
	int i,j,k=0;
	vertex *tmp,*mtmp;
	Graph G;
	G.V=V+G2.V;
	G.E=E+G2.E;
    G.n_vertex=(G.V).getNumber_of_elements();
	for(i=0;i<size;i++)
	    G.g[i]=NULL;
	for(i=1;i<=G.n_vertex;i++){
        tmp=g[i];
		while(tmp!=NULL){
			G.addEdge(i,tmp->data,tmp->e);
			tmp=tmp->next;
		}
	}
	for(i=1;i<=G.n_vertex;i++){
		tmp=G2.g[i];
		while(tmp!=NULL){
			mtmp=G.g[i];
			while(mtmp!=NULL){
                if(tmp->data==mtmp->data)
			       break;
			    else if(tmp->data<mtmp->data){
				   G.addEdge(i,tmp->data,tmp->e);
				   break;}
				mtmp=mtmp->next;
			}   
			if(mtmp==NULL)
			    G.addEdge(i,tmp->data,tmp->e);
			tmp=tmp->next;
		}
	}
	return G;
}

Graph Graph::intersection(Graph & G2){            //member function to do intersection
	Graph G;
	vertex *tmp,*mtmp;
	int i,max;
	G.V=V.intersection(G2.V);
	G.E=E.intersection(G2.E);
    if(V.getMaxElement()>(G2.V).getMaxElement())
	    max=V.getMaxElement();
	else
	    max=(G2.V).getMaxElement();
	for(i=1;i<=max;i++){
        tmp=g[i];
		while(tmp!=NULL){
			mtmp=G2.g[i];
			while(mtmp!=NULL){
				if(tmp->data==mtmp->data)
				   G.addEdge(i,mtmp->data,mtmp->e);
				mtmp=mtmp->next;
			}
			tmp=tmp->next;
		}
	}
	return G;
}

int Graph::findDegree(int i){             //member function to find the degree of vertexs
	vertex *tmp;
	int count=0,k;
	tmp=g[i];
	while(tmp!=NULL){
		count++;
		tmp=tmp->next;
	}
	int max=V.getMaxElement();
	for(k=1;k<=max;k++){
		tmp=g[k];
		while(tmp!=NULL){
			if((tmp->data)==i){
				count++;
				break;
			}
			tmp=tmp->next;
		}
	}
    return count;
}

bool Graph::checkDisjoint(int i){            //function to find if a vertex is disjoint or not
	vertex *tmp;
	int j;
	if(g[i]==NULL){
		int max=V.getMaxElement();
		for(j=0;j<=max;j++){
			tmp=g[j];
			while(tmp!=NULL){
				if(i==tmp->data)
				   return false;
				tmp=tmp->next;
			}
		}
		return true;
	}
	else
		return false;
}

Graph Graph::createSubGraph(int nV,int nE){            //member function to create a subgraph
    Graph G;
	int i,j,l1,l2,k;
    cout<<"Enter the Vertex Set(integer) -\n";
	(G.V).inputElements(nV);
	cout<<"Enter the Edge Set(characters) -\n";
	(G.E).inputElements(nE);
	for(i=0;i<size;i++)
	    G.g[i]=NULL;
	G.n_vertex=(G.V).getNumber_of_elements();
	l1=(G.E).getNumber_of_elements();
	for(i=0;i<l1;i++){
		l2=E.getNumber_of_elements();
		for(j=0,k=1;j<l2;j++,k++){
            if((G.E).showEdge(i)==E.showEdge(j)){
				G.addEdge(ev[2*(k-1)],ev[2*(k-1)+1],E.showEdge(j));
				break;
			}
		}
	}
    return G;
}


//main function//
int main(){
    int nv,ne,choice,c,i,j,n,flag1=0,flag2=0;;
	bool b;
	cout<<"Welcome:-)\n";
	cout<<"\nFirst create the (Graph 1)\n";
	cout<<"Enter the number of vertex of the Graph 1 : ";
	cin>>nv;
	cout<<"Enter the number of edges of the Graph 1 : ";
	cin>>ne;
	Graph G1(nv,ne);
	cout<<"\nNow create the 2nd graph(Graph 2)\n";
	cout<<"Enter the number of vertex of the Graph 2 : ";
	cin>>nv;
	cout<<"Enter the number of edges of the Graph 2 : ";
	cin>>ne;
	Graph G2(nv,ne);
	cout<<"\nBoth Graphs created\n";
	Graph Gu,Gi;
	do{
		cout<<"\n1. to find union of two graphs\n";
		cout<<"2. to find intrsection of two graphs\n";
		cout<<"3. to check the degree of any vertex\n";
		cout<<"4. to check if a vertex is disjoint or not\n";
		cout<<"5. to find create a subGraph\n";
		cout<<"0. to exit\n";
		cout<<"Enter your choice : ";
		cin>>choice;
		switch(choice){
			case 1:
			    Gu=G1+G2;
			    Gu.displayGraph();
				flag1=1;
			    break;
			case 2:
			    Gi=G1.intersection(G2);
			    Gi.displayGraph();
				flag2=1;
			    break;
			case 3:
			    cout<<"\n1. for any vertex of Graph1\n";
			    cout<<"2. for any vertex of Graph2\n";
				if(flag1==1)
			        cout<<"3. for any vetex of the Union Graph\n";
			    if(flag2==1)
				    cout<<"4. for any vertex of the Intersection Graph\n";
			    cout<<"Enter your choice : ";
			    cin>>c;
			    cout<<"Enter the vertex whose degree you want to find : ";
			    cin>>i;
			    if(c==1)
			        n=G1.findDegree(i);
				else if(c==2)
				    n=G2.findDegree(i);
				else if(c==3)
				    n=Gu.findDegree(i);
				else if(c==4)
				    n=Gi.findDegree(i);
				cout<<"The degree of vertex ("<<i<<") is : "<<n<<endl;
	            break;
			case 4:
			    cout<<"\n1. for any vertex of Graph1\n";
			    cout<<"2. for any vertex of Graph2\n";
				if(flag1==1)
			        cout<<"3. for any vetex of the Union Graph\n";
			    if(flag2==1)
				    cout<<"4. for any vertex of the Intersection Graph\n";
			    cout<<"Enter your choice : ";
			    cin>>c;
			    cout<<"Enter the vertex which you want to check if disjoint or not : ";
			    cin>>i;
				if(c==1)
			        b=G1.checkDisjoint(i);
				else if(c==2)
				    b=G2.checkDisjoint(i);
				else if(c==3)
				    b=Gu.checkDisjoint(i);
				else if(c==4)
				    b=Gi.checkDisjoint(i);
				if(b==true)
				    cout<<"The vertex ("<<i<<") is : Disjoint\n";
				else
				    cout<<"The vertex ("<<i<<") is : Not disjoint\n";
	            break;
			case 5:{
                Graph SubG;
				cout<<"\n1. for creating a subgraph of Graph 1\n";
				cout<<"2. for creating a subgraph of Graph 2\n";
				cout<<"Enter your choice : ";
				cin>>c;
				if(c==1){
				    cout<<"Enter the number of Vertex of the SubGraph : ";
					cin>>nv;
					cout<<"Enter the number of Edges of the SubGraph : ";
					cin>>ne;
				    SubG=G1.createSubGraph(nv,ne);
					SubG.displayGraph();
				}
				else if(c==2){
                    cout<<"Enter the number of Vertex of the SubGraph : ";
					cin>>nv;
					cout<<"Enter the number of Edges of the SubGraph : ";
					cin>>ne;
				    SubG=G2.createSubGraph(nv,ne);
					SubG.displayGraph();
				}
				break;
			}
			case 0:
			    break;
			default:
			    cout<<"Enter correct choice \n";
		}
		cout<<endl;
	}while(choice!=0);
	cout<<"Thank You:-)\n";
}