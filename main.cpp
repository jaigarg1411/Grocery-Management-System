#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <cstring>
#include <string>
#include "grocerymanagement.h"
#include "items.h"
#include "fruits.h"
#include "vegetables.h"

using namespace std;

int main()
{
	FILE* fp;
	fp = fopen ("fruits.txt" , "r");
	char fr[20][7];
	float frr[20][6];
	int i=0,k=0;
	if (fp == NULL)
	{
		printf("Error opening the file !");
	}
	else{
		for(k=0;k<20;k++)
		{
			while((fscanf(fp,"%s%f%f%f%f%f%f",fr[i],&frr[i][0],&frr[i][1],&frr[i][2],&frr[i][3],&frr[i][4],&frr[i][5])) != EOF)
			{
				i++;
			}
		}
	}
	fclose(fp);

	FILE* fp1;
	fp1 = fopen ("vegetables.txt" , "r");
	char vg[20][7];
	float vgg[20][6];
	int m=0,n;
	if (fp1 == NULL)
	{
		printf("Error opening the file !");
	}
	else{
		for(n=0;n<20;n++)
		{
			while((fscanf(fp1,"%s%f%f%f%f%f%f",vg[m],&vgg[m][0],&vgg[m][1],&vgg[m][2],&vgg[m][3],&vgg[m][4],&vgg[m][5])) != EOF)
			{
				m++;
			}
		}
	}
	fclose(fp1);
	int j;

	for(i=0;i<20;i++)
	{
		for(j=i+1;j<20;j++)
		{	
			if(frr[i][3] > frr[j][3])
			{
				for(k=0;k<6;k++)
				{
					float temp = frr[i][k];
					frr[i][k] = frr[j][k];
					frr[j][k] = temp;
				}
				char ctemp[7];
				strcpy(ctemp,fr[i]);
				strcpy(fr[i],fr[j]);
				strcpy(fr[j],ctemp);
			}
		}
	}

	for(int q=0;q<20;q++)
	{
		for(int r=q+1;r<20;r++)
		{	
			if(vgg[q][2] > vgg[r][2])
			{
				for(int w=0;w<6;w++)
				{
					float temp = vgg[q][w];
					vgg[q][w] = vgg[r][w];
					vgg[r][w] = temp;
				}
				char ctemp1[7];
				strcpy(ctemp1,vg[q]);
				strcpy(vg[q],vg[r]);
				strcpy(vg[r],ctemp1);
			}
		}
	}
	grocerymanagement <fruits*> fruit;
	for(i=0;i<20;i++)
	{
		fruits* f = new fruits(fr[i],frr[i][0],frr[i][1],frr[i][4],frr[i][2],frr[i][3],frr[i][5]);
		fruit.add(f);
	}

	grocerymanagement <vegetables*> vegetable;
	for(i=0;i<20;i++)
	{
		vegetables* v = new vegetables(vg[i],vgg[i][0],vgg[i][1],vgg[i][4],vgg[i][3],vgg[i][2],vgg[i][5]);
		vegetable.add(v);
	}

	grocerymanagement<fruits*> :: node* fhead = fruit.head;
	grocerymanagement<vegetables*> :: node* vhead = vegetable.head;

	grocerymanagement<fruits*> :: node* fhead1 = fruit.head;
	grocerymanagement<vegetables*> :: node* vhead1 = vegetable.head;

	grocerymanagement<fruits*> :: node* fhead3 = fruit.head;
	grocerymanagement<vegetables*> :: node* vhead3 = vegetable.head;
	
	cout << "Welcome to My Grocery Store!" << endl;
	int no;
	while(1)
	{
		fhead = fruit.head;
		vhead = vegetable.head;
		fhead1 = fruit.head;
		vhead1 = vegetable.head;
		fhead3 = fruit.head;
		vhead3 = vegetable.head;
		cout << "\nSelect the functionality you want to execute: " << endl;
		cout << "1. Add fruits or vegetables to the system." << endl;
		cout << "2. Buy fruits or vegetables." << endl;
		cout << "3. Check the current amount available in store." << endl;
		cout << "4. See details of all items available in the store." << endl;
		cout << "5. Find items in a particular area." << endl;
		cout << "6. Buy fruits or vegetables based on calories" << endl;
		cout << "0. To EXIT" << endl << endl;
		cin >> no;

		if(no == 1)
		{
			char type;
			string type1;
			float cal,x,y,weight_per_unit,price_per_unit,units;
			cout << "Enter 'f' for fruits and 'v' for vegetables: ";
			cin >> type;
			cout << "Enter location x y: ";
			cin >> x >> y;
			cout << "Enter no. of units: ";
			cin >> units;
			cout << "Enter calories: ";
			cin >> cal;
			if(type == 'f')
			{
				cout << "Enter type of fruit: ";
				cin >> type1;
				cout << "Enter weight per unit: ";
				cin >> weight_per_unit;
				cout << "Enter price per unit: ";
				cin >> price_per_unit;
				fruits* ff = new fruits(type1,x,y,cal,weight_per_unit,price_per_unit,units);
				fruit.add(ff);
				cout << "\nNew stock list of fruits:\n";
				fruit.print();
			}

			else
			{
				cout << "Enter type of vegetable: ";
				cin >> type1;
				cout << "Enter volume per kg: ";
				cin >> weight_per_unit;
				cout << "Enter price per kg: ";
				cin >> price_per_unit;
				vegetables* vv = new vegetables(type1,x,y,cal,weight_per_unit,price_per_unit,units);
				vegetable.add(vv);
				cout << "\nNew stock list of vegetables:\n";
				vegetable.print();
			}
		}

		else if (no == 2)
		{
			char type;
			string type1;
			int units,bill,temp = 0,temp1 = 0,units1;
			cout << "Enter 'f' for fruits and 'v' for vegetables: ";
			cin >> type;
			time_t tt;
			struct tm* ti;
			time (&tt);
			ti = localtime(&tt);
			if(type == 'f')
			{
				cout << "Enter type of fruit: ";
				cin >> type1;
				cout << "Enter no. of units you want to buy: ";
				cin >> units;
				units1 = units;
				while(1)
				{
					if(fhead != NULL)
					{
						if((fhead->data->gettype() == type1) && (fhead->data->units >= units))
						{
							break;
						}
						else if((fhead->data->gettype() == type1) && (fhead->data->units < units))
						{
							temp = temp + (fhead->data->units * fhead->data->getprice_per_unit());
							units = units - fhead->data->units;
							temp1 = 1;
						}
					}
					else if(fhead == NULL)
					{
						cout << "The amount required is not in stock!";
						break;
					}
					if(temp1 == 1)
					{
						grocerymanagement<fruits*> :: node* fhead2 = fhead;
						fhead = fhead->next;
						fruit.remove(fhead2->data);
					}
					else if (temp1 == 0)
						fhead = fhead->next;
				}
				if(fhead != NULL)
				{
					bill = temp + units * fhead->data->getprice_per_unit();
					cout << "\nYour bill: " << endl;
					cout << "Type: " << type1 << endl;
					cout << "Purchase time: " << asctime(ti);
					cout << "Total units bought: " << units1 << endl;
					cout << "Total bill: Rs. " << bill << endl << endl;
				}
			}

			if(type == 'v')
			{
				cout << "Enter type of vegetable: ";
				cin >> type1;
				cout << "Enter no. of kg's you want to buy: ";
				cin >> units;
				units1 = units;
				while(1)
				{
					if(vhead != NULL)
					{
						if((vhead->data->gettype() == type1) && (vhead->data->units >= units))
						{
							break;
						}
						else if((vhead->data->gettype() == type1) && (vhead->data->units < units))
						{
							temp = temp + (vhead->data->units * vhead->data->getprice_per_unit());
							units = units - vhead->data->units;
							temp1 = 1;
						}
					}
					else if(vhead == NULL)
					{
						cout << "The amount required is not in stock!";
						break;
					}
					if(temp1 == 1)
					{
						grocerymanagement<vegetables*> :: node* vhead2 = vhead;
						vhead = vhead->next;
						vegetable.remove(vhead2->data);
					}
					else if (temp1 == 0)
						vhead = vhead->next;
				}
				if(vhead != NULL)
				{
					bill = temp + units * vhead->data->getprice_per_unit();
					cout << "\nYour bill: " << endl;
					cout << "Type: " << type1 << endl;
					cout << "Purchase time: " << asctime(ti);
					cout << "Total kg's bought: " << units1 << endl;
					cout << "Total bill: Rs. " << bill << endl << endl;
				}
			}
		}

		else if(no == 3)
		{
			char type;
			string type1;
			cout << "Enter 'f' for fruits and 'v' for vegetables: ";
			cin >> type;
			int n = 0;
			if(type == 'f')
			{
				cout << "Enter type of fruit: ";
				cin >> type1;
				while(fhead != NULL)
				{
					if((fhead->data->gettype()) == type1)
					{
						n = n + fhead->data->units;
						fhead->data->print();
						cout << endl;
					}
					fhead = fhead->next;
				}
				cout << "Total stock available of " << type1 << " is " << n << " units." << endl;
			}

			else
			{
				cout << "Enter type of vegetable: ";
				cin >> type1;
				while(vhead != NULL)
				{
					if((vhead->data->gettype()) == type1)
					{
						n = n + vhead->data->units;
						vhead->data->print();
						cout << endl;
					}
					vhead = vhead->next;
				}
				cout << "Total stock available of " << type1 << " is " << n << " kg" << endl;
			}

		}

		else if(no == 4)
		{
			cout << "Available stock of fruits is:" << endl;
			fruit.print();
			cout << endl;
			cout << "Available stock of vegetables is:" << endl;
			vegetable.print();
		}

		else if (no == 5)
		{
			char t;
			cout << "Which parameter you want to fix (x or y) or enter 'b' for fixing both: ";
			cin >> t;
			int x,y,temp = 0;
			if(t == 'x')
			{
				cout << "Enter x: ";
				cin >> x;
				while(fhead != NULL)
				{
					if(fhead->data->getx() == x)
					{
						fhead->data->print();
						cout << endl;
						temp = 1;
					}
					fhead = fhead->next;
				}

				while(vhead != NULL)
				{
					if(vhead->data->getx() == x)
					{
						vhead->data->print();
						cout << endl;
						temp = 1;
					}
					vhead = vhead->next;
				}
				if(temp == 0)
				{
					cout << "Not Found at this location!";
				}
			}

			else if(t == 'y')
			{
				cout << "Enter y: ";
				cin >> y;
				while(fhead != NULL)
				{
					if(fhead->data->gety() == y)
					{
						fhead->data->print();
						cout << endl;
						temp = 1;
					}
					fhead = fhead->next;
				}

				while(vhead != NULL)
				{
					if(vhead->data->gety() == y)
					{
						vhead->data->print();
						cout << endl;
						temp = 1;
					}
					vhead = vhead->next;
				}
				if(temp == 0)
				{
					cout << "Not found at this location!";
				}
			}

			else
			{
				cout << "Enter x y: ";
				cin >> x >> y;
				while(fhead != NULL)
				{
					if((fhead->data->getx() == x) && (fhead->data->gety() == y))
					{
						fhead->data->print();
						cout << endl;
						temp = 1;
					}
					fhead = fhead->next;
				}

				while(vhead != NULL)
				{
					if((vhead->data->getx() == x) && (vhead->data->gety() == y))
					{
						fhead->data->print();
						cout << endl;
						temp = 1;
					}
					vhead = vhead->next;
				}
				if(temp == 0)
				{
					cout << "Not found at this location!";
				}
			}
		}

		else if(no == 6)
		{
			int n;
			cout << "Enter calories: ";
			cin >> n;
			int max = 0,temp,i=0,count,bill = 0;
			cout << "\nYour bill summary: " << endl;
			while(1)
			{
				fhead = fruit.head;
				vhead = vegetable.head;
				fhead1 = fruit.head;
				vhead1 = vegetable.head;
				while(fhead != NULL)
				{
					temp = n / (fhead->data->getcalories());
					if(temp > max)
					{
						max = temp;
						count = i;
					}
					i++;
					fhead = fhead->next;
				}
				while(vhead != NULL)
				{
					temp = n / (vhead->data->getcalories());
					if(temp > max)
					{
						max = temp;
						count = i;
					}
					i++;
					vhead = vhead->next;
				}

				if(count <= 20)
				{
					for(int j=0;j<count;j++)
					{
						fhead1 = fhead1->next;
					}
					cout << "Type: " << fhead1->data->gettype() << endl;
					cout << "Price per unit: " << fhead1->data->getprice_per_unit() << endl;
					if((fhead1->data->units) <= (n/fhead1->data->getcalories()))
					{
						cout << "Total units: " << fhead1->data->units << endl <<endl;
						bill = bill + (fhead1->data->units * fhead1->data->getprice_per_unit());
						n = n - (fhead1->data->units * fhead1->data->getcalories());
						fhead3 = fhead1;
						fhead1 = fhead1->next;
						fruit.remove(fhead3->data);
					}
					else
					{
						cout << "Total units: " << (n/fhead1->data->getcalories()) << endl <<endl;
						bill = bill + ((n/fhead1->data->getcalories()) * fhead1->data->getprice_per_unit());
						break;
					}
				}

				if(count > 20)
				{
					count = count - 20;
					for(int j=0;j<count;j++)
					{
						vhead1 = vhead1->next;
					}
					cout << "Type: " << vhead1->data->gettype() << endl;
					cout << "Price per kg: " << vhead1->data->getprice_per_unit() << endl;
					if((vhead1->data->units) < (n/vhead1->data->getcalories()))
					{
						cout << "Total units: " << vhead1->data->units << endl << endl;
						bill = bill + vhead1->data->units * vhead1->data->getprice_per_unit();
						n = n - (vhead1->data->units * vhead1->data->getcalories());
						vhead3 = vhead1;
						vhead1 = vhead1->next;
						vegetable.remove(vhead3->data);
					}
					else
					{
						cout << "Total units: " << (n/vhead1->data->getcalories()) << endl << endl;
						bill = bill + ((n/vhead1->data->getcalories()) * vhead1->data->getprice_per_unit());
						break;
					}
				}
			}
			cout << "Your Total Bill: Rs." << bill << endl;
		}
		else if(no == 0)
		{
			break;
		}
	}
		
	return 0;
}