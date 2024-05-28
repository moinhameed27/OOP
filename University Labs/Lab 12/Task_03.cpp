#include <iostream>
#include <string>

using namespace std;

template <typename T>
T numberValidation(T &);

const int MAX_ITEMS = 23;

// Custom Exception Classes
class InventoryFullException : public runtime_error
{
public:
    InventoryFullException() : runtime_error("Inventory is full") {}
};

class ItemNotFoundException : public runtime_error
{
public:
    ItemNotFoundException(const string itemName) : runtime_error("Item '" + itemName + "' not found") {}
};

class InvalidItemOperationException : public runtime_error
{
public:
    InvalidItemOperationException(const string message) : runtime_error(message) {}
};

class Item
{
private:
    string itemName;
    int quantity;
    double price;

public:
    // Constructors
    Item() : itemName(""), quantity(0), price(0.0) {}
    Item(const string name, const int qty, const double prc) : itemName(name), quantity(qty), price(prc) {}

    // Mutators
    void setName(const string name) { itemName = name; }
    void setQuantity(const int qty) { quantity = qty; }
    void setPrice(const double prc) { price = prc; }

    // Accessors
    string getName() const { return itemName; }
    int getQuantity() const { return quantity; }
    double getPrice() const { return price; }

    void updateQuantity(int newQuantity)
    {
        if (newQuantity < 0)
            throw InvalidItemOperationException("Quantity cannot be negative");

        quantity = newQuantity;
    }

    void updatePrice(double newPrice)
    {
        if (newPrice < 0)
            throw InvalidItemOperationException("Price cannot be negative");

        price = newPrice;
    }
};

class Inventory
{
private:
    Item items[MAX_ITEMS];
    int itemCount;

    int findItemIndex(const string &itemName) const
    {
        for (int i = 0; i < itemCount; ++i)
        {
            if (items[i].getName() == itemName)
                return i;
        }
        return -1;
    }

public:
    Inventory() : itemCount(0) {}

    void addItem(const Item newItem)
    {
        if (itemCount == MAX_ITEMS)
            throw InventoryFullException();

        if (newItem.getQuantity() < 0)
            throw InvalidItemOperationException("Quantity cannot be negative");
        
        if (newItem.getPrice() < 0)
            throw InvalidItemOperationException("Price cannot be negative");

        for (int i = 0; i < itemCount; ++i)
        {
            if (items[i].getName() == newItem.getName())
                throw InvalidItemOperationException("Item with the same name already exists");
        }

        items[itemCount++] = newItem;
    }

    void removeItem(const string itemName)
    {
        int idx = findItemIndex(itemName);
        if (idx == -1)
        {
            throw ItemNotFoundException(itemName);
        }

        // Shift all the items after idx to cover the deleted item
        for (int i = idx; i < itemCount - 1; ++i)
            items[i] = items[i + 1];

        itemCount--;
    }

    void updateItemQuantity(const string itemName, int newQuantity)
    {
        int idx = findItemIndex(itemName);
        if (idx == -1)
            throw ItemNotFoundException(itemName);

        items[idx].updateQuantity(newQuantity);
    }

    void updateItemPrice(const string itemName, double newPrice)
    {
        int idx = findItemIndex(itemName);
        if (idx == -1)
            throw ItemNotFoundException(itemName);

        items[idx].updatePrice(newPrice);
    }

    Item getItem(const string itemName) const
    {
        int idx = findItemIndex(itemName);
        if (idx == -1)
            throw ItemNotFoundException(itemName);

        return items[idx];
    }

    void printInventory() const
    {
        if (itemCount == 0)
        {
            cout << "Inventory is empty." << endl;
            return;
        }
        cout << "Inventory Items:" << endl;
        for (int i = 0; i < itemCount; ++i)
        {
            cout << "  - " << items[i].getName() << " (Quantity: " << items[i].getQuantity()
                 << ", Price: " << items[i].getPrice() << " Rs )" << endl;
        }
    }
};

void displayMenu()
{
    cout << "\n----------Inventory Management System----------" << endl;
    cout << "1. Add Item" << endl;
    cout << "2. Remove Item" << endl;
    cout << "3. Update Item Quantity" << endl;
    cout << "4. Update Item Price" << endl;
    cout << "5. Search Item" << endl;
    cout << "6. Print Inventory" << endl;
    cout << "7. Exit" << endl;
}

int main()
{
    Inventory inventory;

    int choice;
    string itemName;
    int quantity;
    double price;

    while (choice != 7)
    {
        displayMenu();
        cout << "Enter your choice: ";
        numberValidation(choice);
        cout << endl;

        switch (choice)
        {
        // Add Item
        case 1:
        {
            cin.ignore();
            cout << "Enter item name: ";
            getline(cin, itemName);
            cout << "Enter quantity: ";
            numberValidation(quantity);
            cout << "Enter price: ";
            numberValidation(price);
            try
            {
                inventory.addItem(Item(itemName, quantity, price));
                cout << "\nItem added successfully." << endl;
            }
            catch (const exception &e)
            {
                cout << "\nError: " << e.what() << endl;
            }
        }
        break;

        // Remove Item
        case 2:
        {
            cin.ignore();
            cout << "Enter item name to remove: ";
            getline(cin, itemName);
            try
            {
                inventory.removeItem(itemName);
                cout << "\nItem removed successfully." << endl;
            }
            catch (const exception &e)
            {
                cout << "\nError: " << e.what() << endl;
            }
        }
        break;

        // Update Item Quantity
        case 3:
        {
            cin.ignore();
            cout << "Enter item name to update quantity: ";
            getline(cin, itemName);
            cout << "Enter new quantity: ";
            numberValidation(quantity);
            try
            {
                inventory.updateItemQuantity(itemName, quantity);
                cout << "\nItem quantity updated successfully." << endl;
            }
            catch (const exception &e)
            {
                cout << "\nError: " << e.what() << endl;
            }
        }
        break;

        // Update Item Price
        case 4:
        {
            cin.ignore();
            cout << "Enter item name to update price: ";
            getline(cin, itemName);
            cout << "Enter new price: ";
            numberValidation(price);
            try
            {
                inventory.updateItemPrice(itemName, price);
                cout << "\nItem price updated successfully." << endl;
            }
            catch (const exception &e)
            {
                cout << "\nError: " << e.what() << endl;
            }
        }
        break;

        // Search Item
        case 5:
        {
            cin.ignore();
            cout << "Enter item name to search: ";
            getline(cin, itemName);
            try
            {
                Item item = inventory.getItem(itemName);
                cout << "Item found:" << endl;
                cout << "  - Name: " << item.getName() << endl;
                cout << "  - Quantity: " << item.getQuantity() << endl;
                cout << "  - Price: " << item.getPrice() << " Rs" << endl;
            }
            catch (const exception &e)
            {
                cout << "\nError: " << e.what() << endl;
            }
        }
        break;

        // Print Inventory
        case 6:
        {

            inventory.printInventory();
        }
        break;

        // Exit
        case 7:
        {

            cout << "Exiting Inventory Management System." << endl;
        }
        break;

        default:
            cout << "Invalid choice. Enter Again." << endl;
        }
    }

    return 0;
}

// Number Validation
template <typename T>
T numberValidation(T &number)
{
    bool validInput = false;
    while (!validInput)
    {
        if (cin >> number)
            validInput = true;

        else
        {
            cin.clear();
            while (cin.get() != '\n')
                ;
            cout << "Invalid input. Please enter a valid number: ";
        }
    }
    return number;
}
