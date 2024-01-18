#include <stdio.h>
#include <unistd.h>

int main() {
    printf("Hello, I'm exec program!\n");
    getchar();
    execl("./02_05_another_Milosz_Gaszyna", "02_05_another_Milosz_Gaszyna", (char *)NULL);
    return 0;
}
