//With builtin Functions
#include <stdio.h>
int total_salary_with_builtin(int base_salaries[], int experience_years[], int bonus_per_year, int n) {
 int total = 0;
 for (int i = 0; i < n; i++) {
 total += base_salaries[i] + (experience_years[i] * bonus_per_year);
 }
 return total;
}
int main() {
 int n, bonus_per_year;

 printf("Enter the number of employees: ");
 scanf("%d", &n);

 int base_salaries[n], experience_years[n];
 printf("Enter the base salaries of employees:\n");
 for (int i = 0; i < n; i++) {
 scanf("%d", &base_salaries[i]);
 }
 printf("Enter the experience years of employees:\n");
 for (int i = 0; i < n; i++) {
 scanf("%d", &experience_years[i]);
 }
 printf("Enter the bonus per year: ");
 scanf("%d", &bonus_per_year);
 printf("Total Salary (with built-in functions): %d\n", total_salary_with_builtin(base_salaries,
experience_years, bonus_per_year, n));
 return 0;
}

Without built in functions
#include <stdio.h>
int total_salary_with_builtin(int base_salaries[], int experience_years[], int bonus_per_year, int n) {
 int total = 0;
 for (int i = 0; i < n; i++) {
 total += base_salaries[i] + (experience_years[i] * bonus_per_year);
 }
 return total;
}
int main() {
 int n, bonus_per_year;

 printf("Enter the number of employees: ");
 scanf("%d", &n);

 int base_salaries[n], experience_years[n];
 printf("Enter the base salaries of employees:\n");
 for (int i = 0; i < n; i++) {
 scanf("%d", &base_salaries[i]);
 }
 printf("Enter the experience years of employees:\n");
 for (int i = 0; i < n; i++) {
 scanf("%d", &experience_years[i]);
 }
 printf("Enter the bonus per year: ");
 scanf("%d", &bonus_per_year);
 printf("Total Salary (with built-in functions): %d\n", total_salary_with_builtin(base_salaries,
experience_years, bonus_per_year, n));
 return 0;
}
