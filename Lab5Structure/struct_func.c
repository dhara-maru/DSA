// 4. Write a program to add two complex numbers by passing structure to a Function.
#include <stdio.h>
struct addnums{
   int a;
   int b;
   int add;
};
int addcomplexnum(struct addnums *c){
    c->add = c->a + c->b;
}
void main(){
   struct addnums obj;

   printf("Enter number 1 : ");
   scanf("%d", &obj.a);
   printf("Enter number 2 : ");
   scanf("%d", &obj.b);

   addcomplexnum(&obj);

   printf("Sum of %d + %d is = %d",obj.a,obj.b,obj.add);
   
}