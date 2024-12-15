// SPDX-License-Identifier: GPL-2.0-only  
/*  
 *  linux/init/version.c  
 *  
 *  Copyright (C) 1992  Theodore Ts'o  
 *  
 *  May be freely distributed as part of Linux.  
 */  

#include <generated/compile.h>  
#include <linux/build-salt.h>  
#include <linux/elfnote-lto.h>  
#include <linux/export.h>  
#include <linux/init.h>  
#include <linux/printk.h>  
#include <linux/uts.h>  
#include <linux/utsname.h>  
#include <linux/proc_ns.h>  

static int __init early_hostname(char *arg)  
{  
    size_t bufsize = sizeof(init_uts_ns.name.nodename);  
    size_t maxlen  = bufsize - 1;  
    ssize_t arglen;  

    arglen = strscpy(init_uts_ns.name.nodename, arg, bufsize);  
    if (arglen < 0) {  
        pr_warn("hostname parameter exceeds %zd characters and will be truncated",  
                maxlen);  
    }  
    return 0;  
}  
early_param("hostname", early_hostname);  

const char linux_proc_banner[] =  
    "%s version %s"  
    " (" LINUX_COMPILE_BY "@" LINUX_COMPILE_HOST ")"  
    " (" LINUX_COMPILER ") %s\n";  

/* Mensaje personalizado */  
const char linux_banner[] __weak =  
    "\n"  
    "*************************************************\n"  
    "*       Bienvenido a MiKernel Personalizado     *\n"  
    "*                Versión 1.0                    *\n"  
    "*************************************************\n";  

/* Función que imprime el mensaje */  
static int __init print_banner(void)  
{  
    pr_info("%s\n", linux_banner);  
    return 0;  
}  

/* Registrar la función para que se ejecute al arranque */  
core_initcall(print_banner);  

BUILD_SALT;  
BUILD_LTO_INFO;  

struct uts_namespace init_uts_ns __weak;  

/* Si esta línea está presente, coméntala. */  
// #include "version-timestamp.c"  

EXPORT_SYMBOL_GPL(init_uts_ns);