#include <stdio.h>
#include <string.h>
#define MAX_PRODUCTS 100
// Structure to store product details
typedef struct {
 int id;
 char name[50];
 char description[100];
 float price;
 int quantity;
} Product;
Product products[MAX_PRODUCTS];
int product_count = 0;
// Function to add a new product
void add_product() {
 if (product_count >= MAX_PRODUCTS) {
 printf("Product list is full!\n");
 return;
 }
 printf("Enter Product ID: ");
 scanf("%d", &products[product_count].id);
 getchar(); // Consume newline
 printf("Enter Product Name: ");
 fgets(products[product_count].name, 50, stdin);
 products[product_count].name[strcspn(products[product_count].name, "\n")] = '\0';
 printf("Enter Description: ");
 fgets(products[product_count].description, 100, stdin);
 products[product_count].description[strcspn(products[product_count].description, "\n")] = '\0';
 printf("Enter Price: ");
 scanf("%f", &products[product_count].price);
 printf("Enter Quantity: ");
 scanf("%d", &products[product_count].quantity);
 product_count++;
 printf("Product added successfully!\n");
}
// Function to display all products
void display_products() {
 if (product_count == 0) {
 printf("No products available!\n");
 return;
 }
 printf("\nProduct List:\n");
 printf("-----------------------------------------------------\n");
 for (int i = 0; i < product_count; i++) {
 printf("ID: %d | Name: %s | Price: %.2f | Quantity: %d\n",
 products[i].id, products[i].name, products[i].price, products[i].quantity);
 }
 printf("-----------------------------------------------------\n");
}
// Function to search for a product by ID or name
void search_product() {
 char query[50];
 printf("Enter Product ID or Name to search: ");
 getchar();
 fgets(query, 50, stdin);
 query[strcspn(query, "\n")] = '\0';
 int found = 0;
 for (int i = 0; i < product_count; i++) {
 if (products[i].id == atoi(query) || strcasecmp(products[i].name, query) == 0) {
 printf("Product Found: ID: %d | Name: %s | Price: %.2f | Quantity: %d\n",
 products[i].id, products[i].name, products[i].price, products[i].quantity);
 found = 1;
 break;
 }
 }
 if (!found) {
 printf("Product not found!\n");
 }
}
// Function to delete a product by ID
void delete_product() {
 int id;
 printf("Enter Product ID to delete: ");
 scanf("%d", &id);
 int found = 0;
 for (int i = 0; i < product_count; i++) {
 if (products[i].id == id) {
 for (int j = i; j < product_count - 1; j++) {
 products[j] = products[j + 1];
 }
 product_count--;
 printf("Product deleted successfully!\n");
 found = 1;
 break;
 }
 }
 if (!found) {
 printf("Product not found!\n");
 }
}
// Function to update a product
void update_product() {
 int id;
 printf("Enter Product ID to update: ");
 scanf("%d", &id);
 for (int i = 0; i < product_count; i++) {
 if (products[i].id == id) {
 printf("Enter new name: ");
 getchar();
 fgets(products[i].name, 50, stdin);
 products[i].name[strcspn(products[i].name, "\n")] = '\0';
 printf("Enter new price: ");
 scanf("%f", &products[i].price);
 printf("Enter new quantity: ");
 scanf("%d", &products[i].quantity);
 printf("Product updated successfully!\n");
 return;
 }
 }
 printf("Product not found!\n");
}
// Main Menu
int main() {
 int choice;
 do {
 printf("\nProduct Management System\n");
 printf("1. Add Product\n");
 printf("2. Display Products\n");
 printf("3. Search Product\n");
 printf("4. Update Product\n");
 printf("5. Delete Product\n");
 printf("6. Exit\n");
 printf("Enter choice: ");
 scanf("%d", &choice);
 switch (choice) {
 case 1:
 add_product();
 break;
 case 2:
 display_products();
 break;
 case 3:
 search_product();
 break;
 case 4:
 update_product();
 break;
 case 5:
 delete_product();
 break;
 case 6:
 printf("Exiting program...\n");
 break;
 default:
 printf("Invalid choice! Try again.\n");
 }
 } while (choice != 6);
 return 0;
}
