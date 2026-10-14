#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LINES 100
#define MAX_LENGTH 200
#define MAX_VARS 50


typedef enum 
{
    BEGIN, PROMPT, STORE, COMPUTE, DISPLAY, END, COMMENT, INVALID
} PseudoCodeTokens;


typedef struct 
{
    char pseudocodeVar[MAX_VARS][MAX_LENGTH];  
    char cVar[MAX_VARS][MAX_LENGTH];          
    int varCount;                             
} VariableMapping;


PseudoCodeTokens getToken(char *word) 
{
    if (strcmp(word, "BEGIN") == 0) {
        return BEGIN;
    } else if (strcmp(word, "PROMPT") == 0) {
        return PROMPT;
    } else if (strcmp(word, "STORE") == 0) {
        return STORE;
    } else if (strcmp(word, "COMPUTE") == 0) {
        return COMPUTE;
    } else if (strcmp(word, "DISPLAY") == 0) {
        return DISPLAY;
    } else if (strcmp(word, "END") == 0) {
        return END;
    } else if (strstr(word, "#") != NULL) {
        return COMMENT;  
    } else {
        return INVALID;
    }
}


char* getCVarForPseudo(VariableMapping *varMapping, const char *pseudoVar)
 {
    
    for (int i = 0; i < varMapping->varCount; i++) {
        if (strcmp(varMapping->pseudocodeVar[i], pseudoVar) == 0) {
            return varMapping->cVar[i];  
        }
    }

    
    char *newVar = (char *)malloc(MAX_LENGTH * sizeof(char));
    if (!newVar) {
        printf("Memory allocation failed!\n");
        exit(1); 
    }

   
    sprintf(newVar, "var%d", varMapping->varCount + 1);

   
    strcpy(varMapping->pseudocodeVar[varMapping->varCount], pseudoVar);
    strcpy(varMapping->cVar[varMapping->varCount], newVar);
    varMapping->varCount++;

    return newVar;  
}

int main() 
{
    
    char pseudocode[MAX_LINES][MAX_LENGTH];

    
    FILE *file = fopen("pseudocode.txt", "r");
    if (!file) {
        printf("Error: Could not open the pseudocode file.\n");
        return 1;
    }

    int lineCount = 0;
   
    while (fgets(pseudocode[lineCount], sizeof(pseudocode[lineCount]), file)) {
        lineCount++;
    }
    fclose(file);

   
    FILE *outFile = fopen("output.txt", "w");
    if (!outFile) {
        printf("Error: Could not open the output file.\n");
        return 1;
    }

   
    fprintf(outFile, "#include <stdio.h>\n\n");
    fprintf(outFile, "int main() {\n");

    VariableMapping varMapping = { .varCount = 0 };

    
    for (int i = 0; i < lineCount; i++) {
        char *line = pseudocode[i];
        while (*line == ' ') {
            line++;
        }
        if (strlen(line) == 0 || strstr(line, "#") == line) {
            continue;  
        }

      
        char *token = strtok(line, " \n");

        PseudoCodeTokens tokenType = getToken(token);

        switch (tokenType) {
            case BEGIN:
                break;

            case PROMPT:
                token = strtok(NULL, " \n");
                if (token != NULL) {
                    fprintf(outFile, "    printf(\"Enter the value for %s: \");\n", token);
                }
                break;

            case STORE:
                token = strtok(NULL, " \n");
                if (token != NULL) {
                    char *cVar = getCVarForPseudo(&varMapping, token);  
                    fprintf(outFile, "    int %s;\n", cVar);
                    fprintf(outFile, "    scanf(\"%%d\", &%s);\n", cVar);
                }
                break;

            case COMPUTE:
                {
                    char *var1 = strtok(NULL, " \n");
                    char *var2 = strtok(NULL, " \n");
                    char *result = strtok(NULL, " \n");
                    if (var1 && var2 && result) {
                        char *cVar1 = getCVarForPseudo(&varMapping, var1);  
                        char *cVar2 = getCVarForPseudo(&varMapping, var2);
                        char *cResult = getCVarForPseudo(&varMapping, result);
                        fprintf(outFile, "    int %s = %s + %s;\n", cResult, cVar1, cVar2);
                    }
                }
                break;

            case DISPLAY:
                token = strtok(NULL, " \n");
                if (token != NULL) {
                    char *cVar = getCVarForPseudo(&varMapping, token); 
                    fprintf(outFile, "    printf(\"The value of %s is: %%d\\n\", %s);\n", cVar, cVar);
                }
                break;

            case END:
                fprintf(outFile, "    return 0;\n}\n");
                break;

            case COMMENT:
                break;

            default:
                break;
        }
    }

    fclose(outFile);

    printf("C code has been successfully generated in 'output.txt'.\n");
    return 0;
}
