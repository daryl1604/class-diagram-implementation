//Daryl Vince De Castro
#include <iostream>
#include <algorithm>
#include <string>
#include <iomanip>

using namespace std;

class Customer {
private:
    string name,email,address;

public:
    Customer(){
    	name="";
		email="";
		address="";
	}
    Customer(string n,string e,string a){
    	name=n;
		email=e;
		address=a;
	}
    void setName(string n){
		name=n;
	}
    void setEmail(string e){
		email=e;
	}
    void setAddress(string a){
		address=a;
	}

    string getName()const{
		return name;
	}
    string getEmail()const{
		return email;
	}
    string getAddress()const{
		return address;
	}
};

class Product {
private:
    int productId;
    double price;
    string productName;

public:
		Product(){
			productId = 0;
			price = 0;
			productName = "";
		}
		Product(int id, double pr, string pn){
			productId = id;
			price = pr;
			productName = pn;		
		}
		
		void setProductId(int id){
			productId = id;
		}
		void setPrice(double pr){
			price = pr;
		}
		void setProductName(string pn){
			productName = pn;
		}
		
		int getProductID()const{
			return productId;
		}
		double getPrice()const{
			return price;
		}
		string getProductName()const{
			return productName;
		}
};

const int productCount=15;
const int maxOrders=100;

Product products[productCount]={
    Product(111,2200.00,"Barbell"),
    Product(222,1190.00,"Dumbbell"),
    Product(333,500.00,"Plates"),
    Product(444,5000.00,"Rack"),
    Product(555,200.40,"Gloves"),
    Product(666,4000.20,"Gear"),
    Product(777,5000.75,"Shoes"),
    Product(888,990.20,"Ball"),
    Product(999,500.00,"Mouse"),
    Product(1111,90.90,"Key"),
    Product(2222,490.20,"Charger"),
    Product(3333,7890.00,"Phone"),
    Product(4444,9990.50,"Laptop"),
    Product(5555,9999.99,"PC"),
    Product(6666,90.00,"CD")
};

class ShoppingCart {
private:
    Product cart[100];
    int quantities[100];
    int itemCount;

public:
    ShoppingCart(){
    	itemCount=0;
	}

    void addProduct(int id,int quantity){
        for(int i=0;i<itemCount;++i){
            if(cart[i].getProductID()==id){
                quantities[i]+=quantity;
                return;
            }
        }
        if(itemCount<100){
            for(int i=0;i<productCount;++i){
                if(products[i].getProductID()==id){
                    cart[itemCount]=products[i];
                    quantities[itemCount]=quantity;
                    itemCount++;
                    return;
                }
            }
        }
    }

    void viewCart()const{
        cout<<setw(10)<<"Product ID"<<setw(20)<<"Name"<<setw(10)<<"Price"<<setw(10)<<"Quantity"<<endl;
        double totalAmount=0;
        for(int i=0;i<itemCount;++i){
            cout<<setw(10)<<cart[i].getProductID()
                <<setw(20)<<cart[i].getProductName()
                <<setw(10)<<fixed<<setprecision(2)<<cart[i].getPrice()
                <<setw(10)<<quantities[i]<<endl;
            totalAmount+=cart[i].getPrice()*quantities[i];
        }
        cout<<"\nTotal Amount: "<<fixed<<setprecision(2)<<totalAmount<<endl;
    }

    double getTotalAmount()const{
        double totalAmount=0;
        for(int i=0;i<itemCount;++i){
            totalAmount+=cart[i].getPrice()*quantities[i];
        }
        return totalAmount;
    }

    void clearCart(){itemCount=0;}
};

class Order {
private:
    int orderID;
    ShoppingCart cart;
    Customer customer;

public:
    Order(int id){
    	orderID=id;	
	}
    
    void setOrderDetails(const ShoppingCart& shoppingCart,const Customer& cust){
        cart=shoppingCart;
        customer=cust;
    }

    void viewOrder()const{
        cout<<"\nOrder ID: "<<orderID<<endl;
        cart.viewCart();
    }
};

int nextOrderID=1;
Order* orders[maxOrders];
int orderCount=0;

void account();
void menu();

int main(){
    cout<<"E-Commerce Store System"<<endl;
    account();
    menu();
    return 0;
}

void menu(){
    ShoppingCart cart;
    Customer customer;
    char choice;

    while(true){
        cout<<"\nM E N U"<<endl;
        cout<<"[1] View Products"<<endl;
        cout<<"[2] View Shopping Cart"<<endl;
        cout<<"[3] View Orders"<<endl;
        cout<<"[4] Exit"<<endl;
        cout<<"Enter your choice: ";
        cin>>choice;
        cin.ignore();
        system("cls");

        switch(choice){
            case '1':{
                cout<<"\n---View Products---"<<endl;
                cout<<setw(10)<<"Product ID"<<setw(20)<<"Name"<<setw(10)<<"Price"<<endl;
                for(int i=0;i<productCount;++i){
                    cout<<setw(10)<<products[i].getProductID()
                        <<setw(20)<<products[i].getProductName()
                        <<setw(10)<<fixed<<setprecision(2)<<products[i].getPrice()<<endl;
                }

                int id,quantity;
                char addMore;

                do{
                    cout<<"\nEnter the ID of the product you want to add to the shopping cart: ";
                    cin>>id;

                    bool productFound=false;
                    for(int i=0;i<productCount;++i){
                        if(products[i].getProductID()==id){
                            productFound=true;
                            break;
                        }
                    }

                    if(!productFound){
                        cout<<"Invalid product ID. Please try again."<<endl;
                        continue;
                    }

                    cout<<"Enter the quantity: ";
                    cin>>quantity;

                    cart.addProduct(id,quantity);
                    cout<<"Product added successfully!"<<endl;

                    cout<<"\nDo you want to add another product? (Y/N): ";
                    cin>>addMore;

                }while(addMore=='Y'||addMore=='y');
                
                system("cls");
                break;
            }

            case '2':
                cart.viewCart();
                cout<<"\nDo you want to check out all the products? (Y/N): ";
                char checkoutChoice;
                cin>>checkoutChoice;

                if(checkoutChoice=='Y'||checkoutChoice=='y'){
                    if(orderCount<maxOrders){
                        orders[orderCount]=new Order(nextOrderID++);
                        orders[orderCount]->setOrderDetails(cart,customer);
                        orderCount++;
                        cart.clearCart();
                        cout<<"You have successfully checked out the products!"<<endl;
                    }else{
                        cout<<"Order limit reached. Cannot place more orders."<<endl;
                    }
                    system("cls");
                }else{
                    cout<<"Checkout canceled."<<endl;
                    system("cls");
                }
                break;

            case '3':
                if(orderCount==0){
                    cout<<"\nNo orders have been placed yet."<<endl;
                }else{
                    cout<<"\n---View Orders---"<<endl;
                    for(int i=0;i<orderCount;++i){
                        orders[i]->viewOrder();
                    }
                    cout<<"\n\nPress any key to proceed to the Menu: ";
                    cin.ignore();
                    cin.get();
                    system("cls");
                }
                break;

            case '4':
                cout<<"\nExiting..."<<endl;
                for(int i=0;i<orderCount;++i){
                    delete orders[i];
                }
                return;

            default:
                cout<<"\nInvalid Input...Returning to Menu..."<<endl;
                break;
        }
    }
}

void account(){
    Customer customer;
    string name,email,address;

    cout<<"\nAccount Sign Up: "<<endl<<endl;
    cout<<"Enter your name: ";
    getline(cin,name);
    transform(name.begin(),name.end(),name.begin(),::tolower);

    cout<<"Enter your email: ";
    getline(cin,email);
    transform(email.begin(),email.end(),email.begin(),::tolower);

    cout<<"Enter your address: ";
    getline(cin,address);
    transform(address.begin(),address.end(),address.begin(),::tolower);

    customer.setName(name);
    customer.setEmail(email);
    customer.setAddress(address);

    cout<<"\nAccount Successfully Added!!"<<endl;
    cout<<"\nAccount Details: "<<endl;
    cout<<"\nName: "<<customer.getName();
    cout<<"\nEmail: "<<customer.getEmail();
    cout<<"\nAddress: "<<customer.getAddress();

    cout<<"\n\nPress any key to proceed to the Menu: ";
    cin.ignore();
    cin.get();
    system("cls");
    cout<<"Welcome Mr/Mrs. "<<customer.getName()<<","<<endl;
}
