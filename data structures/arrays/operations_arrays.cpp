#include<iostream>
#include<bits/stdc++.h>
using namespace std;
// function prototypes
void swap(int *p,int *q);
int rbinary(int a[],int l,int h,int key);
void display(struct Array arr);
void append(struct Array *arr,int x);
void insert(struct Array *arr,int index,int element);
void Delete(struct Array *arr,int index);
int linear(struct Array arr,int key);
int mod_linear(struct Array *arr,int key);
int binary(struct Array arr,int key);


struct Array{
int a[20];
int size{};
int length{};
}arr;

void display(struct Array arr){
    cout<<"The elements of array are:"<<endl;
    for(int i=0;i<arr.length;i++){
      cout<<arr.a[i]<<endl;
    }
}
void append(struct Array *arr,int x){
    if(arr->length<arr->size){
        arr->a[arr->length++]=x;
    }
}
void insert(struct Array *arr,int index,int element){
    if(index>=0 && index<= arr->length){
        for(int i=arr->length;i>index;i--){
            arr->a[i]=arr->a[i-1];
        }
        arr->a[index]=element;
        arr->length++;
    }
}
void Delete(struct Array *arr,int index){
    if(index>=0 && index<=arr->length){
        for(int i=index;i<arr->length-1;i++){
           int x=arr->a[index];
           arr->a[i]=arr->a[i+1];
}
arr->length--;
}
}
int linear(struct Array arr,int key){
    for(int i=0;i<arr.length;i++){
        if(arr.a[i]==key){
            return i;
        }
    }
    return -1;
}
int mod_linear(struct Array *arr,int key){
 for(int i=0;i<arr->length;i++){
 if(arr->a[i]==key){
//  swap(&arr->a[i],&arr->a[i-1]);      //transformation
swap(&arr->a[i],&arr->a[0]);            //move to head
 return i;
 } 
 }
 return -1;
}
void swap(int *p,int *q){
    int temp=*p;
    *p=*q;
    *q=temp;
}
// int binary(struct Array arr,int key){
//     int low=0,high=arr.length-1,mid=(low+high)/2;
//     while(low<=high){
//         mid=(low+high)/2;
//         if(arr.a[mid]==key){
//             return mid;
//         }
//         else if(key<arr.a[mid]){
//             high=mid-1;
//         }
//         else{
//             low=mid+1;
//         }
//     }
//     return -1;
// }
// int rbinary(int a[],int l,int h,int key){
//     if(l<=h){
//         int mid=(l+h)/2;
//         if(a[mid]==key){
//             return mid;
//         }
//         else if(key<a[mid]){
//             return rbinary(a,l,mid-1,key);
//         }
//         else{
//             return rbinary(a,mid+1,h,key);
//         }
// }
// }
// int Get(struct Array arr,int index){
//     if(index>0 && index<=arr.length){
//         return arr.a[index];
//     }
// }

// int Set(struct Array *arr,int index,int x){
//     if(index>0 && index<=arr->length){
//         arr->a[index]=x;
//     }
// }
int Max(struct Array arr){
    int max=arr.a[0];
    for(int i=0;i<arr.length;i++){
        if(arr.a[i]>max){
            max=arr.a[i];
        }
    }
    return max;
}
int Min(struct Array arr){
    int min=arr.a[0];
    for(int i=0;i<arr.length;i++){
        if(arr.a[i]<min){
            min=arr.a[i];
        }
    }
    return min;
}
int Sum(struct Array arr){
    int sum=0;
    for(int i=0;i<arr.length;i++){
        sum=sum+arr.a[i];
    }
    return sum;
}
float Average(struct Array arr){
    return (float)Sum(arr)/arr.length;
}

// void Reverse(struct Array *arr){
//     int *b=new int[arr->length];
//     for(int i=0,j=arr->length-1;i<arr->length,j>=0;i++,j--){
//         b[i]=arr->a[j];

//     for(int i=0;i<arr->length;i++){
//         arr->a[i]=b[i];
//     }
// }
// }

// void Reverse_1(struct Array *arr){
//     for(int i=0,j=arr->length;i<j;i++,j--){
//         swap(&arr->a[i],&arr->a[j]);
//     }
// }
void insertsort(struct Array *arr,int x){
    int i=arr->length-1;
    while(i>=0 && arr->a[i]>x){
        arr->a[i+1]=arr->a[i];
        i--;
    }
    arr->a[i+1]=x;
    arr->length++;


}

void is_sorted(struct Array arr){
    for(int i=0;i<arr.length-1;i++){
        if(arr.a[i]>arr.a[i+1]){
        cout<<"Array is not sorted!"<<endl;
    }
}
 cout<<"Array is sorted"<<endl;
}

void rearrange(struct Array *arr){
    int i=0,j=arr->length-1;
    while(i<j){
        while(arr->a[i]<0)i++;
        while(arr->a[j]>0)j--;
        if(i<j){
            swap(&arr->a[i],&arr->a[j]);
        }
    }

}

struct Array * Merge(struct Array *arr1,struct Array *arr2){
    struct Array *arr3;
    arr3= new struct Array[arr1->length+arr2->length];
   int i=0,j=0,k=0;
   while(i<arr1->length && j<arr2->length){
   if(arr1->a[i]<arr2->a[j]){
       arr3->a[k]=arr1->a[i];
       i++;k++;
   }
   else{
   arr3->a[k]=arr2->a[j];
    k++;j++;
   }
}
  for(;i<arr1->length;i++){
     arr3->a[k]=arr1->a[i];
     k++;
  }
  for(;j<arr2->length;j++){
     arr3->a[k]=arr2->a[j];
     k++;
}
return arr3;
}



int main(){
    // struct Array arr={{1,2,3,5,7},20,5};
    //  append(&arr,6);
    //  insert(&arr,2,10);
    // Delete(&arr,1);
    // cout<<mod_linear(&arr,4)<<endl;
    // cout<<binary(arr,1)<<endl;
    // cout<<rbinary(arr.a,0,arr.length,1);
    // cout<<Get(arr,2)<<endl;
    // insertsort(&arr,5);
    // is_sorted(arr);
    // rearrange(&arr);
    struct Array arr1={{1,3,5,7,9},10,5};
    struct Array arr2={{2,4,6,8,10},10,5};
    struct Array *arr3;
    arr3=Merge(&arr1,&arr2);
    display(*arr3);
    // display(arr);
    
}