#include <stdio.h>
#include <string.h>
int main() {
	char header[10];
	char trailer[10];
	char ch[100];
	char add[10];
	char out[100];
	char esc[] = "esc";
	int i,j,k = 0,l,m;
	printf("Enter the characters :");
	scanf("%s", ch);
	printf("Enter a charcter that represents starting delimiter :");
	scanf("%s", header);
	printf("Enter a character that represents ending delimiter :");
	scanf("%s", trailer);
	printf("Enter a character that is to be stuffed :");
	scanf("%s", add);
	for (i = 0; i <strlen(header); i++) {
		out[k] = header[i];
		k++;
	}
	for (i = 0; i < strlen(ch); i++) {
		int count = 0;
		for (j = i, l = 0; j < (i + strlen(header)); j++,l++) {
		    if (ch[j] == header[l]) {
		        count++;
			} else {
				break;
			}
		}
		if (count == strlen(header)) {
			for (m = 0; m < strlen(add); m++) {
				out[k] = add[m];
				k++;
			}
		}
		count = 0;
		for (j = i, l = 0; j < (i + strlen(trailer)); j++,l++) {
            if (ch[j] == trailer[l]) {
                count++;
            } else {
                break;
            }
        }
        if (count == strlen(trailer)) {
            for (m = 0; m < strlen(add); m++) {
                out[k] = add[m];
                k++;
            }
        }
		count = 0;
		for (j = i, l = 0; j < (i + strlen(esc)); j++,l++) {
		    if (ch[j] == esc[l]) {
		        count++;
            } else {
                break;
            }
        }
        if (count == strlen(esc)) {
            for (m = 0; m < strlen(add); m++) {
                out[k] = add[m];
                k++;
            }
        }
        out[k] = ch[i];
		k++;
	}
	for (i = 0; i <strlen(trailer); i++) {
	    out[k] = trailer[i];
	    k++;
	}
	out[k] = '\0';
	printf("\nAfter Stuffing: %s\n", out);
	return 0;
}