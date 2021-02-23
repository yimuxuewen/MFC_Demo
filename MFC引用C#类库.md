## 一、使用 /clr 编译 MFC 可执行文件或规则 DLL

#####   1、打开“项目属性”对话框，方法是右键单击“解决方案资源管理器”中的项目并选择“属性”。

#####   2、展开“配置属性”旁边的节点并选择“常规”。在右侧窗格中的“项目默认值”下，将“公共语言运行库支持”设置为“公共语言运行库支持 (/clr)”。

#####   3、在相同的窗格中，确保将“MFC 的使用”设置为“在共享 DLL 中使用 MFC”。

#####   4、在“配置属性”下，展开“C/[C++](http://c.chinaitlab.com/)”旁边的节点并选择“常规”。请确保将“调试信息格式”设置为“程序数据库

/Zi”（而不是“/ZI”）。

#####   5、在“配置属性”下，选择“C/[C++](http://c.chinaitlab.com/)”，然后选择“代码生成”。请确保将“运行时库”设置为“多线程调试

DLL (/MDd)”或“多线程 DLL (/MD)”之一。

##   二、在代码引用需要的dll

  \#using <mscorlib.dll>

  \#using "DownloaFiles.dll" //换成需要的dll文件

  using namespace System;

  using namespace ADMessage_test;//换成dll中类所使用的namespace

##   三、在dll函数调用代码前加入#pragma managed

  这是manage和unmanage混合编程在MFC下的一种实现方式。

## 四、CString转System::String ^应用实例

这里的*CString*是指*MFC*的*CString*，System::String为CLR中的字符串类，我认为最简单的做法是：

```
#这里的CString是指MFC的CString，System::String为CLR中的字符串类，我认为最简单的做法是：
CString text; 
System::String^ str1 = gcnew String(text);
#在自己编写调用魔方复原程序（动态链接库）的时候，由于C#中的函数接收字符串的类型为string,而MFC字符串的类型为CString类型，使用动态链接库的GetResult函数时需要类型转换。
```

## System.String 转换到 CString

五、直接 cast 即可

```
System::String^ s1 = gcnew System::String("How easy!");
CString s = (CString)s1;

```

