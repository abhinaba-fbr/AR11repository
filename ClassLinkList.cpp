#include<iostream>
using namespace std;

struct node{
    int coff;
    int degree;
    struct node* next;
};

class LinkList{
    struct node* ll;
public:
    LinkList(){
        ll=NULL;
    }
    LinkList(struct node *n){
        ll=n;
    }
    void addnode(int,int);
    void addnodeSorted(int,int);
    void createPoly(int*,int*,int);
    void printLL();   
    LinkList operator+(LinkList);
};

void LinkList::addnode(int co,int deg){
       struct node *neew,*tmp;
       neew=new struct node;
       neew->coff=co;
       neew->degree=deg;
       neew->next=NULL;
       if(ll==NULL)
           ll=neew;
       else{
           tmp=ll;
           while(tmp->next!=NULL)
               tmp=tmp->next;
           tmp->next=neew;
       }
}

void LinkList::addnodeSorted(int co,int deg){
        struct node *neew,*tmp,*ptmp;
        neew=new struct node;
        neew->coff=co;
        neew->degree=deg;
        if(ll==NULL){
            neew->next=NULL;
            ll=neew;
        }
        else if(neew->degree>ll->degree){
            neew->next=ll;
            ll=neew;
        }
        else{
            tmp=ll;
            ptmp=ll;
            while(tmp!=NULL){
                if(tmp->degree==neew->degree){
                     tmp->coff+=neew->coff;
                     break;
                }
                 if(tmp->degree<neew->degree){
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

void LinkList::createPoly(int co[],int deg[],int n){
      int i;
      struct node *neew,*tmp,*ptmp;
      for(i=0;i<n;i++){
         neew=new struct node;
         neew->coff=co[i];
         neew->degree=deg[i];
         if(ll==NULL){
             neew->next=NULL;
             ll=neew;
         }
         else if(neew->degree>ll->degree){
             neew->next=ll;
             ll=neew;
         }
         else{
             tmp=ll;
             ptmp=ll;
             while(tmp!=NULL){
                 if(tmp->degree==neew->degree){
                      tmp->coff+=neew->coff;
                      break;
                 }
                 if(tmp->degree<neew->degree){
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
}

LinkList LinkList::operator+(LinkList l2){
     LinkList l;
     struct node *tmp1,*tmp2; 
     tmp1=ll;
     tmp2=l2.ll;
     while(tmp1!=NULL&&tmp2!=NULL){
         if(tmp1->degree==tmp2->degree){
              l.addnode(tmp1->coff+tmp2->coff,tmp1->degree);
              tmp1=tmp1->next;
              tmp2=tmp2->next;
         }
         else if(tmp1->degree>tmp2->degree){
              l.addnode(tmp1->coff,tmp1->degree);
              tmp1=tmp1->next;
         }
         else{
              l.addnode(tmp2->coff,tmp2->degree);
              tmp2=tmp2->next;
         }
    }
    while(tmp1!=NULL){
        l.addnode(tmp1->coff,tmp1->degree);
        tmp1=tmp1->next;
    }
    while(tmp2!=NULL){
        l.addnode(tmp2->coff,tmp2->degree);
        tmp2=tmp2->next;
    }
    return l;
}
          
void LinkList::printLL(){
     struct node *tmp;
     tmp=ll;
     if(tmp==NULL)
         cout<<"List is Empty!!!\n";
     else{
     while(tmp->next!=NULL){
         cout<<tmp->coff<<"x^"<<tmp->degree<<"+";
         tmp=tmp->next;
     }     
     cout<<tmp->coff<<"x^"<<tmp->degree<<endl;}
}




int main(){ 
     LinkList L1,L2,L3;
     int n1,n2,i,a,b,choice,c,flag=0;
     do{
          cout<<"\n1. to Enter in list1\n";
          cout<<"2. to Enter in list2\n";
          if(flag==1)
              cout<<"3. to Enter list3\n";
          else
              cout<<"3. to add polynomial1 and polymomial2\n";
          cout<<"0. to exit program\n";
          cout<<"Enter your choice : ";
          cin>>choice;
          switch(choice){
          case 1:
           do{
              cout<<"\nThe list1 is - ";
              L1.printLL();
              cout<<"\n1. to add node\n";
              cout<<"2. to create polyinomial\n";
              cout<<"0. to exit list1\n";
              cout<<"Enter your choice : ";
              cin>>c;
              if(c==1){
                   cout<<"\nEnter the cofficient : ";
                   cin>>a;
                   cout<<"Enter the degree : ";
                   cin>>b;
                   L1.addnodeSorted(a,b);
              }
              else if(c==2){
                   cout<<"Enter the number of cofficients : ";
                   cin>>n1;
                   int C[n1],D[n1];
                   for(i=0;i<n1;i++){
                        cout<<"Enter the cofficient : ";
                        cin>>C[i];
                        cout<<"Enter the degree : ";
                        cin>>D[i];
                   }
                   L1.createPoly(C,D,n1);
             }
           }while(c!=0);
           cout<<"List1 Exited:-(\n";
           break;
           case 2:
              do{
              cout<<"\nThe list2 is - ";
              L2.printLL();
              cout<<"\n1. to add node\n";
              cout<<"2. to create polyinomial\n";
              cout<<"0. to exit list2\n";
              cout<<"Enter your choice : ";
              cin>>c;
              if(c==1){
                   cout<<"\nEnter the cofficient : ";
                   cin>>a;
                   cout<<"Enter the degree : ";
                   cin>>b;
                   L2.addnodeSorted(a,b);
              }
              else if(c==2){
                   cout<<"Enter the number of cofficients : ";
                   cin>>n2;
                   int C[n2],D[n2];
                   for(i=0;i<n2;i++){
                        cout<<"Enter the cofficient : ";
                        cin>>C[i];
                        cout<<"Enter the degree : ";
                        cin>>D[i];
                   }
                   L2.createPoly(C,D,n2);
             }
           }while(c!=0);
           cout<<"List2 Exited:-(\n";
           break;
           case 3:
            if(flag==0){
              L3=L1+L2;
              cout<<endl<<"List 1 - ";
              L1.printLL();
              cout<<"List 2 - ";
              L2.printLL();
              cout<<endl<<"Therefor List 3 - ";
              L3.printLL();
              flag=1;
            }
            else{
               do{
              cout<<"\nThe list3 is - ";
              L1.printLL();
              cout<<"\n1. to add node\n";
              cout<<"2. to create polyinomial\n";
              cout<<"0. to exit list3\n";
              cout<<"Enter your choice : ";
              cin>>c;
              if(c==1){
                   cout<<"\nEnter the cofficient : ";
                   cin>>a;
                   cout<<"Enter the degree : ";
                   cin>>b;
                   L2.addnodeSorted(a,b);
              }
              else if(c==2){
                   cout<<"Enter the number of cofficients : ";
                   cin>>n1;
                   int C[n1],D[n1];
                   for(i=0;i<n1;i++){
                        cout<<"Enter the cofficient : ";
                        cin>>C[i];
                        cout<<"Enter the degree : ";
                        cin>>D[i];
                   }
                   L2.createPoly(C,D,n1);
             }
            }while(c!=0);
           cout<<"List3 exited:-(\n";
           }
           break;
          case 0:
           break;
          default:
           cout<<"Enter Correct Choice\n";
         }
        cout<<endl;
       }while(choice!=0);
     cout<<"\nThank You\n\n";
     return 0;
}
     










