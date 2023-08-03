#include<iostream>
using namespace std;
int main()
{
	double i;
	while(true)
	{
		cin>>i;
		if(i<=10){ cout<<((int) i*0.1/1000)*1000;continue;	}
		if(i>10&&i<20){ cout<<((int) (10*0.1+(i-10)*0.75)/1000)*1000;continue;	}
		if(i>=20&&i<40){ cout<<((int) (10*0.1+10*0.075+(i-20)*0.05)/1000)*1000;continue;	}
		if(i>=40&&i<60){ cout<<((int) (10*0.1+10*0.075+20*0.05+(i-40)*0.03)/1000)*1000;continue;	}
		if(i>=60&&i<100){ cout<<((int) (10*0.1+10*0.075+20*0.05+20*0.03+(i-60)*0.015)/1000)*1000;continue;	}
		if(i>100){        cout<<((int) (10*0.1+10*0.075+20*0.05+20*0.03+40*0.015+(i-100)*0.01)/1000)*1000;continue;	}
	}
}
