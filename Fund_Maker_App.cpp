
#include <iostream>
#include<vector>

using namespace std;

// DataSet of existing Customers
struct customer_info_dt{
    string ci_fund_name;
    string ci_name;
    int ci_age;
    string ci_phone_number;
};
vector<customer_info_dt> customer_info;

void initializeData(){
    customer_info.push_back({"Retirement", "Sachin", 46, "1251237789"});
    customer_info.push_back({"General", "Virat", 33, "3451897789"});
    customer_info.push_back({"Student", "Surya", 26, "5651265789"});
    customer_info.push_back({"General", "Rohit", 35, "7851237789"});
}

// Every class that inherits from this class will have to provide implementation of CheckIfAccountRxists func.
class AbstractFund{
    public:
        virtual bool CheckIfAccountExists() = 0;
};

class Fund: public AbstractFund{
    private:
        string FundName, CustomerName, PhoneNumber;
        int Age;
    public:
        // constructor
        Fund(string fund_name, string customer_name, int age, string phone_number){
            FundName = fund_name;
            CustomerName = customer_name;
            Age = age;
            PhoneNumber = phone_number;
        }
        
        // Abstraction
        bool CheckIfAccountExists(){
            for(int i = 0; i < customer_info.size(); i++){
                if(PhoneNumber == customer_info[i].ci_phone_number){
                    cout << "An Account already Exists" << endl;
                    return true;
                }
            }
            return false;
        }
        
        // getters and setters
        string getFundName(){
            return FundName;
        }
        
        void setFundName(string fund_name){
            FundName = fund_name;
        }
        
        int getAge(){
            return Age;
        }
        
        void setAge(int age){
            Age = age;
        }
        
        string getCustomerName(){
            return CustomerName;
        }
        
        void setCustomerName(string customer_name){
            CustomerName = customer_name;
        }
        
        string getPhoneNumber(){
            return PhoneNumber;
        }
        
        void setPhoneNumber(string phone_number){
            PhoneNumber = phone_number;
        }
    
};

int main()
{
    initializeData();
    string f_name, c_name, phn_num;
    int age;
    cout<<"Hello To The Fund Maker App: "<< endl;
    cout << "Enter the following info:" << endl;
    cin << "Fund Name (Retirement, General, Student): " <<  f_name << endl;
    cin << "Your First Name : " <<  c_name << endl;
    cin << "Phone Number: " <<  phn_num << endl;
    cin << "Age: " <<  c_age << endl;
    
    Fund fund_info = Fund(f_name, c_name, c_age, phn_num);
    // Fund fund_info = Fund("General", "Hardik", 29, "9015462378");
    // Fund fund_info = Fund("General", "Hardik", 29, "3451897789");
    bool chk_val = fund_info.CheckIfAccountExists();
    if(!chk_val){
        customer_info.push_back({fund_info.getFundName(), fund_info.getCustomerName(), fund_info.getAge(), fund_info.getPhoneNumber()});
    }
    
    for (auto x : customer_info)
        cout << x.ci_age << endl;
    return 0;
}

