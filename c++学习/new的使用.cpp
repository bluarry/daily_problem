#include <iostream>
using namespace std;

int main(){

	int *pt=new int ;
	*pt=100;
	cout << "int " << "value= " << *pt <<",location = " << pt << endl;


	delete pt;
	return 0;
}