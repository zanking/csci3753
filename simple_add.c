#include <linux/kernel.h>
#include <linux/linkage.h>

asmlinkage long sys_simple_add(int number1, int number2, int* result){
	printk("Number1 is %d\n", number1);
	printk("Number2 is %d\n", number2);
	int aaa; 
	aaa = number1 + number2;
	*result = aaa;
	printk("Result is %d\n", aaa);
	return 0;
}
