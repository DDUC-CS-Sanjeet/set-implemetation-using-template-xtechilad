#include<bits/stdc++.h>
#include<string.h>
#include<ctype.h>
using namespace std;

template <class T>
class MySet
{
	private:
    T *set;
    int cad;
    
    public:
    MySet(int n)
    {
        cad=n;
        set=new T[cad];
    }
	
    void input(T t)
    {
        for(int k=0;k<cad;k++)
        {
            	cin>>set[k];
        }
      rem_duplicate();
    }
     void display()
    {
    	cout<<"{ ";
        for(int i=0;i<cad;i++)
        {
        	if(i==cad-1)
        	{
        		cout<<set[i];
			}
        	else
            {
            	cout<<set[i]<<", ";
			}
        }
        cout<<"\b}"<<endl;
        showcad();
    }

    void rem_duplicate()
    {
        for(int i=0;i<cad;i++)
        {
            for(int j=i+1;j<cad;)
            {
                if(set[i]==set[j])
                {
                    set[i]=set[j];
                    for(int k=j;k<cad-1;k++)
                    {
                        set[k]=set[k+1];
                    }
                    --cad;
                }
                else
                {
                    j++;
                }
            }
        }
    }
    MySet operator + (const MySet& M)
    {
        MySet<T>temp(cad+M.cad);
        for(int i=0,j=0;i<(cad+M.cad);i++)
        {
            if (i<cad)
            {
                temp.set[i]=set[i];
            }
            else
            {
                temp.set[i]=M.set[j];
                j++;
            }
            
        }
        temp.rem_duplicate();
        return temp;
        
    }
    MySet operator * (const MySet& ob)
    {
      
        int k=0;
        for(int i=0;i<cad;i++)
        {
        	for(int j=0;j<ob.cad;j++)
        	{
        		if(set[i]==ob.set[j])
        		{
        			k++;
				}
			}
		}
		int p=0;
		MySet<T> temp1(k);
		 for(int i=0;i<cad;i++)
        {
        	for(int j=0;j<ob.cad;j++)
        	{
        		if(set[i]==ob.set[j])
        		{
        			temp1.set[p]=set[i];
        			p++;
				}
			}
		}
		temp1.rem_duplicate();
		return temp1;
    }
    MySet operator - (const MySet& ob1)
    {
        MySet<T> temp2(cad);
        for(int i=0;i<cad;i++)
        {
            temp2.set[i]=set[i];
        }
        MySet<T> Sub=temp2*ob1;
        for(int i=0;i<temp2.cad;i++)
        {
            for(int j=0;j<Sub.cad;j++)
            {
                if(temp2.set[i]==Sub.set[j])
                {
                    for(int k=i;k<temp2.cad-1;k++)
                    {
                        temp2.set[k]=temp2.set[k+1];
                    }
                    temp2.cad--;
                }
            }
        }
        temp2.rem_duplicate();
        return temp2;
    }
     MySet operator ^ (MySet ob2)
    {
        MySet<T> temp3(cad);
        for(int i=0;i<cad;i++)
        {
            temp3.set[i]=set[i];
        }
        MySet<T> Sub1=temp3*ob2;
        MySet<T> Union=temp3+ob2;
        for(int i=0;i<Union.cad;i++)
        {
            for(int j=0;j<Sub1.cad;j++)
            {
                if(Union.set[i]==Sub1.set[j])
                {
                    for(int k=i;k<Union.cad-1;k++)
                    {
                        Union.set[k]=Union.set[k+1];
                    }
                    Union.cad--;
                }
            }
        }
        Union.rem_duplicate();
        return Union;
    }
    
    bool operator == (const MySet<T>& ob4)
    {
    	int flag=0;
    	if(cad>=ob4.cad)
    	{
    	    for(int i=0;i<cad;i++)
        	{
        		for(int j=0;j<cad;j++)
                {
                	if(set[i]==ob4.set[j])
            		{
             		   	flag =1;
             		   	break;
            		}
				}
            		
        	}
		}
		else
		{
		    for(int i=0;i<ob4.cad;i++)
        	{
        		for(int i=0;i<ob4.cad;i++)
          	    	if(set[i]!=ob4.set[i])
          	   		{
            	   		 flag=1;
            	   		 break;
            		}
      		}
		}
      if(flag)
      {
      	 return true;
	  }
	  else{
	  	 return false;
	  }
       
    }
    MySet<T>& operator =(const MySet<T>& ob3)
    {
        for(int i=0;i<cad;i++)
        {
            set[i]=ob3.set[i];
        }
        return *this;
    }
    void showcad()
    {
        cout<<"\nCardinality :"<<cad << "\n";
    }
    void PowerSet()
    {
    	int len=pow(2,cad);
    	cout<<"{ ";
    	for(int i=0;i<len;i++)
    	{
    		cout<<"{ ";
    		for(int t=i,j=0;j<cad;j++)
    		{
    			if(t&1)
    			{
    				cout << set[j];
				}
				t>>=1;
			}
			if(i==len-1)
			{
				cout<<"\b\b },"; 
		    }   
			else
			{
				cout<<"\b\b }, "; 
			}    
        }
		cout<<"\b }"; 
	}
};

template<typename T>
void Set(T t)
{
	char choice;
	int ch;
	int cad1,cad2;
	
	cout << "Enter cardinality of first set:";
	cin >> cad1;
	MySet<T> Set1(cad1);
	cout << "\nEnter cardinality of second set:";
	cin >> cad2;
	MySet<T> Set2(cad2);
	cout << "\nEnter the elements of first set:";
	Set1.input(t);
	cout << "\nEnter the elements of second set:";
	Set2.input(t);
	cout << "\n\nMENU FOR SET:\n";
	cout << "1. Union\n";
    cout << "2. Intersection\n";
    cout << "3. Difference(Enter the biggest set first)\n";
    cout << "4. Symmetric Difference\n";
    cout << "5. Equality of sets\n";
    cout << "6. Power sets for both sets\n";
    cout << "7. Implementation of assignment operator\n";
    do
    {
    	cout << "Enter your choice: ";
    	cin >> ch;
    	switch(ch)
    	{
    		case 1:
            {
            	MySet<T> Set3=Set1+Set2;
            	Set3.display();
                break;
            }
            case 2:
            {
            	MySet<T> Set3(Set1*Set2);
            	Set3.display();
                break;
            }
            case 3:
            {
            	MySet<T> Set3=Set2-Set1;
            	MySet<T> Set4=Set1-Set2;
            	cout<<"\nDifference Set2-Set1 is: ";
            	Set3.display();
            	cout<<"\nDifference Set1-Set2 is: ";
            	Set4.display();
                break;
            }
            case 4:
            {
            	MySet<T> Set3=Set1^Set2;
            	Set3.display();
                break;
            }
            case 5:
            {
            	if(Set1==Set2)
            	{
            		cout<<"\nSets are equal.";
				}
				else
				{
					cout<<"\nSets aren't equal.";
				}
                break;
            }
            case 6:
           	{  cout<<"\nPower Set of Set1:";
			   Set1.PowerSet();
			   cout<<"\nPower Set of Set2:";
			   Set2.PowerSet(); 	
			   break;	
			}
            case 7:
            {
            	cout<<"\nImplementing assignment operator:"<<endl;
            	MySet<T> Set3(cad2);
            	Set3=Set2;
            	Set3.display();
                break;
            }
            default:
            {
            	cout<<"\nInvalid choice!!!";
            	break;
            }
        }
        cout<<"Do you want to continue?(Y/N):";
        cin>>choice;
    }while(choice=='Y'||choice=='y');
}

int main()
{
   int ch;
   string str="abcd";
   cout << "SELECTION MENU:";
	cout << "\n1.char";
	cout << "\n2.int";
	cout << "\n3.double";
	cout << "\n4.String";
	cout << "\n\nEnter your choice:";
	cin>>ch;
   switch (ch)
   {
        case 1:
        {
            Set('a');
            break;
        }
        case 2:
        {
            Set(1);
            break;
        }
        case 3:
        {
            Set(1.0);
            break;
        }
        case 4:
        {
            Set(str);
            break;
        }
        default:
        {
            cout<<"You entered an invalid choice\n";
        }
   }
    return 0;
}

template class MySet<char>;
template class MySet<int>;
template class MySet<double>;
template class MySet<string>;
