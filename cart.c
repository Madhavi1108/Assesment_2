#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_CART_SIZE 100
typedef struct {
 int productID;
 char productName[50];
 float price;
 int quantity;
} CartItem;
CartItem cart[MAX_CART_SIZE];
int cartSize = 0;
void addProduct(int productID, char productName[], float price, int quantity) {
 for (int i = 0; i < cartSize; i++) {
 if (cart[i].productID == productID) {
 cart[i].quantity += quantity;
 printf("Updated quantity of product %d to %d\n", productID, cart[i].quantity);
 return;
 }
 }
 if (cartSize < MAX_CART_SIZE) {
 cart[cartSize].productID = productID;
 strcpy(cart[cartSize].productName, productName);
 cart[cartSize].price = price;
 cart[cartSize].quantity = quantity;
 cartSize++;
 printf("Added product %d to the cart.\n", productID);
 } else {
 printf("Cart is full!\n");
 }
}
void removeProduct(int productID) {
 int found = 0;
 for (int i = 0; i < cartSize; i++) {
 if (cart[i].productID == productID) {
 found = 1;
 for (int j = i; j < cartSize - 1; j++) {
 cart[j] = cart[j + 1];
 }
 cartSize--;
 printf("Removed product %d from the cart.\n", productID);
 break;
 }
 }
 if (!found) {
 printf("Product %d not found in the cart.\n", productID);
 }
}
void updateQuantity(int productID, int newQuantity) {
 for (int i = 0; i < cartSize; i++) {
 if (cart[i].productID == productID) {
 cart[i].quantity = newQuantity;
 printf("Updated quantity of product %d to %d\n", productID, newQuantity);
 return;
 }
 }
 printf("Product %d not found in the cart.\n", productID);
}
void displayCart() {
 if (cartSize == 0) {
 printf("Shopping cart is empty.\n");
 return;
 }
 printf("Shopping Cart:\n");
 printf("ID\tName\t\tPrice\tQuantity\tTotal\n");
 for (int i = 0; i < cartSize; i++) {
 printf("%d\t%s\t\t%.2f\t%d\t\t%.2f\n",
 cart[i].productID, cart[i].productName, cart[i].price,
 cart[i].quantity, cart[i].price * cart[i].quantity);
 }
}
float calculateTotal() {
 float total = 0;
 for (int i = 0; i < cartSize; i++) {
 total += cart[i].price * cart[i].quantity;
 }
 return total;
}
void applyDiscount(float discountPercent) {
 float total = calculateTotal();
 float discountAmount = (discountPercent / 100) * total;
 float finalTotal = total - discountAmount;
 printf("Total before discount: %.2f\n", total);
 printf("Discount applied: %.2f\n", discountAmount);
 printf("Final total after discount: %.2f\n", finalTotal);
}
int main() {
 int choice, productID, quantity;
 char productName[50];
 float price, discountPercent;
 while (1) {
 printf("\nShopping Cart Menu:\n");
 printf("1. Add Product\n");
 printf("2. Remove Product\n");
 printf("3. Update Quantity\n");
 printf("4. Display Cart\n");
 printf("5. Calculate Total\n");
 printf("6. Apply Discount\n");
 printf("7. Exit\n");
 printf("Enter your choice: ");
 scanf("%d", &choice);
 switch (choice) {
 case 1:
 printf("Enter Product ID: ");
 scanf("%d", &productID);
 printf("Enter Product Name: ");
 scanf("%s", productName);
 printf("Enter Price: ");
 scanf("%f", &price);
 printf("Enter Quantity: ");
 scanf("%d", &quantity);
 addProduct(productID, productName, price, quantity);
 break;
 case 2:
 printf("Enter Product ID to remove: ");
 scanf("%d", &productID);
 removeProduct(productID);
 break;
 case 3:
 printf("Enter Product ID to update: ");
 scanf("%d", &productID);
 printf("Enter New Quantity: ");
 scanf("%d", &quantity);
 updateQuantity(productID, quantity);
 break;
 case 4:
 displayCart();
 break;
 case 5:
 printf("Total Cost: %.2f\n", calculateTotal());
 break;
 case 6:
 printf("Enter discount percentage: ");
 scanf("%f", &discountPercent);
 applyDiscount(discountPercent);
 break;
 case 7:
 printf("Exiting...\n");
 return 0;
 default:
 printf("Invalid choice! Please try again.\n");
 }

}
}
