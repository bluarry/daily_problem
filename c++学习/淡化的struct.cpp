#include <iostream>
using namespace std;


struct inflateble{
	char name[20];
	float volume;
	double price;
};

int main()
{

	/*看这里！*/inflateble guest={"Glorious Gloria",1.88,32.29};
	cout << "guest' name:" <<guest.name<< endl;
	cout << "guest's volume : " << guest.volume<<endl;
	cout << "guest's price : " << guest.price;
	return 0;
}



