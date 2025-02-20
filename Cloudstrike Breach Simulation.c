#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX_LINE_LENGTH 256
#define MIN_PASSWORD_LENGTH 8
// Function to evaluate password strength
int evaluate_password_strength(const char *password) {
 int has_upper = 0, has_lower = 0, has_digit = 0, has_special = 0;
 int length = strlen(password);

 if (length < MIN_PASSWORD_LENGTH)
 return 0; // Weak password
 for (int i = 0; i < length; i++) {
 if (isupper(password[i])) has_upper = 1;
 else if (islower(password[i])) has_lower = 1;
 else if (isdigit(password[i])) has_digit = 1;
 else has_special = 1;
 }

 return has_upper && has_lower && has_digit && has_special;
}
// Function to process credentials file
void process_credentials(const char *filename) {
 FILE *file = fopen(filename, "r");
 if (!file) {
 perror("Error opening credentials file");
 return;
 }

 printf("\nCompromised Credentials:\n");
 printf("---------------------------------\n");
 char line[MAX_LINE_LENGTH];
 while (fgets(line, sizeof(line), file)) {
 char *username = strtok(line, ",");
 char *password = strtok(NULL, ",");
 char *business_info = strtok(NULL, ",");

 if (username && password && business_info) {
 printf("User: %s, Password: %s, Business Info: %s", username, password, business_info);
 int strength = evaluate_password_strength(password);
 printf(" -> Password Strength: %s\n", strength ? "Strong" : "Weak");
 }
 }
 fclose(file);
}
// Function to process network vulnerabilities
void process_network_vulnerabilities(const char *filename) {
 FILE *file = fopen(filename, "r");
 if (!file) {
 perror("Error opening network devices file");
 return;
 }

 printf("\nNetwork Security Vulnerabilities:\n");
 printf("---------------------------------\n");
 char line[MAX_LINE_LENGTH];
 while (fgets(line, sizeof(line), file)) {
 char *device = strtok(line, ",");
 char *vulnerability = strtok(NULL, ",");

 if (device && vulnerability) {
 printf("Device: %s, Vulnerability: %s\n", device, vulnerability);
 }
 }
 fclose(file);
}
// Function to generate phishing emails
void generate_phishing_emails() {
 const char *fake_emails[] = {
 "security@cloudstrike-security.com",
 "admin-support@cloudstrike.com",
 "update@cloudstrike-info.com"
 };

 printf("\nPhishing Attack Simulation:\n");
 printf("---------------------------------\n");
 for (int i = 0; i < 3; i++) {
 printf("Fake Email: %s -> Effectiveness: High\n", fake_emails[i]);
 }
}
int main() {
 const char *credentials_file = "credentials.txt";
 const char *network_file = "network_devices.txt";

 process_credentials(credentials_file);
 process_network_vulnerabilities(network_file);
 generate_phishing_emails();

 return 0;
}
