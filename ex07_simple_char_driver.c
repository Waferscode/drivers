
#include <linux/init.h>
#include <linux/module.h>


#include <linux/fs.h>/* for character driver support */

int ex07_open(struct inode *pinode, struct file *pfile)
{
    printk(KERN_ALERT "Inside the %s function\n",__FUNCTION__);
    return 0;
}
ssize_t ex07_read(struct file *pfile, char __user *buffer, size_t length, loff_t *offset)
{
    printk(KERN_ALERT "Inside the %s function\n",__FUNCTION__); 
    return 0;   
}
ssize_t ex07_write(struct file *pfile, const char __user *buffer, size_t length, loff_t *offset)
{
    printk(KERN_ALERT "Inside the %s function\n",__FUNCTION__);
    return length;
}
int ex07_close(struct inode *pinode, struct file *pfile)
{
    printk(KERN_ALERT "Inside the %s function\n",__FUNCTION__);
    return 0;
}

/*To hold the file operations perfomed on this device */
const struct file_operations ex07_file_operations = {
    .owner = THIS_MODULE,
    .open  = ex07_open,
    .read  = ex07_read,
    .write = ex07_write,
    .release = ex07_close,

};

int ex07_simple_module_init(void) 
{
    printk(KERN_ALERT "Inside the %s function\n",__FUNCTION__);
    /*Register with the kernel and indicate that we are registering a character device driver*/
    register_chrdev(240 /*Major Number*/,
		    "Simple Char Drv" /* Name of the driver*/,
		    &ex07_file_operations /* File Operations*/);  
    return 0;
}

void ex07_simple_module_exit(void)
{
    printk(KERN_ALERT "Inside the %s function\n",__FUNCTION__);
    /*Unregister the character device driver*/
    unregister_chrdev(240, "Simple Char Dev");
}

module_init(ex07_simple_module_init);
module_exit(ex07_simple_module_exit);

