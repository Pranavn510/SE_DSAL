#include <iostream>
#include <string.h>
#define SIZE 10
using namespace std;

class node
{
    string name;
    long long int mobile;
    int link;

    node()
    {
        name = "";
        mobile = 0;
        link = -1;
    }
    node(string name, long long int mobile, int link)
    {
        this->name = name;
        this->mobile = mobile;
        this->link = link;
    }

    friend class hashtable;
};

class hashtable
{
node table[SIZE];

public:
    int hashcode(long long int);
    void insertWithReplace(string, long long int);
    void insertWithoutReplace(string, long long int);
    void display();
    void search(long long int);

};

int hashtable::hashcode(long long int mobile)
{
    return mobile % SIZE;
}

void hashtable::insertWithoutReplace(string n, long long int num)
{
    int pos= hashcode(num);
    int prepos;
    if (table[pos].mobile == 0)
    {
        table[pos].mobile = num;
        table[pos].name = n;
    }
    else
    {
        while (table[pos].link != -1)
        {
            pos= table[pos].link;
        }
        prepos= pos;
        while (table[pos].mobile != 0)
        {
            pos= (pos + 1) % 10;
        }
        table[pos].mobile = num;
        table[pos].name = n;
        table[prepos].link = pos;
    }
}

void hashtable::display()
{
    for (int i = 0; i < SIZE; i++)
    {
        cout << i << ")\t" << table[i].mobile << ":\t" << table[i].name << "\n";
    }
}

void hashtable::search(long long int num)
{
    int count = 1;
    int hashadd = hashcode(num);
    if (table[hashadd].mobile == num)
    {
        cout<<"Number is found "<<endl;
        cout <<"Mobile No. : "<<table[hashadd].mobile << " , Name of client : " << table[hashadd].name << " " << endl;
        cout <<"No. of comparisons : "<<count << endl;
        return;
    }
    else
    {
        while (table[hashadd].link != -1)
        {
            hashadd = table[hashadd].link;
            count++;
            if (table[hashadd].mobile == num)
            {
                cout<<"Number is found "<<endl;
                cout <<"Mobile No. : "<<table[hashadd].mobile << " , Name of client : " << table[hashadd].name << " " << endl;
                cout <<"No. of comparisons : "<<count << endl;
                return;
            }
        }
        cout<<"Not found..."<<endl;
    }
}

void hashtable::insertWithReplace(string n,long long int num)
{
    int pos= hashcode(num);
    int prepos;
    if(table[pos].mobile == 0)
    {
        table[pos].mobile = num;
        table[pos].name = n;
    }
    else
    {
        if(pos== hashcode(table[pos].mobile))
        {
            prepos= pos;
            while(table[pos].link != -1)
            {
                pos= table[pos].link;
                prepos= pos;
            }
            while(table[pos].mobile != 0)
            {
                pos = (pos+1)%SIZE;
            }
            table[pos].name = n;
            table[pos].mobile = num;
            table[prepos].link =pos;
        }
        else
        {
            node temp = table[pos];
            int m = hashcode(table[pos].mobile);
            table[m].link = temp.link;
            table[pos].mobile = num;
            table[pos ].name = n;
            insertWithReplace(temp.name,temp.mobile);
        }
    }
}



int main()
{
    hashtable ht;
    string name;
    long long int mobile;
    int flag=1;

    while(flag)
    {
    int choice;
    cout << "\n-----------------menu-----------\n 1.Hashing table without replacement\n 2.Hashing table with replacement\n 3.Exit" << endl;
    cout << "\nEnter choice : ";
    cin >> choice;

    if(choice == 1)
    {
        int ch;
        do
        {
            cout << "\n1.insert\n2.search\n3.display hash table\n4.exit" << endl;
            cout << "\nEnter choice : ";
            cin >> ch;
            switch(ch)
            {
                case 1 :
                {
                    char a;
                    do
                    {
                        cout<<"Enter name : ";
                        cin>>name;
                        cout<<"Enter mobile : ";
                        cin>>mobile;
                        ht.insertWithoutReplace(name,mobile);
                        cout<<"do you want to insert more ? (y/n) : ";
                        cin>>a;
                    }while(a=='y');
                    break;
                }

                case 2:
                {
                    cout<<"Enter mobile no. for search : ";
                    cin>>mobile;
                    ht.search(mobile);
                    break;
                }

                case 3:
                {
                    ht.display();
                    break;
                }

            }
        }while(ch!=4);
    }

    if(choice == 2)
    {
        int ch;
        do
        {
            cout << "\n1.insert\n2.search\n3.display hash table\n4.exit" << endl;
            cout << "\nEnter choice : ";
            cin >> ch;

            switch(ch)
            {
                case 1 :
                {
                    char a;
                    do
                    {
                        cout<<"Enter name : ";
                        cin>>name;
                        cout<<"Enter mobile : ";
                        cin>>mobile;
                        ht.insertWithReplace(name,mobile);
                        cout<<"do you want to insert more ? (y/n) : ";
                        cin>>a;
                    }while(a=='y');
                    break;
                }

                case 2:
                {
                    cout<<"Enter mobile no. for search : ";
                    cin>>mobile;
                    ht.search(mobile);
                    break;
                }

                case 3:
                {
                    ht.display();
                    break;
                }
            }
        }
        while(ch!=4);
    }

    if(choice == 3)
    {
        cout<<"Exited successfully !!";
        flag=0;
    }
    return 0;
    }
}

