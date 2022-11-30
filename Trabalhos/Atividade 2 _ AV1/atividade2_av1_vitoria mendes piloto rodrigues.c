/*

                                    ╔═══*.·:·.☽✧    ✦    ✧☾.·:·.*═══╗
                                            𝐓𝐑𝐀𝐁𝐀𝐋𝐇𝐎 𝟐 - 𝐀𝐕𝟏

                                        𝐀𝐥𝐮𝐧𝐚: 𝐕𝐢𝐭𝐨𝐫𝐢𝐚 𝐏𝐢𝐥𝐨𝐭𝐨
                                        𝐃𝐬𝐢𝐜𝐢𝐩𝐥𝐢𝐧𝐚: 𝐅𝐏𝐑
                                        𝐏𝐫𝐨𝐟𝐞𝐬𝐬𝐨𝐫: 𝐋𝐞𝐨𝐧𝐚𝐫𝐝𝐨 𝐕𝐢𝐚𝐧𝐧𝐚
                                    ╚═══*.·:·.☽✧    ✦    ✧☾.·:·.*═══╝

𝐐𝐔𝐄𝐒𝐓𝐀𝐎:
    𝙳𝚎𝚜𝚎𝚗𝚟𝚘𝚕𝚟𝚎𝚛 𝚞𝚖𝚊 𝚏𝚞𝚗𝚌𝚊𝚘 𝚚𝚞𝚎, 𝚍𝚊𝚍𝚊 𝚞𝚖𝚊 𝚜𝚝𝚛𝚒𝚗𝚐 𝚜, 𝚍𝚎𝚜𝚕𝚘𝚚𝚞𝚎 𝚊𝚜 𝚜𝚞𝚊𝚜 𝚟𝚘𝚐𝚊𝚒𝚜 𝚙𝚊𝚛𝚊 𝚘 𝚜𝚎𝚞 𝚒𝚗𝚒𝚌𝚒𝚘 𝚎 𝚊𝚜 𝚜𝚞𝚊𝚜 𝚌𝚘𝚗𝚜𝚘𝚊𝚗𝚝𝚎𝚜 𝚙𝚊𝚛𝚊 𝚘 𝚏𝚒𝚗𝚊𝚕.
    𝙾𝚜 𝚍𝚎𝚖𝚊𝚒𝚜 𝚌𝚊𝚛𝚊𝚌𝚝𝚎𝚛𝚎𝚜 𝚍𝚎𝚟𝚎𝚖 𝚙𝚎𝚛𝚖𝚊𝚗𝚎𝚌𝚎𝚛 𝚗𝚊𝚜 𝚖𝚎𝚜𝚖𝚊𝚜 𝚙𝚘𝚜𝚒𝚌𝚘𝚎𝚜.

    𝙽𝚘𝚝𝚊: 𝚊 𝚘𝚛𝚍𝚎𝚖 𝚍𝚊𝚜 𝚟𝚘𝚐𝚊𝚒𝚜 𝚎 𝚍𝚊𝚜 𝚌𝚘𝚗𝚜𝚘𝚊𝚗𝚝𝚎𝚜 𝚗𝚊 𝚜𝚝𝚛𝚒𝚗𝚐 𝚒𝚗𝚒𝚌𝚒𝚊𝚕 𝚗𝚊𝚘 𝚙𝚛𝚎𝚌𝚒𝚜𝚊 𝚜𝚎𝚛 𝚙𝚛𝚎𝚜𝚎𝚛𝚟𝚊𝚍𝚊 𝚗𝚊 𝚏𝚒𝚗𝚊𝚕.
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define TAM 30

//𝐏𝐫𝐨𝐭𝐨𝐭𝐢𝐩𝐨 𝐝𝐚𝐬 𝐟𝐮𝐧𝐜𝐨𝐞𝐬
void deslocaLetras(char s[], char s2[], char s3[]);

// 𝐌𝐚𝐢𝐧
void main(){
    char s[TAM], sAux[TAM], sAux2[TAM];
    printf("-------- ESCREVA UMA PALAVRA: ");
    fflush(stdin);
    gets(s);
    deslocaLetras(s,sAux,sAux2);
}

// 𝐃𝐞𝐬𝐥𝐨𝐜𝐚 𝐥𝐞𝐭𝐫𝐚𝐬
void deslocaLetras(char s[], char s2[], char s3[]){
   int i, j, k=0, l=0;
   int tamanho = strlen(s);
   for (i=0;i<=tamanho;i++){
       s[i] = toupper(s[i]);
   }

   for (j=0;j<=tamanho;j++){
        if ( (s[j] == 'A') || (s[j] == 'E') || (s[j] == 'I') || (s[j] == 'O') || (s[j] == 'U') ){
            s2[k] = s[j];
            k++;
       } else {
           s3[l] = s[j];
           l++;
       }
   }
   s2[k]='\0';
   s3[l]='\0';
   printf("\n ---- PALAVRA ORIGINAL: %s\n",s);
   printf("\n ---- SOMENTE VOGAIS: %s\n",s2);
   printf("\n ---- SOMENTE CONSOANTES: %s\n",s3);
   printf("\n ---- PALAVRA INVERTIDA: %s\n", strcat(s2,s3));
}
