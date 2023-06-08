#include<iostream>
#include<string>
#include<vector>
using namespace std;
class Product {
private:
    string product_name;
    double product_price;
    int product_id;
public:
    Product(string name, double price, int id) : product_name(name), product_price(price), product_id(id) {}

    Product(string pName) : product_name(pName)

    {
        cout<< pName;
    }

    double ProductPrice()
    {
        return product_price;
    }

    int ProductId()
    {
    return product_id;
    }
};

class Customer {
private:
    string customer_name;
    string customer_email;
    int customer_id;
public:
    Customer(string name, string email, int id) : customer_name(name), customer_email(email), customer_id(id) {}

    string CustomerName()
    {
        return customer_name;
    }
    string CustomerEmail()
    {
        return customer_email;
    }
    int CustomerId()
    {
        return customer_id;
    }
};

class Order {
private:
    Customer order_customer;
    vector<Product> order_products;
    int order_id;
public:
    Order(Customer customer, vector<Product> products, int id) : order_customer(customer), order_products(products), order_id(id) {}

    void AddProduct(Product product)
    {
        order_products.push_back(product);
    }

    double TotalCost() {
        double totalCost = 0.0;
        for (auto& product : order_products) {
            totalCost = totalCost + product.ProductPrice();
        }
        return totalCost;
    }


};
int main(){
    vector<Product> products;
    Customer customer("Anna Nowak", "anna@o2.pl", 1);
    Product apple("Apple", 2.59, 1);
    Product banana("banana", 5.30, 2);

    Order order(customer, products, 1);
    order.AddProduct(apple);
    order.AddProduct(banana);

    double totalcost = order.TotalCost();
    cout<<"total cost: "<<totalcost<<endl;
    return 0;
}


