#include<iostream>
#include<fstream>
using namespace std; 

class shopping
{
    private_member_variables:
        int productcode; 
        string productname; 
        float price; 
        float discount; 
        
        public_member_functions: 
            void menu(); 
            void administrator(); 
            void buyer(); 
            void add(); 
            void edit();
            void remove(); 
            void list(); 
            void receipt(); 
       
}; 

// Created a set of variables that will be intended to store information about the products/items that will be sold in the supermarket
// Created a set of functions that the user can use when navigating through the supermarket

void shopping :: menu()
{
    mainstartingpage; 
    int usermenuchoice; 
    string useremail; 
    string userpassword; 

    cout<<"\t\t\t\t_______________________\n";
    cout<<"\t\t\t\t                       \n";
    cout<<"\t\t\t\t Supermarket Main Menu \n";
    cout<<"\t\t\t\t                       \n";
    cout<<"\t\t\t\t_______________________\n";
    cout<<"\t\t\t\t                       \n";
    cout<<"\t\t\t\t 1) Administrator      \n";
    cout<<"\t\t\t\t 2) Buyer              \n";
    cout<<"\t\t\t\t 3) Exit               \n";
    cout<<"\t\t\t\t                       \n";
    cout<<"\t\t\t\t Select and Option:    \n";
    cin>>usermenuchoice; 

    // Main Menu Graphics 

    switch(usermenuchoice)
    {
        //User enters 1; They will be brought to the adminstrator login page where they have to enter the correct email and password to be logged in as an adminstrator
        case 1:
            cout<<" Please Login \n"; 
            cout<<" Enter Email: \n"; 
            cin>>useremail; 
            cout<<" Password: \n"; 
            cin>>userpassword;

            if(useremail="supermarket123@email.com" && userpassword="supermarket123")
            {
                adminstrator();
            }
            else
            {
                cout<<"Invalid Email/Password"; 
            }
            break;    
    
        //User enters 2; They will be brought to a buyer page where the given functions will be attached to where they can operate around the supermarket
        case 2: 
            {
                buyer();
            }
        // User enters 3; They will exit the program and be brough to the main menu    
        case 3: 
            {
                exit(); 
            }
        // If the user doesn't enter any of the given options they will be prompted to try again
        default:
            {
                cout<<"Please select from the given options"; 
            }
    }
    goto mainstartingpage; 

}


void shopping :: administrator()
{
    mainstartingpage;
    int useradminchoice;  
    cout<<"\t\t\t\t_______________________\n";
    cout<<"\t\t\t\t   Adminsistrator Menu \n";
    cout<<"\t\t\t\t_______________________\n";
    cout<<"\t\t\t\t                       \n";
    cout<<"\t\t\t\t 1) Add Product        \n";
    cout<<"\t\t\t\t 2) Modify Product     \n";
    cout<<"\t\t\t\t 3) Remove Product     \n";
    cout<<"\t\t\t\t 4) Back to Main Menu  \n";
    
    cout<<"\t\t\t\t Enter your choice: \n";
    cin>>useradminchoice;

    switch(useradminchoice)
    {
        case 1:
            add();
            break; 

        case 2:
            edit(); 
            break; 
        
        case 3:
            remove();
            break; 
        
        defualt:
            cout>>"Please select from the given options";

    }
    goto mainstartingpage; 
}

void shopping :: buyer()
{
    mainstartingpage;
    int userbuyerchoice; 
    cout<<"\t\t\t\t_______________________\n";
    cout<<"\t\t\t\t   Buyer Menu          \n";
    cout<<"\t\t\t\t_______________________\n";
    cout<<"\t\t\t\t                       \n";
    cout<<"\t\t\t\t 1) Buy Product        \n";
    cout<<"\t\t\t\t 2) Back to Main Menu  \n";
    
    cout<<"\t\t\t\t Enter your choice: \n";
    cin>>userbuyerchoice;

    switch(userbuyerchoice)
    {
        case 1: 
            receipt();
            break; 

        case 2:
            menu();

        defualt:
            cout>>"Please select from the given options";

    }
    goto mainstartingpage; 


}

void shopping :: add()
{
    fstream data;
    int c; 
    int token=0;
    float p; 
    float d; 
    string n; 

    cout<<"\t\t\t\t Add New Product \n";
    cout<<"\t\t\t\t Product Code of the Product \n";
    cin>>productcode; 
    cout<<"\t\t\t\t Name of the Product  \n";
    cin>>productname; 
    cout<<"\t\t\t\t Price of Product \n";
    cin>>price; 
    cout<<"\t\t\t\t Discount on Product \n";
    cin>>discount;

    data.open("database.txt",ios::in);

    if(!data)
    {
        data.open("database.txt", ios::app|ios::out);
        data<<" "<<productcode<<" "<<productname<<" "<<price<<" "<<discount<<"\n";
        data.close();
    }
    else
    {
        data>>c>>n>>p>>d;

        while(!data.eof())
        {
            if(c ==pcode)
            {
                token++;

            }
            data>>c>>n>>p>>d;

        }
        data.close();
    }

    if(token==1)
        goto mainstartingpage;
    else
    {
        data.open("database.txt", ios::app|ios::out);
        data<<" "<<productcode<<" "<<productname<<" "<<price<<" "<<discount<<"\n";
        data.close();
    }
    
    cout<<"\t\t\t\t Record Enlisted! \n";
}

void shopping :: edit()
{
    fstream data,data1;
    int pkey;
    int token=0
    int c;
    float p; 
    float d; 
    string n; 

    cout<<"\t\t\t\t Modify the Record \n";
    cout<<"\t\t\t\t Product Code :\n";
    cin>>productkey; 

    data.open("database.txt", ios::in);
    if(!data)
    {
        cout<<"\t\t\t\t File doesn't exist! \n";
    }
    else
    {
        data1.open("database1.txt", ios::app|ios::out)
        data>>productcode>>productname>>price>>discount; 
        while(!data.eof())
        {
            if(productkey=productcode)
            {
                cout<<"\t\t\t\t Product New Code : \n";
                cin>>c; 
                cout<<"\t\t\t\t Name of the Product : \n";
                cin>>n; 
                cout<<"\t\t\t\t Price : \n";
                cin>>p; 
                cout<<"\t\t\t\t Discount : \n";
                cin>>d; 
                data1<<" "<<c<<" "<<n<<" "<<p<<" "<<d<<"\n";
                cout<<"\t\t\t\t Record Edited: \n";
                token++; 
            }
            else
            {
               data1<<" "<<productcode<<" "<<productname<<" "<<price<<" "<<discount<<"\n";
            }
            data>>productcode>>productname>>price>>discount; 
        }
        data.close();
        data1.close();

        remove("database.txt");
        rename("database1.txt", "database.txt"); 

        if(token==0)
        {
            cout<<"\t\t\t\t Record not found sorry! \n";
        }

    }



}

void shopping::remove()
{
    fstream data,data1; 
    int productkey; 
    int token==0
    cout<<"\t\t\t\t Delete Product \n";
    cout<<"\t\t\t\t Product Code:  \n";
    cin>>productkey; 
    data.open("database.txt", ios::in);
    if(!data)
    {
        cout<<"File doesn't exist";

    }
    else
    {
        data1.open("database1.txt", ios::app|ios::out);
        data>>productcode>>productname>>price>>discount; 
        while(!data.eof())
        {
            if(productcode==productkey)
            {
                cout<<"\t\t\t\t Product deleted succefully \n";
                token++;
            }
            else
            {
                data1<<" "<<productcode<<" "<<productname<<" "<<price<<" "<<" "<<discount<<"\n";

            }
            data>>productcode>>productname>>price>>discount;

        }
        data.close();
        data1.close();
        remove("database.txt"); 
        rename("database1.txt", "database.txt");

        if(tokens==0)
        {
            cout<<"\t\t\t\t Record can't be found \n";
        }
    }

}

void shopping:: list()
{
    fstream data; 
    data.open("database.txt", ios::in)
    cout<<"\t\t\t\t________________________________________\n";
    cout<<"ProductNumber\t\tProductName\t\tPrice"\n;
    cout<<"\t\t\t\t________________________________________\n";
    data>>productcode>>productname>>price>>discount; 
    while(!data.eof())
    {
        cout<<productcode<"\t\t"<<productname<<"\t\t"<<price<<"\n";
        data>>productcode>>productname>>price>>discount; 
    }
    data.close(); 


}

void shopping receipt()
{
    fstream data; 
    
    int arrc[100]
    int arrq[100]
    char choice; 
    int c=0; 
    float amount=0; 
    float discount=0; 
    float total=0

    cout<<"\t\t\t\t RECIEPT \n";
    data.open("database.txt",ios::in)

}


