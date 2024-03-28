#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/hash.h>
#include <linux/gcd.h>
#include <asm/param.h>
#include <linux/jiffies.h>


void print_jiffies(const char *msg)
{
 printk(KERN_INFO "jiffies %s value: %lu\n", msg, jiffies);
}

int simple_init(void)
{
    printk(KERN_INFO "Loading Kernel Module\n");
    printk(KERN_INFO "GOLDEN_RATIO_PRIME: %lu\n", GOLDEN_RATIO_PRIME);
    print_jiffies("init");
    printk(KERN_INFO "Hz: %lu\n", HZ);
    return 0;
}


void simple_exit(void)
{
    printk(KERN_INFO "Removing Kernel Module\n");
    printk(KERN_INFO "gcd(3,300, 24) = %lu\n", gcd( 3300, 24));
    print_jiffies("exit");
}

module_init(simple_init);
module_exit(simple_exit);

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Simple Module");
MODULE_AUTHOR("SGG");