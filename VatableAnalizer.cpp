//Application for VTABLE Analizer
//In these application we are going to access VPTR and through VPTR we access VTABLE and from the VTABLE we access the adress of virtual function

using namespace std;
#include<iostream>

class Base
{
	      int i,j;
		  
 		   virtual void fun()             
		   {
			   cout<<"Base fun\n";
		   }
		   virtual void gun()
		   {
			   cout<<"Base gun\n";
		   }
		   void sun()
		   {
			   cout<<"Base sun\n";
		   }

};

class Derived : public Base
{
	public:
	   
	       int i;
		   Derived()
		   {
			   i = 21;
		   }
		   void fun()
		   {
			   cout<<"Derived fun\n";
		   }
		   	void sun()
		   {
			   cout<<"Derived sun\n";
		   }
		   virtual void run()
		   {
			   cout<<"Derived run\n";
		   }
};
int main()
{
	Base bobj;
	Derived dobj;
	
	cout<<"size of Base class"<<"\t"<<sizeof(bobj)<<"\n";
	cout<<"size of derived class"<<"\t"<<sizeof(dobj)<<"\n";
	
    int *op = (int*) (&dobj);                            //type conversio is important ie (int*)otherwise  error: cannot convert 'Derived*' to 'int*' i
	cout<<"Base Adress of dobj is:\t"<<op<<"\n";
	
    int *vptr = (int*) (*op);  
	cout<<"Adress of vtable is:\t"<<vptr<<"\n";
	
	void (*fp)();
	
	fp = (void(*)())(*vptr);
	fp();
	
	
	fp = (void(*)())(*vptr+1);
	fp();
	
	fp = (void(*)())(*vptr+2);
	fp();
	
	return 0;
}

/*
output 
size of Base class      12
size of derived class   16
Base Adress of dobj is: 0x61fee8
Adress of vtable is:    0x4052ec
Derived fun
Derived fun
*/