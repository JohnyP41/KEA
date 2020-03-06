#include <iostream>
using namespace std;

int pieniadze[5];
int wartosci[5] = {10, 20, 50, 100, 200};

bool check(int k)
{
	int start = k;
	int Poziom = 4;
	while(Poziom >= 0 && k > 0)
	{
		if(pieniadze[Poziom] > 0 && k >= wartosci[Poziom])
		{
			int amount = k/wartosci[Poziom];
			if(wartosci[Poziom] != 50)
			{
				if(pieniadze[Poziom] >= amount)
				{
					k -= wartosci[Poziom] * amount;
				}
				else
				{
					k -= wartosci[Poziom] * pieniadze[Poziom];
				}
			}
			else
			{
				if(pieniadze[Poziom] >= amount)
				{
					if(amount%2 == 1)
					{
						k -= wartosci[Poziom] * (amount - 1);
					}
					else
					{
						k -= wartosci[Poziom] * amount;
					}
				}
				else
				{
					if(pieniadze[Poziom]%2 == 1)
					{
						k -= wartosci[Poziom] * (pieniadze[Poziom] - 1);
					}
					else
					{
						k -= wartosci[Poziom] * pieniadze[Poziom];
					}
				}
			}			
		}
		Poziom--;
	}
	if(k == 0) return true;
	
	Poziom = 4;
	k = start;
	while(Poziom >= 0 && k > 0)
	{
		if(pieniadze[Poziom] > 0 && k >= wartosci[Poziom])
		{
			int amount = k/wartosci[Poziom];
			if(wartosci[Poziom] != 50)
			{
				if(pieniadze[Poziom] >= amount)
				{
					k -= wartosci[Poziom] * amount;
				}
				else
				{
					k -= wartosci[Poziom] * pieniadze[Poziom];
				}
			}
			else
			{
				if(pieniadze[Poziom] >= amount)
				{
					if(amount%2 == 1)
					{
						k -= wartosci[Poziom] * amount;
					}
					else
					{
						k -= wartosci[Poziom] * (amount - 1);
					}
				}
				else
				{
					if(pieniadze[Poziom]%2 == 1)
					{
						k -= wartosci[Poziom] * pieniadze[Poziom];
					}
					else
					{
						k -= wartosci[Poziom] * (pieniadze[Poziom] - 1);
					}
				}
			}			
		}
		Poziom--;
	}
	if(k == 0) return true;
	else return false;
}

int main()
{
	int d, k = 0;
	bool wyniki[1000];
	cin >> d;
	for(int i = 1 ; i <= d ; i++)
	{
		cin >> pieniadze[0]; 
		cin >> pieniadze[1];
		cin >> pieniadze[2];
		cin >> pieniadze[3];
		cin >> pieniadze[4];
		cin >> k;
		
		if(k%10 == 0)
			wyniki[i] = check(k);
		else
			wyniki[i] = false;			
	}
	
	for(int i = 1 ; i <=d ; i++)
	{
		if(wyniki[i]) cout << "TAK" << endl;
		else cout << "NIE" << endl;
	}
	
	return 0;
}