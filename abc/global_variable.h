#ifndef GLOBAL_VARIABLE_H
#define GLOBAL_VARIABLE_H

#endif // GLOBAL_VARIABLE_H

//全局变量类


extern int register_location;
//判断注册按钮信号是来自登录界面还是超级管理员窗口
//目的：实现可注册用户类型根据情况变化

extern int manage_jurisdiction;
//判断是超级管理员还是管理员（不同的权限）

extern int user_key;
//用户表中的Key;

extern int admin_key;
//管理员表中的Key
