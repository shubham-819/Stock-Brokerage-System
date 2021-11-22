#include<iostream>
#include<fstream>
#include<limits>
#include<vector>
using namespace std;
class stock
{
    public: 
    float price, priceopen, high, low;
    string ticker;
    string volume;

    void printstock()
    {
        cout<<"\n\nSymbol:\t"<<ticker<<"\nPrice:\t"<<price<<"\nPrice Open:\t"<<priceopen<<"\nHigh:\t"<<high<<"\nLow:\t"<<low<<"\nVolume:\t"<<volume<<endl<<endl;
        return;
    }
};

class broker
{
    public: 
    string b_name = "Zerodha", b_ID="INZ000031633", b_email="support@zerodha.com";
};

class customer : public broker
{
    public:

    string name, phone,emailid, username;
    int balance;
    vector<string> v;
    customer()
    {
        name="Shubham"; phone="9999999999";emailid="shubham@zerodha.com"; username="shubham_819";
        balance=100000;
    }

};

std::fstream& GotoLine(std::fstream& file, unsigned int num){
    file.seekg(std::ios::beg);
    for(int i=0; i < num - 1; ++i){
        file.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    }
    return file;
}
stock input(fstream &f)
{
    stock s;
    char c;
    string temp="\0";
    while(true)
    {
    while(true)
    {
        f.get(c);
        if(c=='{'||c=='}'||c==','||c==':'||c==' '||c=='\'')
        {
            if(temp.length()==0)
            continue;
            else
            break;
        }
        else
        {
            temp=temp+c;
        }
    }
    if(temp=="symbol"||temp=="price"||temp=="priceopen"||temp=="high"||temp=="low"||temp=="volume")
    {
    temp="\0";
    continue;
    }
    else
    {
        s.ticker=temp;
        temp="\0";
        break;
    }
    }

    while(true)
    {
    while(true)
    {
        f.get(c);
        if(c=='{'||c=='}'||c==','||c==':'||c==' '||c=='\'')
        {
            if(temp.length()==0)
            continue;
            else
            break;
        }
        else
        {
            temp=temp+c;
        }
    }
    if(temp=="symbol"||temp=="price"||temp=="priceopen"||temp=="high"||temp=="low"||temp=="volume")
    {
    temp="\0";
    continue;
    }
    else
    {
        s.price = std::stof(temp);
        temp="\0";
        break;
    }
    }

    while(true)
    {
    while(true)
    {
        f.get(c);
        if(c=='{'||c=='}'||c==','||c==':'||c==' '||c=='\'')
        {
            if(temp.length()==0)
            continue;
            else
            break;
        }
        else
        {
            temp=temp+c;
        }
    }
    if(temp=="symbol"||temp=="price"||temp=="priceopen"||temp=="high"||temp=="low"||temp=="volume")
    {
    temp="\0";
    continue;
    }
    else
    {
        s.priceopen = std::stof(temp);
        temp="\0";
        break;
    }
    }

    while(true)
    {
    while(true)
    {
        f.get(c);
        if(c=='{'||c=='}'||c==','||c==':'||c==' '||c=='\'')
        {
            if(temp.length()==0)
            continue;
            else
            break;
        }
        else
        {
            temp=temp+c;
        }
    }
    if(temp=="symbol"||temp=="price"||temp=="priceopen"||temp=="high"||temp=="low"||temp=="volume")
    {
    temp="\0";
    continue;
    }
    else
    {
        s.high = std::stof(temp);
        temp="\0";
        break;
    }
    }

    while(true)
    {
    while(true)
    {
        f.get(c);
        if(c=='{'||c=='}'||c==','||c==':'||c==' '||c=='\'')
        {
            if(temp.length()==0)
            continue;
            else
            break;
        }
        else
        {
            temp=temp+c;
        }
    }
    if(temp=="symbol"||temp=="price"||temp=="priceopen"||temp=="high"||temp=="low"||temp=="volume")
    {
    temp="\0";
    continue;
    }
    else
    {
        s.low = std::stof(temp);
        temp="\0";
        break;
    }
    }

    while(true)
    {
    while(true)
    {
        f.get(c);
        if(c=='{'||c=='}'||c==','||c==':'||c==' '||c=='\'')
        {
            if(temp.length()==0)
            continue;
            else
            break;
        }
        else
        {
            temp=temp+c;
        }
    }
    if(temp=="symbol"||temp=="price"||temp=="priceopen"||temp=="high"||temp=="low"||temp=="volume")
    {
    temp="\0";
    continue;
    }
    else
    {
        s.volume=temp;
        temp="\0";
        break;
    }
    }
    return s;
}

stock search(string key, fstream &f)
{
    string line;
    unsigned int curLine = 0;
    while(getline(f, line)) { 
        curLine++;
        if (line.find(key, 0) != string::npos)
        break;
    }
    GotoLine(f,curLine);
    stock s=input(f);
    return s;
}

int main()
{
    fstream f;
    customer s1;
    f.open("data.txt",ios::in);

    //stock s=search("CIPLA",f);
    //cout<<s.ticker;
    //system("cls");
    cout<<"\t\t\t\t******Welcome to Stock Brokerage System******"<<endl;
    while(true)
    {
    cout<<"\n\nEnter your choice\n";
    cout<<"1.Check price of a stock\n2.Buy a stock\n3.Portfolio overview\n4.Account Information\n5.Add balance\n6.Exit\n\n";
    int ch;
    cin>>ch;
    if(ch==1)
    {
        string key;
        cout<<"Enter the stock ticker: ";
        cin>>key;
        f.seekg(0);
        stock s1=search(key,f);
        s1.printstock();
    }

    else if(ch==6)
    {
        cout<<"\n\n\t\t\t******Thank You******";
        exit(0);
    }

    else if(ch==2)
    {
        cout<<"\nEnter the stock ticker you want to buy: ";
        string temp;
        cin>>temp;
        s1.v.push_back(temp);
        f.seekg(0);
        stock s = search(temp, f);
        s1.balance=s1.balance-s.price;
        cout<<"\nStock Purchased!!"<<endl;
    }

    else if(ch==3)
    {
        cout<<"\n\n\t\tPORTFOLIO OVERVIEW"<<endl;
        cout<<"Balance: \t"<<s1.balance<<endl;
        if(s1.v.empty())
        {
            cout<<"No stocks purchased yet!!"<<endl;
        }
        else
        {
            int len=s1.v.size();
            
            for(int i=0; i<len;i++)
            {
                f.seekg(0);
                stock sp=search(s1.v[i],f);
                sp.printstock();
            }
        }
    }

    else if(ch==4)
    {
        cout<<"\n\t\tACCOUNT INFORMATION"<<endl;
        cout<<"Name: "<<s1.name<<"\nPhone: "<<s1.phone<<"\nEmail: "<<s1.emailid<<"\nUsername: "<<s1.username<<"\nBalance: "<<s1.balance<<"\nBroker Name: "<<s1.b_name<<"\nBroker ID: "<<s1.b_ID<<"\nBroker Email: "<<s1.b_email<<endl;
    }

    else if(ch==5)
    {
        cout<<"\nAdd amount of money to add: ";
        int n;
        cin>>n;
        s1.balance=s1.balance+n;
    }

    else
    {
        cout<<"\nWrong Choice"<<endl;
        continue;
    }



    }
    f.close();
    return 0;
}