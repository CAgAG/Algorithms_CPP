#include "List_Stack.h"

int main(){
    EleType data;

    SStack *stack = (SStack *) malloc(sizeof(SStack));

    InitStack(stack);
    printf("%d\n", StackEmpty(stack));

    for (int i = 0; i < 5; ++i) {
        Push(stack, i);
    }
    print_stack(stack);

    Pop(stack, data);
    printf("%d\n", data);
    print_stack(stack);

    GetTop(stack, data);
    printf("%d\n", data);

    printf("%d\n", StackEmpty(stack));

    return 0;
}
