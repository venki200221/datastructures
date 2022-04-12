#include<iostream>
#include<stdio.h>
#include<bits/stdc++.h>

using namespace std;

struct term{
    int coeff{};
    int exp{};
};
struct poly{
int n{};
struct term *t;
};

void create(struct poly *p){
    cout<<"Enter the number of non-zero terms:"<<endl;
    cin>>p->n;
    p->t=new term[p->n];
    for(int i=0;i<p->n;i++){
        cout<<"Enter the coefficient & exponent of "<<i+1<<" term:"<<endl;
        cin>>p->t[i].coeff>>p->t[i].exp;
    }
}

int evaluate(struct poly p,int x){
int sum=0;
for(int i=0;i<p.n;i++){
sum+=p.t[i].coeff*pow(x,p.t[i].exp);
}
return sum;
}

struct poly *add(struct poly *p1,struct poly *p2){
    int i{},j{},k{};
    struct poly *p3;
    p3=new poly[p1->n+p2->n];
 i=j=k=0;
 while(i<p1->n && j<p2->n){
   if(p1->t[i].exp>p2->t[j].exp){
       p3->t[k++]=p1->t[i++];
   }
   else if(p1->t[i].exp<p2->t[j].exp){
       p3->t[k++]=p2->t[j++];
   }
   else{
       p3->t[k].exp=p1->t[i].exp;
       p3->t[k++].coeff=p1->t[i++].coeff + p2->t[j++].coeff;
   }
 }
 for(;i<p1->n;i++){
     p3->t[k++]=p1->t[i];
 }
 for(;j<p2->n;j++){
     p3->t[k++]=p2->t[j];
 }
p3->n=k;

return p3;
}



int main()
{
int x{};
cout<<"Enter the value of x:"<<endl;
cin>>x;
struct poly p1,p2,*p3;
create(&p1);
create(&p2);
p3=add(&p1,&p2);
cout<<evaluate(*p3,x)<<endl;



}