/*
 * @Descripttion: 
 * @version: 
 * @Author: linhao
 * @Date: 2022-04-04 15:52:30
 * @LastEditors: linhao
 * @LastEditTime: 2022-04-04 16:53:46
 */
#include "ini.h"

int main(void)
{
    CMyINI *p = new CMyINI();
	p->ReadINI("Setting.ini");
	cout << "\n原始INI文件内容：" << std::endl;
	p->Travel();
	p->SetValue("setting", "hehe", "eheh");
	cout << "\n增加节点之后的内容：" << std::endl;
	p->Travel();
	cout << "\n修改节点之后的内容：" << std::endl;
	p->SetValue("kk", "kk", "2");
	p->Travel();
	p->WriteINI("Setting.ini");

    delete p;
}