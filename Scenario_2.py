//With built in functions
#include <iostream>
#include <string>
#include <algorithm> // For std::transform
std::string format_username_builtin(std::string username) {
 // Remove spaces
 username.erase(std::remove(username.begin(), username.end(), ' '), username.end());
 // Convert to lowercase
 std::transform(username.begin(), username.end(), username.begin(), ::tolower);
 return username;
}
int main() {
 std::string username;
 std::cout << "Enter a username: ";
 std::getline(std::cin, username);
 std::cout << "Formatted Username (built-in functions): " << format_username_builtin(username)
<< std::endl;
 return 0;
}


//Without builtin functions
#include <iostream>
#include <string>
std::string format_username_manual(std::string username) {
 std::string formatted = "";

 for (int i = 0; username[i] != '\0'; i++) { // Iterate through the string manually
 char ch = username[i];
 if (ch != ' ') { // Skip spaces
 // Convert uppercase to lowercase manually
 if (ch >= 'A' && ch <= 'Z') {
 ch = ch + ('a' - 'A'); // ASCII conversion
 }
 formatted += ch; // Append to new string
 }
 }
 return formatted;
}
int main() {
 std::string username;
 std::cout << "Enter a username: ";
 std::getline(std::cin, username);
 std::cout << "Formatted Username (manual method): " << format_username_manual(username)
<< std::endl;
 return 0;
}
