#include <stdio.h>
#define MAX 100
typedef struct {
    int coeff;
    int expo;
} Term;
int inputPolynomial(Term poly[]) {
    int n;
    printf("Enter the number of terms: ");
    scanf("%d", &n);

    printf("Enter each term as <coefficient> <exponent>:\n");
    for (int i = 0; i < n; i++) {
        printf("Term %d: ", i + 1);
        scanf("%d %d", &poly[i].coeff, &poly[i].expo);
    }
    return n;
}
void displayPolynomial(Term poly[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%dx^%d", poly[i].coeff, poly[i].expo);
        if (i != n - 1)
            printf(" + ");
    }
    printf("\n");
}
int addPolynomials(Term poly1[], int n1, Term poly2[], int n2, Term result[]) {
    int i = 0, j = 0, k = 0;

 
    while (i < n1 && j < n2) {
        if (poly1[i].expo == poly2[j].expo) {
            result[k].coeff = poly1[i].coeff + poly2[j].coeff;
            result[k].expo = poly1[i].expo;
            i++;
            j++;
            k++;
        } else if (poly1[i].expo > poly2[j].expo) {
            result[k] = poly1[i];
            i++;
            k++;
        } else {
            result[k] = poly2[j];
            j++;
            k++;
        }
    }

    
    while (i < n1) {
        result[k++] = poly1[i++];
    }

    while (j < n2) {
        result[k++] = poly2[j++];
    }

    return k; 
}

int main() {
    Term poly1[MAX], poly2[MAX], result[MAX];
    int n1, n2, n3;

    printf("Enter first polynomial:\n");
    n1 = inputPolynomial(poly1);

    printf("Enter second polynomial:\n");
    n2 = inputPolynomial(poly2);

    n3 = addPolynomials(poly1, n1, poly2, n2, result);

    printf("\n First Polynomial: ");
    displayPolynomial(poly1, n1);

    printf("Second Polynomial: ");
    displayPolynomial(poly2, n2);

    printf("Sum Polynomial: ");
    displayPolynomial(result, n3);

    return 0;
}

