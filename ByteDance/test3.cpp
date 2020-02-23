// 去除字符串中空格函数

// 思路为在数组中自我比较，若相同，自我赋值，若不同，跳过赋值，到下一轮

#include <stdio.h>

void findspacevalue(char *p) {
    if (p=NULL) return;

    for (int i=0,j=0; ; i++) {
        if (p[i]!=' ' && p[i]!='\0'){
            p[j] = p[i];
            j++;
        } else if (p[i]='\0') {
            break;
        }
    }
}


int main() {
    char p[] = "dfk fd get";
    findspacevalue(p);
    printf("%s", p);
}