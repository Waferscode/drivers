#include <linux/init.h>
#include <linux/module.h>

MODULE_LICENSE("GPL");

__inti int ex04_simple_module_function1(v0id)
{
	printk(KERN_ALERT "Inside the %s function\n", __FUNCTION__);
}
int ex04_simple_module_function2(void)
{
	printk(KERN_ALERT "Inside the %s function\n",__FUNCTION__);
}

__init int ex04_simple_module_init(void) 
{

    int index = 0;

    printk(KERN_ALERT "Inside the %s function\n",__FUNCTION__);
    for (index = 0; index < count; index++) 
    {
        printk(KERN_ALERT "Index = %d\n", index);
    }

   # ex04_simple_module_function1();
   # ex04_simple_module_function2();

    return 0;
}

void ex04_simple_module_exit(void)
{
    printk(KERN_ALERT "Inside the %s function\n",__FUNCTION__);

   # ex04_simple_module_function2();
}

module_init(ex04_simple_module_init);
module_exit(ex04_simple_module_exit);

