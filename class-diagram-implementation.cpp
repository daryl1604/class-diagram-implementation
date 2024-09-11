#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

class Customer{
	private: 
	string  name, email, address;
	int phoneNum;
	
	public:
		Customer(){
			name="";
			email="";
			address="";
			phoneNum=0;
		}
		Customer(string n, string e, string a, int p){
			string  name = n;
			email = e;
			address = a;
			phoneNum = p;
		}
		//setters
		void setName(string n){
			name = n;
		}
		void setEmail(string e){
			address = e;
		}
		void setAddress(string a){
			address = a;
		}
		void setPhoneNumber(int p){
			phoneNum = p;
		//getters
		string getName(){
			return name;
		}
		string getEmail(){
			return email;
		}
		string getAddress(){
			return address;
		}
		int getPhoneNum(){
			return phoneNum;
		}
};

class ShoppingCart{
	
};

class Product{
	private:
		int productId;
		double price;
		string productName;
		
	public:
		Product(){
			productID = 0;
			price = 0;
			productName = "";
		}
		Product(int i, double pr, string pn){
			productID = i;
			price = pr;
			productName = pn;		
		}
		//setters
		void setProductId(int i){
			productID = i;
		}
		void setPrice(double pr){
			price = pr;
		}
		void setProductName(string pn){
			productName = pm;
		}
		//getters
		int getProductID(){
			return productID;
		}
		double getPrice(){
			return price;
		}
		string getProductName(){
			return productName;
		}
};

class Order{
	private:
		int orderID;
	
	public:
		Order(){
			orderID = 0;
		}	
		Order(int o){
			orderID = o;
		}
		//setters
		void setOrderID(int o){
			orderID = o;
		}
		//getters
		int getOrderID(){
			return orderID;
		}
};

void menu();
void viewProducts();
void viewShoppingCart();
void viewOrders();

int main(){
	cout<<"\nE Commerce Store System"<<endl;
	menu();
}

void menu(){
	char choice;
	cout<<"[1]View Products"<<endl;
	cout<<"[2]View Shopping Cart"<<endl;
	cout<<"[3]View Orders"<<endl;
	cout<<"[4]Exit"<<endl;
	cout<<"Enter your choice: ";
	cin>>choice;
	transform(choice.begin(),choice.end(),choice.begin()::tolower)
	system("cls");
	
	switch(choice){
		case '1':
			viewProducts();
			break;
		
		case '2':
			viewShoppingCart();
			break;
			
		case '3':
			viewOrders();
			break;
		
		case'4':
			cout<<"\nExiting..."<<endl;
			break;
			exit(0);
		
		default:
			cout<<"\nInvalid Input...Returning to Menu..."<<endl;
			menu();
			system("cls");		
	}	
}

void viewProducts(){
	cout<<"\n---View Products---"<<endl;
	Products prod;
	string productItems;
}