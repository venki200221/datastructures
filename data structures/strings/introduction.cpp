#include<iostream>
#include<stdio.h>
#include<bits/stdc++.h>
#include<vector>

using namespace std;

// Length of string

// int main()
// {
//     char *s="venki";
//     int i=0;
//     while(s[i]!='\0'){
//         i++;
//     }
//     cout<<"The length of the string is:"<<i<<endl;
// }

// convert uppercase to lowercase
// int main()
// {
//     char s[]="WELCoME";
//     int i=0;
//     while(s[i]!='\0'){
//         if(s[i]>=65 && s[i]<=90){
//             s[i]+=32;
//         }
//         else if(s[i]>=97 && s[i]<=122){
//             s[i]-=32;
//         }
//         i++;
//     }
//     int j=0;
//     while(s[j]!='\0'){
//         cout<<s[j];
//       j++;
//     }
// return 0;
// }

// number of vowels & consonents
// int main()
// {
// int vcount=0,ccount=0;
// int i=0;
// char s[]="venki";
// while(s[i]!='\0'){
//     if(s[i]=='a'||s[i]=='A'||s[i]=='e'||s[i]=='E'||s[i]=='i'||s[i]=='I'||s[i]=='o'||s[i]=='O'||s[i]=='u'||s[i]=='U'){
//         vcount++;
//     }
//     else if((s[i]>=65 && s[i]<=90) || (s[i]>=97 && s[i]<=122)){
//         ccount++;
//     }
//     i++;
// }
// cout<<"Vowels:"<<vcount<<endl;
// cout<<"Consonents:"<<ccount<<endl;
// }

// number of words
// int main()
// {
// char s[]="My name  is   venki.";
// int words=0,i=0;
// while(s[i]!='\0'){
//     if(s[i]==' ' && s[i-1]!=' ' ){
//         words++;
//     }
//     i++;
// }
// cout<<"The number of words in the sentence is:"<<words+1<<endl;
// }

// validation of string
// int main()
// {
// char *name="Venki@2002";
// int i=0;
// while(name[i]!='\0'){

// if(!(name[i]>=65 && name[i]<=90) && !(name[i]>=97 && name[i]<=122) && !(name[i]>=48 && name[i]<=57)){
//     cout<<"The string is not valid!"<<endl;
//     break;
// }
// else{
//     i++;
//     continue;
// }
// }
// }    

// reversing a string
// method-1

// int main()
// {
// char s[]="python";
// char rev[7];
// int i=0,j=6;
// while(s[i]!='\0'){
//     rev[j]=s[i];
//     i++;j--;
// }
// rev[6]='\0';
// int k=0;
// while(rev[k]!='\0'){
// cout<<rev[k];
// }
// }
    
// method-2
// int main()
// {
//     char s[]="venki";
//     int i=0,j=4;
//     char t;
//     while(i<j){
//         t=s[i];
//         s[i]=s[j];
//         s[j]=t;
//         i++;j--;
//     }
//     int k=0;
//     while(s[k]!='\0'){
//         cout<<s[k];
//         k++;
//     }
// }

// finding duplcates in strng using hash table
// method-1
// int main()
// {
//     char s[]="original";
//     int arr[26]={0};
//     int i=0,j=0;
//     while(s[i]!='0'){
//      arr[s[i]-97]++;
//         i++;
//     }
//     for(j=0;j<26;j++){
//         if(arr[j]>1){
//         printf("%c is repeated for %d times\n",j+97,arr[j]);
//         }
//     }
// }

// method-2
// using bitwise operator

// int main()
// {
//     char s[]="finding";
//     long int h=0,x=0;
//     for(int i=0;s[i]!='\0';i++){
//         x=1;
//         x=x<<s[i]-97;
//         if(x & h >0){
//             cout<<s[i]<<" Is Repeated"<<endl;
//         }
//         else{
//             h=x|h;
//         }
//     }
// }

// anagram

int main()
{
    char first[]="decimal";
    char second[]="medical";
    int hash[26]={0};
    for(int i=0;first[i]!='\0';i++){
        hash[first[i]-97]++;
    }
    for(int i=0;second[i]!='\0';i++){
        hash[second[i]-97]--;
    }
    
    for(int i=0;i<26;i++){
         if(hash[i]<0){
            cout<<"its not an anagram"<<endl;
            break;
        }
    }
}