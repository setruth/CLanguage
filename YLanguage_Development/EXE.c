
//执行器
int Initialization_stack(struct vm_instruction *code, vm * spstack)
{
	int size = 0;
	for (;;)
	{
		switch (code[size].opcode){
		case CONST:
		//spstack->stack[++spstack->sp]=code[size].operand;
		case END:
		    return 0;
			}
		++size;
	}
}
//栈初始

void stack_vm(vm * stack)
{
	stack->sp = -1;
	stack->stack = malloc(sizeof(void *) * 100);
}