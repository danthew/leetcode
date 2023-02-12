bool isValid(char * s){
    //current character
    char cur = s[0];
    if(cur == '\0') return false;
    //array to hold the stack of brackets
    char *arr;
    arr = (char*)malloc(sizeof(char));
    arr[0] = cur;
    //if we start with a closing bracket, return false
    if(cur == ')' || cur == ']' || cur == '}') return false;
    //counter starting at the second index, since we already used the first
    int i = 1, j = 1;
    //while we aren't at the end of the string
    while(cur != '\0'){
        if(i == 0){
            if(cur == ')' || cur == ']' || cur == '}') return false;
        }
        //if we have an opening bracket, make space for it, add it to arr, then iterate i
        if(cur == '(' || cur == '{' || cur == '['){
            arr = (char*)realloc(arr, sizeof(char)*(i+1));
            arr[i] = cur;
            i++;
        }
        //if we have a closing bracket...
        //if the backet closes its corresponding opener, then remove them from the stack and decrement i by 1
        //else, return false
        else if(cur == ')'){
            if(arr[i-1] == '('){
                arr = (char*)realloc(arr, sizeof(char)*(i-1));
                i--;
            }
            else return false;
        }
        else if(cur == '}'){
            if(arr[i-1] == '{'){
                arr = (char*)realloc(arr, sizeof(char)*(i-1));
                i--;
            }
            else return false;
        }
        else if(cur == ']'){
            if(arr[i-1] == '['){
                arr = (char*)realloc(arr, sizeof(char)*(i-1));
                i--;
            }
            else return false;
        }
        cur = s[j];
        j++;
    }
    free(arr);
    //if all items are off the stack, true. else, false
    if(i == 1) return true;
    else return false;
}